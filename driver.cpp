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

	battle.init(creatureCodex.getCreature(2), creatureCodex.getCreature(0));
	battle.startBattle();

	std::cin >> in;


}