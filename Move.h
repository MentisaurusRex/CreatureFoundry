#pragma once
#include <vector>
#include "Effect.h"

class Move
{
public:
	Move(std::string name, int priority, int accuracy);
	Move(void);
	~Move(void);

	void addEffect(int damage, std::string effectType, std::string whoIsAffected, std::string statAffected, Condition condition, MoveCondition moveCondition);
	int getPriority();
	int getAccuracy();

	std::string getName();
	std::vector<Effect> getEffects();

private:
	std::string _name;
	std::vector<Effect> _effectList;
	int _priority;
	int _accuracy;

};

