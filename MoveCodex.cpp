#include "MoveCodex.h"


MoveCodex::MoveCodex(void)
{
}


MoveCodex::~MoveCodex(void)
{
}

void MoveCodex::init(){

	MoveCondition noCondition;
	noCondition._type = NONE;

	Move pinch = Move("Pinch", 0, 100);
	pinch.addEffect(20, DAMAGE, ENEMY, NONE, NONE, noCondition);
	_moveList.push_back(pinch);

	Move molt = Move("Molt", 1, 100);
	molt.addEffect(-1, DEBUFF, SELF, ARMOR, NONE, noCondition);
	molt.addEffect(1, BUFF, SELF, AGILITY, NONE, noCondition);
	_moveList.push_back(molt);

	Move snip = Move("Snip", 0, 100);
	snip.addEffect(10, DAMAGE, ENEMY, NONE, BLEED, noCondition);
	_moveList.push_back(snip);

	Move froth = Move("Froth", 1, 100);
	froth.addEffect(-1, DEBUFF, ENEMY, ATTACK, NONE, noCondition);
	_moveList.push_back(froth);
}

Move MoveCodex::getMove(int index){
	return _moveList[index];;
}
