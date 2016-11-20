#include "Scene.h"
#include <vector>
#include <string>

Scene::Scene(std::string name, 
			int id,
                        std::string description, 
                        std::vector<item> items_nearby, 
                        std::vector<Scene *> scenes_nearby) 
{
	this->name = name;
	this->id = id;
	this->description = description;
	this->items_nearby = items_nearby;
	this->scenes_nearby = scenes_nearby;
}
