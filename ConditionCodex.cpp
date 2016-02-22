#pragma once
#include "ConditionCodex.h"
#include "Condition.h"
#include "Move.h"

std::vector<Condition> ConditionCodex::_conditionList;

ConditionCodex::ConditionCodex(void){

}

ConditionCodex::~ConditionCodex(void){

}

void ConditionCodex::init(){
	Condition noCondition;
	noCondition._name = NONE;
	_conditionList.push_back(noCondition);

	Condition bleedCondition;
	bleedCondition._name = BLEED;
	bleedCondition._turnsLeft = -1;

	_conditionList.push_back(bleedCondition);
}

Condition ConditionCodex::get(std::string conditionName){

	for(int i = 0; i < _conditionList.size(); i++){
		if(_conditionList[i]._name == conditionName){
			return _conditionList[i];
		}
	}

}