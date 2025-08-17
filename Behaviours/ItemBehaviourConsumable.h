
class ItemBehaviourConsumable : ItemBehaviour {
public:

	bool isDrink = false;
	uint64_t useTime = 10000LL;

	ItemBehaviourConsumable() {};

	ItemBehaviourConsumable(bool _isDrink) {
		isDrink = _isDrink;
	};

	ItemBehaviourConsumable(bool _isDrink, uint64_t _useTime) {
		isDrink = _isDrink;
		useTime = _useTime;
	};

	void OnUse(cube::Creature* creature, cube::ItemStack* stack) override {
		creature->entity_data.last_special_item.Copy(&stack->item);
		if (IsDrink()) {
			creature->entity_data.current_ability = 84;
		}
		else {
			creature->entity_data.current_ability = 85;
		}
		creature->entity_data.time_since_ability = 0.0f;
		creature->entity_data.roll_time = 0.0f;

		if (--stack->quantity <= 0) {
			stack->item.category = 0;
			stack->item.id = 0;
			stack->quantity = 0;
		}
	}

	bool CanBeUsed() override {
		return true;
	}

	uint64_t GetConsumableUseTime(cube::Item* item) override {
		return useTime;
	}

	// Return if the item is eatable (false) or drinkable (true).
	virtual bool IsDrink() { return isDrink; };
};