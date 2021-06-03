#pragma once

#include<string>

enum MyEnum
{

};

struct Item
{
	int count;
	float price;
	std::string Name;
	char *Origin;

	Item(int _count, float _price, std::string _Name, char *_origin) {
		count = _count;
		price = _price;
		Name = _Name;
		Origin = new char[4];
		Origin[0] = _origin[0];
		Origin[1] = _origin[1];
		Origin[2] = _origin[2];
		Origin[3] = _origin[3];
	}
};

