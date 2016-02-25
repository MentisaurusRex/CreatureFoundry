#pragma once
#include <iostream>
#include "CreatureCodex.h"
#include "Battle.h"
#include "ConditionCodex.h"
#include "MoveConditionCodex.h"
#include "EffectCodex.h"

int main(int argc, char** argv){
	CreatureCodex creatureCodex;
	Battle battle;
	int in;

	ConditionCodex::init();
	MoveConditionCodex::init();
	EffectCodex::init();
	creatureCodex.init();

	battle.init(creatureCodex.getCreature(5), creatureCodex.getCreature(1));
	battle.startBattle();

	std::cin >> in;


}