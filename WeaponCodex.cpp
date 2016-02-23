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


	//0
	Weapon simpleClaw = Weapon("Simple Claw", 20);
	_weaponList.push_back(simpleClaw);

	//1
	Weapon gooeyMucus = Weapon("Gooey Mucus", 10);
	gooeyMucus.addWeaponAbility(EffectCodex::get(ACIDIC));
	_weaponList.push_back(gooeyMucus);

	//2
	Weapon narrowBeak = Weapon("Narrow Beak", 25);
	_weaponList.push_back(narrowBeak);

	//3
	Weapon mandibles = Weapon("Mandibles", 25);
	_weaponList.push_back(mandibles);

	//4
	Weapon sprouts = Weapon("Sprouts", 20);
	_weaponList.push_back(sprouts);


}

Weapon WeaponCodex::getWeapon(int index){
	return _weaponList[index];	
}
