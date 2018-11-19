#include "BFS.h"
#include "Solver.h"
#include "map.h"
#include "Queue.h"
#include <fstream>
#include <thread>
#include <vector>

Queue<map> map_queue;
std::vector<int> Goal_Vec;
//std::queue<map> map_queue;

std::vector<map> map_list;
std::mutex mtx;
int sokoMan = 0;
int Width = 0;
int Height = 0;


/*bool checkGoal(std::string aMap)
{
	for (unsigned int i = 0; i < Goal_Vec.size(); i++)
	{
		if (aMap[i] == 'G' || aMap[i] == 'M')
			return false;
		else
			return true;
	}
}*/
void ravage(std::string free_map)
{
	map temp;
	while (true)
	{
		temp = map_queue.pop();
		if (temp.goalCheck(Goal_Vec))
		{
			std::cout << "GOAL FOUND WITH: " << std::endl;
			for (int i = 0; i<temp.Directions.size(); i++)
			std::cout << temp.Directions[i] << std::endl;

		}


		if (temp.up_clear() && temp.sokoMan - 8 != temp.parent_sokoman)
			map_queue.push(temp.spawnUp(free_map));
		if (temp.down_clear() && temp.sokoMan - 8 != temp.parent_sokoman)
			map_queue.push(temp.spawnDown(free_map));
		if (temp.left_clear() && temp.sokoMan - 8 != temp.parent_sokoman)
			map_queue.push(temp.spawnLeft(free_map));
		if (temp.right_clear() && temp.sokoMan - 8 != temp.parent_sokoman)
			map_queue.push(temp.spawnRight(free_map));
	}
}


int main()
{
	/*Import the Sokoban map*/
	std::fstream input_competition_map ("C:/Users/Chris/Downloads/2017-competation-map", std::ios::in);
	std::fstream input_map("C:/Users/Chris/Downloads/test", std::ios::in);
	std::string initTestMap;
	std::string initCompMap;
	if (input_map)
	{
		while (!input_map.eof())
			initTestMap.push_back(input_map.get());
	}
	if (input_competition_map)
	{
		while (!input_competition_map.eof())
			initCompMap.push_back(input_competition_map.get());
	}
	
	BFS testmap(initCompMap);
	/*Solver sokobanTestMap(initCompMap);
	sokobanTestMap.Plan();*/


	return 0;
}