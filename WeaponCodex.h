#pragma once
#include <vector>
#include "Weapon.h"
class WeaponCodex
{
public:
	WeaponCodex(void);
	~WeaponCodex(void);

	void init();
	Weapon getWeapon(int index);

private:
	std::vector<Weapon> _weaponList;
};

