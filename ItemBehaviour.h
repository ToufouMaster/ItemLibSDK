#pragma once

class ItemBehaviour {
public:
	//Constructor
	ItemBehaviour() {};

	//Whenever the PLAYER uses this item, this function is called
	virtual void OnUse(cube::Creature* creature, cube::ItemStack* stack) {};

	// Return if a PLAYER can use the item.
	virtual bool CanBeUsed() { return false; };

	// Return if the item give a buff when drinked.
	virtual bool CanBuff() { return false; };

	// Return the buff given when a potion is drinked
	virtual cube::Creature::Buff* GetAppliedBuff() {
		return nullptr;
	}

	// Return if the item is eatable (false) or drinkable (true).
	virtual bool IsDrink() { return false; };

	//Whenever we Spawn this item into the world this function is called
	virtual void OnSpawn() {};

	//Whenever this item is looted by a PLAYER this function is called.
	virtual void OnLoot() {};

	//Whenver the item despawn this function is called.
	virtual void OnDestroy() {};

	// Return the sprite to be shown on screen.
	virtual cube::Sprite* GetModel(SpriteLoader* sprite_loader, cube::Item* item) { return nullptr; };

	// Return the time to consume a consumable item.
	virtual uint64_t GetConsumableUseTime(cube::Item* item) { return 0LL; };

	// Return the name displayed in game.
	virtual std::wstring* GetDisplayName(cube::Item* item) { return nullptr; }

	// Return the displayed name color.
	virtual FloatRGBA* GetNameColor(cube::Item* item) { return nullptr; }

	// Return the selling price of the item.
	virtual int GetSellingPrice(cube::Item* item) { return 0; }

	// Return the buying price of the item.
	virtual int GetBuyingPrice(cube::Item* item) { return 0; }

	// Return the maximum item amount you can have in your inventory.
	virtual int GetMaximumStackSize(cube::Item* item) { return 5; }
};