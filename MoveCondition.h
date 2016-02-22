#pragma once
#include <string>

#define STAT_COMPARE "stat compare"
#define CHANCE "chance"

#define LESSER "<"
#define LESSER_EQUAL "<="
#define GREATER ">"
#define GREATER_EQUAL ">="

//names
#define CHANCE30 "30% chance"


struct MoveCondition{
	std::string _name;
	std::string _type;
	std::string _comparing;
	std::string _howToCompare;
	std::string _compareTo;
	double _chance;
};