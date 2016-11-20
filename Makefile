all: Game

Game: main.cpp Player.cpp Player.h Scene.cpp Scene.h Level.cpp Level.h
	g++ -std=c++11 -g -o Game main.cpp Player.cpp Player.h Scene.cpp Scene.h Level.cpp Level.h -lcurses
clean:
	rm -rf Game
