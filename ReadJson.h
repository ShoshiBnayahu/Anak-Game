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
    static unordered_map<string, std::vector<int>> sizes;
    //static vector<std::string> resourceTypes;
    static unordered_map<string, int> resourceTypes;
    ///try

    static unordered_map<string, string>tilesResourceType;
    static unordered_map<string, std::vector<int>> costs;
    static unordered_map<string, std::vector<int>> capacities;
private:
    //static vector<std::string>& getResourceTypes();
    static unordered_map<string, int>& getResourceTypes();
    ///try
    static unordered_map<string, int>& getRains();
    static unordered_map<string, std::vector<int>>& getSizes();
    static unordered_map<string, std::vector<int>>& getCosts();
    static unordered_map<string, std::vector<int>>& getCapacities();
    static unordered_map<int, string>& getTiles();
    static unordered_map<string, string>& getTilesResourceType();

};