#include "Game.h"

void Game::startGame()
{
	input.parse_and_store();
	world.fillTileGrid(input.world->data);
	world.fillCellGrid();
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
		selectStartCommand(cmd);
}

void Game::readInputCommand()
{
	for (auto& cmd : input.steps)
		selectInputCommand(cmd);
}

void Game::readAssertCommand()
{
	for (auto cmd : input.asserts)
		selectAssertCommand(cmd);
}

void Game::selectStartCommand(const std::shared_ptr<Command>& cmd)
{
	if (cmd.get()->name == Command::RESOURCE)
		resource(cmd.get());
	else if (cmd.get()->name == Command::PEOPLE)
		people(cmd.get());
	else if (cmd.get()->name == Command::BUILD)
		build(cmd.get(),true);
	if (cmd.get()->name == Command::SELECT)
		select(cmd.get());
	else if (cmd.get()->name == Command::RAIN)
		rain(cmd.get());
	else if (cmd.get()->name == Command::WORK)
		work(cmd.get());
	else if (cmd.get()->name == Command::MANUFACTURE)
		manufactur(cmd.get());
	else if (cmd.get()->name == Command::MAKE_EMPTY)
		makeEmpty(cmd.get());
	else if (cmd.get()->name == Command::DEPOSIT)
		deposit(cmd.get());
	else if (cmd.get()->name == Command::TAKE_RESOURCES)
		takeResource(cmd.get());
}

void Game::selectInputCommand(const std::shared_ptr<Command>& cmd)
{
	if (cmd.get()->name == Command::RESOURCE)
		resource(cmd.get());
	else if (cmd.get()->name == Command::PEOPLE)
		people(cmd.get());
	else if (cmd.get()->name == Command::BUILD)
		build(cmd.get(),false);
	if (cmd.get()->name == Command::SELECT)
		select(cmd.get());
	else if (cmd.get()->name == Command::RAIN)
		rain(cmd.get());
	else if (cmd.get()->name == Command::WORK)
		work(cmd.get());
	else if (cmd.get()->name == Command::MANUFACTURE)
		manufactur(cmd.get());
	else if (cmd.get()->name == Command::MAKE_EMPTY)
		makeEmpty(cmd.get());
	else if (cmd.get()->name == Command::DEPOSIT)
		deposit(cmd.get());
	else if (cmd.get()->name == Command::TAKE_RESOURCES)
		takeResource(cmd.get());

}

void Game::selectAssertCommand(const string& cmd)
{
	if (cmd == "SelectedResource") {
		cout << "SelectedResource ";
		for (auto res : world.selectedResource(cell))
			cout << res << " ";
		cout << std::endl;
	}
	else if (cmd == "SelectedCategory")
		cout << "SelectedCategory " << world.selectedCategory(cell) << std::endl;

	else if (cmd == "SelectedComplete")
		cout << "SelectedComplete " << world.selectedComplete(cell) << endl;

	else if (cmd == "SelectedPeople")
		cout << "selectedPeople " << world.selectedPeople(cell) << endl;

	else if (cmd == "SelectedCar")
		cout << "SelectedCar " << world.selectedCar(cell) << endl;

	else if (cmd == "SelectedTruck")
		cout << "SelectedTruck " << world.selectedTruck(cell) << endl;

	else if (cmd == "CityCount")
		cout << "CityCount " << world.cityCount() <<std::endl;

	else if (cmd == "VillageCount")
		cout << "VillageCount " << world.villageCount() << std::endl;

	else if (cmd == "RoadCount")
		cout << "RoadCount " << world.roadCount() << std::endl;
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

void Game::wait(Command* command)
{
	for (size_t i = 0; i < std::stoi(command->arguments[0]); i++);
}

void Game::work(Command* command)
{
	world.peopleWork(cell, std::pair<int, int>(std::stoi(command->arguments[0]), std::stoi(command->arguments[1])));
}

void Game::rain(Command* command)
{
	world.rainFall(std::stoi(command->arguments[0]));
}

void Game::build(Command* command ,bool isComplate) {
	world.buildGroundObject(command->arguments[0], std::stoi(command->arguments[1]), std::stoi(command->arguments[2]), isComplate);
}

void Game::manufactur(Command* command) {
	if(command->arguments[0]== GroundTransportation::typeToString(GroundTransportationType::Car)||
		command->arguments[0] == GroundTransportation::typeToString(GroundTransportationType::Truck))
		world.manufactureGroundTransportation(command->arguments[0], std::stoi(command->arguments[1]), std::stoi(command->arguments[2]));
	else if (command->arguments[0] == AirTransport::typeToString(AirTransportType::Helicopter))
	{

	}
		// Handle Helicopter case
}

void Game::makeEmpty(Command* command) {
	world.makeEmpty(std::stoi(command->arguments[0]), std::stoi(command->arguments[1]));
}

void Game::deposit(Command* command)
{
	world.deposit(cell, std::pair<int, int>(std::stoi(command->arguments[0]), std::stoi(command->arguments[1])));
}

void Game::takeResource(Command* command)
{
	world.takeResources(cell, std::pair<int, int>(std::stoi(command->arguments[0]), std::stoi(command->arguments[1])));
}