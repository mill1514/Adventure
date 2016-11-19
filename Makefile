all: Game

Game: main.cpp Player.cpp Player.h
	g++ -std=c++11 -g -o Game main.cpp Player.cpp Player.h
clean:
	rm -rf Game
