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

	void addWeaponAbility(std::string name,
							Effect effect, 
							int priority,
							int accuracy,
							int critChance,
							double critMultiplier);

	bool abilityAcitaves();
	std::string getWeaponAbilityName();
	WeaponAbility getWeaponAbility();
	Effect getWeaponEffect();
	int getWeaponPriority();
	int getWeaponAccuracy();
	int getWeaponCritChance();
	double getWeaponCritMultiplier();

private:
	std::string _name;
	int _weaponDamage;
	WeaponAbility _ability;
};

