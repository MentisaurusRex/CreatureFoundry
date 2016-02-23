#pragma once
#include <string>
#include "MoveCondition.h"
#include "Condition.h"

//default for not used
#define NONE ""

//effect types
#define DAMAGE "damage"
#define BUFF "buff"
#define DEBUFF "debuff"

//who it effects
#define ENEMY "enemy"
#define SELF "self"

//stat
#define HEALTH "health"
#define ATTACK "attack"
#define ARMOR "armor"
#define AGILITY "agility"
#define ENERGY "energy"


struct Effect{
	std::string _name;
	int _modifier;
	std::string _effectType;
	std::string _whoIsAffected;
	std::string _statAffected;
	Condition _condition;
	MoveCondition _moveCondition;
	int _critChance;
	double critMultiplier;
};