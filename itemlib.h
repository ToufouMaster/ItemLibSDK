#include "SpriteLoader.h"
#include "ModItem.h"
#include "ItemData.h"
#include "ItemManager.h"
#include <mutex>

static ItemManager* g_itemManager = nullptr;
static SpriteLoader* g_spriteLoader = nullptr;
static std::once_flag g_initFlag;

typedef ItemManager* (*tGetItemManager)();
typedef SpriteLoader* (*tGetSpriteLoader)();
static tGetItemManager GetItemManager = nullptr;
static tGetSpriteLoader GetSpriteLoader = nullptr;

void InitializeCILib() {
    HMODULE hRoot = GetModuleHandleA("ItemLib.dll");
    if (hRoot) {
        GetItemManager = (tGetItemManager)GetProcAddress(hRoot, "internal_GetItemManager");
        GetSpriteLoader = (tGetSpriteLoader)GetProcAddress(hRoot, "internal_GetSpriteLoader");
    }
}