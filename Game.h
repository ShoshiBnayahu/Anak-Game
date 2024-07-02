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
public:
	void startGame();
	void readCommand();
	void readStartCommand();
	void readInputCommand();
	void readAssertCommand();
	void selectCommand(const std::shared_ptr<Command>& cmd);
	void selectAssertCommand(const string& cmd);
	void resource(Command* command);
	void people(Command* comand);
	void select(Command* comand);
	void wait(Command* comand);
	void work(Command* comand);
	void rain(Command* comand);		
};
