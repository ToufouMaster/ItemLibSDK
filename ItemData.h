#pragma once

typedef struct ItemData
{

    enum MaterialType : int
    {
        Iron = 1,
        Wood = 2,
        Steel = 4,
        Obsidian = 5,
        Cloth = 6,
        Bone = 7,
        Copper = 10,
        Gold = 11,
        Silver = 12,
        Platinum = 13,
        Emerald = 14,
        Sapphire = 15,
        Ruby = 16,
        Diamond = 17,
        Sandstone = 18,
        Saurian = 19,
        Parrot = 20,
        Mammoth = 21,
        Plant = 22,
        Ice = 23,
        Light = 24,
        Glass = 25,
        Silk = 26,
        Linnen = 27,
        Cotton = 28,
        Bronze = 29,
        Calcio = 30,
        Felt = 31,
        Flannell = 32,
        Mail = 33,
        Rivet = 34,
        Filament = 35,
        Spike = 36,
        Fiber = 37,
        Scale = 38,
        Web = 39,
        Shadow = 40,
        Dark = 41,
        Demon = 42,
        Fire = 43,
        Druid = 44,
        FireSpirit = 128,
        UnholySpirit = 129,
        IceSpirit = 130,
        WindSpirit = 131,
    };

    enum CategoryType : char {
        Consumable = 1,
        Formula = 2,
        Weapon = 3,
        ArmorChest = 4,
        ArmorGloves = 5,
        ArmorBoots = 6,
        ArmorShoulders = 7,
        Amulet = 8,
        Ring = 9,
        UnknownVoxel = 10,
        Collectible = 11,
        Coin = 12,
        PlatinumCoin = 13,
        ManaCube = 14,
        Leftover = 15,
        Beak = 16,
        Painting = 17,
        Vase = 18,
        Candle = 19,
        PetCage = 20,
        PetFood = 21,
        Quest = 22,
        Artifact = 23,
        Special = 24,
        Lamp = 25,
        EyePatch = 26,
        Building = 27,
        Potion = 28,
        Glyph = 29,
        // OnGroundLoot = 30,
        Loot = 31,
        ManaSpirit = 32,
        Whistle = 33,
    };

	std::wstring itemName;					//Item name
	CategoryType itemCategory;  //Item Category;
	int itemID;								//Item ID
	ModItem* itemBehaviour;

	//This is not needed as this struct contain all the needed data;
	//ModItem* id_modItem; //Item mod, used to implement the ITEM in the mod;

	ItemData(std::wstring name, ModItem* behaviour, CategoryType category, int id)
	{
		this->itemName = name;
		this->itemCategory = category;
		this->itemID = id;
		this->itemBehaviour = behaviour;
	}

	ItemData* SetName(std::wstring name)
	{
		this->itemName = name;
		return this;
	}

	ItemData* SetCategory(CategoryType category)
	{
		this->itemCategory = category;
		return this;
	}

	ItemData* SetBehaviour(ModItem* behaviour)
	{
		this->itemBehaviour = behaviour;
		return this;
	}

	ItemData* SetID(int id)
	{
		this->itemID = id;
		return this;
	}
};