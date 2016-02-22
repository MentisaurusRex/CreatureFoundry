#pragma once
#include <vector>
#include "MoveCondition.h"

class MoveConditionCodex
{
public:
	MoveConditionCodex(void);
	~MoveConditionCodex(void);

	static void init();
	static MoveCondition get(std::string moveConditionName);

private:
	static std::vector<MoveCondition> _moveConditionList;
};