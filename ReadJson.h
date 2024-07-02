#pragma once
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <unordered_map>
#include <vector>
using namespace std;
using json = nlohmann::json;
class ReadJson
{
private:
    ReadJson();
public:
    static json config;
    static void init();
    static unordered_map<int, string> tiles;
    static unordered_map<string, int> rains;
    static vector<std::string> resourceTypes;
    static vector<int> sizeOfTiles;
    static vector<int>& getSizeOfTiles();
    static vector<std::string>& getResourceTypes();
    static unordered_map<string, int>& getRains();
    static unordered_map<int, string>& getTiles();

};