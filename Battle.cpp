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


void Battle::startBattle(){
	int result = 0;

	while(result == 0){
		
		startTurn();
		Move playerMove = playerTurn();
		Move enemyMove = enemyTurn();

		if(fight(playerMove, enemyMove)){
			break;
		}
		
		endTurn(result);
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

	return _enemyCreature.getMove(selection);
}

bool Battle::fight(Move playerMove, Move enemyMove){	

	if(playerMove.getPriority() > enemyMove.getAccuracy()){
		if (execute(_playerCreature, playerMove, _enemyCreature)) return true;
		if (execute(_enemyCreature, enemyMove, _playerCreature)) return true;
	}

	else if(playerMove.getPriority() < enemyMove.getAccuracy()){
		if (execute(_enemyCreature, enemyMove, _playerCreature)) return true;
		if (execute(_playerCreature, playerMove, _enemyCreature)) return true;
	}

	else{
		if(calculateSpeed(_playerCreature) > calculateSpeed(_playerCreature)){
			if (execute(_playerCreature, playerMove, _enemyCreature)) return true;
			if (execute(_enemyCreature, enemyMove, _playerCreature)) return true;
		}
		else{
			if (execute(_enemyCreature, enemyMove, _playerCreature)) return true;
			if (execute(_playerCreature, playerMove, _enemyCreature)) return true;
		}
	}
	return false;
}

bool Battle::checkForFinish(){
	if(_playerCreature.getCurrentHealth() <= 0){
		std::cout << "You lose!" << std::endl;
		return true;
	}
	else if(_enemyCreature.getCurrentHealth() <= 0){
		std::cout << "You win!" << std::endl;
		return true;
	}
	return false;
}



bool Battle::execute(Creature &user, Move move, Creature &opposed){

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << user.getName() << " used: " << move.getName() << std::endl; 

	if(!isDodged(opposed) && doesHit(move)){
		for(int i = 0; i < move.getMoveEffects().size(); i++){
			MoveEffect effect = move.getMoveEffects()[i];

			if(testCondition(user, effect, opposed)){

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
	}
	return(checkForFinish());
}

bool Battle::testCondition(Creature user, MoveEffect effect, Creature opposed){
	if(effect._condition._type == NONE){
		return true;
	}	

	else if(effect._condition._type == STAT_COMPARE){

		int userStat = user.getStat(effect._condition._comparing);
		int opposedStat = opposed.getStat(effect._condition._compareTo);

		if(effect._condition._howToCompare == GREATER){
			return (userStat > opposedStat);
		}
		else if(effect._condition._howToCompare == GREATER_EQUAL){
			return (userStat >= opposedStat);
		}
		else if(effect._condition._howToCompare == LESSER){
			return (userStat < opposedStat);
		}
		else if(effect._condition._howToCompare == LESSER_EQUAL){
			return (userStat <= opposedStat);
		}
	}

	else if(effect._condition._type == CHANCE){
		int chance = (rand() % 100) + 1;

		return (chance <= effect._condition._chance);

	}
	
	return false;
	
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
	int damage = calculateDamage(effect._modifier, user);
	double blocked = calculateBlocked(opposed);

	int realDamage = damage - (damage * blocked);
	opposed.setCurrentHealth(opposed.getCurrentHealth() - realDamage);

	std::cout <<"It caused: " << realDamage << " damage!" << std::endl; 	
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

bool Battle::isDodged(Creature creature){

	int dodgeChance = rand() % 100 + 1;

	double agility = creature.getAgility() + (creature.getAgility() * (creature.getBattleStats().agilityMod * .10));
	double dodge = (.97 * agility)/(1 + (.0273 * agility));

	if(dodgeChance <= dodge){
		std::cout <<"Dodged!" << std::endl; 
		return true;
	}
	else{
		return false;
	}
}

bool Battle::doesHit(Move move){
	int hitChance = rand() % 100 + 1;
	if(hitChance > move.getAccuracy()){
		std::cout << "The attack missed" << std::endl;
		return false;
	}
	else{
		return true;
	}
}

int Battle::calculateSpeed(Creature creature){
	double speed = creature.getAgility() + (creature.getAgility() * (creature.getBattleStats().agilityMod * .10));
	return speed;

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