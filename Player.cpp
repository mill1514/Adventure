#include "Player.h"

#include <string>

Player::Player(int age, std::string name) 
{

	this->age = age;
	this->name = name;

}

int 
Player::getAge() 
{
	return this->age;
}

std::string 
Player::getName() 
{
	return this->name;
}


