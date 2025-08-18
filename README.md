# Item Lib SDK
Is a library that you modders can use to add new items to our beloved CubeWorld.
It contains classes and functions to simplify the item creation process.
- An ItemManager that keep tracks of all registered items and keep them compatible with each others.
- A SpriteLoader so you can name your sprites and load them with ease.
- ItemData, Contain all the infos CubeWorld need for your item to be registered.
- And ItemBehaviour, the base class of your items logic.


## To safely use this library, please load and register all your sprite and items in OnGameTick() instead of Initialize().

(you want to initialize them only once)

### This library does not have a real documentation, but here are the functions you're gonna need to remember
- void InitializeCILib()
  > This is the most important function of them all, without this you'll never be sure if the library is loaded or not.
  > Always call this before anything else that come from this library. 
- ItemManager* GetItemManager()
  > It retrieve for you the ItemManager.
- SpriteLoader* GetSpriteLoader()
  > It retrieve for you the SpriteLoader.

### Now for the different classes
- ItemManager
  - bool Register(ItemData* item)
    > Register your items for you, it takes an ItemData ptr.
  - ItemData* Get(std::wstring name)
  - ItemData* Get(ItemData::CategoryType category, int id)
    > Retrieve any item you or any other mod loaded, simply provide the item_name or it's category and id and you'll get the ItemData associated with it.
    > In the case where no items was found it return a nullptr instead.

- SpriteLoader
  - cube::Sprite* LoadModel(std::wstring mod_id, cube::SpriteManager* sprite_manager, std::wstring model_name, std::string file_path)
    > Load the provided model based on mod_id and file_path and stores it behind the model_name using CubeWorld SpriteManager.
    > If a sprite of the same name is already loaded it will return a nullptr.
    > Otherwise it will return the loaded sprite.
  - std::string GetSpriteFilePath(std::wstring mod_id, std::string file_path)
    > Return the path to the specified provided model where file_path is the file name with it's extension (model.cub)
  - cube::Sprite* GetSprite(std::wstring model_name)
    > Return a loaded sprite of the same name as model_name.
    > If no sprite is found, return nullptr.

- ItemData
  - ItemData(std::wstring name, ItemBehaviour* behaviour, CategoryType category, int id)
    > The constructor of your ItemData, you'll need to give it a name (my_item) a category (Potion) an id (15) and finally a behaviour that will define how the item will interact with the game and the player.
  - ItemData* SetName(std::wstring name)
    > Allow you to change the item name. Don't use this function after the item is registered.
  - ItemData* SetCategory(CategoryType category)
    > Allow you to change the item category. Usage of this function after item registration is not recommended.
  - ItemData* SetID(int id)
    > Allow you to change the item id. Usage of this function after item registration is not recommended.
  - ItemData* SetBehaviour(ItemBehaviour* behaviour)
    > Allow you to change the item behaviour.

- ItemBehaviour
  > This class only contains virtual functions, the entire concept of it is that you override it's functionalities with yours.
  
    - virtual void OnUse(cube::Creature* creature, cube::ItemStack* stack)
      > This function is called whenever a player uses the item
      * Returns void by default
    - virtual bool CanBeUsed()
      > Determine if the OnUse function can be called by the library
      * Returns false by default
    - virtual cube::Creature::Buff* GetAppliedBuff()
      > This function is called whenever a player uses a mod item using ItemBehaviourPotion behaviour. When an item with this behaviour is used it grants the player with the buff specified in this function.
      * Returns nullptr by default
    - virtual bool CanBuff()
      > Determine if the GetAppliedBuff function can be called by the library. Buff is applied by the game only when drinking an item, IsDrink must return true.
      * Returns false by default
    - virtual bool IsDrink()
      > Determine if the item must be drinked (true) or eaten (false). This function is used by the library only if the item behaviour is ItemBehaviourConsumable, CanBeUsed must return true.
      * Returns false by default
    - virtual void OnSpawn()
      > not yet implemented.
    - virtual void OnLoot()
      > not yet implemented.
    - virtual void OnDestroy()
      > not yet implemented.
    - virtual cube::Sprite* GetModel(SpriteLoader* sprite_loader, cube::Item* item)
      > This function is called whenever the game has to render the item model.
      > You must provide the function a loaded sprite so it can display the item. (Use SpriteLoader::GetSprite() for this)
      * Returns nullptr by default
    - virtual uint64_t GetConsumableUseTime(cube::Item* item)
      > Return the amount of millisecond an item consume itself. This function is used by the library only if the item behaviour is ItemBehaviourConsumable, CanBeUsed must return true.
      * Returns 0LL by default
    - virtual std::wstring* GetDisplayName(cube::Item* item)
      > Return the displayed name of the item. 
      * Returns nullptr by default
    - virtual FloatRGBA* GetNameColor(cube::Item* item)
      > Determine the text color of the item name.
      > If the returned value is nullptr, the default item color is used instead.
      * Returns nullptr by default
    - virtual int GetSellingPrice(cube::Item* item)
      > Return the amount of gold you will get when the item is sold to a merchant.
      * Returns 0 by default
    - virtual int GetBuyingPrice(cube::Item* item)
      > Return the amount of gold you will spend to buy the item to a merchant.
      * Returns 0 by default
    - virtual int GetMaximumStackSize(cube::Item* item)
      > Return the amount of item of the same type you can store in your inventory.
      * Returns 5 by default
