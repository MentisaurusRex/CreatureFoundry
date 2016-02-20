#include "ArmorCodex.h"


ArmorCodex::ArmorCodex(void)
{
}


ArmorCodex::~ArmorCodex(void)
{
}

void ArmorCodex::init(){
	Armor basicArmor = Armor("simpleShell", 50);
	_armorList.push_back(basicArmor);
}

Armor ArmorCodex::getArmor(int index){
	return _armorList[index];	
}
