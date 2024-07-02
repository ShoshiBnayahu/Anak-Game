#include "Game.h"

void Game::startGame()
{
	input.parse_and_store();
	world.fillGrid(input.world->data);
	readCommand();
}

void Game::readCommand()
{
	readStartCommand();
	readInputCommand();
	readAssertCommand();
}

void Game::readStartCommand()
{
	for (auto& cmd : input.start)
		selectCommand(cmd);
}

void Game::readInputCommand()
{
	for (auto& cmd : input.steps)
		selectCommand(cmd);
}

void Game::readAssertCommand()
{
	for (auto cmd : input.asserts)
		selectAssertCommand(cmd);
}

void Game::selectCommand(const std::shared_ptr<Command>& cmd)
{
	if (cmd.get()->name == Command::RESOURCE)
		resource(cmd.get());
	else if (cmd.get()->name == Command::PEOPLE)
		people(cmd.get());
	/*else if (cmd.get()->name == Command::BUILD)
		build(cmd.get());*/

	if (cmd.get()->name == Command::SELECT)
		select(cmd.get());
	else if (cmd.get()->name == Command::RAIN)
		rain(cmd.get());
	else if (cmd.get()->name == Command::WAIT)
		wait(cmd.get());
	else if (cmd.get()->name == Command::WORK)
		work(cmd.get());
}

void Game::selectAssertCommand(const string& cmd)
{
	if (cmd == "SelectedResource") {
		cout << "SelectedResource ";
		for (auto res : world.selectedResource(cell))
			cout << res << " ";
	}
		
	else if (cmd == "SelectedCategory")
		cout << "SelectedCategory " << world.selectedCategory(cell);
}

void Game::resource(Command* command)
{
	world.insertResource(std::stoi(command->arguments[0]), command->arguments[1], std::stoi(command->arguments[2]), std::stoi(command->arguments[3]));
}

void Game::people(Command* comand)
{
	world.insertPeople(std::stoi(comand->arguments[0]), std::stoi(comand->arguments[1]), std::stoi(comand->arguments[2]));
}

void Game::select(Command* comand)
{
	cell = std::pair<int, int>(std::stoi(comand->arguments[0]), std::stoi(comand->arguments[1]));

}

void Game::wait(Command* comand)
{
	for (size_t i = 0; i < std::stoi(comand->arguments[0]); i++);
}

void Game::work(Command* comand)
{
	world.peopleWork(cell, std::pair<int, int>(std::stoi(comand->arguments[0]), std::stoi(comand->arguments[1])));
}

void Game::rain(Command* comand)
{
	world.rainFall(std::stoi(comand->arguments[0]));
}
