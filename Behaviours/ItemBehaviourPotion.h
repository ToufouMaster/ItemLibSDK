
class ItemBehaviourPotion : ItemBehaviourConsumable {
public:

	cube::Creature::Buff::BuffType buffType = (cube::Creature::Buff::BuffType) 0;
	uint64_t buffDuration = 600000LL;

	ItemBehaviourPotion() {};

	ItemBehaviourPotion(bool _isDrink, cube::Creature::Buff::BuffType _buffType) {
		isDrink = _isDrink;
		buffType = _buffType;
	};

	ItemBehaviourPotion(bool _isDrink, cube::Creature::Buff::BuffType _buffType, uint64_t _buffDuration) {
		isDrink = _isDrink;
		buffType = _buffType;
		buffDuration = _buffDuration;
	};

	ItemBehaviourPotion(bool _isDrink, uint64_t _useTime, cube::Creature::Buff::BuffType _buffType) {
		isDrink = _isDrink;
		useTime = _useTime;
		buffType = _buffType;
	};

	ItemBehaviourPotion(bool _isDrink, uint64_t _useTime, cube::Creature::Buff::BuffType _buffType, uint64_t _buffDuration) {
		isDrink = _isDrink;
		useTime = _useTime;
		buffType = _buffType;
		buffDuration = _buffDuration;
	};

	// For potion buff addition check cubeworld.exe+2C5408 in IDA
	virtual cube::Creature::Buff GetAppliedBuff() {
		cube::Creature::Buff buff = cube::Creature::Buff();
		buff.type = buffType;
		buff.time_remaining = buffDuration;
		return buff;
	}

};