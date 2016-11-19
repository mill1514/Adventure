#include "Player.h"
#include <vector>
#include <string>
#include <time.h>
#include <algorithm>

Player::Player() 
{
	this->age = 0;
	this->name = "Nobody";
}

Player::Player(int age, std::string name) 
{

	this->age = age;
	this->name = name;

}

void
Player::setAge(int age) {this->age = age;}

int 
Player::getAge() {return this->age;}

void 
Player::setName(std::string name) {this->name = name;}

std::string 
Player::getName() {return this->name;}


// Generates a name of unspecified length
std::string
Player::generateName() 
{
	// In order to gen the names, 
	// english scrabble distrobution
	std::vector<char> cons {'b','b','b',
			'c','c','c',
			'd','d','d','d',
			'f','f',
			'g','g','g',
			'h','h','j','k','k',
			'l','l','l','l',
			'm','m','m',
			'n','n','n','n','n','n',
			'p','p','p',
			'q',
			'r','r','r','r','r','r',
			's','s','s','s',
			't','t','t','t','t','t',
			'v','v','w','w','x','y','y','z'};
	std::vector<char> vows {'a','e','i','o','u'};

	// GEN THE NAMES!
	std::string ret;
	while( ((ret.length() < 3) || (rand() % 5 != 0)) || (!contains(ret, vows))) 
	{
		if (rand() % 3 == 0) {
			ret += vows[rand() % vows.size()];
		} else {
			ret += cons[rand() % cons.size()];
		}
	}

	return ret;

}

// Returns 1 if the string word has any letters that are in check.
// Otherwise, returns 0.
int Player::contains(std::string word, std::vector<char> check) 
{
	for (int i = 0; i < word.length(); i++) 
	{
		if (std::find(check.begin(), check.end(), word[i]) != check.end()) 
		{ return 1; }
	}
	return 0;
}

