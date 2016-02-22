#pragma once
#include <string>
#include "WeaponAbility.h"
#include "Effect.h"

class Weapon
{
public:
	Weapon(std::string name, int weaponDamage);
	Weapon(void);
	~Weapon(void);

	std::string getName();
	int getWeaponDamage();

	void addWeaponAbility(Effect effect);
	bool abilityAcitaves();
	WeaponAbility getWeaponAbility();
	Effect getWeaponEffect();

private:
	std::string _name;
	int _weaponDamage;
	WeaponAbility _ability;
};

