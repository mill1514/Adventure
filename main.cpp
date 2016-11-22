#include "Player.h"
#include "Scene.h"
#include "Level.h"
#include <stdio.h>

int main() {

	Player * main = new Player();
	main->setNameFun();

	// Trial level
	Scene * r1; Scene * r2;
	Scene * r3; Scene * r4;
	item r1_i = {11, "Partridge"}; 
	std::vector<item> r1_in = {r1_i};
	item r2_i = {22, "Turtle Doves"}; 
	std::vector<item> r2_in = {r2_i};
	item r3_i = {33, "French Hen"}; 
	std::vector<item> r3_in = {r3_i};
	item r4_i = {44, "Calling Bird"}; 
	std::vector<item> r4_in = {r4_i};
	std::vector<int> r1_sn = {-1,-1,3,1};
	std::vector<int> r2_sn = {-1,0,2,-1};
	std::vector<int> r3_sn = {1,3,-1,-1};
	std::vector<int> r4_sn = {0,-1,-1,2};
	r1 = new Scene("One", 0, "The first room in the trial. The second room lies WEST and the fourth room lies SOUTH.", r1_in, r1_sn);
	r2 = new Scene("Two", 1, "The second room in the trial. The first room lies EAST and the third room lies SOUTH.", r2_in, r2_sn);
	r3 = new Scene("Three", 2, "The third room in the trial. The second room lies NORTH and the fourth room lies EAST.", r3_in, r3_sn);
	r4 = new Scene("Four", 3, "The fourth room in the trial. The first room lies NORTH and the third room lies WEST.", r4_in, r4_sn);

	// Needs to be AFTER scenes are initialized	
	std::vector<Scene *> all = {r1, r2, r3, r4};

	Level * trial_level = new Level("Trial Level", all);

	trial_level->play(main);

	return 0;
}
