#include "MoveCodex.h"
#include "Condition.h"


MoveCodex::MoveCodex(void)
{
}


MoveCodex::~MoveCodex(void)
{
}

void MoveCodex::init(){

	Condition noCondition;
	noCondition._name = NONE;

	Condition bleedCondition;
	bleedCondition._name = BLEED;
	bleedCondition._turnsLeft = -1;

	MoveCondition noMoveCondition;
	noMoveCondition._type = NONE;

	MoveCondition percent30Condition;
	percent30Condition._type = CHANCE;
	percent30Condition._chance = 30;



	Move pinch = Move("Pinch", 0, 100);
	pinch.addEffect(20, DAMAGE, ENEMY, NONE, noCondition, noMoveCondition);
	_moveList.push_back(pinch);

	Move molt = Move("Molt", 1, 100);
	molt.addEffect(-1, DEBUFF, SELF, ARMOR, noCondition, noMoveCondition);
	molt.addEffect(1, BUFF, SELF, AGILITY, noCondition, noMoveCondition);
	_moveList.push_back(molt);

	Move snip = Move("Snip", 0, 100);
	snip.addEffect(10, DAMAGE, ENEMY, NONE, bleedCondition, noMoveCondition);
	_moveList.push_back(snip);

	Move froth = Move("Froth", 1, 100);
	froth.addEffect(-1, DEBUFF, ENEMY, ATTACK, noCondition, noMoveCondition);
	_moveList.push_back(froth);

	Move polishShell = Move("Polish Shell", 1, 100);
	polishShell.addEffect(2, BUFF, SELF, AGILITY, noCondition, noMoveCondition);
	_moveList.push_back(polishShell);

	Move shellWithdraw = Move("Shell Withdraw", 1, 100);
	shellWithdraw.addEffect(1, BUFF, SELF, ARMOR, noCondition, noMoveCondition);
	shellWithdraw.addEffect(-1, DEBUFF, SELF, AGILITY, noCondition, noMoveCondition);
	_moveList.push_back(shellWithdraw);

	Move ram = Move("Ram", 0, 100);
	ram.addEffect(20, DAMAGE, ENEMY, NONE, noCondition, noMoveCondition);
	_moveList.push_back(ram);

	Move gooSlide = Move("Goo Slide", 5, 100);
	gooSlide.addEffect(20, DAMAGE, ENEMY, NONE, noCondition, noMoveCondition);
	gooSlide.addEffect(-1, DEBUFF, ENEMY, AGILITY, noCondition, percent30Condition);
	gooSlide.addEffect(-1, DEBUFF, ENEMY, ARMOR, noCondition, percent30Condition);
	_moveList.push_back(gooSlide);


}

Move MoveCodex::getMove(int index){
	return _moveList[index];;
}
