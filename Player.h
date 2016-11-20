
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>





class Player 
{

	private :

		int age;
		std::string name;
		std::string generateName();

	public :
		Player();
		Player(int age, std::string name);
		void setAge(int age);
		int getAge();
		void setName(std::string name);
		std::string getName();
		void setNameFun();
				

		// Not sure if should be in the player class. Doesn't need to be.
		int contains(std::string word, std::vector<char> check);

};

#endif

