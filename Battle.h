#pragma once
#include <vector>
#include "Creature.h"

class Battle
{
public:
	Battle(void);
	~Battle(void);

	void init(Creature &playerCreature, Creature &enemyCreature);
	void startBattle();
	Move playerTurn();
	Move enemyTurn();

private:
	Creature _playerCreature;
	Creature _enemyCreature;

	int startTurn();
	bool fight(Move playerMove, Move enemyMove);
	bool execute(Creature &user, Move move, Creature &opposed);
	bool testCondition(Creature user, MoveEffect effect, Creature opposed);
	int endTurn(int result);
	bool checkForFinish();

	void applyDamage(Creature &user, MoveEffect effect, Creature &opposed);
	void applyBuff(Creature &creatureToBuff, MoveEffect effect);
	void applyDebuff(Creature &creatureToDebuff, MoveEffect effect);

	int calculateSpeed(Creature creature);
	bool isDodged(Creature creature);
	bool doesHit(Move move);
	int calculateDamage(int power, Creature creature);
	double calculateBlocked(Creature creature);

};

