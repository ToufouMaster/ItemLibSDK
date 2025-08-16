#include "SpriteLoader.h"
#include "ModItem.h"
#include "ItemData.h"
#include "ItemManager.h"

#pragma data_seg("Shared")
ItemManager* g_itemManager = nullptr; // shared between DLL instances
SpriteLoader* g_spriteLoader = nullptr;
#pragma data_seg()
#pragma comment(linker, "/SECTION:Shared,RWS")

void InitializeCILib() {
    if (!g_itemManager) {
        g_itemManager = new ItemManager();
    }
    if (!g_spriteLoader) {
        g_spriteLoader = new SpriteLoader();
    }
}

ItemManager* GetItemManager() {
    return g_itemManager;
}

SpriteLoader* GetSpriteLoader() {
    return g_spriteLoader;
}