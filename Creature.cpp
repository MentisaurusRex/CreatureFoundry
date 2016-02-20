#include "Creature.h"


Creature::Creature(std::string name, int health, int attack, int armor, int agility, int energy, Armor naturalArmor, Weapon naturalWeapon)
{
	_name = name;
	_maxHealth = health;
	_currentHealth = health;
	_attack = attack;
	_armor = armor;
	_agility = agility;
	_energy = energy;
	_naturalArmor = naturalArmor;
	_naturalWeapon = naturalWeapon;

}

Creature::Creature(void)
{
}

Creature::~Creature(void)
{
}

void Creature::addMove(Move move){
	for(int i = 0; i < (sizeof(_moveSet)/sizeof(*_moveSet)); i++){
		if(_moveSet[i].getName().empty()){
			_moveSet[i] = move;
			break;
		}
	}
}

Move Creature::getMove(int index){
	return _moveSet[index];
}

std::string Creature::getName(){
	return _name;
}

int Creature::getMaxHealth(){
	return _maxHealth;
}

int Creature::getCurrentHealth(){
	return _currentHealth;
}

void Creature::setCurrentHealth(int newHealth){
	_currentHealth = newHealth;
}

int Creature::getAttack(){
	return _attack;
}

int Creature::getArmor(){
	return _armor;
}

int Creature::getAgility(){
	return _agility;
}

int Creature::getEnergy(){
	return _energy;
}

Armor Creature::getNaturalArmor(){
	return _naturalArmor;
}

Weapon Creature::getNaturalWeapon(){
	return _naturalWeapon;
}

void Creature::setBattleStats(){

	_battleStats.currentHealth = _currentHealth;
	_battleStats.healthMod = 0;
	_battleStats.attackMod = 0;
	_battleStats.armorMod = 0;
	_battleStats.agilityMod = 0;
	_battleStats.energyMod = 0;
}

BattleStats& Creature::getBattleStats(){
	return _battleStats;
}
