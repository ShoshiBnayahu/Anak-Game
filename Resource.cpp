#include "ReadJson.cpp"
#include "Resource.h"

std::vector<int> Resource::selectedResource()
{
	std::vector<int> amount;
	for (const auto& res : ReadJson::resourceTypes) {
		if (resources.find(res.first) != resources.end())
			amount.push_back(resources.at(res.first));
		else
			amount.push_back(0);
	}
	//pop the people resource 
	amount.pop_back();
	return amount;
}

void Resource::addResource(std::string resourceType, int amount)
{
	resources[resourceType] += amount;
}

void Resource::subResource(std::string resourceType,int amount)
{
	resources[resourceType] -= amount;
}
