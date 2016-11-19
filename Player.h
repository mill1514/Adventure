
#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player 
{

	private :

		int age;
		std::string name;
	
	public :

		Player(int age, std::string name);
		void setAge(int age);
		int getAge();
		void setName(std::string name);
		std::string getName();
		std::string generateName();

};

#endif

