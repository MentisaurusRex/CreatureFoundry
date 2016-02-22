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
	bleedCondition._turnsLeft = 4;

	MoveCondition noMoveCondition;
	noMoveCondition._type = NONE;





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
}

Move MoveCodex::getMove(int index){
	return _moveList[index];;
}
