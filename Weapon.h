#pragma once
#include <string>
class Weapon
{
public:
	Weapon(std::string name, int weaponDamage);
	Weapon(void);
	~Weapon(void);

	std::string getName();
	int getWeaponDamage();

private:
	std::string _name;
	int _weaponDamage;
};

