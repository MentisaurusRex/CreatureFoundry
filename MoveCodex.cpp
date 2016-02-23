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
	
	//0
	Move pinch = Move("Pinch", 0, 100);
	pinch.addEffect(20, DAMAGE, ENEMY, NONE, ConditionCodex::get(NONE), MoveConditionCodex::get(NONE), 0);
	_moveList.push_back(pinch);

	//1
	Move molt = Move("Molt", 1, 100);
	molt.addEffect(-1, DEBUFF, SELF, ARMOR, ConditionCodex::get(NONE), MoveConditionCodex::get(NONE), 0);
	molt.addEffect(1, BUFF, SELF, AGILITY, ConditionCodex::get(NONE), MoveConditionCodex::get(NONE), 0);
	_moveList.push_back(molt);

	//2
	Move snip = Move("Snip", 0, 100);
	snip.addEffect(10, DAMAGE, ENEMY, NONE, ConditionCodex::get(BLEED), MoveConditionCodex::get(NONE), 0);
	_moveList.push_back(snip);

	//3
	Move froth = Move("Froth", 1, 100);
	froth.addEffect(-1, DEBUFF, ENEMY, ATTACK, ConditionCodex::get(NONE), MoveConditionCodex::get(NONE), 0);
	_moveList.push_back(froth);

	//4
	Move polishShell = Move("Polish Shell", 1, 100);
	polishShell.addEffect(2, BUFF, SELF, AGILITY, ConditionCodex::get(NONE), MoveConditionCodex::get(NONE), 0);
	_moveList.push_back(polishShell);

	//5
	Move shellWithdraw = Move("Shell Withdraw", 1, 100);
	shellWithdraw.addEffect(1, BUFF, SELF, ARMOR, ConditionCodex::get(NONE), MoveConditionCodex::get(NONE), 0);
	shellWithdraw.addEffect(-1, DEBUFF, SELF, AGILITY, ConditionCodex::get(NONE), MoveConditionCodex::get(NONE), 0);
	_moveList.push_back(shellWithdraw);

	//6
	Move ram = Move("Ram", 0, 100);
	ram.addEffect(30, DAMAGE, ENEMY, NONE, ConditionCodex::get(NONE), MoveConditionCodex::get(NONE), 0);
	_moveList.push_back(ram);

	//7
	Move gooSlide = Move("Goo Slide", 5, 100);
	gooSlide.addEffect(20, DAMAGE, ENEMY, NONE, ConditionCodex::get(NONE), MoveConditionCodex::get(NONE), 0);
	gooSlide.addEffect(-1, DEBUFF, ENEMY, AGILITY, ConditionCodex::get(NONE), MoveConditionCodex::get(CHANCE30), 0);
	gooSlide.addEffect(-1, DEBUFF, ENEMY, ARMOR, ConditionCodex::get(NONE), MoveConditionCodex::get(CHANCE30), 0);
	_moveList.push_back(gooSlide);

	//8
	Move peck = Move("Peck", 0, 100);
	peck.addEffect(30, DAMAGE, ENEMY, NONE, ConditionCodex::get(NONE), MoveConditionCodex::get(NONE), 0);
	_moveList.push_back(peck);

	//9
	Move quickDive = Move("Quick Dive", 5, 100);
	quickDive.addEffect(20, DAMAGE, ENEMY, NONE, ConditionCodex::get(NONE), MoveConditionCodex::get(NONE), 0);
	_moveList.push_back(quickDive);

	//10
	Move puffUp = Move("Puff Up", 1, 100);
	puffUp.addEffect(-1, DEBUFF, ENEMY, ATTACK, ConditionCodex::get(NONE), MoveConditionCodex::get(NONE), 0);
	_moveList.push_back(puffUp);

	//11
	Move sharpen = Move("Sharpen", 1, 100);
	sharpen.addEffect(1, BUFF, SELF, ATTACK, ConditionCodex::get(NONE), MoveConditionCodex::get(NONE), 0);
	_moveList.push_back(sharpen);

	//12
	Move bite = Move("Bite", 0, 100);
	bite.addEffect(30, DAMAGE, ENEMY, NONE, ConditionCodex::get(NONE), MoveConditionCodex::get(NONE), 0);
	_moveList.push_back(bite);

	//13
	Move thrash = Move("Thrash", 0, 90);
	thrash.addEffect(40, DAMAGE, ENEMY, NONE, ConditionCodex::get(NONE), MoveConditionCodex::get(NONE), 0);
	thrash.addEffect(20, DAMAGE, SELF, NONE, ConditionCodex::get(NONE), MoveConditionCodex::get(NONE), 0);
	_moveList.push_back(thrash);

	//14
	Move digIn = Move("Dig In", 1, 100);
	digIn.addEffect(1, BUFF, SELF, ARMOR, ConditionCodex::get(NONE), MoveConditionCodex::get(NONE), 0);
	digIn.addEffect(-1, DEBUFF, SELF, AGILITY, ConditionCodex::get(NONE), MoveConditionCodex::get(NONE), 0);
	_moveList.push_back(digIn);

	//15
	Move sprout = Move("Sprout", 1, 100);
	sprout.addEffect(1, BUFF, SELF, ATTACK, ConditionCodex::get(NONE), MoveConditionCodex::get(NONE), 0);
	sprout.addEffect(-1, DEBUFF, ENEMY, AGILITY, ConditionCodex::get(NONE), MoveConditionCodex::get(NONE), 0);
	_moveList.push_back(sprout);

	//16
	Move strongOdor = Move("Strong Odor", 0, 100);
	strongOdor.addEffect(20, DAMAGE, ENEMY, NONE, ConditionCodex::get(SICKENED), MoveConditionCodex::get(NONE), 0);
	_moveList.push_back(strongOdor);
	
}

Move MoveCodex::getMove(int index){
	return _moveList[index];;
}
