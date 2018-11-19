#include "map.h"

map::map()
{
}
map::map(std::string map_input,int soko)
{
	map_self = map_input;
	sokoMan = soko;
	//printMap();
}
bool map::goalCheck(std::vector<int> goal_vector)
{
	for (int i = 0; i < goal_vector.size(); i++)
		if (map_self[goal_vector[i]] == 'G' || map_self[goal_vector[i]] == 'M')
			return false;
	return true;
}
void map::set_freemap(std::string a_map)
{
	map_self = a_map;
}
void map::printMap()
{
	if (map_self.size() == 0)
		std::cout << "Map not found";
	else
	{
		for (unsigned int i = 0; i < map_self.size(); i++)
		{
			std::cout << map_self[i];
		}
	}
	
}
map map::spawnUp(std::string free_map)    
{
	/*If the above is not a wall*/
	if (map_self[sokoMan - 8] != 'X' && sokoMan >= 8)
	{
		//up = new map(map_self, sokoMan - 8);
		map up(map_self, sokoMan - 8);
		//up.parent_ = &parent;
		up.parent_map = map_self;
		up.parent_sokoman = sokoMan;
		/*If the above is a Jewel and the above that, is not a wall*/
		if (map_self[sokoMan - 8] == 'J' && map_self[sokoMan - 16] != 'X')
		{
			/*push the jewel and move sokoman*/
			up.map_self.replace(sokoMan - 16, 1, "J");
			up.map_self.replace(sokoMan - 8, 1, "M");

			up.map_self.erase(sokoMan, 1); 
			up.map_self.insert(up.map_self.begin() + sokoMan, free_map[sokoMan]);
		}
		/*If the above is free path OR goal*/
		if (map_self[sokoMan - 8] == '.' || map_self[sokoMan - 8] == 'G')
		{
			up.map_self.replace(sokoMan - 8, 1, "M");

			/*replace the current position in the next "frame"*/
			up.map_self.erase(sokoMan, 1);
			up.map_self.insert(up.map_self.begin() + sokoMan, free_map[sokoMan]);
		}
		up.parent = this;
		parent->Directions.push_back('R');
		return up;
	}
}
map map::spawnDown(std::string free_map)
{
	/*If the below is not a wall*/
	if (map_self[sokoMan + 8] != 'X')
	{
		map down(map_self, sokoMan + 8);
		down.parent_map = map_self;
		down.parent_sokoman = sokoMan;

		/*If the below is a Jewel and the below that, is not a wall*/
		if (map_self[sokoMan + 8] == 'J' && map_self[sokoMan + 16] != 'X')
		{
			
			down.map_self.replace(sokoMan + 16, 1, "J");
			down.map_self.replace(sokoMan + 8, 1, "M");

			/*replace the current position in the next "frame"*/
			down.map_self.erase(sokoMan, 1);
			down.map_self.insert(down.map_self.begin() + sokoMan, free_map[sokoMan]);
		}
		/*If the below is free path OR goal*/
		if (map_self[sokoMan + 8] == '.' || map_self[sokoMan + 8] == 'G')
		{
			down.map_self.replace(sokoMan + 8, 1, "M");

			/*replace the current position in the next "frame"*/
			down.map_self.erase(sokoMan, 1);
			down.map_self.insert(down.map_self.begin() + sokoMan, free_map[sokoMan]);
		}
		parent->Directions.push_back('R');
		down.parent = this;
		return down;
	}
}
map map::spawnLeft(std::string free_map)
{
	/*If the above is not a wall*/
	if (map_self[sokoMan -1] != 'X')
	{
		map left(map_self, sokoMan - 1);
		left.parent_map = map_self;
		left.parent_sokoman = sokoMan;
		/*If the above is a Jewel and the above that, is not a wall*/
		if (map_self[sokoMan -1] == 'J' && map_self[sokoMan -2] != 'X')
		{
			left.map_self.replace(sokoMan -2, 1, "J");
			left.map_self.replace(sokoMan -1, 1, "M");
			/*replace the current position in the next "frame"*/
			left.map_self.erase(sokoMan, 1);
			left.map_self.insert(left.map_self.begin() + sokoMan, free_map[sokoMan]);
		}
		/*If the above is free path OR goal*/
		if (map_self[sokoMan - 1] == '.' || map_self[sokoMan - 1] == 'G')
		{
			left.map_self.replace(sokoMan - 1, 1, "M");

			/*replace the current position in the next "frame"*/
			left.map_self.erase(sokoMan, 1);
			left.map_self.insert(left.map_self.begin() + sokoMan, free_map[sokoMan]);
		}
		parent->Directions.push_back('R');
		left.parent = this;
		return left;
	}
}
map map::spawnRight(std::string free_map)
{
	/*If the above is not a wall*/
	if (map_self[sokoMan + 1] != 'X')
	{

		map right(map_self, sokoMan + 1);
		right.parent_map = map_self;
		right.parent_sokoman = sokoMan;

		/*If the above is a Jewel and the above that, is not a wall*/
		if (map_self[sokoMan + 1] == 'J' && map_self[sokoMan + 2] != 'X')
		{
			right.map_self.replace(sokoMan + 2, 1, "J");
			right.map_self.replace(sokoMan + 1, 1, "M");

			/*replace the current position in the next "frame"*/
			right.map_self.erase(sokoMan, 1);
			right.map_self.insert(right.map_self.begin() + sokoMan, free_map[sokoMan]);
			/*If the above is free path OR goal*/
		}
		if (map_self[sokoMan + 1] == '.' || map_self[sokoMan + 1] == 'G')
		{
			right.map_self.replace(sokoMan + 1, 1, "M");

			/*replace the current position in the next "frame"*/
			right.map_self.erase(sokoMan, 1);
			right.map_self.insert(right.map_self.begin() + sokoMan, free_map[sokoMan]);
		}
		parent->Directions.push_back('R');
		right.parent = this;
		return right;
	}
}

bool map::up_clear()
{
	if (map_self[sokoMan - 8] != 'X' && sokoMan >= 8)
	{
		/*If the above is a Jewel and the above that, is not a wall*/
		if (map_self[sokoMan - 8] == 'J' && map_self[sokoMan - 16] != 'X')
		{
			return true;
		}
		/*If the above is free path OR goal*/
		if (map_self[sokoMan - 8] == '.' || map_self[sokoMan - 8] == 'G')
		{
			return true;
		}
	}
	return false;
}
bool map::down_clear()
{
	if (map_self[sokoMan + 8] != 'X')
	{
		/*If the above is a Jewel and the above that, is not a wall*/
		if (map_self[sokoMan + 8] == 'J' && map_self[sokoMan + 16] != 'X')
		{
			return true;
		}
		/*If the above is free path OR goal*/
		if (map_self[sokoMan + 8] == '.' || map_self[sokoMan + 8] == 'G')
		{
			return true;
		}
	}
	return false;
}
bool map::left_clear()
{
	if (map_self[sokoMan - 1] != 'X')
	{
		/*If the above is a Jewel and the above that, is not a wall*/
		if (map_self[sokoMan - 1] == 'J' && map_self[sokoMan - 2] != 'X')
		{
			return true;
		}
		/*If the above is free path OR goal*/
		if (map_self[sokoMan - 1] == '.' || map_self[sokoMan - 1] == 'G')
		{
			return true;
		}
	}
	return false;
}
bool map::right_clear()
{
	if (map_self[sokoMan + 1] != 'X')
	{
		/*If the above is a Jewel and the above that, is not a wall*/
		if (map_self[sokoMan + 1] == 'J' && map_self[sokoMan + 2] != 'X')
		{
			return true;
		}
		/*If the above is free path OR goal*/
		if (map_self[sokoMan + 1] == '.' || map_self[sokoMan + 1] == 'G')
		{
			return true;
		}
	}
	return false;
}

map::~map()
{
}
