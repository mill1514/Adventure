#include "Level.h"
#include "Scene.h"
#include <vector>
#include <string>
#include <curses.h>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

Level::Level(string name, vector<Scene *> scenes) 
{
	this->name = name;
	this->scenes = scenes;
}


// Loads a level from text file. Just beautiful.
// 
// Format:
//
// <name of level>
// <scene1_name>,<scene1_id>,<scene1_desc>
// <scene1_item1_id>,<scene1_item1_name>;<scene1_item1_id>,<scene1_item1_name>; ect..
// <scene1_scenes_nearby>
// <scene2_name>,<scene2_id>,<scene2_desc>
// <scene2_item1_id>,<scene2_item1_name>;<scene2_item1_id>,<scene2_item1_name>; ect..
// <scene2_scenes_nearby>
// ect..
//
//
// May change later.
//
//
Level::Level(string filename) 
{
	ifstream fin;
	fin.open(filename);

	string name;
	getline(fin, name);
	
	string line;
	vector<string> nameIdDesc;
	vector<string> group;
	vector<string> single_item;

	vector<Scene *> scenes;
	while ( getline(fin, line) )
	{
		vector<item> items_nearby;
		vector<int> scenes_nearby;

		// Split first line of scene into 3 pieces
		nameIdDesc = this->separate(line, ',');

		// Get items_nearby
		getline(fin, line);
		group = this->separate(line, ';');
		for (int i = 0; i < group.size(); i++) 
		{
			// Sep item by commas, make item, push item
			single_item = this->separate(group[i], ',');
			item done = {atoi(single_item[0].c_str()), single_item[1]};
			items_nearby.push_back(done);
		}

		// Get scenes_nearby
		getline(fin, line);
		group = this->separate(line, ',');
		for (int i = 0; i < 4; i++) 
		{
			// Convert string to int and push to scenes_nearby
			scenes_nearby.push_back(atoi(group[i].c_str()));
		}
	
		Scene * temp_scene = new Scene(nameIdDesc[0],
						atoi(nameIdDesc[1].c_str()),
						nameIdDesc[2],
						items_nearby,
						scenes_nearby);
		
		scenes.push_back(temp_scene);

	}

	this->scenes = scenes;
	this->name = name;

	fin.close();
}


// Plays a level with a given player.
void
Level::play(Player * main)
{


	// -----------INTRO--------------
	string msg1 = main->getName() + "'s Adventure:";
	string msg2 = this->name;
	initscr();
	
	// Get screen dims
	int row, col;
	getmaxyx(stdscr, row, col);
	
	mvprintw(row/2, (col - msg1.length())/2, msg1.c_str());
	mvprintw(row/2+1, (col - msg2.length())/2, msg2.c_str());
	move(row-1, 0);
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


		// Print a compass out 
		// that also shows your current movement options.
		if (currScene->scenes_nearby[0] != -1) {mvprintw((row/2)-2, (col/2), "|");} // North
		if (currScene->scenes_nearby[1] != -1) {mvprintw((row/2), (col/2)+2, "--");} // East
		mvprintw(row/2, col/2, "x");
		if (currScene->scenes_nearby[2] != -1) {mvprintw((row/2)+2, (col/2), "|");} // South
		if (currScene->scenes_nearby[3] != -1) {mvprintw((row/2), (col/2)-3, "--");} // West

		// Print your inventory (8 rows up);
		string invStatus = "Inv: ";
		if (main->inventory.id != -1) {invStatus.append(main->inventory.name);}
		mvprintw(row-8, 0, invStatus.c_str());

		// Print the name of the room you're in
		// (Top left)
		string location = "Location: "; location.append(currScene->getName());
		mvprintw(0, 0, location.c_str());

		// Print the description of the room you're in
		// near the bottom (4 rows up).
		mvprintw(row-4, 0, currScene->getDescription().c_str());
		refresh();
	
		// Collect a response at bottom of screen.
		move(row-1, 0);
		do {
			getstr(response);
			sep_response = separate(response, ' ');
		} while (sep_response.size() == 0);

		// Try to travel to a different room.
		if (sep_response[0] == "go" && sep_response.size() > 1) 
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
			// Weird structure to correctly use commas
			string items = "Items here: ";
			for (int i = 0; i < currScene->items_nearby.size()-1; i++) 
			{
				items.append(currScene->items_nearby[i].name);
				items.append(", "); 
			}
			items.append(currScene->items_nearby[currScene->items_nearby.size()-1].name);
			items.append((3 * (col)) - items.length(), ' ');

			mvprintw(row-4, 0, items.c_str());
			move(row-1, 0);
			getch();
		
		// Try to pick up item
		} else if (sep_response[0] == "get" && sep_response.size() > 1)
		{

			// Kind of confusing? Doesn't save a lot of space.
			vector<item> items = currScene->items_nearby;

			// Loop through all items to find matching name
			for(int i = 0; i < items.size(); i++) 
			{
				if (items[i].name == sep_response[1]) 
				{
					// Holds string to print what happened
					string temp = "";

					// Get ref to what was in inv
					item holder = main->inventory;

					// Remove what you're getting from scene's inventory
					currScene->items_nearby.erase(currScene->items_nearby.begin() + i);

					// If we already had an item, "drop" it
					// Meaning put our item into the scene's inventory
					if (main->inventory.id != -1) 
					{
						temp.append("Dropped ");
						temp.append(main->inventory.name);
						temp.append(col-temp.length(), ' ');
						currScene->items_nearby.push_back(holder);
					}
					
					// Add scene item to our inventory
					// (Overwriting what was there)
					main->addToInventory(items[i]);

					// Let us know what the deal was
					temp.append("Picked up ");
					temp.append(sep_response[1]);
					temp.append((2*col)-temp.length(), ' ');
					mvprintw(row-7, 0, temp.c_str());
					move(row-1,0);
					getch();
				}
			}

		// Quit the game.
		} else if (sep_response[0] == "quit") 
		{
			clear();
			
			mvprintw(row-4, 0, "Are you sure? (y/n)");
			move(row-1, 0);
			getstr(response);
			sep_response = separate(response, ' ');

			if (sep_response.size() > 0 && (sep_response[0] == "y" || sep_response[0] == "yes")) 
			{
				clear();
				mvprintw(row-4, 0, "You quitter.");
				move(row-1, 0);
				getch();
				gameOver = 1;
			}
		}
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
