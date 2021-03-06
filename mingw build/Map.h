#ifndef MAP_H
#define MAP_H
#include <string>
#include <vector>
#include <fstream>
#include "common.h"
#include <iostream>
#include "Door.h"
#include "GenericActor.h"
class Player;
class Enemy;
//class Door;
class Map
{
public:
	Map();
	Map(std::string level) : _name(level){}
	bool LoadMap(std::string path);
	const char GetTile(int x, int y);
	void SetTile(const char tile, int x, int y);
	void ProcessLevel(Player &player, std::vector<Door> &doors, std::vector<GenericActor> &actors, std::vector<Enemy> &enemies);
	void printLevel();
	void SetVisited(bool visited) { _visited = visited; }
	void EnteredViaRight(bool flag) { _rightEntered = flag; }
	void EnteredViaLeft(bool flag) { _leftEntered = flag; }
	void setName(std::string nameOfLevel)
	{
		_name = nameOfLevel;
	}
	const char* getName() { return _name.c_str(); }
private:
	bool _visited = false;
	bool _leftEntered = false;
	bool _rightEntered = false;
	std::vector<std::string> _levelData;
	std::string _name;
};

#endif