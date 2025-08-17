
class ItemBehaviourPotion : public ItemBehaviourConsumable {
public:

	cube::Creature::Buff::BuffType buffType = (cube::Creature::Buff::BuffType) 0;
	uint64_t buffDuration = 600000LL;
	float buffMultiplier = 1.0f;

	cube::Creature::Buff* buff = new cube::Creature::Buff();

	ItemBehaviourPotion(cube::Creature::Buff::BuffType _buffType) {
		useTime = 500LL;
		buffType = _buffType;
	};

	ItemBehaviourPotion(cube::Creature::Buff::BuffType _buffType, uint64_t _buffDuration) {
		useTime = 500LL;
		buffType = _buffType;
		buffDuration = _buffDuration;
	};

	ItemBehaviourPotion(cube::Creature::Buff::BuffType _buffType, uint64_t _buffDuration, float _buffMultiplier) {
		useTime = 500LL;
		buffType = _buffType;
		buffDuration = _buffDuration;
		buffMultiplier = _buffMultiplier;
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

	ItemBehaviourPotion(uint64_t _useTime, cube::Creature::Buff::BuffType _buffType, uint64_t _buffDuration, float _buffMultiplier) {
		useTime = _useTime;
		buffType = _buffType;
		buffDuration = _buffDuration;
		buffMultiplier = _buffMultiplier;
	};

	cube::Creature::Buff* GetAppliedBuff() override {
		buff->type = buffType;
		buff->unk = buffMultiplier;
		buff->time_remaining = buffDuration;
		return buff;
	}

	bool IsDrink() override { return true; };
	bool CanBuff() override { return true; };

};