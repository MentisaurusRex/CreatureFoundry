#pragma once
#include <vector>
#include "Effect.h"

#define ACIDIC "acidic"

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