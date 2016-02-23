#include "Weapon.h"

Weapon::Weapon(std::string name, int weaponDamage){
	_name = name;
	_weaponDamage = weaponDamage;
}

Weapon::Weapon(void)
{
}

Weapon::~Weapon(void)
{
}

std::string Weapon::getName(){
	return _name;
}

int Weapon::getWeaponDamage(){
	return _weaponDamage;
}

void Weapon::addWeaponAbility(std::string name,
							Effect effect, 
							int priority,
							int accuracy,
							int critChance,
							double critMultiplier){
	_ability._name = name;
	_ability._effect = effect;
	_ability._priority = priority;
	_ability._accuracy = accuracy;
	_ability._critChance = critChance;
	_ability._critMultiplier = critMultiplier;
}

std::string Weapon::getWeaponAbilityName(){
	return _ability._name;
}

WeaponAbility Weapon::getWeaponAbility(){
	return _ability;
}

Effect Weapon::getWeaponEffect(){
	return _ability._effect;
}

int Weapon::getWeaponPriority(){
	return _ability._priority;
}

int Weapon::getWeaponAccuracy(){
	return _ability._accuracy;
}

int Weapon::getWeaponCritChance(){
	return _ability._critChance;
}

double Weapon::getWeaponCritMultiplier(){
	return _ability._critMultiplier;
}
