#pragma once
#include "Input.h"
#include "World.h"
#include "Tile.h"
#include "People.h"
class Game
{
private:
	Input input;
	World world;
	std::pair<int, int> cell;
	std::pair<int, int> lastMove;
	int points;

public:
	Game() :points(0){}
	int getPoints()const { return points; }
	void setPoints(int amount);
	void startGame();
	void readCommand();
	void readStartCommand();
	void readInputCommand();
	void readAssertCommand();
	void selectStartCommand(const std::shared_ptr<Command>& cmd);
	void selectInputCommand(const std::shared_ptr<Command>& cmd);
	void selectAssertCommand(const string& cmd);
	void resource(Command* command);
	void people(Command* comand);
	void select(Command* comand);
	void wait(Command* comand);
	void work(Command* comand);
	void rain(Command* comand);
	void build(Command* comand, bool isComplate);
    void manufactur(Command* comand,bool chekResource);
	//void manufactur(Command* command);
	void makeEmpty(Command* command);
	void deposit(Command* command);
	void takeResource(Command* command);
	void resources(Command* command);
	void move(Command* command);

};
