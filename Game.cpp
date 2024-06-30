//// Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
//
//#include <iostream>
//#include <string>
//#include "World.h"
//#include "Input.h"
//
//
//
//int main() {
//
//	//world map
//	Input myInput;
//	myInput.parse_and_store();
//	World world(myInput.world->data);
//	int select1 = stoi(myInput.steps[0]->arguments[0]);
//	int select2 = stoi(myInput.steps[0]->arguments[1]);
//	//for (auto cmd : myInput.start) {
//	// .....
//	//for (auto step : myInput.steps) {
//	//......
//	
//	//for (string step : myInput.asserts) {
//	std::string category = world.selectedCategory(select1 - 1, select2 - 1);
//	std::cout << "SelectedCategory " << category;
//
//	
//
//	// Resrouce Usage
//	//Input myInput;
//	//myInput.parse_and_store();
//	//World world(myInput.world->data);
//	//ReadJson readJson;
	////for (auto cmd : myInput.start) {
	////	string name = cmd->name;
	////		if (name == Command::RESOURCE) {
	////			int amount= stoi(cmd->arguments[0]);
	////			string name = cmd->arguments[1];
	////			int x= stoi(cmd->arguments[2]);
	////			int y= stoi(cmd->arguments[3]);
	////			if (kind == "Wood") {
	////				if (world.selectedCategory(x - 1, y - 1) == "Forest")
	////					world.addResourse(x, y);
//	//				   	
//	//			}
//	//		}
//	//		if (name == Command::PEOPLE) {
//	//			/*People $number $x $y : Should place $number of people at the $x $y world location
//	//				Should happen in the infrastructure at the given location if 
//	//				possible(have capacity) or simply at the world location if no infrastructure exists*/
//	//		}
//	//		if (name == Command::MANUFACTURE) {
//
//	//			   
//	//		}
//	//		if (name == Command::BUILD) {
//
//
//	//		}
//	//		if (name == Command::RAIN) {
//
//
//	//		}
//	//		if (name == Command::WAIT) {
//
//
//	//		}
//	//		if (name == Command::SELECT) {
//
//
//	//		}
//
//	//}
//
//	//for (auto step : myInput.steps) {
//	//	string name = step->name;
//	//	if (name == Command::RESOURCE) {
//	//		int amount = stoi(step->arguments[0]);
//	//		string kind = step->arguments[1];
//	//		int x = stoi(step->arguments[2]);
//	//		int y = stoi(step->arguments[3]);
//	//		if (kind == "Wood") {
//	//			if (world.selectedCategory(x - 1, y - 1) == "Forest")
//	//				world.addResourse(x, y);
//
//	//		}
//	//	}
//	//	if (name == Command::PEOPLE) {
//	//		/*People $number $x $y : Should place $number of people at the $x $y world location
//	//			Should happen in the infrastructure at the given location if
//	//			possible(have capacity) or simply at the world location if no infrastructure exists*/
//	//	}
//	//	if (name == Command::MANUFACTURE) {
//
//
//	//	}
//	//	if (name == Command::BUILD) {
//
//
//	//	}
//	//	if (name == Command::RAIN) {
//
//
//	//	}
//	//	if (name == Command::WAIT) {
//
//
//	//	}
//	//	if (name == Command::SELECT) {
//
//	//		int x = stoi(step->arguments[0]);
//	//		int y = stoi(step->arguments[1]);
//	//		std::string resource = world.selectedResource(x-1, y-1);
//	//		std::cout << "SelectedResource " << resource; 
//	//	}
//
//	//	std::cout << step->name << "\t" << "\t" << step->arguments[0] << " \t" << step->arguments[1] << step->arguments[2] << step->arguments[3] << "\n";
//	//}
//
//
//	/*std::string category = world.selectedCategory(select1 - 1, select2 - 1);
//	std::cout << "SelectedCategory " << category;*/
//
//}
//
//
//// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
//// Debug program: F5 or Debug > Start Debugging menu
//
//// Tips for Getting Started: 
////   1. Use the Solution Explorer window to add/manage files
////   2. Use the Team Explorer window to connect to source control
////   3. Use the Output window to see build output and other messages
////   4. Use the Error List window to view errors
////   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
////   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
#include <iostream>
#include <string>
#include "World.h"
#include "Input.h"
#include "ReadJson.h"
#include <unordered_map>


using namespace std;
int main()
{
	ReadJson::init();
	Input myInput;
	myInput.parse_and_store();
	World myWorld(myInput.world->data);

	/*+World
		3 1 4
		1 1 1
		5 1 6
		+ Start
		Resource 1 Wood 1 1
		+ Input
		Select 1 1
		+ Asserts
		SelectedResource*/

		string name = myInput.start[0]->name;
		//if (name == Command::RESOURCE) {
		int amount = stoi(myInput.start[0]->arguments[0]);
		string resourceName = myInput.start[0]->arguments[1];
		int x = stoi(myInput.start[0]->arguments[2]);
		int y = stoi(myInput.start[0]->arguments[3]);

		myWorld.insertResource(amount, resourceName, x, y);
		std::cout << "SelectedResource ";
		for (int a : myWorld.selectedResource())
		{
			std::cout << a << " ";
		}

	return 0;
}