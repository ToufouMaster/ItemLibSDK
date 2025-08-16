#include "SpriteLoader.h"
#include "ModItem.h"
#include "ItemData.h"
#include "ItemManager.h"
#include <mutex>

static ItemManager* g_itemManager = nullptr;
static SpriteLoader* g_spriteLoader = nullptr;
static std::once_flag g_initFlag;

static void InitializeObjects() {
    g_itemManager = new ItemManager();
    g_spriteLoader = new SpriteLoader();
}

void InitializeCILib() {
    std::call_once(g_initFlag, InitializeObjects);
}

extern "C" __declspec(dllexport) ItemManager* GetItemManager() {
    return g_itemManager;
}

extern "C" __declspec(dllexport) SpriteLoader* GetSpriteLoader() {
    return g_spriteLoader;
}