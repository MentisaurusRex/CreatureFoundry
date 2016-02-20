#pragma once
#include <string>
class Armor
{
public:
	Armor(std::string name, int armorValue);
	Armor(void);
	~Armor(void);

	std::string getName();
	int getArmorValue();

private:
	std::string _name;
	int _armorValue;
};

