#include "ReadJson.h"
nlohmann::json ReadJson::config;
vector<int> ReadJson::SizeOfTiles;
unordered_map<int, string> ReadJson::Tiles;
std::vector<std::string>ReadJson::resourceTypes;
void ReadJson::init()
{
    ifstream f("configuration.json");
    if (!f) {
        cerr << "Failed to open configuration.json" << endl;
        return;
    }
    try {
        f >> config;
        SizeOfTiles = getSizeOfTiles();
        Tiles = getTiles();
        resourceTypes = getResourceTypes();
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
        for (const auto item : config["ResourceTypes"]) {
            resourceTypes.push_back(item);
        }
    }
    return resourceTypes;
}