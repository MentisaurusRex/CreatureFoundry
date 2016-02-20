#pragma once
#include <iostream>
#include "CreatureCodex.h"
#include "Battle.h"

int main(int argc, char** argv){
	CreatureCodex creatureCodex;
	Battle battle;
	int in;

	creatureCodex.init();

	battle.init(creatureCodex.getCreature(0), creatureCodex.getCreature(1));
	battle.startBattle();

	std::cin >> in;


}