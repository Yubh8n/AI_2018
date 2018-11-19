#include "BFS.h"



BFS::BFS()
{
}

void BFS::getParams(std::string map)
{
	for (int i = 0; i < map.size(); i++)
	{
		if (map[i] == 'G')
			goal_vec.push_back(i);
		if (map[i] == 'J')
			Diamonds.push_back(i);
		if (map[i] == 'M')
			sokoMan = i;
	}

	mapWidth = 10 * (map[0] - 48) + map[1] - 48;
	mapHeight = 10 * (map[3] - 48) + map[4] - 48;
}


void BFS::pickPairs(std::vector<int> goals, std::vector<int> diamonds)
{
	std::vector<int> temp_vec;
	for (int i = 0; i < goals.size(); i++)
	{
		for (int j = 0; j < diamonds.size(); j++)
		{
		temp_vec.push_back(goals[i]);
		temp_vec.push_back(diamonds[j]);
		pairs.push_back(temp_vec);
		temp_vec.clear();
		}
	}
}

bool BFS::try_move(std::vector<int> pair)
{
	sokoMan = init_sokoMan;

	if (sokoMan - 8 > pair[1] && map[sokoMan - 8] != 'X')
	{

	}
	return true;
}

BFS::~BFS()
{
}
