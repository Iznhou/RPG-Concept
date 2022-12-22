#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include <ctime>

#include "EnemyCreatorHeader.h"

using namespace std;

EnemyCreator::EnemyCreator(string name, int lvl, int enemyID)
{
	enemyName = name;
	//this->weapon = weapon;
	//characterClass = cClass;
	level = lvl;
}

void EnemyCreator::enemyGenerate()
{
	srand(time(0));

	cout << "**********************" << endl;
	cout << "\nEnemy Name: \n" << endl;
	cout << enemyName << endl;

	cout << "\nWeapon: \n" << endl;
	cout << weapon << endl;

	cout << "\nEnemy Class: \n" << endl;

	if (weapon == "Daggers")
	{
		characterClass = "Slicer";
	}

	else if (weapon == "Sword")
	{
		characterClass = "SwordMaster";
	}

	else if (weapon == "SwordAndShield")
	{
		characterClass = "ShadowKnight";
	}

	else if (weapon == "BowAndArrow")
	{
		characterClass = "Archer";
	}

	else if (weapon == "Axes")
	{
		characterClass = "Berserker";
	}

	else if (weapon == "Gauntlets")
	{
		characterClass = "KnuckleFighter";
	}

	else if (weapon == "Magic")
	{
		characterClass = "ForceBender";
	}

	else
	{
		cout << "Invalid...Unable to create Character" << endl;
		exit(0);
	}

	cout << characterClass << endl;

	cout << "\nLevel: \n" << endl;
	cout << level;

	cout << "\n**********************\n" << endl;
}

EnemyCreator::~EnemyCreator() 
{
	cout << "\a" << endl;
}

