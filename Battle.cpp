#include "Battle.h"
#include "EffectCodex.h"
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
		std::system("cls");
		Move enemyMove = enemyTurn();

		if(fight(playerMove, enemyMove)){
			break;
		}
		
		if(endTurn()){
			break;
		}
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
	srand((unsigned int)time(NULL));
	int selection = rand() % 4;

	return _enemyCreature.getMove(selection);
}

bool Battle::fight(Move playerMove, Move enemyMove){	

	if(playerMove.getPriority() > enemyMove.getPriority()){
		if (executeMove(_playerCreature, playerMove, _enemyCreature)) return true;
		if (executeMove(_enemyCreature, enemyMove, _playerCreature)) return true;
	}

	else if(playerMove.getPriority() < enemyMove.getPriority()){
		if (executeMove(_enemyCreature, enemyMove, _playerCreature)) return true;
		if (executeMove(_playerCreature, playerMove, _enemyCreature)) return true;
	}

	else{
		if(calculateSpeed(_playerCreature) > calculateSpeed(_enemyCreature)){
			if (executeMove(_playerCreature, playerMove, _enemyCreature)) return true;
			if (executeMove(_enemyCreature, enemyMove, _playerCreature)) return true;
		}
		else{
			if (executeMove(_enemyCreature, enemyMove, _playerCreature)) return true;
			if (executeMove(_playerCreature, playerMove, _enemyCreature)) return true;
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



bool Battle::executeMove(Creature &user, Move move, Creature &opposed){
	

	if(noConditionsProhibit(user)){
		if(doesHit(move) || opposed.hasCondition(GRAPPLED)){
			std::cout << user.getName() << " used: " << move.getName() << std::endl; 
			for(unsigned int i = 0; i < move.getEffects().size(); i++){
				Effect effect = move.getEffects()[i];
				executeEffect(user, effect, opposed);
			}
		}
	}
	std::cout << std::endl;
	return(checkForFinish());
}

bool Battle::noConditionsProhibit(Creature user){
	if(user.hasCondition(SICKENED)){
		if((rand() % 100) + 1 <= 40){
			std::cout << user.getName() << " is sick and cant act!" << std::endl;
			return false;
		}
	}
	return true;
}

void Battle::executeEffect(Creature &user, Effect effect, Creature &opposed){

	if(testCondition(user, effect, opposed)){

		if(effect._effectType == DAMAGE){
			if(effect._whoIsAffected == SELF){
				applyDamage(user, effect, user);
			}
			if(effect._whoIsAffected == ENEMY && (opposed.hasCondition(GRAPPLED) || !isDodged(opposed))){
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

bool Battle::testCondition(Creature user, Effect effect, Creature opposed){
	if(effect._moveCondition._type == NONE){
		return true;
	}	

	else if(effect._moveCondition._type == STAT_COMPARE){

		int userStat = user.getStat(effect._moveCondition._comparing);
		int opposedStat = opposed.getStat(effect._moveCondition._compareTo);

		if(effect._moveCondition._howToCompare == GREATER){
			return (userStat > opposedStat);
		}
		else if(effect._moveCondition._howToCompare == GREATER_EQUAL){
			return (userStat >= opposedStat);
		}
		else if(effect._moveCondition._howToCompare == LESSER){
			return (userStat < opposedStat);
		}
		else if(effect._moveCondition._howToCompare == LESSER_EQUAL){
			return (userStat <= opposedStat);
		}
	}

	else if(effect._moveCondition._type == CHANCE){
		int chance = (rand() % 100) + 1;

		return (chance <= effect._moveCondition._chance);

	}
	
	return false;
	
}

bool Battle::endTurn(){

	if(_playerCreature.getConditions().size() > 0){
		doConditions(_playerCreature);
		if(checkForFinish()){
			return true;
		}
	}

	if(_enemyCreature.getConditions().size() > 0){
		doConditions(_enemyCreature);
		if(checkForFinish()){
			return true;
		}
	}
	
	return false;
}

void Battle::applyDamage(Creature &user, Effect effect, Creature &opposed){
	int damage = calculateDamage(effect._modifier, user);
	double blocked = calculateBlocked(opposed);

	int critChance = user.getNaturalWeapon().getWeaponCritChance() + effect._critChance;
	if((rand() % 100) + 1 <= critChance){
		std::cout <<"Critical hit! " ;
		if(user.getNaturalWeapon().getWeaponCritMultiplier() != 0){
			damage = (int)(damage * user.getNaturalWeapon().getWeaponCritMultiplier());
		}
		else{
			damage = (int)(damage * 1.5);
		}
	}

	int potentialDamage = (int)(damage - (damage * blocked));

	int realDamage = (potentialDamage > 1) ? potentialDamage : 1;


	opposed.setCurrentHealth(opposed.getCurrentHealth() - realDamage);
	applyCondition(effect, opposed);

	std::cout <<"It caused " << realDamage << " damage!" << std::endl; 	

	if(user.getNaturalWeapon().getWeaponEffect()._name != NONE){
		executeEffect(user, user.getNaturalWeapon().getWeaponEffect(), opposed);
	}
}

//As of right now this is exactly the same as applyDebuff
void Battle::applyBuff(Creature &creatureToBuff, Effect effect){

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

	std::cout <<"It raised " << creatureToBuff.getName() << "'s " << effect._statAffected << " by " << effect._modifier << " stages!" << std::endl; 

}

//As of right now this is exactly the same as applyBuff
void Battle::applyDebuff(Creature &creatureToDebuff, Effect effect){

	bool worked = true;

	if(effect._statAffected == HEALTH){
		creatureToDebuff.getBattleStats().addToHealth(effect._modifier);
	}

	else if(effect._statAffected == ATTACK){
		if(creatureToDebuff.getNaturalWeapon().getWeaponAbilityName() == WEAPONREGROWTH){
			std::cout << creatureToDebuff.getName() << "'s regrowth prevented its attack from falling." << std::endl;
			worked = false;
		}
		else{
			creatureToDebuff.getBattleStats().addToAttack(effect._modifier);
		}
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

	if(worked){
		std::cout <<"It lowered " << creatureToDebuff.getName() << "'s " << effect._statAffected << " by " << effect._modifier * -1 << " stages!" << std::endl; 
	}
}

void Battle::applyCondition(Effect effect, Creature &opposed){
	if(effect._condition._name != NONE){
		opposed.addCondition(effect._condition);
	}
}

void Battle::doConditions(Creature &affected){
	std::vector<Condition> conditions = affected.getConditions();

	for(unsigned int i = 0; i < conditions.size(); i++){
		Condition condition = conditions[i];

		if(condition._name == BLEED){
			int damage = (int)(affected.getMaxHealth() * .1);
			affected.setCurrentHealth(affected.getCurrentHealth() - damage);
			std::cout << affected.getName() << " took " << damage << " bleed damage." << std::endl;
		}

		if(condition._name == SICKENED){
			if(affected.minusConditionTurn(SICKENED)){
				std::cout << affected.getName() << "'s sickness wore off!" << std::endl;
				affected.clearCondition(SICKENED);
			}
		}

		if(condition._name == GRAPPLED){
			if(affected.minusConditionTurn(GRAPPLED)){
				std::cout << affected.getName() << " broke out of the grapple!" << std::endl;
				affected.clearCondition(GRAPPLED);
			}
			else{
				std::cout << affected.getName() << " is grappled!" << std::endl;
			}
		}
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
	return (int)speed;
}

int Battle::calculateDamage(int power, Creature creature){
	double fullAttack = creature.getAttack() + creature.getNaturalWeapon().getWeaponDamage();
	double scaledAttack = (fullAttack * ((creature.getBattleStats().attackMod + 3.0) / 3.0));

	double bonus = scaledAttack * .0125;
	return (int)(power * bonus);
}

double Battle::calculateBlocked(Creature creature){
	double fullArmor = creature.getArmor() + creature.getNaturalArmor().getArmorValue();
	double scaledArmor = (fullArmor * ((creature.getBattleStats().armorMod + 3.0) / 3.0));

	return scaledArmor * .002;
}