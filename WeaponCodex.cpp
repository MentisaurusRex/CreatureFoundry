#include "WeaponCodex.h"


WeaponCodex::WeaponCodex(void)
{
}


WeaponCodex::~WeaponCodex(void)
{
}

void WeaponCodex::init(){
	Weapon simpleClaw = Weapon("simpleClaw", 10);
	_weaponList.push_back(simpleClaw);
}

Weapon WeaponCodex::getWeapon(int index){
	return _weaponList[index];	
}
