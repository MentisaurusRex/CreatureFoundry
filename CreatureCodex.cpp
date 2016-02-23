#include "CreatureCodex.h"


CreatureCodex::CreatureCodex(void){
}

CreatureCodex::~CreatureCodex(void){
}

void CreatureCodex::init(){
	_armorCodex.init();
	_weaponCodex.init();
	_moveCodex.init();
	
	//0
	Creature cribble = Creature("Cribble", 20, 20, 20, 20, 100, _armorCodex.getArmor(0), _weaponCodex.getWeapon(0));
	cribble.addMove(_moveCodex.getMove(0));
	cribble.addMove(_moveCodex.getMove(1));
	cribble.addMove(_moveCodex.getMove(2));
	cribble.addMove(_moveCodex.getMove(3));
	_creatureList.push_back(cribble);

	//1
	Creature chromum = Creature("Chromum", 25, 10, 10, 10, 100, _armorCodex.getArmor(1), _weaponCodex.getWeapon(1));
	chromum.addMove(_moveCodex.getMove(4));
	chromum.addMove(_moveCodex.getMove(5));
	chromum.addMove(_moveCodex.getMove(6));
	chromum.addMove(_moveCodex.getMove(7));
	_creatureList.push_back(chromum);

	//2
	Creature yutern = Creature("Yutern", 20, 15, 10, 25, 100, _armorCodex.getArmor(2), _weaponCodex.getWeapon(2));
	yutern.addMove(_moveCodex.getMove(8));
	yutern.addMove(_moveCodex.getMove(9));
	yutern.addMove(_moveCodex.getMove(10));
	yutern.addMove(_moveCodex.getMove(11));
	_creatureList.push_back(yutern);

	//3
	Creature vermer = Creature("Vermer", 20, 15, 15, 20, 100, _armorCodex.getArmor(0), _weaponCodex.getWeapon(3));
	vermer.addMove(_moveCodex.getMove(0));
	vermer.addMove(_moveCodex.getMove(1));
	vermer.addMove(_moveCodex.getMove(13));
	vermer.addMove(_moveCodex.getMove(14));
	_creatureList.push_back(vermer);

	//4
	Creature cepalil = Creature("Cepalil", 26, 15, 15, 9, 100, _armorCodex.getArmor(3), _weaponCodex.getWeapon(4));
	cepalil.addMove(_moveCodex.getMove(6));
	cepalil.addMove(_moveCodex.getMove(15));
	cepalil.addMove(_moveCodex.getMove(16));
	cepalil.addMove(_moveCodex.getMove(14));
	_creatureList.push_back(cepalil);

	
}

Creature CreatureCodex::getCreature(int index){
	return _creatureList[index];	
}