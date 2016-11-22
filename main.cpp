#include "Player.h"
#include "Scene.h"
#include "Level.h"
#include <stdio.h>

int main(int argc, char* argv[]) {

	Player * main = new Player();
	main->setNameFun();
	
	Level * lvl;

	if (argc == 2) 
	{
		lvl = new Level(argv[1]);
	} 
	else 
	{
		lvl = new Level("trial.txt");
	}

	lvl->play(main);

	return 0;
}
