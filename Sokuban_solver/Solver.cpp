#include "Solver.h"


Solver::Solver()
{
}
Solver::Solver(std::string a_map)
{
	Solver_map temp(a_map, 0, 0);
	map_vec.push_back(temp);
	free_map = getParameters(map_vec);
}
Solver_map Solver::createMap(std::string a_map, int parentVecPos, int sokoman)
{
	Solver_map temp(a_map,parentVecPos,sokoman);

	return temp;
}
std::string Solver::getParameters(std::vector<Solver_map> &map_vector)
{
	std::string temp;
	if (!map_vector.empty())
	{
		temp = map_vector[0].map;
		Width = 10 * (temp[0] - 48) + temp[1] - 48;
		Height = 10 * (temp[3] - 48) + temp[4] - 48;
		for (unsigned int i = 0; i < temp.size(); i++)
		{
			if (temp[i] == 'M')
			{
				map_vector[0].Sokoman = i;
				temp[i] = '.';
			}
			if (temp[i] == 'G')
			{
				goal_vec.push_back(i);
			}
			if (temp[i] == 'J')
			{
				temp[i] = '.';
			}
		}
	}
	else
	{
		std::cout << "Cannot get free map and parameters, map_vector is empty!" << std::endl;
	}
	return temp;

}
bool Solver::Plan()
{
	Solver_map temp;
	while (i<map_vec.size())
	{

		if (map_vec.size() % 1000000 == 0)
			std::cout << map_vec.size() / 1000000 << ".000.000 elements!\n";
		/*Create UP*/
		if (map_vec[i].map[map_vec[i].Sokoman - (Width+1)] != 'X' &&
			map_vec[i].Sokoman - 8 != map_vec[map_vec[i].parentVecPos].Sokoman)
		{
			if (map_vec[i].map[map_vec[i].Sokoman- (Width + 1)] == 'J' && map_vec[i].map[map_vec[i].Sokoman - (2* (Width + 1))] != 'X' && map_vec[i].map[map_vec[i].Sokoman - (2* (Width + 1))] != 'J')
			{
				temp = createMap(map_vec[i].map, i, map_vec[i].Sokoman - (Width + 1));
				temp.map.replace(temp.Sokoman- (Width + 1), 1, "J");
				temp.map.replace(temp.Sokoman, 1, "M");

				temp.map.erase(temp.Sokoman+ (Width + 1), 1);
				temp.map.insert(temp.map.begin() + temp.Sokoman+ (Width + 1), free_map[temp.Sokoman+ (Width + 1)]);
				map_vec.push_back(temp);
				if (checkGoal(temp, goal_vec) > checkGoal(map_vec[i], goal_vec))
					i = map_vec.size()-1;
			}

			if (map_vec[i].map[map_vec[i].Sokoman- (Width + 1)] == '.' || map_vec[i].map[map_vec[i].Sokoman- (Width + 1)] == 'G')
			{
				temp = createMap(map_vec[i].map, i, map_vec[i].Sokoman - (Width + 1));
				temp.map.replace(temp.Sokoman, 1, "M");
				temp.map.erase(temp.Sokoman+ (Width + 1), 1);
				temp.map.insert(temp.map.begin() + temp.Sokoman+ (Width + 1), free_map[temp.Sokoman+ (Width + 1)]);
				map_vec.push_back(temp);
				if (checkGoal(temp, goal_vec) > checkGoal(map_vec[i], goal_vec))
					i = map_vec.size()-1;
			}
		}

		if (map_vec.size() % 1000000 == 0)
			std::cout << map_vec.size() / 1000000 << ".000.000 elements!\n";
		/*Create Down*/
		if (map_vec[i].map[map_vec[i].Sokoman + (Width + 1)] != 'X' &&
			map_vec[i].Sokoman + 8 != map_vec[map_vec[i].parentVecPos].Sokoman)
		{
			if (map_vec[i].map[map_vec[i].Sokoman + (Width + 1)] == 'J' && map_vec[i].map[map_vec[i].Sokoman + (2* (Width + 1))] != 'X' && map_vec[i].map[map_vec[i].Sokoman + 2*((Width + 1))] != 'J')
			{
				temp = createMap(map_vec[i].map, i, map_vec[i].Sokoman + (Width + 1));
				temp.map.replace(temp.Sokoman + (Width + 1), 1, "J");
				temp.map.replace(temp.Sokoman, 1, "M");

				temp.map.erase(temp.Sokoman - (Width + 1), 1);
				temp.map.insert(temp.map.begin() + temp.Sokoman- (Width + 1), free_map[temp.Sokoman- (Width + 1)]);
				map_vec.push_back(temp);
				if (checkGoal(temp, goal_vec) > checkGoal(map_vec[i], goal_vec))
					i = map_vec.size()-1;
			}

			if (map_vec[i].map[map_vec[i].Sokoman + (Width + 1)] == '.' || map_vec[i].map[map_vec[i].Sokoman + (Width + 1)] == 'G')
			{
				temp = createMap(map_vec[i].map, i, map_vec[i].Sokoman + (Width + 1));
				temp.map.replace(temp.Sokoman, 1, "M");
				temp.map.erase(temp.Sokoman - (Width + 1), 1);
				temp.map.insert(temp.map.begin() + temp.Sokoman - (Width + 1), free_map[temp.Sokoman- (Width + 1)]);
				map_vec.push_back(temp);
				if (checkGoal(temp, goal_vec) > checkGoal(map_vec[i], goal_vec))
					i = map_vec.size()-1;
			}
		}

		if (map_vec.size() % 1000000 == 0)
			std::cout << map_vec.size() / 1000000 << ".000.000 elements!\n";
		/*Create Right*/
		if (map_vec[i].map[map_vec[i].Sokoman + 1] != 'X' &&
			map_vec[i].Sokoman + 1 != map_vec[map_vec[i].parentVecPos].Sokoman)
		{
			if (map_vec[i].map[map_vec[i].Sokoman + 1] == 'J' && map_vec[i].map[map_vec[i].Sokoman + 2] != 'X' && map_vec[i].map[map_vec[i].Sokoman + 2] != 'J')
			{
				temp = createMap(map_vec[i].map, i, map_vec[i].Sokoman + 1);
				temp.map.replace(temp.Sokoman + 1, 1, "J");
				temp.map.replace(temp.Sokoman, 1, "M");

				temp.map.erase(temp.Sokoman - 1, 1);
				temp.map.insert(temp.map.begin() + temp.Sokoman - 1, free_map[temp.Sokoman-1]);
				map_vec.push_back(temp);
				if (checkGoal(temp, goal_vec) > checkGoal(map_vec[i], goal_vec))
					i = map_vec.size()-1;
			}

			if (map_vec[i].map[map_vec[i].Sokoman + 1] == '.' || map_vec[i].map[map_vec[i].Sokoman + 1] == 'G')
			{
				temp = createMap(map_vec[i].map, i, map_vec[i].Sokoman + 1);
				temp.map.replace(temp.Sokoman, 1, "M");
				temp.map.erase(temp.Sokoman - 1, 1);
				temp.map.insert(temp.map.begin() + temp.Sokoman - 1, free_map[temp.Sokoman-1]);
				map_vec.push_back(temp);
				if (checkGoal(temp, goal_vec) > checkGoal(map_vec[i], goal_vec))
					i = map_vec.size()-1;
			}
		}

		if (map_vec.size() % 1000000 == 0)
			std::cout << map_vec.size() / 1000000 << ".000.000 elements!\n";
		/*Create Left*/
		if (map_vec[i].map[map_vec[i].Sokoman - 1] != 'X' &&
			map_vec[i].Sokoman - 1 != map_vec[map_vec[i].parentVecPos].Sokoman)
		{
			if (map_vec[i].map[map_vec[i].Sokoman - 1] == 'J' && map_vec[i].map[map_vec[i].Sokoman - 2] != 'X' && map_vec[i].map[map_vec[i].Sokoman - 2] != 'J')
			{
				temp = createMap(map_vec[i].map, i, map_vec[i].Sokoman - 1);
				temp.map.replace(temp.Sokoman - 1, 1, "J");
				temp.map.replace(temp.Sokoman, 1, "M");

				temp.map.erase(temp.Sokoman + 1, 1);
				temp.map.insert(temp.map.begin() + temp.Sokoman + 1, free_map[temp.Sokoman+1]);
				map_vec.push_back(temp);
				if (checkGoal(temp, goal_vec) > checkGoal(map_vec[i], goal_vec))
					i = map_vec.size()-1;
			}

			if (map_vec[i].map[map_vec[i].Sokoman - 1] == '.' || map_vec[i].map[map_vec[i].Sokoman - 1] == 'G')
			{
				temp = createMap(map_vec[i].map, i, map_vec[i].Sokoman - 1);
				temp.map.replace(temp.Sokoman, 1, "M");
				temp.map.erase(temp.Sokoman + 1, 1);
				temp.map.insert(temp.map.begin() + temp.Sokoman + 1, free_map[temp.Sokoman+1]);
				map_vec.push_back(temp);
				if (checkGoal(temp, goal_vec) > checkGoal(map_vec[i], goal_vec))
					i = map_vec.size()-1;


			}
		}
		i++;
		

	}
	return false;

}
Solver::~Solver()
{
}
int Solver::checkGoal(Solver_map a_map, std::vector<int> goal_vector)
{
	int temp = 0;
	for (int i = 0; i < goal_vector.size(); i++)
	{
		if (temp == goal_vector.size())
		{
			std::cout << "goal found" << std::endl;
			backtrace(a_map);
		}
		if (a_map.map[goal_vector[i]] == 'J')
		{ 
			temp++;
		}
	}
	return temp;
}


void Solver::backtrace(Solver_map &goal)
{
	Solver_map temp;
	temp = goal;

	while (temp.parentVecPos > 0)
	{
		add_direction(temp, map_vec[temp.parentVecPos]);
		temp = map_vec[temp.parentVecPos];
		if (temp.parentVecPos == 0)
		{
			add_direction(temp, map_vec[temp.parentVecPos]);
		}
	}
	std::ofstream out;
	out.open("Directions", std::ios_base::app);
	out << current_solution << ": ";
	for (int i = solution.size()-1; i >= 0 ; i--)
	{
		out << solution[i];
	}
	out << "\n";
	out.close();
	out.clear();
	current_solution++;
	solution.clear();
}

void Solver::add_direction(Solver_map &current, Solver_map & previous)
{
	if (current.Sokoman - (Width + 1) == previous.Sokoman)
	{
		solution.push_back('D');
	}
	if (current.Sokoman + (Width + 1) == previous.Sokoman)
	{
		solution.push_back('U');
	}
	if (current.Sokoman + 1 == previous.Sokoman)
	{
		solution.push_back('L');
	}
	if (current.Sokoman - 1 == previous.Sokoman)
	{
		solution.push_back('R');
	}
}