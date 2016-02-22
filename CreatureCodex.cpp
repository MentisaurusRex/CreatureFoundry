#include "CreatureCodex.h"


CreatureCodex::CreatureCodex(void){
}

CreatureCodex::~CreatureCodex(void){
}

void CreatureCodex::init(){
	_armorCodex.init();
	_weaponCodex.init();
	_moveCodex.init();
	
	Creature player = Creature("Cribble", 20, 20, 20, 20, 100, _armorCodex.getArmor(0), _weaponCodex.getWeapon(0));
	player.addMove(_moveCodex.getMove(0));
	player.addMove(_moveCodex.getMove(1));
	player.addMove(_moveCodex.getMove(2));
	player.addMove(_moveCodex.getMove(3));
	_creatureList.push_back(player);

	Creature enemy = Creature("Chromum", 25, 10, 10, 10, 100, _armorCodex.getArmor(1), _weaponCodex.getWeapon(1));
	enemy.addMove(_moveCodex.getMove(4));
	enemy.addMove(_moveCodex.getMove(5));
	enemy.addMove(_moveCodex.getMove(6));
	enemy.addMove(_moveCodex.getMove(7));
	_creatureList.push_back(enemy);

	
}

Creature CreatureCodex::getCreature(int index){
	return _creatureList[index];	
}