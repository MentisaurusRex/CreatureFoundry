#include "Move.h"


Move::Move(std::string name, int priority, int accuracy){
	_name = name;
	_priority = priority;
	_accuracy = accuracy;

}

Move::Move(void){
}

Move::~Move(void){
}

void Move::addEffect(int modifier, 
						std::string effectType, 
						std::string whoIsAffected, 
						std::string statAffected, 
						Condition condition, 
						MoveCondition moveCondition){
	Effect newEffect;
	newEffect._modifier = modifier;
	newEffect._effectType = effectType;
	newEffect._whoIsAffected = whoIsAffected;
	newEffect._statAffected = statAffected;
	newEffect._condition = condition;
	newEffect._moveCondition = moveCondition;

	_effectList.push_back(newEffect);

}

int Move::getPriority(){
	return _priority;
}

int Move::getAccuracy(){
	return _accuracy;
}

std::string Move::getName(){
	return _name;
}

std::vector<Effect> Move::getEffects(){
	return _effectList;
}
