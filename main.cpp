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
	std::vector<Scene *> all = {r1, r2, r3, r4};
	std::vector<Scene *> r1_sn = {r2, r4};
	std::vector<Scene *> r2_sn = {r1, r3};
	std::vector<Scene *> r3_sn = {r2, r4};
	std::vector<Scene *> r4_sn = {r1, r3};
	item r1_i = {11, "Partridge"}; 
	std::vector<item> r1_in = {r1_i};
	item r2_i = {22, "Turtle Doves"}; 
	std::vector<item> r2_in = {r2_i};
	item r3_i = {33, "French Hen"}; 
	std::vector<item> r3_in = {r3_i};
	item r4_i = {44, "Calling Bird"}; 
	std::vector<item> r4_in = {r4_i};
	r1 = new Scene("One", 1, "The first room in the trial.", r1_in, r1_sn);
	r1 = new Scene("Two", 2, "The second room in the trial.", r2_in, r2_sn);
	r1 = new Scene("Three", 3, "The third room in the trial.", r3_in, r3_sn);
	r1 = new Scene("Four", 4, "The fourth room in the trial.", r4_in, r4_sn);
	Level * trial_level = new Level("Trial Level", all);



	trial_level->play(main);


	return 0;
}
