#pragma once
#include <string>
#include "Effect.h"

struct WeaponAbility{
	std::string _name;
	Effect _effect;

	int _priority;
	int _accuracy;
	int _critChance;
	double _critMultiplier;
};