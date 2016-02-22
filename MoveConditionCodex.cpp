#pragma once
#include "MoveConditionCodex.h"
#include "Condition.h"
#include "Move.h"

std::vector<MoveCondition> MoveConditionCodex::_moveConditionList;

MoveConditionCodex::MoveConditionCodex(void){

}

MoveConditionCodex::~MoveConditionCodex(void){

}

void MoveConditionCodex::init(){
	MoveCondition noCondition;
	noCondition._name = NONE;
	_moveConditionList.push_back(noCondition);

	MoveCondition percent30Condition;
	percent30Condition._name = CHANCE30;
	percent30Condition._type = CHANCE;
	percent30Condition._chance = 30;
	_moveConditionList.push_back(percent30Condition);
}

MoveCondition MoveConditionCodex::get(std::string conditionName){

	for(int i = 0; i < _moveConditionList.size(); i++){
		if(_moveConditionList[i]._name == conditionName){
			return _moveConditionList[i];
		}
	}
}