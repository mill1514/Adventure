

#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <vector>

struct item {
	int id;
	std::string name;
};

class Scene
{


	private :

		int id;
		std::vector<item> items_nearby; // Items in this scene
		std::vector<Scene *> scenes_nearby; // Scenes you can go to immediately  

	public :
		Scene(std::string name, 
			int id,
			std::string description, 
			std::vector<item> items_nearby, 
			std::vector<Scene *> scenes_nearby);	
		std::string name;
		std::string description;
		
};

#endif
