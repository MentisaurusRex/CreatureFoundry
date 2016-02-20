#pragma once
#include <vector>
#include "Armor.h"
class ArmorCodex
{
public:
	ArmorCodex(void);
	~ArmorCodex(void);

	void init();
	Armor getArmor(int index);

private:
	std::vector<Armor> _armorList;

};

