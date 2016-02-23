#pragma once
#include <string>

//status effects
#define BLEED "bleed"
#define SICKENED "sickened"

struct Condition{
	std::string _name;
	int _turnsLeft;
};