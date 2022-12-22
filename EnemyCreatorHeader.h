#pragma once


#include<string>

using namespace std;

class EnemyCreator
{
	//Private variables
	private:
		string enemyName;
		string weapon;
		string characterClass;
		int level;

	//Public functions and constructor
	public:
		EnemyCreator(string name, int lvl, int enemyID);
		string setEnemyName(string name);
		string setWeapon(string weapon);
		/*string setCharacterClass(string cClass);
		int setCharacterLevel(int lvl);*/

		void enemyGenerate();

		~EnemyCreator();
};

