#pragma once
#include <iostream>
#include <vector>
#include <fstream>

class Solver_map
{
public:
	std::string map;
	int Sokoman;
	int parentVecPos;

	Solver_map() {}
	Solver_map(std::string a_map, int pVecPos) : map(a_map), parentVecPos(pVecPos) {}
	Solver_map(std::string a_map, int pVecPos, int soko) : map(a_map), parentVecPos(pVecPos) ,Sokoman(soko) {}
	~Solver_map() {};
private:
};



class Solver
{
public:
	/*default constructor*/
	Solver();
	/*Map init constructor*/
	Solver(std::string a_map);
	Solver_map createMap(std::string map, int parentVecPos,int sokoman);
	std::string getParameters(std::vector<Solver_map> &map_vector);
	int checkGoal(Solver_map a_map, std::vector<int> goal_vector);
	bool Plan();
	void add_direction(Solver_map &current, Solver_map & previous);

	~Solver();
private:
	std::vector<int> goal_vec;
	std::vector<int> box_vec;
	std::string free_map;
	void backtrace(Solver_map &goal);
	std::ofstream out;


	std::vector<Solver_map> map_vec;
	std::vector<char> solution;
	long i = 0;
	int init_ = 9;
	int Width = 0;
	int Height = 0;
	int current_solution = 0;

};


