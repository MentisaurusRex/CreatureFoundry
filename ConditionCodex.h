#pragma once
#include <vector>
#include "Condition.h"

class ConditionCodex
{
public:
	ConditionCodex(void);
	~ConditionCodex(void);

	static void init();
	static Condition get(std::string conditionName);

private:
	static std::vector<Condition> _conditionList;
};