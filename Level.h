#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>
#include "Player.h"
#include "Scene.h"

using namespace std;

class Level
{
	private:


	public:
		vector<Scene *> scenes;
		Level(string name, vector<Scene *> scenes);	
		void play(Player * main);
		string name;
		vector<string> separate(string target, char delim);

};


#endif
