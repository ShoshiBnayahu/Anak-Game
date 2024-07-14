#include "ReadJson.h"
#include "Resource.h"

std::vector<int> Resource::selectedResource()
{
	std::vector<int> amount(ReadJson::resourceTypes.size());

	for (const auto& res : ReadJson::resourceTypes) {
		if (resources.find(res.first) != resources.end())
			amount[res.second] = resources.at(res.first);
		else
			amount[res.second] = 0;
	}
	//pop the people resource
	amount.pop_back();
	return amount;
}
void Resource::addResource(std::string resourceType, int amount)
{
	resources[resourceType] += amount;
}
void Resource::subResource(std::string resourceType, int amount)
{
	resources[resourceType] -= amount;
}
void Resource::makeEmpty()
{
	for (auto r : resources) {
		r.second = 0;
	}
}
