#pragma once
#include <string>

//status effects
#define BLEED "bleed"

struct Condition{
	std::string _name;
	int _turnsLeft;
};