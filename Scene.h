#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <vector>

using namespace std;

struct item {
	int id;
	string name;
};

class Scene
{


	private :

		int id;
		string name;
		string description;

	public :
		Scene(std::string name, 
			int id,
			string description, 
			vector<item> items_nearby, 
			vector<int> scenes_nearby);	
		vector<int> scenes_nearby; // Scenes you can go to immediately  
		vector<item> items_nearby; // Items in this scene
		string getName();
		string getDescription();
		int getID();
		
};

#endif
