#include "ReadJson.h"
nlohmann::json ReadJson::config;
vector<int> ReadJson::sizeOfTiles;
unordered_map<int, string> ReadJson::tiles;
std::vector<std::string>ReadJson::resourceTypes;
unordered_map<string, int> ReadJson::rains;

void ReadJson::init()
{
    ifstream f("configuration.json");
    if (!f) {
        cerr << "Failed to open configuration.json" << endl;
        return;
    }
    try {
        f >> config;
        sizeOfTiles = getSizeOfTiles();
        tiles = getTiles();
        resourceTypes = getResourceTypes();
        rains = getRains();
    }
    catch (const json::parse_error& e) {
        cerr << "Error parsing JSON: " << e.what() << endl;
    }
}
unordered_map<int, string>& ReadJson::getTiles()
{
    static unordered_map<int, string> tiles;
    if (config.contains("Tiles")) {
        for (const auto& item : config["Tiles"].items()) {
            tiles[item.value().get<int>()] = item.key();
        }
    }
    return tiles;
}
vector<int>& ReadJson::getSizeOfTiles()
{
    static vector<int> size;
    if (config.contains("Sizes")) {
        for (const auto item : config["Sizes"]["Tile"]) {
            size.push_back(item);
        }
    }
    return size;
}
vector<std::string>& ReadJson::getResourceTypes()
{
    static vector<std::string> resourceTypes;
    if (config.contains("ResourceTypes")) {
        for (const auto item : config["ResourceTypes"])
            resourceTypes.push_back(item);
    }
    return resourceTypes;
}
unordered_map<string, int>& ReadJson::getRains()
{
   static unordered_map<string, int> rains;
    if (config.contains("Rains")) {
        for (const auto item : config["Rains"].items()) 
            rains[item.key()] = item.value().get<int>();
    }
    return rains;
}
