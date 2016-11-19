
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
		int getAge();
		std::string getName();


};

#endif

