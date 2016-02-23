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
	bool executeMove(Creature &user, Move move, Creature &opposed);
	void executeEffect(Creature &user, Effect effect, Creature &opposed);
	bool testCondition(Creature user, Effect effect, Creature opposed);
	bool endTurn();
	bool checkForFinish();
	bool noConditionsProhibit(Creature user);

	void applyDamage(Creature &user, Effect effect, Creature &opposed);
	void applyBuff(Creature &creatureToBuff, Effect effect);
	void applyDebuff(Creature &creatureToDebuff, Effect effect);
	void applyCondition(Effect effect, Creature &opposed);

	void doConditions(Creature &affected);

	int calculateSpeed(Creature creature);
	bool isDodged(Creature creature);
	bool doesHit(Move move);
	int calculateDamage(int power, Creature creature);
	double calculateBlocked(Creature creature);

};

