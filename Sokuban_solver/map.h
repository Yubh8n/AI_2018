#pragma once
#include <string>
#include <iostream>
#include <vector>

class map
{
public:
	int sokoMan;
	int parent_sokoman;
	std::vector<char> Directions;

	map();
	map(std::string map_input, int soko);
	bool goalCheck(std::vector <int> goal_vector);
	void set_freemap(std::string a_map);
	void printMap();
	bool up_clear();
	bool down_clear();
	bool left_clear();
	bool right_clear();
	map spawnUp(std::string free_map);
	map spawnDown(std::string free_map);
	map spawnLeft(std::string free_map);
	map spawnRight(std::string free_map);

	~map();
private:
	std::string map_self;
	std::string parent_map;
	map* parent;
};