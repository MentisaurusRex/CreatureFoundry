#pragma once
#include <vector>
#include "MoveEffect.h"
class Move
{
public:
	Move(std::string name);
	Move(void);
	~Move(void);

	void addEffect(int damage, std::string effectType, std::string whoIsAffected, std::string statAffected, std::string status);

	std::string getName();
	std::vector<MoveEffect> getMoveEffects();

private:
	std::string _name;
	std::vector<MoveEffect> _moveEffects;

};

