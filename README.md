# "Adventure!"
This is a text-based 'engine' type-deal written in c++, meant entirely for the terminal. This 'engine' uses the curses library.

# Player
First off, there's a player. It has a name and everything. It's name is picked randomly; you either like the name or you generate a new one.

# Scene
Then, we have Scenes. These are individual rooms. They have items in them and passageways to other rooms.

# Level
Then, we have Levels, which are collections of Scenes. That way, all you need to do is say myLevel->play(myPlayer) to play a level with a given character.

When playing a level, you can move from scene to scene in the four cardinal directions by typing 'go (north/south/east/west)'

You can also type 'look' or 'inspect' to see what items are in the current room.

At any time, you can quit with 'quit'.


# Loading Levels
To load a level, all you need to do is have the filename of the level. Make sure it is in the same directory.

Level * myLevel = new Level("level1.txt");

Just because I can, I started saving them as .lvl files. Doesn't matter. 
Currently, you can call the game and a level you want with
<b>./Game myLevel</b>

level files are in this format:


<b>[string:level name]</b> //Line 1 is always the level name<br>
//The rest of the lines can repeat as much as necessary. <br>
//For every 3 additional lines past this point, a new scene is added to the game.<br>
<b>[string:scene 1 name],[int: scene 1 id],[string: scene 1 description]</b> <br>// Name, ID, and Description separated by commas.<br>
<b>[scene1_item1_id],[scene1_item1_name];[scene1_item2_id],[scene1_item2_name]; ect...</b> <br>//List of items in the scene separated by semicolon. Individual traits of items separated by commas.
<b>[scene1_scenes_nearby]</b><br> //This is an int[4], each number is separated by commas. The numbers represent ID of rooms to the [N,E,S,W]<br>
ect...

The ids are pointless for now; I use the position of the scene on the list as the reference for now. I figured I'd find a use for them down the road.
 
This will almost definitely change as the I add more capabilities, like npcs and puzzle mechanics for interaction.
