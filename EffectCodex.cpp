#pragma once
#include "EffectCodex.h"
#include "ConditionCodex.h"
#include "MoveConditionCodex.h"

std::vector<Effect> EffectCodex::_effectList;

EffectCodex::EffectCodex(void){

}

EffectCodex::~EffectCodex(void){

}

void EffectCodex::init(){
	//NO EFFECT
	Effect noEffect;
	noEffect._name = NONE;
	_effectList.push_back(noEffect);

	//ACIDIC
	Effect acidic;
	acidic._name = ACIDIC;
	acidic._modifier = -1;
	acidic._effectType = DEBUFF;
	acidic._whoIsAffected = ENEMY;
	acidic._statAffected = ARMOR;
	acidic._condition = ConditionCodex::get(NONE);
	acidic._moveCondition = MoveConditionCodex::get(CHANCE30);
	_effectList.push_back(acidic);
}

Effect EffectCodex::get(std::string effectName){

	for(int i = 0; i < _effectList.size(); i++){
		if(_effectList[i]._name == effectName){
			return _effectList[i];
		}
	}
}