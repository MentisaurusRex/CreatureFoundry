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

void Weapon::addWeaponAbility(Effect effect){
	_ability._effect = effect;
}

WeaponAbility Weapon::getWeaponAbility(){
	return _ability;
}

Effect Weapon::getWeaponEffect(){
	return _ability._effect;
}
