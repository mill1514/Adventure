

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
		std::string name;
		std::string description;

	public :
		Scene(std::string name, 
			int id,
			std::string description, 
			std::vector<item> items_nearby, 
			std::vector<int> scenes_nearby);	
		std::vector<int> scenes_nearby; // Scenes you can go to immediately  
		std::vector<item> items_nearby; // Items in this scene
		std::string getName();
		std::string getDescription();
		int getID();
		
};

#endif
