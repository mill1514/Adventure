#include "Level.h"
#include <vector>
#include <string>
#include <curses.h>
#include <sstream>
#include <iostream>

using namespace std;

Level::Level(string name, vector<Scene *> scenes) 
{
	this->name = name;
	this->scenes = scenes;
}

void
Level::play(Player * main)
{


	// -----------INTRO--------------
	string msg = main->getName() + "'s Adventure";
	initscr();
	
	// Get screen dims
	int row, col;
	getmaxyx(stdscr, row, col);
	
	mvprintw(row/2, (col - msg.length())/2, msg.c_str());
	refresh();
	getch();
	clear();
	
	// ----------Into the game!----------

	// c string to store commands
	char * response = new char[30];
	vector<string> sep_response;

	// This is the flag for a game over, dumbass
	int gameOver = 0;

	// The scene you start in is always scenes[0]
	Scene * currScene = this->scenes[0];

	// This loop runs once per typed command
	while (!gameOver) 
	{
		clear();
		getmaxyx(stdscr, row, col);	

		// In the top right, print the name of the room you're in
		mvprintw(0, 0, currScene->getName().c_str());

		// Print the description of the room you're in
		// near the bottom (4 rows up).
		mvprintw(row-4, 0, currScene->getDescription().c_str());
		refresh();
	
		// Collect a response at bottom of screen.
		move(row-1, 0);
		getstr(response);

		sep_response = separate(response, ' ');

		// Try to travel to a different room.
		if (sep_response[0] == "go") 
		{
			string r = sep_response[1];

			if ((r == "north" || r == "n") && (currScene->scenes_nearby[0] != -1)) 
			{
				currScene = this->scenes[currScene->scenes_nearby[0]];

			} else if ((r == "east" || r == "e") && (currScene->scenes_nearby[1] != -1)) 
			{
				currScene = this->scenes[currScene->scenes_nearby[1]];
			} else if ((r == "south" || r == "s") && (currScene->scenes_nearby[2] != -1)) 
			{
				currScene = this->scenes[currScene->scenes_nearby[2]];
			} else if ((r == "west" || r == "w") && (currScene->scenes_nearby[3] != -1)) 
			{
				currScene = this->scenes[currScene->scenes_nearby[3]];
			}

		// List all objects in this room.
		} else if (sep_response[0] == "look" || sep_response[0] == "inspect") 
		{
			string items = "Items here: ";
			for (int i = 0; i < currScene->items_nearby.size()-1; i++) 
			{
				items.append(currScene->items_nearby[i].name);
				items.append(", "); 
			}
			items.append(currScene->items_nearby[currScene->items_nearby.size()-1].name);
			items.append((3 * (col)) - items.length(), ' ');
			items.append("ENTER to continue...");

			mvprintw(row-4, 0, items.c_str());
			move(row-1, 0);
			getch();

		// Quit the game.
		} else if (sep_response[0] == "quit") 
		{
			clear();
			
			mvprintw(row-4, 0, "Are you sure? (y/n)");
			move(row-1, 0);
			getstr(response);
			sep_response = separate(response, ' ');
			if (sep_response[0] == "y" || sep_response[0] == "yes") 
			{
				clear();
				mvprintw(row-4, 0, "You quitter.");
				move(row-1, 0);
				getch();
				gameOver = 1;
			}
		}

		//gameOver = 1;	

	}


	endwin();

}


vector<string>
Level::separate (string target, char delim) 
{

	vector<string> ret;

	istringstream f(target);
	string s;

	while (getline(f, s, delim)) 
	{
		ret.push_back(s);
	}

	return ret;
} 
