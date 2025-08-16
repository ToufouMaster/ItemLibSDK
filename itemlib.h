#include "SpriteLoader.h"
#include "ModItem.h"
#include "ItemData.h"
#include "ItemManager.h"

static void* g_base = nullptr;
static HANDLE g_hMap = nullptr;

static bool* g_initialized = nullptr;
static ItemManager* g_itemManager = nullptr;
static SpriteLoader* g_spriteLoader = nullptr;

static void EnsureSharedData() {
    if (g_itemManager) return; // already initialized

    SIZE_T totalSize = sizeof(bool) + sizeof(ItemManager) + sizeof(SpriteLoader);

    g_hMap = CreateFileMappingA(
        INVALID_HANDLE_VALUE,
        nullptr,
        PAGE_READWRITE,
        0,
        (DWORD)totalSize,
        "Global\\CubeItemLib"
    );

    if (!g_hMap) return;

    g_base = MapViewOfFile(
        g_hMap,
        FILE_MAP_ALL_ACCESS,
        0, 0,
        totalSize
    );

    if (!g_base) return;

    char* base = reinterpret_cast<char*>(g_base);
    g_initialized = reinterpret_cast<bool*>(base);
    g_itemManager = reinterpret_cast<ItemManager*>(base + sizeof(bool));
    g_spriteLoader = reinterpret_cast<SpriteLoader*>(base + sizeof(bool) + sizeof(ItemManager));

    if (!*g_initialized) {
        g_itemManager = new ItemManager();
        g_spriteLoader = new SpriteLoader();
        *g_initialized = true;
    }
}

void InitializeCILib() {
    EnsureSharedData();
}

// Public API
extern "C" __declspec(dllexport) ItemManager* GetItemManager() {
    EnsureSharedData();
    return g_itemManager;
}

extern "C" __declspec(dllexport) SpriteLoader* GetSpriteLoader() {
    EnsureSharedData();
    return g_spriteLoader;
}