all: Game

Game: main.cpp Player.cpp Player.h Scene.h
	g++ -std=c++11 -g -o Game main.cpp Player.cpp Player.h Scene.h
clean:
	rm -rf Game
