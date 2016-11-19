#include "Player.h"
#include <stdio.h>

int main() {

	Player * main = new Player(12, "Charles");


	// Pick a name!
	char * response = new char[10]; std::string temp_name;
	do { 
		temp_name = main->generateName();
		printf("Is %s a good name? (y/n)\n", temp_name.c_str());
		scanf("%s", response);
	}
	while (response[0] != 'y');

	printf("%s is an excellent name!\n", temp_name.c_str());
	main->setName(temp_name);


	return 0;
}
