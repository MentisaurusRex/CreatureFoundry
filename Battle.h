#pragma once
#include <vector>
#include "Creature.h"

class Battle
{
public:
	Battle(void);
	~Battle(void);

	void init(Creature &playerCreature, Creature &enemyCreature);
	bool startBattle();
	Move playerTurn();
	Move enemyTurn();

private:
	Creature _playerCreature;
	Creature _enemyCreature;

	int startTurn();
	int fight(Move playerMove, Move enemyMove);
	void execute(Creature &user, Move move, Creature &opposed);
	int endTurn(int result);

	void applyDamage(Creature &user, MoveEffect effect, Creature &opposed);
	void applyBuff(Creature &creatureToBuff, MoveEffect effect);
	void applyDebuff(Creature &creatureToDebuff, MoveEffect effect);

	int calculateSpeed(Creature creature);
	int calculateDodge(Creature creature);
	int calculateDamage(int power, Creature creature);
	double calculateBlocked(Creature creature);
};

