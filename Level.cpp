#include "Level.h"
#include <vector>
#include <string>

Level::Level(std::string name, std::vector<Scene *> scenes) 
{
	this->name = name;
	this->scenes = scenes;
}

void
Level::play(Player * main)
{

	printf("%s is playing %s\n", main->getName().c_str(), this->name.c_str());
	// This is kinda a big function
}
