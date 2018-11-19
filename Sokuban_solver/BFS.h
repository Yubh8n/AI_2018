#pragma once
#include <iostream>
#include <vector>

class BFS
{
public:
	BFS();
	BFS(std::string Init_map) : map(Init_map) { getParams(map); pickPairs(goal_vec, Diamonds); };
	void pickPairs(std::vector<int> goals, std::vector<int> diamonds);
	void getParams(std::string map);
	bool try_move(std::vector<int> pair);
	void pushUp(int &a_box) { a_box = a_box - (mapWidth + 1); };
	void pushDown(int &a_box) { a_box = a_box + (mapWidth + 1); };
	void pushRight(int &a_box) { a_box = a_box + 1; };
	void pushLeft(int &a_box) { a_box = a_box - 1; };
	void Sokoman_up(int &sokoban_man) { sokoban_man = sokoban_man - (mapWidth + 1); };
	void Sokoman_down(int &sokoban_man) { sokoban_man = sokoban_man + (mapWidth + 1); };
	void Sokoman_right(int &sokoban_man) { sokoban_man = sokoban_man + 1; };
	void Sokoman_left(int &sokoban_man) { sokoban_man = sokoban_man - 1; };


	~BFS();


private:
	int mapWidth;
	int mapHeight;
	int init_sokoMan;
	std::vector<int> goal_vec;
	std::vector<int> Diamonds;
	std::vector<std::vector<int>> pairs;
	std::string map;
	int sokoMan;
};

