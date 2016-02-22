#pragma once
#include <vector>
#include "MoveEffect.h"
class Move
{
public:
	Move(std::string name, int priority, int accuracy);
	Move(void);
	~Move(void);

	void addEffect(int damage, std::string effectType, std::string whoIsAffected, std::string statAffected, std::string status, MoveCondition condition);
	int getPriority();
	int getAccuracy();

	std::string getName();
	std::vector<MoveEffect> getMoveEffects();

private:
	std::string _name;
	std::vector<MoveEffect> _moveEffects;
	int _priority;
	int _accuracy;

};

