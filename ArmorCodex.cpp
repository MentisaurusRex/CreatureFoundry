#include "ArmorCodex.h"


ArmorCodex::ArmorCodex(void)
{
}


ArmorCodex::~ArmorCodex(void)
{
}

void ArmorCodex::init(){

	//0
	Armor chitin = Armor("Chitin", 20);
	_armorList.push_back(chitin);

	//1
	Armor spiralShell = Armor("Spiral Shell", 80);
	_armorList.push_back(spiralShell);

	//2
	Armor feathers = Armor("Feathers", 10);
	_armorList.push_back(feathers);

	//3
	Armor toughFiber = Armor("Tough Fiber", 40);
	_armorList.push_back(toughFiber);
}

Armor ArmorCodex::getArmor(int index){
	return _armorList[index];	
}
