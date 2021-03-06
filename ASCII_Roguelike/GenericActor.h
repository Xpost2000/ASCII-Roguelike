#pragma once
// A simple actor.
/*
	Pretty much a sample for the enemies to build of
	off
*/
#include <random>
#include <functional>
class Map;

class GenericActor
{
public:
	GenericActor(int hp, int defense, bool killable, int xpGain, int x, int y, int id, std::string name);
	bool isKillable(){ return _Killable; }
	void TakeDamage(int damage) { _hp -= damage - _def % 2; };
	bool processMove(Map map, int targetX, int targetY);
	bool MoveX(Map &map, int targetX);
	bool MoveY(Map &map, int targetY);
	bool isDead(Map &map);
	void AI_Loop(Map &map);
	const char* getResponse();
	const char* getName();
	// Do not use this function 
	int GetX() { return _x; }
	int GetY() { return _y; }
private:
	int _hp, _def, _xpGain;
	bool _Killable;
	std::string _name;
	int _x, _y;
	int _id; // RNG Purposes
};

