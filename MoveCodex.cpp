#include "MoveCodex.h"


MoveCodex::MoveCodex(void)
{
}


MoveCodex::~MoveCodex(void)
{
}

void MoveCodex::init(){
	Move pinch = Move("Pinch");
	pinch.addEffect(20, DAMAGE, ENEMY, NONE, NONE);
	_moveList.push_back(pinch);

	Move molt = Move("Molt");
	molt.addEffect(-1, DEBUFF, SELF, ARMOR, NONE);
	molt.addEffect(1, BUFF, SELF, AGILITY, NONE);
	_moveList.push_back(molt);

	Move snip = Move("Snip");
	snip.addEffect(10, DAMAGE, ENEMY, NONE, BLEED);
	_moveList.push_back(snip);

	Move froth = Move("Froth");
	froth.addEffect(-1, DEBUFF, ENEMY, ATTACK, NONE);
	_moveList.push_back(froth);
}

Move MoveCodex::getMove(int index){
	return _moveList[index];;
}
