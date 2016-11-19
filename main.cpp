#include "Player.h"
#include <stdio.h>

int main() {

	Player * main = new Player(12, "Charles");

	printf("Main player's name: %s\n%s's age: %d\n", main->getName().c_str(), main->getName().c_str(), main->getAge());

	return 0;
}
