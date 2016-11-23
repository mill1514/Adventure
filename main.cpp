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
		string filename = argv[1];
		filename += ".lvl";
		lvl = new Level(filename);
	} 
	else 
	{
		lvl = new Level("trial.lvl");
	}

	lvl->play(main);

	return 0;
}
