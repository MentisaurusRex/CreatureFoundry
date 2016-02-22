#include "ArmorCodex.h"


ArmorCodex::ArmorCodex(void)
{
}


ArmorCodex::~ArmorCodex(void)
{
}

void ArmorCodex::init(){
	Armor simpleShell = Armor("simpleShell", 20);
	_armorList.push_back(simpleShell);

	Armor spiralShell = Armor("spiralShell", 80);
	_armorList.push_back(spiralShell);
}

Armor ArmorCodex::getArmor(int index){
	return _armorList[index];	
}
