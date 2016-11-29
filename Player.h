
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Scene.h"

using namespace std;

class Player 
{

	private :

		int age;
		string name;
		string generateName();

	public :
		Player();
		Player(int age, string name);
		void setAge(int age);
		int getAge();
		void setName(string name);
		string getName();
		void setNameFun();
		void addToInventory(item target);
		item inventory;

		// Not sure if should be in the player class. Doesn't need to be.
		int contains(string word, vector<char> check);

};

#endif

