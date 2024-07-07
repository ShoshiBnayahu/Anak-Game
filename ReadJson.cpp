#include "ReadJson.h"
nlohmann::json ReadJson::config;
unordered_map<int, string> ReadJson::tiles;
unordered_map<string, int> ReadJson::resourceTypes;
unordered_map<string, string> ReadJson::tilesResourceType;
unordered_map<string, int> ReadJson::rains;
unordered_map<string, std::vector<int>> ReadJson::sizes;
unordered_map<string, std::vector<int>>ReadJson::costs;
unordered_map<string, std::vector<int>>ReadJson::capacities;


void ReadJson::init()
{
    ifstream f("configuration.json");
    if (!f) {
        cerr << "Failed to open configuration.json" << endl;
        return;
    }
    try {
        f >> config;
        //sizeOfTiles = getSizeOfTiles();
        tiles = getTiles();
        resourceTypes = getResourceTypes();
        tilesResourceType = getTilesResourceType();
        rains = getRains();
        sizes = getSizes();
        costs = getCosts();
        capacities = getCapacities();
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

unordered_map<string, int>& ReadJson::getResourceTypes()
{
    static unordered_map<string, int> resourceTypes;

    if (config.contains("ResourceTypes"))
    {
        int index = 0;
        for (const auto& item : config["ResourceTypes"])
        {
            resourceTypes[item.get<string>()] = index++;
        }
    }

    return resourceTypes;
}


unordered_map<string, string>& ReadJson::getTilesResourceType()
{
    //כתבתי ידנית מידע שהיה חסר בגסון
    static unordered_map<string, string> tilesResourceType;
    tilesResourceType["Forest"] = "Wood";
    tilesResourceType["Field"] = "Wool";
    tilesResourceType["IronMine"] = "Iron";
    tilesResourceType["BlocksMine"] = "Blocks";
    return tilesResourceType;
}

//vector<std::string>& ReadJson::getResourceTypes()
//{
//    static vector<std::string> resourceTypes;
//    if (config.contains("ResourceTypes")) {
//        for (const auto item : config["ResourceTypes"])
//            resourceTypes.push_back(item);
//    }
//    return resourceTypes;
//}

unordered_map<string, int>& ReadJson::getRains()
{
    static unordered_map<string, int> rains;
    if (config.contains("Rains")) {
        for (const auto item : config["Rains"].items())
            rains[item.key()] = item.value().get<int>();
    }
    return rains;
}


unordered_map<string, std::vector<int>>& ReadJson::getSizes()
{
    static std::unordered_map<string, std::vector<int>> sizes;
    if (config.contains("Sizes")) {
        for (const auto item : config["Sizes"].items()) {
            sizes[item.key()] = item.value().get<vector<int>>();
        }
    }
    return sizes;
}

unordered_map<string, std::vector<int>>&ReadJson::getCosts()
{
    static std::unordered_map<string, std::vector<int>> costs;
    if (config.contains("Costs")) {
        for (const auto item : config["Costs"].items()) {
            costs[item.key()] = item.value().get<vector<int>>();
        }
    }
    return costs;
}

unordered_map<string, std::vector<int>>& ReadJson::getCapacities()
{
    static std::unordered_map<string, std::vector<int>> capacities;
    if (config.contains("Capacities")) {
        for (const auto item : config["Capacities"].items()) {
            capacities[item.key()] = item.value().get<vector<int>>();
        }
    }
    return capacities;
}