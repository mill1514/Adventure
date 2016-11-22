#include "Scene.h"
#include <vector>
#include <string>

Scene::Scene(std::string name, 
			int id,
                        std::string description, 
                        std::vector<item> items_nearby, 
                        std::vector<int> scenes_nearby) 
{
	this->name = name;
	this->id = id;
	this->description = description;
	this->items_nearby = items_nearby;
	this->scenes_nearby = scenes_nearby;
}

std::string
Scene::getName() {return this->name;}

std::string
Scene::getDescription() {return this->description;}

int
Scene::getID() {return this->id;}

