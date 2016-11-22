all: Game

Game: main.cpp Player.cpp Scene.cpp Level.cpp
	g++ -std=c++11 -g -o Game main.cpp Player.cpp Scene.cpp Level.cpp -lcurses
clean:
	rm -rf Game
