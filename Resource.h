#pragma once
#include <unordered_map>
class Resource {
protected:
	std::unordered_map<std::string, int> resources;
public:
	std::vector<int> selectedResource();
	virtual void addResource(std::string resourceType, int amount);
	void subResource(std::string resourceType, int amount );
	void makeEmpty();
};