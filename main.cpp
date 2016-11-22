#include "Player.h"
#include "Scene.h"
#include "Level.h"
#include <stdio.h>

int main() {

	Player * main = new Player();
	main->setNameFun();
	
	Level * trial_level1 = new Level("trial.txt");

	trial_level1->play(main);

	return 0;
}
