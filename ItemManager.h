#pragma once

class ItemManager
{
private:
	std::vector<ItemData*> item_vector; //Contains all the items registered.

public:
	ItemManager() { item_vector = {}; }

	//Registers the Item to the Manager
	bool Register(ItemData* item)
	{
		if (Exists(item->itemName))
		{
			//Duplicate items are not allowed;
			return false;
		}
		MessageBoxA(NULL, "Registered Item", (std::string(item->itemName.begin(), item->itemName.end())+std::string(" of id: ")+std::to_string(item->itemID)).c_str(), MB_OK);
		item_vector.push_back(item);
		return true;
	}

	bool Exists(std::wstring ItemName)
	{
		for (int i = 0; i < item_vector.size(); i++)
		{
			if (item_vector[i]->itemName == ItemName)
			{
				return true;
			}
		}
		return false;
	}

	bool Exists(ItemData::CategoryType category, int id)
	{
		for (int i = 0; i < item_vector.size(); i++)
		{
			ItemData* item = item_vector[i];
			if (item->itemCategory == category && item->itemID == id)
			{
				return true;
			}
		}
		return false;
	}

	ItemData* Get(std::wstring name)
	{
		for (int i = 0; i < item_vector.size(); i++)
		{
			if (item_vector[i]->itemName == name)
			{
				return item_vector[i];
			}
		}
		return nullptr;
	}

	ItemData* Get(ItemData::CategoryType category, int id)
	{
		for (int i = 0; i < item_vector.size(); i++)
		{
			ItemData* item = item_vector[i];
			if (item->itemCategory == category && item->itemID == id)
			{
				return item;
			}
		}
		return nullptr;
	}

};