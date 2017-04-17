#include <iostream>
#include <vector>
#include "Player.h"
#include <conio.h>
#include "Enemy.h"

void RunGame(Map map[], Player &player)
{
	bool run = true; 
	bool LevelLoaded = false;
	char input;
	int currentLevel = 1;
	std::vector<Door> doors;
	std::vector<GenericActor> actors;
	std::vector<Enemy> enemies;
	std::string name;
	std::cout << "Before we proceed, your name?" << std::endl;
	std::cin >> name;
	std::cout << "Perfect. Welcome " << name << std::endl;
	
	while (run)
	{
		if (LevelLoaded != true){
			map[currentLevel-1].ProcessLevel(player, doors, actors, enemies);
			// Clear the vectors before
			LevelLoaded = true;
		}
		if (player.GetHealth() > 0){
			std::cout << "\n\n";
			std::cout << "| " << map[currentLevel - 1].getName() << " | " << std::endl;
			std::cout << "------------------" << std::endl;
			map[currentLevel-1].printLevel();
			std::cout << "You are Level " << player.GetLevel() << std::endl;
			std::cout << "Name: " << name;
			std::cout << "  Health: " << player.GetHealth() << " \\ " << player.GetMaxHP() ;
			std::cout << "  Defense: " << player.GetDefense();
			std::cout << "  Attack Power: " << player.GetAttack() << std::endl;
			std::cout << "Lockpick Skill: " << player.GetSkill() << std::endl;
			std::cout << "XP To Next Level: " << player.GetXP() << " \\ " << player.GetXpTilNextLevel() << std::endl;
			std::cout << "\nQ to quit game\tT to taunt\n";
			input = getch();
			player.LevelUp();
			int prev = currentLevel;
			player.ProcessInput(input, doors, actors, enemies ,map[currentLevel-1], currentLevel);
			if (prev != currentLevel)
			{
				if (doors.size() > 0)
					doors.clear();
				if (actors.size() > 0)
					actors.clear();
				if (enemies.size() > 0)
					enemies.clear();
				map[currentLevel - 1].ProcessLevel(player, doors, actors, enemies);
			}
			for (int i = 0; i < actors.size(); i++)
			{
				actors[i].AI_Loop(map[currentLevel-1]);
				if (actors[i].isDead(map[currentLevel-1]))
					actors.erase(actors.begin() + i);
			}
			for (int i = 0; i < enemies.size(); i++)
			{
				enemies[i].AI_Loop(map[currentLevel-1],player, actors, input);
				if (enemies[i].isDead(map[currentLevel - 1], player))
					enemies.erase(enemies.begin() + i);
			}
		}
		else
		{
			std::cout << "\n\n\n\n\n\n\n\n\n\n";
			std::cout << "Farewell, " << name << " Your legacy will be remembered." << std::endl;
			
			std::ofstream rip(name + "'s legacy.txt");
			rip << name << " Was Level " << player.GetLevel() << " Upon death" << std::endl;
			rip << "You were remembered as a hero" << std::endl;
			rip << "But was slain on his journey for the quest item or something.\n";
			rip << "He bore no noteworthy accomplishments obviously." << std::endl;
			run = false;
		}
	}
	return;
}