#include "Level.h"
#include <vector>
#include <string>
#include <curses.h>
Level::Level(std::string name, std::vector<Scene *> scenes) 
{
	this->name = name;
	this->scenes = scenes;
}

void
Level::play(Player * main)
{

	initscr();
	printw("Hello, %s, and welcome to adventure!", main->getName().c_str());

	refresh();

	getch();
	endwin();

}
