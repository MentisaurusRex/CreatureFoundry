#include "WeaponCodex.h"
#include "WeaponAbility.h"
#include "EffectCodex.h"

WeaponCodex::WeaponCodex(void)
{
}


WeaponCodex::~WeaponCodex(void)
{
}

void WeaponCodex::init(){



	Weapon simpleClaw = Weapon("Simple Claw", 20);
	_weaponList.push_back(simpleClaw);


	Weapon gooeyMucus = Weapon("Gooey Mucus", 10);
	gooeyMucus.addWeaponAbility(EffectCodex::get(ACIDIC));


	_weaponList.push_back(gooeyMucus);
}

Weapon WeaponCodex::getWeapon(int index){
	return _weaponList[index];	
}
