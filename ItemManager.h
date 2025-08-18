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
		if (Get(item->itemName))
		{
			//Duplicate items are not allowed;
			return false;
		}
		if (Get(item->itemCategory, item->itemID)) {
			/*ItemData* duplicateItem = Get(item->itemCategory, item->itemID);
			std::string name = std::string(item->itemName.begin(), item->itemName.end());
			std::string category = std::to_string(item->itemCategory);
			std::string id = std::to_string(item->itemID);
			std::string dName = std::string(duplicateItem->itemName.begin(), item->itemName.end());
			std::string dCategory = std::to_string(duplicateItem->itemCategory);
			std::string dId = std::to_string(duplicateItem->itemID);
			MessageBoxA(NULL,
				(name + " (category: " + category + ", id: " + id + ") is incompatible with an already existing item: " + dName + " (category: " + dCategory + ", id: " + dId + ")").c_str(),
				"Duplicate item found"
				, MB_OK);*/
			return false;
		}
		item_vector.push_back(item);
		return true;
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