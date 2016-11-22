# "Adventure!"
This is a text-based 'engine' type-deal written in c++. This 'engine' uses the curses library.

# Player
First off, there's a player. It has a name and everything. It's name is picked randomly.

# Scene
Then, we have Scenes. These are individual rooms. They have items in them and passageways to other rooms.

# Level
Then, we have Levels, which are collections of Scenes. That way, all you need to do is say myLevel->play(myPlayer) to play a level with a given character.

When playing a level, you can move from scene to scene in the four cardinal directions by typing 'go (north/south/east/west)'

You can also type 'look' or 'inspect' to see what items are in the current room.

At any time, you can quit with 'quit'.


# Loading Levels
I haven't really solved the issue of how to gracefully load levels, so as of now, I simply do it in the main.cpp immediately.
