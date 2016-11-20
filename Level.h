#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>
#include "Player.h"
#include "Scene.h"
class Level
{
	private:

		std::vector<Scene *> scenes;

	public:
		Level(std::string name, std::vector<Scene *> scenes);	
		void play(Player * main);
		std::string name;

};


#endif
