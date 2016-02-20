#pragma once
#include <string>

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

//status effects
#define BLEED "bleed"


struct MoveEffect{
	int _modifier;
	std::string _effectType;
	std::string _whoIsAffected;
	std::string _statAffected;
	std::string _status;
};