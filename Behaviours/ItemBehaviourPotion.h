
class ItemBehaviourPotion : public ItemBehaviourConsumable {
public:

	cube::Creature::Buff::BuffType buffType = (cube::Creature::Buff::BuffType) 0;
	uint64_t buffDuration = 600000LL;


	cube::Creature::Buff* buff = new cube::Creature::Buff();

	ItemBehaviourPotion(cube::Creature::Buff::BuffType _buffType) {
		buffType = _buffType;
	};

	ItemBehaviourPotion(cube::Creature::Buff::BuffType _buffType, uint64_t _buffDuration) {
		buffType = _buffType;
		buffDuration = _buffDuration;
	};

	ItemBehaviourPotion(uint64_t _useTime, cube::Creature::Buff::BuffType _buffType) {
		useTime = _useTime;
		buffType = _buffType;
	};

	ItemBehaviourPotion(uint64_t _useTime, cube::Creature::Buff::BuffType _buffType, uint64_t _buffDuration) {
		useTime = _useTime;
		buffType = _buffType;
		buffDuration = _buffDuration;
	};

	// For potion buff addition check cubeworld.exe+2C5408 in IDA
	cube::Creature::Buff* GetAppliedBuff() override {
		buff->type = buffType;
		buff->time_remaining = buffDuration;
		return buff;
	}

	bool IsDrink() override { return true; };
	bool CanBuff() override { return true; };

};