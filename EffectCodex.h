#pragma once
#include <vector>
#include "Effect.h"

#define ACIDIC "acidic"
#define RANCIDVAPORS "rancid vapors"
#define WEAPONREGROWTH "weapon regrowth"
#define ARMORREGROWTH "armor regrowth"

class EffectCodex
{
public:
	EffectCodex(void);
	~EffectCodex(void);

	static void init();
	static Effect get(std::string effectName);

private:
	static std::vector<Effect> _effectList;
};