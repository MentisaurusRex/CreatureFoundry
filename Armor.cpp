#include "Armor.h"


Armor::Armor(std::string name, int armorValue){
	_name = name;
	_armorValue = armorValue;
}

Armor::Armor(void)
{
}

Armor::~Armor(void)
{
}

std::string Armor::getName(){
	return _name;
}

int Armor::getArmorValue(){
	return _armorValue;
}