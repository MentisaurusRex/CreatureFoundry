#include "Battle.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

Battle::Battle(void){

}

Battle::~Battle(void){

}

void Battle::init(Creature &playerCreature, Creature &enemyCreature){
	_playerCreature = playerCreature;
	_playerCreature.setBattleStats();

	_enemyCreature = enemyCreature;
	_enemyCreature.setBattleStats();
}


bool Battle::startBattle(){
	int result = 0;

	while(result == 0){
		
		startTurn();
		Move playerMove = playerTurn();
		Move enemyMove = enemyTurn();

		result = fight(playerMove, enemyMove);
		
		endTurn(result);
	}

	if(result == 1){
		return true;
	}
	else{
		return false;
	}
}

int Battle::startTurn(){
	return 0;
}

Move Battle::playerTurn(){
	int selection = -1;

	std::cout << "Enemy Health: " << _enemyCreature.getCurrentHealth() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Health: " << _playerCreature.getCurrentHealth() << std::endl;
	std::cout << "Moves: " << std::endl;

	for(int i = 0; i < 4; i++){
		std::cout << i << ": " << _playerCreature.getMove(i).getName() << std::endl;
	}

	std::cin >> selection;

	return _playerCreature.getMove(selection);
}

Move Battle::enemyTurn(){
	srand(time(NULL));
	int selection = rand() % 4;

	return _enemyCreature.getMove(1);
}

int Battle::fight(Move playerMove, Move enemyMove){	

	if(calculateSpeed(_enemyCreature) > calculateSpeed(_playerCreature)){
		execute(_enemyCreature, enemyMove, _playerCreature);
		execute(_playerCreature, playerMove, _enemyCreature);
	}
	else{
		execute(_playerCreature, playerMove, _enemyCreature);
		execute(_enemyCreature, enemyMove, _playerCreature);
	}


	if(_playerCreature.getCurrentHealth() <= 0){
		return -1;
	}
	if(_enemyCreature.getCurrentHealth() <= 0){
		return 1;
	}
	else{
		return 0;
	}
}



void Battle::execute(Creature &user, Move move, Creature &opposed){

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << user.getName() << " used: " << move.getName() << std::endl; 

	for(int i = 0; i < move.getMoveEffects().size(); i++){
		MoveEffect effect = move.getMoveEffects()[i];

		if(effect._effectType == DAMAGE){
			if(effect._whoIsAffected == SELF){
				applyDamage(user, effect, user);
			}
			if(effect._whoIsAffected == ENEMY){
				applyDamage(user, effect, opposed);
			}
		}
		else if(effect._effectType == BUFF){
			if(effect._whoIsAffected == SELF){
				applyBuff(user, effect);
			}
			if(effect._whoIsAffected == ENEMY){
				applyBuff(opposed, effect);
			}
		}

		else if(effect._effectType == DEBUFF){
			if(effect._whoIsAffected == SELF){
				applyDebuff(user, effect);
			}
			if(effect._whoIsAffected == ENEMY){
				applyDebuff(opposed, effect);
			}
		}
	}
}

int Battle::endTurn(int result){

	std::cout << std::endl;	
	if(result == 1){
		std::cout << "You win" << std::endl;
	}
	if(result == -1){
		std::cout << "You lose" << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	return 0;

}

void Battle::applyDamage(Creature &user, MoveEffect effect, Creature &opposed){
	int dodgeNumber = rand() % 100;
	if(dodgeNumber > calculateDodge(opposed)){
		int damage = calculateDamage(effect._modifier, user);
		double blocked = calculateBlocked(opposed);

		int realDamage = damage - (damage * blocked);
		opposed.setCurrentHealth(opposed.getCurrentHealth() - realDamage);

		std::cout <<"It caused: " << realDamage << " damage!" << std::endl; 
	}
	else{
		std::cout <<"Dodged!" << std::endl; 
	}
}

//As of right now this is exactly the same as applyDebuff
void Battle::applyBuff(Creature &creatureToBuff, MoveEffect effect){

	if(effect._statAffected == HEALTH){
		creatureToBuff.getBattleStats().addToHealth(effect._modifier);
	}

	else if(effect._statAffected == ATTACK){
		creatureToBuff.getBattleStats().addToAttack(effect._modifier);
	}

	else if(effect._statAffected == ARMOR){
		creatureToBuff.getBattleStats().addToArmor(effect._modifier);
	}

	else if(effect._statAffected == AGILITY){
		creatureToBuff.getBattleStats().addToAgility(effect._modifier);
	}

	else if(effect._statAffected == ENERGY){
		creatureToBuff.getBattleStats().addToEnergy(effect._modifier);
	}
}

//As of right now this is exactly the same as applyBuff
void Battle::applyDebuff(Creature &creatureToDebuff, MoveEffect effect){
	if(effect._statAffected == HEALTH){
		creatureToDebuff.getBattleStats().addToHealth(effect._modifier);
	}

	else if(effect._statAffected == ATTACK){
		creatureToDebuff.getBattleStats().addToAttack(effect._modifier);
	}

	else if(effect._statAffected == ARMOR){
		creatureToDebuff.getBattleStats().addToArmor(effect._modifier);
	}

	else if(effect._statAffected == AGILITY){
		creatureToDebuff.getBattleStats().addToAgility(effect._modifier);
	}

	else if(effect._statAffected == ENERGY){
		creatureToDebuff.getBattleStats().addToEnergy(effect._modifier);
	}
}

int Battle::calculateSpeed(Creature creature){
	double speed = creature.getAgility() + (creature.getAgility() * (creature.getBattleStats().agilityMod * .10));
	return speed;

}

int Battle::calculateDodge(Creature creature){
	double agility = creature.getAgility() + (creature.getAgility() * (creature.getBattleStats().agilityMod * .10));
	double dodge = (.97 * agility)/(1 + (.0273 * agility));
	return dodge;
}

int Battle::calculateDamage(int power, Creature creature){
	double fullAttack = creature.getAttack() + creature.getNaturalWeapon().getWeaponDamage();
	double scaledAttack = fullAttack + (fullAttack * (creature.getBattleStats().attackMod * .10));

	double bonus = scaledAttack * .0125;
	return power * bonus;
}

double Battle::calculateBlocked(Creature creature){
	double fullArmor = creature.getArmor() + creature.getNaturalArmor().getArmorValue();
	double scaledArmor = fullArmor + (fullArmor * (creature.getBattleStats().armorMod * .10));

	return scaledArmor * .002;
}