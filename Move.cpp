#include "Move.h"


Move::Move(std::string name){
	_name = name;
}

Move::Move(void){
}

Move::~Move(void){
}

void Move::addEffect(int modifier, std::string effectType, std::string whoIsAffected, std::string statAffected, std::string status){
	MoveEffect newEffect;
	newEffect._modifier = modifier;
	newEffect._effectType = effectType;
	newEffect._whoIsAffected = whoIsAffected;
	newEffect._statAffected = statAffected;
	newEffect._status = status;

	_moveEffects.push_back(newEffect);

}

std::string Move::getName(){
	return _name;
}

std::vector<MoveEffect> Move::getMoveEffects(){
	return _moveEffects;
}
