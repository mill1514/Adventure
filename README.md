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

level text files are in this format:

 // \<name of level\>
 // \<scene1_name\>,\<scene1_id\>,\<scene1_desc\>
 // \<scene1_item1_id\>,\<scene1_item1_name\>;\<scene1_item1_id\>,\<scene1_item1_name\>; ect..
 // \<scene1_scenes_nearby\>
 // \<scene2_name\>,\<scene2_id\>,\<scene2_desc\>
 // \<scene2_item1_id\>,\<scene2_item1_name\>;\<scene2_item1_id\>,\<scene2_item1_name\>; ect..
 // \<scene2_scenes_nearby\>
 // ect..
 
 This will almost definitely change as the I add more capabilities, like npcs and puzzle mechanics for interaction.
