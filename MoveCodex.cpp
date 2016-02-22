#include "MoveCodex.h"
#include "ConditionCodex.h"
#include "MoveConditionCodex.h"


MoveCodex::MoveCodex(void)
{
}


MoveCodex::~MoveCodex(void)
{
}

void MoveCodex::init(){
	
	Move pinch = Move("Pinch", 0, 100);
	pinch.addEffect(20, DAMAGE, ENEMY, NONE, ConditionCodex::get(NONE), MoveConditionCodex::get(NONE));
	_moveList.push_back(pinch);

	Move molt = Move("Molt", 1, 100);
	molt.addEffect(-1, DEBUFF, SELF, ARMOR, ConditionCodex::get(NONE), MoveConditionCodex::get(NONE));
	molt.addEffect(1, BUFF, SELF, AGILITY, ConditionCodex::get(NONE), MoveConditionCodex::get(NONE));
	_moveList.push_back(molt);

	Move snip = Move("Snip", 0, 100);
	snip.addEffect(10, DAMAGE, ENEMY, NONE, ConditionCodex::get(BLEED), MoveConditionCodex::get(NONE));
	_moveList.push_back(snip);

	Move froth = Move("Froth", 1, 100);
	froth.addEffect(-1, DEBUFF, ENEMY, ATTACK, ConditionCodex::get(NONE), MoveConditionCodex::get(NONE));
	_moveList.push_back(froth);

	Move polishShell = Move("Polish Shell", 1, 100);
	polishShell.addEffect(2, BUFF, SELF, AGILITY, ConditionCodex::get(NONE), MoveConditionCodex::get(NONE));
	_moveList.push_back(polishShell);

	Move shellWithdraw = Move("Shell Withdraw", 1, 100);
	shellWithdraw.addEffect(1, BUFF, SELF, ARMOR, ConditionCodex::get(NONE), MoveConditionCodex::get(NONE));
	shellWithdraw.addEffect(-1, DEBUFF, SELF, AGILITY, ConditionCodex::get(NONE), MoveConditionCodex::get(NONE));
	_moveList.push_back(shellWithdraw);

	Move ram = Move("Ram", 0, 100);
	ram.addEffect(30, DAMAGE, ENEMY, NONE, ConditionCodex::get(NONE), MoveConditionCodex::get(NONE));
	_moveList.push_back(ram);

	Move gooSlide = Move("Goo Slide", 5, 100);
	gooSlide.addEffect(20, DAMAGE, ENEMY, NONE, ConditionCodex::get(NONE), MoveConditionCodex::get(NONE));
	gooSlide.addEffect(-1, DEBUFF, ENEMY, AGILITY, ConditionCodex::get(NONE), MoveConditionCodex::get(CHANCE30));
	gooSlide.addEffect(-1, DEBUFF, ENEMY, ARMOR, ConditionCodex::get(NONE), MoveConditionCodex::get(CHANCE30));
	_moveList.push_back(gooSlide);


}

Move MoveCodex::getMove(int index){
	return _moveList[index];;
}
