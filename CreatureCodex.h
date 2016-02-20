#pragma once
#include <vector>
#include "Creature.h"
#include "ArmorCodex.h"
#include "WeaponCodex.h"
#include "MoveCodex.h"

class CreatureCodex
{
public:
	CreatureCodex(void);
	~CreatureCodex(void);

	void init();
	Creature getCreature(int index);

private:
	std::vector<Creature> _creatureList;
	ArmorCodex _armorCodex;
	WeaponCodex _weaponCodex;
	MoveCodex _moveCodex;

};

