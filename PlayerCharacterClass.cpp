#include <iostream>
#include <iterator>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include <iomanip>

//Include needed header file
#include "GameCharacterCreatorHeader.h"

using namespace std;

char userInput;

//Class constructor from character creation
GameCharacterCreator::GameCharacterCreator(string name, string selectedClass, int wepID, double lvl, double jLvl)
{
	characterName = name;
	characterClass = selectedClass;
	weaponID = wepID;
	level = lvl;
	jobLevel = jLvl;
	characterRace = "Null";
	feralType = "Null";
	prevClass = "Null";

	rightWeaponArmEquipped = "empty";
	leftWeaponArmEquipped = "empty";

	torsoArmor = "empty";
	legArmor = "empty";
	armBracers = "empty";
	headArmor = "empty";
	sigilEquipped = "empty";

	equippedWeapon = "empty";
	equippedSecondWeapon = "empty";

	weaponLvl = 0;
	secondWeaponLvl = 0;
	armorLvl = 0;
	greavesLvl = 0;
	bracerLvl = 0;
	headLvl = 0;
	sigilLvl = 0;
}

//Class constructor for character upload
GameCharacterCreator::GameCharacterCreator(string name, string currentClass, string wepType, string torsoType, string bracerType, string legArmType, 
	string equippedFWeapon, string equippedSWeapon, string equippedTorso, string equippedHead, string equippedBracer, string equippedLegArmor, string equippedInk,
	string charRace, string rType, double lvl, double jLvl, double cHP, double cSP, double cStr, double cAgi, double cVit, double cInt, double cDex, double cLuk,
	double armorLevel, double headLevel, double armLevel, double legLevel, double firstWepLvl, double secondWepLvl, double inkLvl)
{
	characterName = name;
	characterClass = currentClass;
	characterWeapon = wepType;
	level = lvl;
	jobLevel = jLvl;
	characterRace = charRace;
	feralType = rType;

	armorType = torsoType;
	armType = bracerType;
	legType = legArmType;

	weaponLvl = firstWepLvl;
	secondWeaponLvl = secondWepLvl;

	headLvl = headLevel;
	armorLvl = armorLevel;
	bracerLvl = armLevel;
	greavesLvl = legLevel;

	equippedWeapon = equippedFWeapon;
	equippedSecondWeapon = equippedSWeapon;
	rightWeaponArmEquipped = equippedFWeapon;
	leftWeaponArmEquipped = equippedSWeapon;
	torsoArmor = equippedTorso;
	headArmor = equippedHead;
	armBracers = equippedBracer;
	legArmor = equippedLegArmor;
	sigilEquipped = equippedInk;
	sigilLvl = inkLvl;

	characterHP = cHP;
	characterSP = cSP;
	characterStr = cStr;
	characterAgi = cAgi;
	characterVit = cVit;
	characterInt = cInt;
	characterDex = cDex;
	characterLuk = cLuk;

	if (getCharacterClass() == "Gladiator" || getCharacterClass() == "BladeDancer")
	{
		setPrevClass("Warrior");
	}

	else if (getCharacterClass() == "Alchemist" || getCharacterClass() == "Engineer")
	{
		setPrevClass("Artisan");
	}

	else if (getCharacterClass() == "Monk" || getCharacterClass() == "Dominator")
	{
		setPrevClass("Breaker");
	}

	else if (getCharacterClass() == "Desperado" || getCharacterClass() == "Mercenary")
	{
		setPrevClass("BulletShark");
	}

	else if (getCharacterClass() == "Shinobi" || getCharacterClass() == "Rebel")
	{
		setPrevClass("Renegade");
	}

	else if (getCharacterClass() == "Knight" || getCharacterClass() == "Templar")
	{
		setPrevClass("Guardian");
	}

	else if (getCharacterClass() == "Sorcerer" || getCharacterClass() == "Occulter")
	{
		setPrevClass("EnergyMaster");
	}

	else if (getCharacterClass() == "Raider" || getCharacterClass() == "Savager")
	{
		setPrevClass("Ravager");
	}

	else if (getCharacterClass() == "BeastKaiser" || getCharacterClass() == "ShotMeister")
	{
		setPrevClass("Hunter");
	}

	else if (getCharacterClass() == "SoulWielder" || getCharacterClass() == "Shaman")
	{
		setPrevClass("Sage");
	}

	else if (getCharacterClass() == "ShadowWalker" || getCharacterClass() == "Executioner")
	{
		setPrevClass("Assassin");
	}

	else
	{
		setPrevClass(getCharacterClass());
	}
}

//Default constructor
GameCharacterCreator::GameCharacterCreator()
{

}

//Take information from either used constructor to display character information
void GameCharacterCreator::generate()
{
	cout << "\n**********************" << endl;
	cout << "\nPlayer Character's Name: \n" << endl;
	cout << characterName << endl;

	cout << "\nCharacterWeapon: \n" << endl;
	cout << characterWeapon << endl;

	srand(time(0));

	if (characterClass == "Renegade")
	{
		setCharacterWeapon ("Daggers");
		setArmorType("LightArmor");
		setArmType("Glove");
		setLegType("Boots");
		setHeadType("Mask");

		characterHP = rand() % (100 - 200) + 100;
		characterSP =  rand() % (250 - 200) + 200;
		characterStr = rand() % (300 - 200) + 200;
		characterAgi = rand() % (500 -  450) + 450;
		characterInt = rand() % (200 - 150) + 150;
		characterVit = rand() % (175 - 100) + 100;
		characterDex = rand() % (400 - 350) + 350;
		characterLuk = rand() % (200 - 150) + 150;
	}

	else if (characterClass == "Warrior")
	{
		setCharacterWeapon("Sword");
		setArmorType("LightArmor");
		setArmType("Bracer");
		setLegType("Boots");
		setHeadType("Helmet");
	
		characterHP = rand() % (400 - 150) + 150;
		characterSP = rand() % (450 - 350) + 350;
		characterStr = 1.5 + rand() % (450 - 400) + 400;
		characterAgi = rand() % (300 - 250) +250;
		characterInt = rand() % (150 - 100) + 100;
		characterVit = rand() % (255 - 200) + 200;
		characterDex = rand() % (300 - 250) + 250;
		characterLuk = rand() % (200 - 150) + 150;		
	}

	else if (characterClass == "Artisan")
	{
		setCharacterWeapon("Sword");
		setArmorType("LightArmor");
		setArmType("Bracer");
		setLegType("Boots");
		setHeadType("Helmet");

		characterHP = rand() % (600 - 550) + 550;
		characterSP = rand() % (550 - 500) + 500;
		characterStr = rand() % (450 - 400) + 400;
		characterAgi = rand() % (200 - 150) + 150;
		characterInt = 1.5 + rand() % (750 - 700) + 700;
		characterVit = rand() % (555 - 500) + 500;
		characterDex = rand() % (600 - 550) + 550;
		characterLuk = rand() % (200 - 150) + 150;
	}

	else if (characterClass == "Guardian")
	{
		if (weaponID == 4)
		{
			setCharacterWeapon( "SwordAndShield");
			setArmorType("HeavyArmor");
			setArmType("ArmGuard");
			setLegType("Greaves");
			setHeadType("Helmet");

			characterHP = rand() % (750 - 700) + 700;
			characterSP = rand() % (550 - 500) + 500;
			characterStr = 1.5 + rand() % (650 - 615) + 615;
			characterAgi = rand() % (200 - 150) + 150;
			characterInt = rand() % (350 - 300) + 300;
			characterVit = rand() % (755 - 715) + 715;
			characterDex = rand() % (600 - 550) + 550;
			characterLuk = rand() % (200 - 150) + 150;
		}

		else if (weaponID == 5)
		{
			setCharacterWeapon("GreatSword");
			setArmorType("Heavy Armor");
			setArmType("ArmGuard");
			setLegType("Greaves");
			setHeadType("Helmet");

			characterHP = rand() % (750 - 700) + 700;
			characterSP = rand() % (550 - 500) + 500;
			characterStr = rand() % (650 - 615) + 615;
			characterAgi = rand() % (200 - 150) + 150;
			characterInt = rand() % (350 - 300) + 300;
			characterVit = 2.0 + rand() % (755 - 715) + 715;
			characterDex = rand() % (600 - 550) + 550;
			characterLuk = rand() % (200 - 150) + 150;
		}
	}

	else if (characterClass == "Hunter")
	{
		if (weaponID == 8)
		{
			setCharacterWeapon("BowAndArrow");
			setArmorType("LightArmor");
			setArmType("Bracer");
			setLegType("Boots");
			setHeadType("Helmet");

			characterHP = rand() % (400 - 350) + 350;
			characterSP = rand() % (550 - 500) + 500;
			characterStr = rand() % (450 - 400) + 400;
			characterAgi = 1.5 + rand() % (500 - 450) + 450;
			characterInt = rand() % (350 - 300) + 300;
			characterVit = rand() % (355 - 300) + 300;
			characterDex = rand() % (600 - 575) + 575;
			characterLuk = rand() % (400 - 350) + 350;
		}

		if (weaponID == 9)
		{
			setCharacterWeapon("CrossBow");
			setArmorType("Light Armor");
			setArmType("Bracer");
			setLegType("Boots");
			setHeadType("Helmet");

			characterHP = rand() % (400 - 350) + 350;
			characterSP = rand() % (550 - 500) + 500;
			characterStr = rand() % (450 - 400) + 400;
			characterAgi = rand() % (500 - 450) + 450;
			characterInt = rand() % (350 - 300) + 300;
			characterVit = rand() % (355 - 300) + 300;
			characterDex = 1.5 + rand() % (600 - 575) + 575;
			characterLuk = rand() % (400 - 350) + 350;
		}
	}

	else if (characterClass == "Ravager")
	{
		setCharacterWeapon("Axes");
		setArmorType("HeavyArmor");
		setArmType("ArmGuard");
		setLegType("Greaves");
		setHeadType("Helmet");

		characterHP = rand() % (400 - 350) + 350;
		characterSP = rand() % (500 - 350) + 350;
		characterStr = rand() % (750 - 700) + 700;
		characterAgi = rand() % (400 - 350) + 350;
		characterInt = rand() % (150 - 100) + 100;
		characterVit = rand() % (355 - 300) + 300;
		characterDex = rand() % (400 - 350) + 350;
		characterLuk = rand() % (200 - 150) + 150;
	}

	else if (characterClass == "Breaker")
	{
		setCharacterWeapon("Gauntlets");
		setArmorType( "LightArmor");
		setArmType("Gauntlets");
		setLegType("Boots");
		setHeadType("Bandana");

		characterHP = rand() % (600 - 550) + 550;
		characterSP = rand() % (550 - 500) + 500;
		characterStr = rand() % (750 - 715) + 715;
		characterAgi = rand() % (500 - 450) + 450;
		characterInt = rand() % (450 - 400) + 400;
		characterVit = rand() % (500 - 450) + 450;
		characterDex = rand() % (600 - 550) + 550;
		characterLuk = rand() % (200 - 150) + 150;
	}

	else if (characterClass == "Sage")
	{
		setCharacterWeapon ( "Magic");
		setArmorType("ClothArmor");
		setArmType("Sleeve");
		setLegType("Boots");
		setHeadType("Headdress");

		characterHP = rand() % (700 - 650) + 650;
		characterSP = rand() % (850 - 800) + 800;
		characterStr = rand() % (250 - 200) + 200;
		characterAgi = rand() % (150 - 100) + 100;
		characterInt = rand() % (950 - 925) + 925;
		characterVit = rand() % (700 - 650) + 650;
		characterDex = rand() % (600 - 575) + 575;
		characterLuk = rand() % (200 - 150) + 150;
	}

	else if (characterClass == "BulletShark")
	{
		setCharacterWeapon("Guns");
		setArmorType("LightArmor");
		setArmType("Bracer");
		setLegType("Boots");
		setHeadType("Helmet");

		characterHP = rand() % (400 - 350) + 350;
		characterSP = rand() % (550 - 500) + 500;
		characterStr = rand() % (450 - 400) + 400;
		characterAgi = rand() % (500 - 450) + 450;
		characterInt = rand() % (350 - 300) + 300;
		characterVit = rand() % (355 - 300) + 300;
		characterDex = rand() % (600 - 570) + 570;
		characterLuk = rand() % (400 - 350) + 350;
	}

	else if (characterClass == "Assassin")
	{
		setCharacterWeapon ("Claws");
		setArmorType("LightArmor");
		setArmType("Glove");
		setHeadType("Mask");

		characterHP = rand() % (400 - 350) + 350;
		characterSP = rand() % (350 - 300) + 300;
		characterStr = rand() % (750 - 600) + 600;
		characterAgi = rand() % (750 - 725) + 725;
		characterInt = rand() % (200 - 150) + 150;
		characterVit = rand() % (375 - 300) + 300;
		characterDex = rand() % (500 - 450) + 450;
		characterLuk = rand() % (200 - 150) + 150;
	}

	else if (characterClass == "EnergyMaster")
	{
		setCharacterWeapon ("Bracelet");
		setArmorType("ClothArmor");
		setArmType("Sleeve");
		setLegType("Boots");
		setHeadType("Headdress");

		characterHP = rand() % (500 - 450) + 450;
		characterSP = rand() % (850 - 800) + 800;
		characterStr = rand() % (300 - 250) + 250;
		characterAgi = rand() % (350 - 300) + 300;
		characterInt = rand() % (900 - 875) + 875;
		characterVit = rand() % (775 - 720) + 720;
		characterDex = rand() % (800 - 750) + 750;
		characterLuk = rand() % (200 - 150) + 150;
	}

	else
	{
		cout << "Invalid...Unable to create Character" << endl;
		exit(0);
	}

	cout << "\nPlayer Class: \n" << endl;

	cout << "Class: " << characterClass << endl;

	cout << "\n**********************\n" << endl;

	cout << "\n**********************" << endl;

	cout <<"\n" << characterName << "'s Stats: \n" << endl;
	cout << "Level: " << level << endl;
	cout << "Job Level: " << jobLevel << endl;
	cout << "Health: " << characterHP << endl;
	cout << "Energy: " << characterSP << endl;
	cout << "Strength: " << characterStr << endl;
	cout << "Agility: " << characterAgi << endl;
	cout << "Vitality: " << characterVit << endl;
	cout << "Dexterity: " << characterDex << endl;
	cout << "Intelligence: " << characterInt << endl;
	cout << "Luck: " << characterLuk << endl;

	cout << "\n**********************\n" << endl;
}

/*Generate weapons by opening the appropriate weapon text filesand feed them to dictionaries
* 
In the dictionaries, the key is the weapon and the value is the level; use an iterator to walk through them

If the character can Dual-Wield and/or job level is high enough, allow them to choose a second weapon. 

The first weapon goes into the right hand, second weapon goes into left hand

Finally, set weapon information to appropriate class properties*/
void GameCharacterCreator::generateWeapons()
{
	string weapon;
	string userFirstWeapon;
	string userSecondWeapon;

	double wepLevel;

	if (getCharacterWeapon() == "Daggers")
	{
		unordered_map<string, double> eqDagger;
		unordered_map<string, double> ::iterator iter;

		ifstream eDagger;

		eDagger.open("ClassWeapons-Daggers.txt");

		while (eDagger >> weapon)
		{
			eDagger >> wepLevel;

			eqDagger.insert(pair<string, double>(weapon, wepLevel));
		}

		cout << "\nChoose your first weapon: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqDagger.begin(); iter != eqDagger.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
			cout << endl;
		}

		cout << endl;

		cin >> userFirstWeapon;

		if (eqDagger.find(userFirstWeapon) != eqDagger.end() && level >= eqDagger[userFirstWeapon])
		{
			setEquippedWeapon(userFirstWeapon);
			setWeaponLevel(eqDagger[userFirstWeapon]);
			setRightWeaponArmEquipped(userFirstWeapon);
			setEquipped(true);
		}

		else if (eqDagger.find(userFirstWeapon) != eqDagger.end() && level <= eqDagger[userFirstWeapon])
		{
			cout << "Character Level too low to equip weapon. " << endl;
			exit(0);
		}

		if (jobLevel >= 16 || getCharacterClass() == "Shinobi")
		{
			cout << "\nCharacter is able to Dual-Wield. "
				<< " Choose your second weapon : \n" << endl;

			cin >> userSecondWeapon;

			if (eqDagger.find(userSecondWeapon) != eqDagger.end() && level >= eqDagger[userSecondWeapon])
			{
				setEquippedSecondWeapon(userSecondWeapon);
				setSecondWeaponLevel(eqDagger[userSecondWeapon]);
				setLeftWeaponArmEquipped(userSecondWeapon);
				setEquipped(true);
			}

			else if (eqDagger.find(userSecondWeapon) != eqDagger.end() && level <= eqDagger[userSecondWeapon])
			{
				cout << "Character Level too low to equip weapon. " << endl;
				exit(0);
			}
		}

		eDagger.close();
	}

	else if (getCharacterWeapon() == "Bracelet" || getCharacterWeapon() == "Bracelet & Grimoire")
	{
		unordered_map<string, double> eqMagicWeapon;
		unordered_map<string, double> ::iterator iter;

		ifstream eMagicEquip;

		eMagicEquip.open("ClassWeapons-EnergyMaster.txt");

		while (eMagicEquip >> weapon)
		{
			eMagicEquip >> wepLevel;

			eqMagicWeapon.insert(pair<string, double>(weapon, wepLevel));
		}

		cout << "\nChoose your first weapon: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqMagicWeapon.begin(); iter != eqMagicWeapon.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << endl;
		cin >> userFirstWeapon;

		if (eqMagicWeapon.find(userFirstWeapon) != eqMagicWeapon.end() && level >= eqMagicWeapon[userFirstWeapon])
		{
			setEquippedWeapon(userFirstWeapon);
			setWeaponLevel(eqMagicWeapon[userFirstWeapon]);
			setRightWeaponArmEquipped(userFirstWeapon);
			setEquipped(true);
		}

		else if (eqMagicWeapon.find(userFirstWeapon) != eqMagicWeapon.end() && level <= eqMagicWeapon[userFirstWeapon])
		{
			cout << "Character Level too low to equip weapon. " << endl;
			exit(0);
		}

		if (jobLevel >= 16 || getCharacterWeapon() == "Bracelet & Grimoire")
		{
			cout << "\nCharacter is able to Dual-Wield." 
				<< " Choose your second weapon : \n" << endl;

			cin >> userSecondWeapon;

			if (eqMagicWeapon.find(userSecondWeapon) != eqMagicWeapon.end() && level >= eqMagicWeapon[userSecondWeapon])
			{
				setEquippedSecondWeapon(userSecondWeapon);
				setSecondWeaponLevel(eqMagicWeapon[userSecondWeapon]);
				setLeftWeaponArmEquipped(userSecondWeapon);
				setEquipped(true);

				if (eqMagicWeapon[userSecondWeapon] >= 16)
				{
					setCharacterWeapon("Bracelet & Grimoire");
				}
			}

			else if (eqMagicWeapon.find(userSecondWeapon) != eqMagicWeapon.end() && level <= eqMagicWeapon[userSecondWeapon])
			{
				cout << "Character Level too low to equip weapon. " << endl;
				exit(0);
			}
		}

		eMagicEquip.close();
	}

	else if (getCharacterWeapon() == "Sword" && getCharacterClass() != "BladeDancer")
	{
		unordered_map<string, double> eqWeapon;
		unordered_map<string, double> ::iterator iter;

		ifstream eSwordEquip;

		eSwordEquip.open("ClassWeapons-Swords.txt");

		while (eSwordEquip >> weapon)
		{
			eSwordEquip >> wepLevel;

			eqWeapon.insert(pair<string, double>(weapon, wepLevel));
		}

		cout << "\nChoose your weapon: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqWeapon.begin(); iter != eqWeapon.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << endl;
		cin >> userFirstWeapon;

		if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level >= eqWeapon[userFirstWeapon])
		{
			setEquippedWeapon(userFirstWeapon);
			setWeaponLevel(eqWeapon[userFirstWeapon]);
			setRightWeaponArmEquipped(userFirstWeapon);
			setEquipped(true);
		}

		else if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level <= eqWeapon[userFirstWeapon])
		{
			cout << "Character Level too low to equip weapon. " << endl;
			exit(0);
		}

		eSwordEquip.close();
	}

	else if (getCharacterWeapon() == "Sword" && getCharacterClass() == "BladeDancer")
	{
		unordered_map<string, double> eqWeapon;
		unordered_map<string, double> ::iterator iter;

		ifstream eSwordEquip;

		eSwordEquip.open("ClassWeapons-Swords.txt");

		while (eSwordEquip >> weapon)
		{
			eSwordEquip >> wepLevel;

			eqWeapon.insert(pair<string, double>(weapon, wepLevel));
		}

		cout << "\nChoose your first weapon: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqWeapon.begin(); iter != eqWeapon.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << endl;
		cin >> userFirstWeapon;

		if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level >= eqWeapon[userFirstWeapon])
		{
			setEquippedWeapon(userFirstWeapon);
			setWeaponLevel(eqWeapon[userFirstWeapon]);
			setRightWeaponArmEquipped(userFirstWeapon);
			setEquipped(true);
		}

		else if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level <= eqWeapon[userFirstWeapon])
		{
			cout << "Character Level too low to equip weapon. " << endl;
			exit(0);
		}

		cout << "\nCharacter is able to Dual-Wield."
			<< " Choose your second weapon : \n" << endl;

		cin >> userSecondWeapon;

		if (eqWeapon.find(userSecondWeapon) != eqWeapon.end() && level >= eqWeapon[userSecondWeapon])
		{
			setEquippedSecondWeapon(userSecondWeapon);
			setSecondWeaponLevel(eqWeapon[userSecondWeapon]);
			setLeftWeaponArmEquipped(userSecondWeapon);
			setEquipped(true);
		}

		else if (eqWeapon.find(userSecondWeapon) != eqWeapon.end() && level <= eqWeapon[userSecondWeapon])
		{
			cout << "Character Level too low to equip weapon. " << endl;
			exit(0);
		}

		eSwordEquip.close();
	}

	else if (getCharacterWeapon() == "Spear")
	{
		unordered_map<string, double> eqWeapon;
		unordered_map<string, double> ::iterator iter;

		ifstream eSpearEquip;

		eSpearEquip.open("ClassWeapons-Spears.txt");

		while (eSpearEquip >> weapon)
		{
			eSpearEquip >> wepLevel;

			eqWeapon.insert(pair<string, double>(weapon, wepLevel));
		}

		cout << "\nChoose your weapon: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqWeapon.begin(); iter != eqWeapon.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << endl;
		cin >> userFirstWeapon;

		if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level >= eqWeapon[userFirstWeapon])
		{
			setEquippedWeapon(userFirstWeapon);
			setEquippedSecondWeapon(userFirstWeapon);
			setWeaponLevel(eqWeapon[userFirstWeapon]);
			setSecondWeaponLevel(eqWeapon[userFirstWeapon]);
			setRightWeaponArmEquipped(userFirstWeapon);
			setLeftWeaponArmEquipped(userFirstWeapon);
			setEquipped(true);
		}

		else if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level <= eqWeapon[userFirstWeapon])
		{
			cout << "Character Level too low to equip weapon. " << endl;
			exit(0);
		}

		eSpearEquip.close();
	}

	else if (getCharacterWeapon() == "SwordAndShield" && getCharacterClass() == "Knight")
	{
		unordered_map<string, double> eqWeapon;
		unordered_map<string, double> ::iterator iter;

		unordered_map<string, double> eqShield;
		unordered_map<string, double> ::iterator iter2;

		ifstream eSwordEquip;
		ifstream eShieldsEquip;

		eSwordEquip.open("ClassWeapons-Swords.txt");

		while (eSwordEquip >> weapon)
		{
			eSwordEquip >> wepLevel;

			eqWeapon.insert(pair<string, double>(weapon, wepLevel));
		}

		cout << "\nChoose your first weapon: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqWeapon.begin(); iter != eqWeapon.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << endl;
		cin >> userFirstWeapon;

		if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level >= eqWeapon[userFirstWeapon])
		{
			setEquippedWeapon(userFirstWeapon);
			setWeaponLevel(eqWeapon[userFirstWeapon]);
			setRightWeaponArmEquipped(userFirstWeapon);
			setEquipped(true);
		}

		else if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level <= eqWeapon[userFirstWeapon])
		{
			cout << "Character Level too low to equip weapon. " << endl;
			exit(0);
		}

		eSwordEquip.close();

		eShieldsEquip.open("ClassWeapons-Shields.txt");

		while (eShieldsEquip >> weapon)
		{
			eShieldsEquip >> wepLevel;

			eqShield.insert(pair<string, double>(weapon, wepLevel));
		}

		cout << "\nChoose your Shield: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: " << endl;

		for (iter2 = eqShield.begin(); iter2 != eqShield.end(); ++iter2)
		{
			cout << iter2->first << "\t" << iter2->second << endl << endl;
		}

		cout << "\n" << endl;

		cin >> userSecondWeapon;

		if (eqShield.find(userSecondWeapon) != eqShield.end() && level >= eqShield[userSecondWeapon])
		{
			setEquippedSecondWeapon(userSecondWeapon);
			setSecondWeaponLevel(eqShield[userSecondWeapon]);
			setLeftWeaponArmEquipped(userSecondWeapon);
			setEquipped(true);
		}

		else if (eqShield.find(userSecondWeapon) != eqShield.end() && level <= eqShield[userSecondWeapon])
		{
			cout << "Character Level too low to equip weapon. " << endl;
			exit(0);
		}

		eShieldsEquip.close();
	}

	else if (getCharacterWeapon() == "GreatSword" && getCharacterClass() == "Knight")
	{
		unordered_map<string, double> eqWeapon;
		unordered_map<string, double> ::iterator iter;

		ifstream eGreatSwordsEquip;

		eGreatSwordsEquip.open("ClassWeapons-GreatSwords.txt");

		while (eGreatSwordsEquip >> weapon)
		{
			eGreatSwordsEquip >> wepLevel;

			eqWeapon.insert(pair<string, double>(weapon, wepLevel));
		}

		cout << "\nChoose your weapon: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqWeapon.begin(); iter != eqWeapon.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << "\n" << endl;

		cin >> userFirstWeapon;

		if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level >= eqWeapon[userFirstWeapon])
		{
			setEquippedWeapon(userFirstWeapon);
			setWeaponLevel(eqWeapon[userFirstWeapon]);
			setEquippedSecondWeapon(userFirstWeapon);
			setSecondWeaponLevel(eqWeapon[userFirstWeapon]);
			setRightWeaponArmEquipped(userFirstWeapon);
			setLeftWeaponArmEquipped(userFirstWeapon);
			setEquipped(true);
		}

		else if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level <= eqWeapon[userFirstWeapon])
		{
			cout << "Character Level too low to equip weapon. " << endl;
			exit(0);
		}

		eGreatSwordsEquip.close();
	}

	else if (getCharacterWeapon() == "SwordAndShield" && getCharacterClass() == "Templar")
	{
		unordered_map<string, double> eqWeapon;
		unordered_map<string, double> ::iterator iter;

		unordered_map<string, double> eqShield;
		unordered_map<string, double> ::iterator iter2;

		ifstream eSwordEquip;
		ifstream eShieldsEquip;

		eSwordEquip.open("ClassWeapons-Swords.txt");

		while (eSwordEquip >> weapon)
		{
			eSwordEquip >> wepLevel;

			eqWeapon.insert(pair<string, double>(weapon, wepLevel));
		}

		cout << "\nChoose your first weapon: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqWeapon.begin(); iter != eqWeapon.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << endl;
		cin >> userFirstWeapon;

		if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level >= eqWeapon[userFirstWeapon])
		{
			setEquippedWeapon(userFirstWeapon);
			setWeaponLevel(eqWeapon[userFirstWeapon]);
			setRightWeaponArmEquipped(userFirstWeapon);
			setEquipped(true);
		}

		else if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level <= eqWeapon[userFirstWeapon])
		{
			cout << "Character Level too low to equip weapon. " << endl;
			exit(0);
		}

		eSwordEquip.close();

		eShieldsEquip.open("ClassWeapons-Shields.txt");

		while (eShieldsEquip >> weapon)
		{
			eShieldsEquip >> wepLevel;

			eqShield.insert(pair<string, double>(weapon, wepLevel));
		}

		cout << "\nChoose your Shield: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: " << endl;

		for (iter2 = eqShield.begin(); iter2 != eqShield.end(); ++iter2)
		{
			cout << iter2->first << "\t" << iter2->second << endl << endl;
		}

		cout << "\n" << endl;

		cin >> userSecondWeapon;

		if (eqShield.find(userSecondWeapon) != eqShield.end() && level >= eqShield[userSecondWeapon])
		{
			setEquippedSecondWeapon(userSecondWeapon);
			setSecondWeaponLevel(eqShield[userSecondWeapon]);
			setLeftWeaponArmEquipped(userSecondWeapon);
			setEquipped(true);
		}

		else if (eqShield.find(userSecondWeapon) != eqShield.end() && level <= eqShield[userSecondWeapon])
		{
			cout << "Character Level too low to equip weapon. " << endl;
			exit(0);
		}

		eShieldsEquip.close();
	}

	else if (getCharacterWeapon() == "GreatSword" && getCharacterClass() == "Templar")
	{
		unordered_map<string, double> eqWeapon;
		unordered_map<string, double> ::iterator iter;

		ifstream eGreatSwordsEquip;

		eGreatSwordsEquip.open("ClassWeapons-GreatSwords.txt");

		while (eGreatSwordsEquip >> weapon)
		{
			eGreatSwordsEquip >> wepLevel;

			eqWeapon.insert(pair<string, double>(weapon, wepLevel));
		}

		cout << "\nChoose your weapon: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqWeapon.begin(); iter != eqWeapon.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << "\n" << endl;

		cin >> userFirstWeapon;

		if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level >= eqWeapon[userFirstWeapon])
		{
			setEquippedWeapon(userFirstWeapon);
			setWeaponLevel(eqWeapon[userFirstWeapon]);
			setEquippedSecondWeapon(userFirstWeapon);
			setSecondWeaponLevel(eqWeapon[userFirstWeapon]);
			setRightWeaponArmEquipped(userFirstWeapon);
			setLeftWeaponArmEquipped(userFirstWeapon);
			setEquipped(true);
		}

		else if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level <= eqWeapon[userFirstWeapon])
		{
			cout << "Character Level too low to equip weapon. " << endl;
			exit(0);
		}

		eGreatSwordsEquip.close();
	}

	else if (getCharacterWeapon() == "CrossBow" && getCharacterClass() == "ShotMeister")
	{
		unordered_map<string, double> eqWeapon;
		unordered_map<string, double> ::iterator iter;

		ifstream eCrossBowsEquip;

		eCrossBowsEquip.open("ClassWeapons-CrossBows.txt");

		while (eCrossBowsEquip >> weapon)
		{
			eCrossBowsEquip >> wepLevel;

			eqWeapon.insert(pair<string, double>(weapon, wepLevel));
		}

		cout << "\nChoose your first weapon: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqWeapon.begin(); iter != eqWeapon.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << "\n" << endl;

		cin >> userFirstWeapon;

		if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level >= eqWeapon[userFirstWeapon])
		{
			setEquippedWeapon(userFirstWeapon);
			setEquippedSecondWeapon(userFirstWeapon);
			setWeaponLevel(eqWeapon[userFirstWeapon]);
			setSecondWeaponLevel(eqWeapon[userFirstWeapon]);
			setRightWeaponArmEquipped(userFirstWeapon);
			setLeftWeaponArmEquipped(userFirstWeapon);
			setEquipped(true);
		}

		else if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level <= eqWeapon[userFirstWeapon])
		{
			cout << "Character Level too low to equip weapon. " << endl;
			exit(0);
		}

		eCrossBowsEquip.close();
	}

	else if (getCharacterWeapon() == "BowAndArrow" && getCharacterClass() == "ShotMeister")
	{
		unordered_map<string, double> eqWeapon;
		unordered_map<string, double> ::iterator iter;

		ifstream eBowsEquip;

		eBowsEquip.open("ClassWeapons-Bows.txt");

		while (eBowsEquip >> weapon)
		{
			eBowsEquip >> wepLevel;

			eqWeapon.insert(pair<string, double>(weapon, wepLevel));
		}

		cout << "\nChoose your first weapon: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqWeapon.begin(); iter != eqWeapon.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << "\n" << endl;

		cin >> userFirstWeapon;

		if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level >= eqWeapon[userFirstWeapon])
		{
			setEquippedWeapon(userFirstWeapon);
			setEquippedSecondWeapon(userFirstWeapon);
			setWeaponLevel(eqWeapon[userFirstWeapon]);
			setSecondWeaponLevel(eqWeapon[userFirstWeapon]);
			setRightWeaponArmEquipped(userFirstWeapon);
			setLeftWeaponArmEquipped(userFirstWeapon);
			setEquipped(true);
		}

		else if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level <= eqWeapon[userFirstWeapon])
		{
			cout << "Character Level too low to equip weapon. " << endl;
			exit(0);
		}

		eBowsEquip.close();
	}

	else if (getCharacterWeapon() == "CrossBow" && getCharacterClass() == "BeastKaiser")
	{
		unordered_map<string, double> eqWeapon;
		unordered_map<string, double> ::iterator iter;

		ifstream eCrossBowsEquip;

		eCrossBowsEquip.open("ClassWeapons-CrossBows.txt");

		while (eCrossBowsEquip >> weapon)
		{
			eCrossBowsEquip >> wepLevel;

			eqWeapon.insert(pair<string, double>(weapon, wepLevel));
		}

		cout << "\nChoose your first weapon: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqWeapon.begin(); iter != eqWeapon.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << "\n" << endl;

		cin >> userFirstWeapon;

		if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level >= eqWeapon[userFirstWeapon])
		{
			setEquippedWeapon(userFirstWeapon);
			setEquippedSecondWeapon(userFirstWeapon);
			setWeaponLevel(eqWeapon[userFirstWeapon]);
			setSecondWeaponLevel(eqWeapon[userFirstWeapon]);
			setRightWeaponArmEquipped(userFirstWeapon);
			setLeftWeaponArmEquipped(userFirstWeapon);
			setEquipped(true);
		}

		else if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level <= eqWeapon[userFirstWeapon])
		{
			cout << "Character Level too low to equip weapon. " << endl;
			exit(0);
		}

		eCrossBowsEquip.close();
	}

	else if (getCharacterWeapon() == "BowAndArrow" && getCharacterClass() == "BeastKaiser")
	{
		unordered_map<string, double> eqWeapon;
		unordered_map<string, double> ::iterator iter;

		ifstream eBowsEquip;

		eBowsEquip.open("ClassWeapons-Bows.txt");

		while (eBowsEquip >> weapon)
		{
			eBowsEquip >> wepLevel;

			eqWeapon.insert(pair<string, double>(weapon, wepLevel));
		}

		cout << "\nChoose your first weapon: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqWeapon.begin(); iter != eqWeapon.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << "\n" << endl;

		cin >> userFirstWeapon;

		if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level >= eqWeapon[userFirstWeapon])
		{
			setEquippedWeapon(userFirstWeapon);
			setEquippedSecondWeapon(userFirstWeapon);
			setWeaponLevel(eqWeapon[userFirstWeapon]);
			setSecondWeaponLevel(eqWeapon[userFirstWeapon]);
			setRightWeaponArmEquipped(userFirstWeapon);
			setLeftWeaponArmEquipped(userFirstWeapon);
			setEquipped(true);
		}

		else if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level <= eqWeapon[userFirstWeapon])
		{
			cout << "Character Level too low to equip weapon. " << endl;
			exit(0);
		}

		eBowsEquip.close();
	}

	else if (getCharacterWeapon() == "Guns")
	{
		unordered_map<string, double> eqWeapon;
		unordered_map<string, double> ::iterator iter;

		ifstream eGunsEquip;

		eGunsEquip.open("ClassWeapons-Guns.txt");

		while (eGunsEquip >> weapon)
		{
			eGunsEquip >> wepLevel;

			eqWeapon.insert(pair<string, double>(weapon, wepLevel));
		}

		cout << "\nChoose your first weapon: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqWeapon.begin(); iter != eqWeapon.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << endl;
		cin >> userFirstWeapon;

		if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level >= eqWeapon[userFirstWeapon])
		{
			equippedWeapon = userFirstWeapon;
			equippedSecondWeapon = userFirstWeapon;
			weaponLvl = eqWeapon[userFirstWeapon];
			secondWeaponLvl = eqWeapon[userFirstWeapon];
			rightWeaponArmEquipped = userFirstWeapon;
			leftWeaponArmEquipped = userFirstWeapon;
			equipped = true;
		}

		else if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level <= eqWeapon[userFirstWeapon])
		{
			cout << "Character Level too low to equip weapon. " << endl;
			exit(0);
		}

		eGunsEquip.close();
	}

	else if (getCharacterWeapon() == "Gauntlets")
	{
		unordered_map<string, double> eqWeapon;
		unordered_map<string, double> ::iterator iter;

		ifstream eGauntletsEquip;

		eGauntletsEquip.open("ClassWeapons-Gauntlets.txt");

		while (eGauntletsEquip >> weapon)
		{
			eGauntletsEquip >> wepLevel;

			eqWeapon.insert(pair<string, double>(weapon, wepLevel));
		}

		cout << "\nChoose your first weapon: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqWeapon.begin(); iter != eqWeapon.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << endl;
		cin >> userFirstWeapon;

		if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level >= eqWeapon[userFirstWeapon])
		{
			equippedWeapon = userFirstWeapon;
			equippedSecondWeapon = userFirstWeapon;
			armBracers = userFirstWeapon;
			weaponLvl = eqWeapon[userFirstWeapon];
			secondWeaponLvl = eqWeapon[userFirstWeapon];
			bracerLvl = eqWeapon[userFirstWeapon];
			rightWeaponArmEquipped = userFirstWeapon;
			leftWeaponArmEquipped = userFirstWeapon;
			equipped = true;
		}

		else if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level <= eqWeapon[userFirstWeapon])
		{
			cout << "Character Level too low to equip weapon. " << endl;
			exit(0);
		}

		eGauntletsEquip.close();
	}

	else if (getCharacterClass() == "Hunter")
	{
		if (weaponID == 8)
		{
			unordered_map<string, double> eqWeapon;
			unordered_map<string, double> ::iterator iter;

			ifstream eBowsEquip;

			eBowsEquip.open("ClassWeapons-Bows.txt");

			while (eBowsEquip >> weapon)
			{
				eBowsEquip >> wepLevel;

				eqWeapon.insert(pair<string, double>(weapon, wepLevel));
			}

			cout << "\nChoose your first weapon: \n" << endl;

			cin.ignore().get();

			cout << "Weapon: " << "    Level: \n" << endl;

			for (iter = eqWeapon.begin(); iter != eqWeapon.end(); ++iter)
			{
				cout << iter->first << "\t" << iter->second << endl << endl;
			}

			cout << "\n" << endl;

			cin >> userFirstWeapon;

			if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level >= eqWeapon[userFirstWeapon])
			{
				setEquippedWeapon(userFirstWeapon);
				setEquippedSecondWeapon(userFirstWeapon);
				setWeaponLevel(eqWeapon[userFirstWeapon]);
				setSecondWeaponLevel(eqWeapon[userFirstWeapon]);
				setRightWeaponArmEquipped(userFirstWeapon);
				setLeftWeaponArmEquipped(userFirstWeapon);
				setEquipped(true);
			}

			else if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level <= eqWeapon[userFirstWeapon])
			{
				cout << "Character Level too low to equip weapon. " << endl;
				exit(0);
			}

			eBowsEquip.close();
		}

		else if (weaponID == 9)
		{
			unordered_map<string, double> eqWeapon;
			unordered_map<string, double> ::iterator iter;

			ifstream eCrossBowsEquip;

			eCrossBowsEquip.open("ClassWeapons-CrossBows.txt");

			while (eCrossBowsEquip >> weapon)
			{
				eCrossBowsEquip >> wepLevel;

				eqWeapon.insert(pair<string, double>(weapon, wepLevel));
			}

			cout << "\nChoose your first weapon: \n" << endl;

			cin.ignore().get();

			cout << "Weapon: " << "    Level: \n" << endl;

			for (iter = eqWeapon.begin(); iter != eqWeapon.end(); ++iter)
			{
				cout << iter->first << "\t" << iter->second << endl <<endl;
			}

			cout << "\n" << endl;

			cin >> userFirstWeapon;

			if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level >= eqWeapon[userFirstWeapon])
			{
				setEquippedWeapon (userFirstWeapon);
				setEquippedSecondWeapon(userFirstWeapon);
				setWeaponLevel(eqWeapon[userFirstWeapon]);
				setSecondWeaponLevel(eqWeapon[userFirstWeapon]);
				setRightWeaponArmEquipped(userFirstWeapon);
				setLeftWeaponArmEquipped(userFirstWeapon);
				setEquipped(true);
			}

			else if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level <= eqWeapon[userFirstWeapon])
			{
				cout << "Character Level too low to equip weapon. " << endl;
				exit(0);
			}

			eCrossBowsEquip.close();
		}

	}

	else if (getCharacterClass() == "Guardian")
	{
		if (weaponID == 4)
		{
			unordered_map<string, double> eqWeapon;
			unordered_map<string, double> ::iterator iter;

			unordered_map<string, double> eqShield;
			unordered_map<string, double> ::iterator iter2;

			ifstream eSwordsEquip;
			ifstream eShieldsEquip;

			eSwordsEquip.open("ClassWeapons-Swords.txt");

			while (eSwordsEquip >> weapon)
			{
				eSwordsEquip >> wepLevel;

				eqWeapon.insert(pair<string, double>(weapon, wepLevel));
			}

			cout << "\nChoose your first weapon: \n" << endl;

			cin.ignore().get();

			cout << "Weapon: " << "    Level: " << endl;

			for (iter = eqWeapon.begin(); iter != eqWeapon.end(); ++iter)
			{
				cout << iter->first << "\t" << iter->second << endl << endl;
			}

			cout << "\n" << endl;

			cin >> userFirstWeapon;

			if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level >= eqWeapon[userFirstWeapon])
			{
				setEquippedWeapon(userFirstWeapon);
				setWeaponLevel(eqWeapon[userFirstWeapon]);
				setRightWeaponArmEquipped(userFirstWeapon);
				setEquipped(true);
			}

			else if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level <= eqWeapon[userFirstWeapon])
			{
				cout << "Character Level too low to equip weapon. " << endl;
				exit(0);
			}

			eSwordsEquip.close();

			eShieldsEquip.open("ClassWeapons-Shields.txt");

			while (eShieldsEquip >> weapon)
			{
				eShieldsEquip >> wepLevel;

				eqShield.insert(pair<string, double>(weapon, wepLevel));
			}

			cout << "\nChoose your Shield: \n" << endl;

			cin.ignore().get();

			cout << "Weapon: " << "    Level: " << endl;

			for (iter2 = eqShield.begin(); iter2 != eqShield.end(); ++iter2)
			{
				cout << iter2->first << "\t" << iter2->second << endl << endl;
			}

			cout << "\n" << endl;

			cin >> userSecondWeapon;

			if (eqShield.find(userSecondWeapon) != eqShield.end() && level >= eqShield[userSecondWeapon])
			{
				setEquippedSecondWeapon(userSecondWeapon);
				setSecondWeaponLevel(eqShield[userSecondWeapon]);
				setLeftWeaponArmEquipped(userSecondWeapon);
				setEquipped(true);
			}

			else if (eqShield.find(userSecondWeapon) != eqShield.end() && level <= eqShield[userSecondWeapon])
			{
				cout << "Character Level too low to equip weapon. " << endl;
				exit(0);
			}

			eShieldsEquip.close();
		}

		else if (weaponID == 5)
		{
			unordered_map<string, double> eqWeapon;
			unordered_map<string, double> ::iterator iter;

			ifstream eGreatSwordsEquip;

			eGreatSwordsEquip.open("ClassWeapons-GreatSwords.txt");

			while (eGreatSwordsEquip >> weapon)
			{
				eGreatSwordsEquip >> wepLevel;

				eqWeapon.insert(pair<string, double>(weapon, wepLevel));
			}

			cout << "\nChoose your weapon: \n" << endl;

			cout << "Weapon: " << "    Level: \n" << endl;

			for (iter = eqWeapon.begin(); iter != eqWeapon.end(); ++iter)
			{
				cout << iter->first << "\t" << iter->second << endl << endl;
			}

			cout << "\n" << endl;

			cin >> userFirstWeapon;

			if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level >= eqWeapon[userFirstWeapon])
			{
				setEquippedWeapon(userFirstWeapon);
				setWeaponLevel(eqWeapon[userFirstWeapon]);
				setEquippedSecondWeapon(userFirstWeapon);
				setSecondWeaponLevel(eqWeapon[userFirstWeapon]);
				setRightWeaponArmEquipped(userFirstWeapon);
				setLeftWeaponArmEquipped(userFirstWeapon);
				setEquipped(true);
			}

			else if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level <= eqWeapon[userFirstWeapon])
			{
				cout << "Character Level too low to equip weapon. " << endl;
				exit(0);
			}

			eGreatSwordsEquip.close();
		}
	}

	else if (getCharacterWeapon() == "Claws")
	{
		unordered_map<string, double> eqWeapon;
		unordered_map<string, double> ::iterator iter;

		ifstream eClawsEquip;

		eClawsEquip.open("ClassWeapons-Claws.txt");

		while (eClawsEquip >> weapon)
		{
			eClawsEquip >> wepLevel;

			eqWeapon.insert(pair<string, double>(weapon, wepLevel));
		}

		cout << "\nChoose your first weapon: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqWeapon.begin(); iter != eqWeapon.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << "\n" << endl;

		cin >> userFirstWeapon;

		if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level >= eqWeapon[userFirstWeapon])
		{
			setEquippedWeapon(userFirstWeapon);
			setEquippedSecondWeapon(userFirstWeapon);
			setWeaponLevel(eqWeapon[userFirstWeapon]);
			setSecondWeaponLevel(eqWeapon[userFirstWeapon]);
			setRightWeaponArmEquipped(userFirstWeapon);
			setLeftWeaponArmEquipped(userFirstWeapon);
			setEquipped(true);
		}

		else if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level <= eqWeapon[userFirstWeapon])
		{
			cout << "Character Level too low to equip weapon. " << endl;
			exit(0);
		}

		eClawsEquip.close();
	}

	else if (getCharacterWeapon() == "Magic")
	{
		unordered_map<string, double> eqWeapon;
		unordered_map<string, double> ::iterator iter;

		unordered_map<string, double> eqShield;
		unordered_map<string, double> ::iterator iter2;

		ifstream eStavesEquip;
		ifstream eShieldsEquip;

		eStavesEquip.open("ClassWeapons-Staves.txt");

		while (eStavesEquip >> weapon)
		{
			eStavesEquip >> wepLevel;

			eqWeapon.insert(pair<string, double>(weapon, wepLevel));
		}

		cout << "\nChoose your first weapon: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqWeapon.begin(); iter != eqWeapon.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << "\n" << endl;

		cin >> userFirstWeapon;

		if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level >= eqWeapon[userFirstWeapon])
		{
			setEquippedWeapon(userFirstWeapon);
			setWeaponLevel(eqWeapon[userFirstWeapon]);
			setRightWeaponArmEquipped(userFirstWeapon);
			setEquipped(true);
		}

		else if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level <= eqWeapon[userFirstWeapon])
		{
			cout << "Character Level too low to equip weapon. " << endl;
			exit(0);
		}

		eStavesEquip.close();

		eShieldsEquip.open("ClassWeapons-Shields.txt");

		while (eShieldsEquip >> weapon)
		{
			eShieldsEquip >> wepLevel;

			eqShield.insert(pair<string, double>(weapon, wepLevel));
		}

		cout << "\nChoose your Shield: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter2 = eqShield.begin(); iter2 != eqShield.end(); ++iter2)
		{
			cout << iter2->first << "\t" << iter2->second << endl << endl;
		}

		cout << "\n" << endl;

		cin >> userSecondWeapon;

		if (eqShield.find(userSecondWeapon) != eqShield.end() && level >= eqShield[userSecondWeapon])
		{
			setEquippedSecondWeapon(userSecondWeapon);
			setSecondWeaponLevel(eqShield[userSecondWeapon]);
			setLeftWeaponArmEquipped(userSecondWeapon);
			setEquipped(true);
		}

		else if (eqShield.find(userSecondWeapon) != eqShield.end() && level <= eqShield[userSecondWeapon])
		{
			cout << "Character Level too low to equip weapon. " << endl;
			exit(0);
		}

		eShieldsEquip.close();
	}

	else if (getCharacterWeapon() == "Axes")
	{
		unordered_map<string, double> eqWeapon;
		unordered_map<string, double> ::iterator iter;

		ifstream eAxes;

		eAxes.open("ClassWeapons-Axes.txt");

		while (eAxes >> weapon)
		{
			eAxes >> wepLevel;

			eqWeapon.insert(pair<string, double>(weapon, wepLevel));
		}

		cout << "\nChoose your first weapon: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqWeapon.begin(); iter != eqWeapon.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << endl;

		cin >> userFirstWeapon;

		if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level >= eqWeapon[userFirstWeapon])
		{
			setEquippedWeapon (userFirstWeapon);
			setWeaponLevel(eqWeapon[userFirstWeapon]);
			setRightWeaponArmEquipped(userFirstWeapon);
			setEquipped(true);
		}

		else if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level <= eqWeapon[userFirstWeapon])
		{
			cout << "Character Level too low to equip weapon. " << endl;
			exit(0);
		}

		if (jobLevel >= 16)
		{
			cout << "\nChoose your second weapon: \n" << endl;

			cin >> userSecondWeapon;

			if (eqWeapon.find(userSecondWeapon) != eqWeapon.end() && level >= eqWeapon[userSecondWeapon])
			{
				setEquippedSecondWeapon(userSecondWeapon);
				setSecondWeaponLevel(eqWeapon[userSecondWeapon]);
				setLeftWeaponArmEquipped(userSecondWeapon);
				setEquipped(true);
			}

			else if (eqWeapon.find(userSecondWeapon) != eqWeapon.end() && level <= eqWeapon[userSecondWeapon])
			{
				cout << "Character Level too low to equip weapon. " << endl;
				exit(0);
			}
		}

		eAxes.close();

	}

	else if (getCharacterWeapon() == "FumaShuriken")
	{
		unordered_map<string, double> eqWeapon;
		unordered_map<string, double> ::iterator iter;

		ifstream eShurikenEquip;

		eShurikenEquip.open("ClassWeapons-Shuriken.txt");

		while (eShurikenEquip >> weapon)
		{
			eShurikenEquip >> wepLevel;

			eqWeapon.insert(pair<string, double>(weapon, wepLevel));
		}

		cout << "\nChoose your weapon: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqWeapon.begin(); iter != eqWeapon.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << "\n" << endl;

		cin >> userFirstWeapon;

		if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level >= eqWeapon[userFirstWeapon])
		{
			setEquippedWeapon(userFirstWeapon);
			setEquippedSecondWeapon(userFirstWeapon);
			setWeaponLevel(eqWeapon[userFirstWeapon]);
			setSecondWeaponLevel(eqWeapon[userFirstWeapon]);
			setRightWeaponArmEquipped(userFirstWeapon);
			setLeftWeaponArmEquipped(userFirstWeapon);
			setEquipped(true);
		}

		else if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level <= eqWeapon[userFirstWeapon])
		{
			cout << "Character Level too low to equip weapon. " << endl;
			exit(0);
		}

		eShurikenEquip.close();
	}

	/*else if (characterClass == "Artisan")
	{
		unordered_map<string, double> eqWeapon;
		unordered_map<string, double> ::iterator iter;

		ifstream eSwordEquip;

		eSwordEquip.open("ClassWeapons-Swords.txt");

		while (eSwordEquip >> weapon)
		{
			eSwordEquip >> wepLevel;

			eqWeapon.insert(pair<string, double>(weapon, wepLevel));
		}

		cout << "\nChoose your first weapon: \n" << endl;

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqWeapon.begin(); iter != eqWeapon.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl;
		}

		cout << endl;

		cin >> userFirstWeapon;

		if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level >= eqWeapon[userFirstWeapon])
		{
			equippedWeapon = userFirstWeapon;
			weaponLvl = eqWeapon[userFirstWeapon];
			rightWeaponArmEquipped = userFirstWeapon;
			equipped = true;
		}

		else if (eqWeapon.find(userFirstWeapon) != eqWeapon.end() && level <= eqWeapon[userFirstWeapon])
		{
			cout << "Character Level too low to equip weapon. " << endl;
			exit(0);
		}

		eSwordEquip.close();
	}*/
}

/*Generate Torso Armor by opening the appropriate armor text filesand feed them to dictionaries
*
In the dictionaries, the key is the armor and the value is the level; use an iterator to walk through them

Finally, set armor information to appropriate class properties*/
void GameCharacterCreator::generateEquippedTorso()
{
	string armor;

	string userArmor;

	double arLevel;

	if (getCharacterWeapon() == "Sword" || 
		getCharacterWeapon() == "Gauntlets" || 
		getCharacterWeapon() == "Guns" ||
		getCharacterWeapon() == "BowAndArrow" ||
		getCharacterWeapon() == "CrossBow")
	{
		unordered_map<string, double> eqArmor;
		unordered_map<string, double> ::iterator iter;

		ifstream classArmor;

		classArmor.open("ClassArmor-WarArtBrkerBSH.txt");

		while (classArmor >> armor)
		{

			classArmor >> arLevel;

			eqArmor.insert(pair<string, double>(armor, arLevel));
		}

		cout << "\nChoose your armor: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqArmor.begin(); iter != eqArmor.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << endl;

		cin >> userArmor;

		if (eqArmor.find(userArmor) != eqArmor.end() && level >= eqArmor[userArmor])
		{
			setTorsoEquipped(userArmor);
			setArmorLevel(eqArmor[userArmor]);
		}

		else if (eqArmor.find(userArmor) != eqArmor.end() && level <= eqArmor[userArmor])
		{
			cout << "Character Level too low to equip armor. " << endl;
			exit(0);
		}
	}

	else if (getCharacterWeapon() == "Bracelet" ||
		getCharacterWeapon() == "Magic" || 
		getCharacterWeapon() == "Bracelet & Grimoire")
	{
		unordered_map<string, double> eqArmor;
		unordered_map<string, double> ::iterator iter;

		ifstream classArmor;

		classArmor.open("ClassArmor-EMSage.txt");

		while (classArmor >> armor)
		{
			classArmor >> arLevel;

			eqArmor.insert(pair<string, double>(armor, arLevel));
		}

		cout << "\nChoose your Armor: \n" << endl;

		cin.ignore().get();
		
		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqArmor.begin(); iter != eqArmor.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl <<endl;
		}

		cout << endl;

		cin >> userArmor;

		if (eqArmor.find(userArmor) != eqArmor.end() && level >= eqArmor[userArmor])
		{
			setTorsoEquipped(userArmor);
			setArmorLevel(eqArmor[userArmor]);
		}

		else if (eqArmor.find(userArmor) != eqArmor.end() && level <= eqArmor[userArmor])
		{
			cout << "Character Level too low to equip armor. " << endl;
			exit(0);
		}
	}

	else if (characterWeapon == "Claws" || characterWeapon == "Daggers")
	{
		unordered_map<string, double> eqArmor;
		unordered_map<string, double> ::iterator iter;

		ifstream classArmor;

		classArmor.open("ClassArmor-AssassinRenegade.txt");

		while (classArmor >> armor)
		{
			classArmor >> arLevel;

			eqArmor.insert(pair<string, double>(armor, arLevel));
		}

		cout << "\nChoose your Armor: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqArmor.begin(); iter != eqArmor.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << endl;

		cin >> userArmor;

		if (eqArmor.find(userArmor) != eqArmor.end() && level >= eqArmor[userArmor])
		{
			setTorsoEquipped(userArmor);
			setArmorLevel(eqArmor[userArmor]);
		}

		else if (eqArmor.find(userArmor) != eqArmor.end() && level <= eqArmor[userArmor])
		{
			cout << "Character Level too low to equip armor. " << endl;
			exit(0);
		}
	}

	else if (characterWeapon == "Axes")
	{
		unordered_map<string, double> eqArmor;
		unordered_map<string, double> ::iterator iter;

		ifstream classArmor;

		classArmor.open("ClassArmor-Ravager.txt");

		while (classArmor >> armor)
		{
			classArmor >> arLevel;

			eqArmor.insert(pair<string, double>(armor, arLevel));
		}

		cout << "\nChoose your Armor: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqArmor.begin(); iter != eqArmor.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << endl;

		cin >> userArmor;

		if (eqArmor.find(userArmor) != eqArmor.end() && level >= eqArmor[userArmor])
		{
			setTorsoEquipped(userArmor);
			setArmorLevel(eqArmor[userArmor]);
		}

		else if (eqArmor.find(userArmor) != eqArmor.end() && level <= eqArmor[userArmor])
		{
			cout << "Character Level too low to equip armor. " << endl;
			exit(0);
		}
	}

	else if (characterWeapon == "GreatSword" || characterWeapon == "SwordAndShield")
	{
		unordered_map<string, double> eqArmor;
		unordered_map<string, double> ::iterator iter;

		ifstream classArmor;

		classArmor.open("ClassArmor-Guardian.txt");

		while (classArmor >> armor)
		{
			classArmor >> arLevel;

			eqArmor.insert(pair<string, double>(armor, arLevel));
		}

		cout << "\nChoose your Armor: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqArmor.begin(); iter != eqArmor.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << endl;

		cin >> userArmor;

		if (eqArmor.find(userArmor) != eqArmor.end() && level >= eqArmor[userArmor])
		{
			setTorsoEquipped(userArmor);
			setArmorLevel(eqArmor[userArmor]);
		}

		else if (eqArmor.find(userArmor) != eqArmor.end() && level <= eqArmor[userArmor])
		{
			cout << "Character Level too low to equip armor. " << endl;
			exit(0);
		}
	}
}

/*Generate Head Armor by opening the appropriate head armor text filesand feed them to dictionaries
*
In the dictionaries, the key is the head armor and the value is the level; use an iterator to walk through them

Finally, set armor information to appropriate class properties.

Same applies to ArmBracer and Leg Armor and Sigil*/
void GameCharacterCreator::generateHeadGear()
{
	string headGear;

	string userArmor;

	double hgLevel;

	if (characterWeapon == "Gauntlets")
	{
		unordered_map<string, double> eqHeadGear;
		unordered_map<string, double> ::iterator iter;

		ifstream classHeadGear;

		classHeadGear.open("ClassHeadGear-Breaker.txt");

		while (classHeadGear >> headGear)
		{
			classHeadGear >> hgLevel;

			eqHeadGear.insert(pair<string, double>(headGear, hgLevel));
		}

		cout << "\nChoose your Bandana: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqHeadGear.begin(); iter != eqHeadGear.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl <<endl;
		}

		cout << endl;

		cin >> userArmor;

		if (eqHeadGear.find(userArmor) != eqHeadGear.end() && level >= eqHeadGear[userArmor])
		{
			setHeadArmor(userArmor);
			setHeadArmorLvl(eqHeadGear[userArmor]);
		}

		else if (eqHeadGear.find(userArmor) != eqHeadGear.end() && level <= eqHeadGear[userArmor])
		{
			cout << "Character Level too low to equip armor. " << endl;
			exit(0);
		}
	}

	else if (characterWeapon == "Daggers" || characterWeapon == "Claws")
	{
		unordered_map<string, double> eqHeadGear;
		unordered_map<string, double> ::iterator iter;

		ifstream classHeadGear;

		classHeadGear.open("ClassHeadGear-AssassinRenegade.txt");

		while (classHeadGear >> headGear)
		{
			classHeadGear >> hgLevel;

			eqHeadGear.insert(pair<string, double>(headGear, hgLevel));
		}

		cout << "\nChoose your Mask: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqHeadGear.begin(); iter != eqHeadGear.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << endl;

		cin >> userArmor;

		if (eqHeadGear.find(userArmor) != eqHeadGear.end() && level >= eqHeadGear[userArmor])
		{
			setHeadArmor(userArmor);
			setHeadArmorLvl(eqHeadGear[userArmor]);
		}

		else if (eqHeadGear.find(userArmor) != eqHeadGear.end() && level <= eqHeadGear[userArmor])
		{
			cout << "Character Level too low to equip armor. " << endl;
			exit(0);
		}
	}

	else if (characterWeapon == "GreatSword" || characterWeapon == "SwordAndShield")
	{
		unordered_map<string, double> eqHeadGear;
		unordered_map<string, double> ::iterator iter;

		ifstream classHeadGear;

		classHeadGear.open("ClassHeadGear-Guardian.txt");

		while (classHeadGear >> headGear)
		{
			classHeadGear >> hgLevel;

			eqHeadGear.insert(pair<string, double>(headGear, hgLevel));
		}

		cout << "\nChoose your Helmet: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqHeadGear.begin(); iter != eqHeadGear.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << endl;

		cin >> userArmor;

		if (eqHeadGear.find(userArmor) != eqHeadGear.end() && level >= eqHeadGear[userArmor])
		{
			setHeadArmor(userArmor);
			setHeadArmorLvl(eqHeadGear[userArmor]);
		}

		else if (eqHeadGear.find(userArmor) != eqHeadGear.end() && level <= eqHeadGear[userArmor])
		{
			cout << "Character Level too low to equip armor. " << endl;
			exit(0);
		}
	}

	else if (characterWeapon == "Sword" || characterWeapon == "Guns")
	{
		unordered_map<string, double> eqHeadGear;
		unordered_map<string, double> ::iterator iter;

		ifstream classHeadGear;

		classHeadGear.open("ClassHeadGear-WarArtBS.txt");

		while (classHeadGear >> headGear)
		{
			classHeadGear >> hgLevel;

			eqHeadGear.insert(pair<string, double>(headGear, hgLevel));
		}

		cout << "\nChoose your Helmet: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqHeadGear.begin(); iter != eqHeadGear.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << endl;

		cin >> userArmor;

		if (eqHeadGear.find(userArmor) != eqHeadGear.end() && level >= eqHeadGear[userArmor])
		{
			setHeadArmor(userArmor);
			setHeadArmorLvl(eqHeadGear[userArmor]);
		}

		else if (eqHeadGear.find(userArmor) != eqHeadGear.end() && level <= eqHeadGear[userArmor])
		{
			cout << "Character Level too low to equip armor. " << endl;
			exit(0);
		}
	}

	else if (characterWeapon == "CrossBow" || characterWeapon == "BowAndArrow")
	{
		unordered_map<string, double> eqHeadGear;
		unordered_map<string, double> ::iterator iter;

		ifstream classHeadGear;

		classHeadGear.open("ClassHeadGear-Hunter.txt");

		while (classHeadGear >> headGear)
		{
			classHeadGear >> hgLevel;

			eqHeadGear.insert(pair<string, double>(headGear, hgLevel));
		}

		cout << "\nChoose your Helmet: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqHeadGear.begin(); iter != eqHeadGear.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << endl;

		cin >> userArmor;

		if (eqHeadGear.find(userArmor) != eqHeadGear.end() && level >= eqHeadGear[userArmor])
		{
			setHeadArmor (userArmor);
			setHeadArmorLvl(eqHeadGear[userArmor]);
		}

		else if (eqHeadGear.find(userArmor) != eqHeadGear.end() && level <= eqHeadGear[userArmor])
		{
			cout << "Character Level too low to equip armor. " << endl;
			exit(0);
		}
	}

	else if (characterWeapon == "Magic" || characterWeapon == "Bracelet" || getCharacterWeapon() == "Bracelet & Grimoire")
	{
		unordered_map<string, double> eqHeadGear;
		unordered_map<string, double> ::iterator iter;

		ifstream classHeadGear;

		classHeadGear.open("ClassHeadGear-EMSage.txt");

		while (classHeadGear >> headGear)
		{
			classHeadGear >> hgLevel;

			eqHeadGear.insert(pair<string, double>(headGear, hgLevel));
		}

		cout << "\nChoose your Headdress: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqHeadGear.begin(); iter != eqHeadGear.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << endl;

		cin >> userArmor;

		if (eqHeadGear.find(userArmor) != eqHeadGear.end() && level >= eqHeadGear[userArmor])
		{
			setHeadArmor(userArmor);
			setHeadArmorLvl(eqHeadGear[userArmor]);
		}

		else if (eqHeadGear.find(userArmor) != eqHeadGear.end() && level <= eqHeadGear[userArmor])
		{
			cout << "Character Level too low to equip armor. " << endl;
			exit(0);
		}
	}

	else if (characterWeapon == "Axes")
	{
		unordered_map<string, double> eqHeadGear;
		unordered_map<string, double> ::iterator iter;

		ifstream classHeadGear;

		classHeadGear.open("ClassHeadGear-Ravager.txt");

		while (classHeadGear >> headGear)
		{
			classHeadGear >> hgLevel;

			eqHeadGear.insert(pair<string, double>(headGear, hgLevel));
		}

		cout << "\nChoose your Helmet: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqHeadGear.begin(); iter != eqHeadGear.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << endl;

		cin >> userArmor;

		if (eqHeadGear.find(userArmor) != eqHeadGear.end() && level >= eqHeadGear[userArmor])
		{
			setHeadArmor(userArmor);
			setHeadArmorLvl(eqHeadGear[userArmor]);
		}

		else if (eqHeadGear.find(userArmor) != eqHeadGear.end() && level <= eqHeadGear[userArmor])
		{
			cout << "Character Level too low to equip armor. " << endl;
			exit(0);
		}
	}

	else if (characterWeapon == "Sword")
	{
		unordered_map<string, double> eqHeadGear;
		unordered_map<string, double> ::iterator iter;

		ifstream classHeadGear;

		classHeadGear.open("ClassHeadGear-WarArtBSH.txt");

		while (classHeadGear >> headGear)
		{
			classHeadGear >> hgLevel;

			eqHeadGear.insert(pair<string, double>(headGear, hgLevel));
		}

		cout << "\nChoose your Helmet: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqHeadGear.begin(); iter != eqHeadGear.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << endl;

		cin >> userArmor;

		if (eqHeadGear.find(userArmor) != eqHeadGear.end() && level >= eqHeadGear[userArmor])
		{
			setHeadArmor(userArmor);
			setHeadArmorLvl(eqHeadGear[userArmor]);
		}

		else if (eqHeadGear.find(userArmor) != eqHeadGear.end() && level <= eqHeadGear[userArmor])
		{
			cout << "Character Level too low to equip armor. " << endl;
			exit(0);
		}
	}
}

void GameCharacterCreator::generateArmBracer()
{
	string bracer;

	string userBracer;

	double brLevel;

	if (characterWeapon == "Daggers" || characterWeapon == "Claws")
	{
		unordered_map<string, double> eqBracer;
		unordered_map<string, double> ::iterator iter;

		ifstream classBracer;

		classBracer.open("ClassBracers-AssassinRenegade.txt");

		while (classBracer >> bracer)
		{
			classBracer >> brLevel;

			eqBracer.insert(pair<string, double>(bracer, brLevel));
		}

		cout << "\nChoose your Glove: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqBracer.begin(); iter != eqBracer.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << endl;

		cin >> userBracer;

		if (eqBracer.find(userBracer) != eqBracer.end() && level >= eqBracer[userBracer])
		{
			setArmBracer(userBracer);
			setBracerLvl(eqBracer[userBracer]);
		}

		else if (eqBracer.find(userBracer) != eqBracer.end() && level <= eqBracer[userBracer])
		{
			cout << "Character Level too low to equip. " << endl;
			exit(0);
		}
	}

	else if (characterWeapon == "GreatSword" || characterWeapon == "SwordAndShield")
	{
		unordered_map<string, double> eqBracer;
		unordered_map<string, double> ::iterator iter;

		ifstream classBracer;

		classBracer.open("ClassBracers-Guardian.txt");

		while (classBracer >> bracer)
		{
			classBracer >> brLevel;

			eqBracer.insert(pair<string, double>(bracer, brLevel));
		}

		cout << "\nChoose your ArmGuard: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqBracer.begin(); iter != eqBracer.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << endl;

		cin >> userBracer;

		if (eqBracer.find(userBracer) != eqBracer.end() && level >= eqBracer[userBracer])
		{
			setArmBracer(userBracer);
			setBracerLvl(eqBracer[userBracer]);
		}

		else if (eqBracer.find(userBracer) != eqBracer.end() && level <= eqBracer[userBracer])
		{
			cout << "Character Level too low to equip. " << endl;
			exit(0);
		}
	}

	else if (characterWeapon == "Axes")
	{
		unordered_map<string, double> eqBracer;
		unordered_map<string, double> ::iterator iter;

		ifstream classBracer;

		classBracer.open("ClassBracers-Ravager.txt");

		while (classBracer >> bracer)
		{
			classBracer >> brLevel;

			eqBracer.insert(pair<string, double>(bracer, brLevel));
		}

		cout << "\nChoose your ArmGuard: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqBracer.begin(); iter != eqBracer.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << endl;

		cin >> userBracer;

		if (eqBracer.find(userBracer) != eqBracer.end() && level >= eqBracer[userBracer])
		{
			setArmBracer(userBracer);
			setBracerLvl(eqBracer[userBracer]);
		}

		else if (eqBracer.find(userBracer) != eqBracer.end() && level <= eqBracer[userBracer])
		{
			cout << "Character Level too low to equip. " << endl;
			exit(0);
		}
	}

	else if (characterWeapon == "BowAndArrow" || characterWeapon == "CrossBow")
	{
		unordered_map<string, double> eqBracer;
		unordered_map<string, double> ::iterator iter;

		ifstream classBracer;

		classBracer.open("ClassBracers-Hunter.txt");

		while (classBracer >> bracer)
		{
			classBracer >> brLevel;

			eqBracer.insert(pair<string, double>(bracer, brLevel));
		}

		cout << "\nChoose your Bracer: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqBracer.begin(); iter != eqBracer.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << endl;

		cin >> userBracer;

		if (eqBracer.find(userBracer) != eqBracer.end() && level >= eqBracer[userBracer])
		{
			setArmBracer(userBracer);
			setBracerLvl(eqBracer[userBracer]);
		}

		else if (eqBracer.find(userBracer) != eqBracer.end() && level <= eqBracer[userBracer])
		{
			cout << "Character Level too low to equip. " << endl;
			exit(0);
		}
	}

	else if (characterWeapon == "Sword" || characterWeapon == "Guns")
	{
		unordered_map<string, double> eqBracer;
		unordered_map<string, double> ::iterator iter;

		ifstream classBracer;

		classBracer.open("ClassBracers-WarArtBS.txt");

		while (classBracer >> bracer)
		{
			classBracer >> brLevel;

			eqBracer.insert(pair<string, double>(bracer, brLevel));
		}

		cout << "\nChoose your Bracer: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqBracer.begin(); iter != eqBracer.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << endl;

		cin >> userBracer;

		if (eqBracer.find(userBracer) != eqBracer.end() && level >= eqBracer[userBracer])
		{
			setArmBracer(userBracer);
			setBracerLvl(eqBracer[userBracer]);
		}

		else if (eqBracer.find(userBracer) != eqBracer.end() && level <= eqBracer[userBracer])
		{
			cout << "Character Level too low to equip. " << endl;
			exit(0);
		}
	}

	else if (characterWeapon == "Bracelet" || characterWeapon == "Magic" || getCharacterWeapon() == "Bracelet & Grimoire")
	{
		unordered_map<string, double> eqSleeve;
		unordered_map<string, double> ::iterator iter;

		ifstream classSleeve;

		classSleeve.open("ClassBracers-EMSage.txt");

		while (classSleeve >> bracer)
		{
			classSleeve >> brLevel;

			eqSleeve.insert(pair<string, double>(bracer, brLevel));
		}

		cout << "\nChoose your Bracer: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqSleeve.begin(); iter != eqSleeve.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << endl;

		cin >> userBracer;

		if (eqSleeve.find(userBracer) != eqSleeve.end() && level >= eqSleeve[userBracer])
		{
			setArmBracer(userBracer);
			setBracerLvl(eqSleeve[userBracer]);
		}

		else if (eqSleeve.find(userBracer) != eqSleeve.end() && level <= eqSleeve[userBracer])
		{
			cout << "Character Level too low to equip. " << endl;
			exit(0);
		}
	}
}

void GameCharacterCreator::generateLegArmor()
{
	string userLegs;
	string boots;

	double legLvl;

	if (getCharacterWeapon() == "Sword" ||
		getCharacterWeapon() == "Guns" ||
		getCharacterWeapon() == "Gauntlets" ||
		getCharacterWeapon() == "Magic" ||
		getCharacterWeapon() == "Bracelet" ||
		getCharacterWeapon() == "BowAndArrow" ||
		getCharacterWeapon() == "CrossBow" ||
		getCharacterWeapon() == "Bracelet & Grimoire")
	{
		setLegType("Boots");

		unordered_map<string, double> eqLegArmor;
		unordered_map<string, double> ::iterator iter;

		ifstream classBoots;

		classBoots.open("ClassLegArmor-WarArtBSHEMSage.txt");

		while (classBoots >> boots)
		{
			classBoots >> legLvl;

			eqLegArmor.insert(pair<string, double>(boots, legLvl));
		}

		cout << "\nChoose your Boots: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqLegArmor.begin(); iter != eqLegArmor.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << endl;

		cin >> userLegs;

		if (eqLegArmor.find(userLegs) != eqLegArmor.end() && level >= eqLegArmor[userLegs])
		{
			setLegArmor(userLegs);
			setLegArmorLvl(eqLegArmor[userLegs]);
		}

		else if (eqLegArmor.find(userLegs) != eqLegArmor.end() && level <= eqLegArmor[userLegs])
		{
			cout << "Character Level too low to equip. " << endl;
			exit(0);
		}
	}

	else if (getCharacterWeapon() == "Axes")
	{
		unordered_map<string, double> eqLegArmor;
		unordered_map<string, double> ::iterator iter;

		ifstream classGreaves;

		classGreaves.open("ClassLegArmor-Ravager.txt");

		while (classGreaves >> boots)
		{
			classGreaves >> legLvl;

			eqLegArmor.insert(pair<string, double>(boots, legLvl));
		}

		cout << "\nChoose your Greaves: \n" << endl;

		cin.ignore().get();

		cout << "Weapon: " << "    Level: \n" << endl;

		for (iter = eqLegArmor.begin(); iter != eqLegArmor.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << endl;

		cin >> userLegs;

		if (eqLegArmor.find(userLegs) != eqLegArmor.end() && level >= eqLegArmor[userLegs])
		{
			setLegArmor(userLegs);
			setLegArmorLvl(eqLegArmor[userLegs]);
		}

		else if (eqLegArmor.find(userLegs) != eqLegArmor.end() && level <= eqLegArmor[userLegs])
		{
			cout << "Character Level too low to equip. " << endl;
			exit(0);
		}
	}

	else if (getCharacterWeapon() == "Daggers" || getCharacterWeapon() == "Claws")
	{
		unordered_map<string, double> eqLegArmor;
		unordered_map<string, double> ::iterator iter;

		ifstream classBoots;

		classBoots.open("ClassLegArmor-AssassinRenegade.txt");

		while (classBoots >> boots)
		{
			classBoots >> legLvl;

			eqLegArmor.insert(pair<string, double>(boots, legLvl));
		}

		cout << "\nChoose your Boots: \n" << endl;

		cin.ignore().get();

		cout << "Boots: " << "    Level: \n" << endl;

		for (iter = eqLegArmor.begin(); iter != eqLegArmor.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << endl;

		cin >> userLegs;

		if (eqLegArmor.find(userLegs) != eqLegArmor.end() && level >= eqLegArmor[userLegs])
		{
			setLegArmor(userLegs);
			setLegArmorLvl(eqLegArmor[userLegs]);
		}

		else if (eqLegArmor.find(userLegs) != eqLegArmor.end() && level <= eqLegArmor[userLegs])
		{
			cout << "Character Level too low to equip. " << endl;
			exit(0);
		}
	}

	else if (getCharacterWeapon() == "GreatSword" || getCharacterWeapon() == "SwordAndShield")
	{
		unordered_map<string, double> eqLegArmor;
		unordered_map<string, double> ::iterator iter;

		ifstream classGreaves;

		classGreaves.open("ClassLegArmor-Guardian.txt");

		while (classGreaves >> boots)
		{
			classGreaves >> legLvl;

			eqLegArmor.insert(pair<string, double>(boots, legLvl));
		}

		cout << "\nChoose your Greaves: \n" << endl;

		cin.ignore().get();

		cout << "Greaves: " << "    Level: \n" << endl;

		for (iter = eqLegArmor.begin(); iter != eqLegArmor.end(); ++iter)
		{
			cout << iter->first << "\t" << iter->second << endl << endl;
		}

		cout << endl;

		cin >> userLegs;

		if (eqLegArmor.find(userLegs) != eqLegArmor.end() && level >= eqLegArmor[userLegs])
		{
			setLegArmor(userLegs);
			setLegArmorLvl(eqLegArmor[userLegs]);
		}

		else if (eqLegArmor.find(userLegs) != eqLegArmor.end() && level <= eqLegArmor[userLegs])
		{
			cout << "Character Level too low to equip. " << endl;
			exit(0);
		}
	}
}

void GameCharacterCreator::generateSigil()
{
	string sigil;
	string usersigil;
	
	double sigilLvl;

	unordered_map<string, double> eqsigil;
	unordered_map<string, double> ::iterator iter;

	ifstream esigil;

	esigil.open("CharacterSigil.txt");

	while (esigil >> sigil)
	{
		esigil >> sigilLvl;

		eqsigil.insert(pair<string, double>(sigil, sigilLvl));
	}

	cout << "\nChoose your Sigil: \n" << endl;

	cout << "Sigil: " << "    Level: \n" << endl;

	for (iter = eqsigil.begin(); iter != eqsigil.end(); ++iter)
	{
		cout << iter->first << "\t" << iter->second << endl << endl;
	}

	cout << endl;
	cin >> usersigil;

	if (eqsigil.find(usersigil) != eqsigil.end() && level >= eqsigil[usersigil])
	{
		setSigilEquipped(usersigil);
		setSigilLvl(eqsigil[usersigil]);
		setEquipped(true);
	}

	else if (eqsigil.find(usersigil) != eqsigil.end() && level <= eqsigil[usersigil])
	{
		cout << "Character Level too low to equip. " << endl;
		exit(0);
	}

	//Close file
	esigil.close();
}

/*Generate character race by opening characte race text file 
and feed the contents into string vector. 
Then assign each race a number for the player to choose*/
void GameCharacterCreator::generateRace()
{
	int userRace;
	int userType;
	const int arraySize = 5;

	string race;

	string raceType[arraySize];

	vector<string> characterRaces;

	ifstream playerRace;

	playerRace.open("CharacterRaces.txt");

	while (playerRace >> race)
	{
		characterRaces.push_back(race);
	}

	cout << "\nSelect your race: " << endl;
	cin.ignore().get();

	for (int i = 0; i < characterRaces.size() / 2; ++i)
	{
		cout << i << " - " << characterRaces[i] << " | ";
	}

	cout << "\n\n";

	for (int i = characterRaces.size () /2; i < characterRaces.size(); ++i)
	{
		cout << i << " - " << characterRaces[i] << " | ";
	}

	cout << "\n\n";

	cin >> userRace;

	//Assign race to character depending on the number
	if (userRace == 0)
	{
		setCharacterRace(characterRaces[0]);
	}

	else if (userRace == 1)
	{
		setCharacterRace(characterRaces[1]);
	}

	else if (userRace == 2)
	{
		setCharacterRace(characterRaces[2]);
	}

	else if (userRace == 3)
	{
		setCharacterRace(characterRaces[3]);
	}

	else if (userRace == 4)
	{
		setCharacterRace(characterRaces[4]);
	}

	else if (userRace == 5)
	{
		setCharacterRace(characterRaces[5]);
	}

	/*If the chosen character race is Feral, 
	player enters another number to determine what type of Feral*/
	else if (userRace == 6)
	{
		setCharacterRace(characterRaces[6]);

		raceType[0] = "Canine";
		raceType[1] = "Feline";
		raceType[2] = "Reptile";
		raceType[3] = "Amphibian";
		raceType[4] = "Avian";

		cout << endl;

		for (int i = 0; i < 2; ++i)
		{
			cout <<"| " << i << " - " << raceType[i] << " |" <<" ";
		}

		cout << endl << endl;

		for (int i = 2; i < arraySize; ++i)
		{
			cout <<"| " << i << " - " << raceType[i] << " |" << " ";
		}

		cout << "\n\nWhat type of Feral?" << endl;
		cin >> userType;

		if (userType == 0)
		{
			setFeralType(raceType[0]);
		}

		else if (userType == 1)
		{
			setFeralType(raceType[1]);
		}

		else if (userType == 2)
		{
			setFeralType(raceType[2]);
		}

		else if (userType == 3)
		{
			setFeralType(raceType[3]);
		}

		else if (userType == 4)
		{
			setFeralType(raceType[4]);
		}
	}

	//Close file
	playerRace.close();
}

// Character Info Getters

bool GameCharacterCreator::getEquipped()
{
	return equipped;
}

double GameCharacterCreator::getLevel()
{
	return level;
}

double GameCharacterCreator::getJobLevel()
{
	return jobLevel;
}

string GameCharacterCreator::getName()
{
	return characterName;
}

string GameCharacterCreator::getCharacterClass()
{
	return characterClass;
}

string GameCharacterCreator::getCharacterRace()
{
	return characterRace;
}

string GameCharacterCreator::getFeralType()
{
	return feralType;
}

string GameCharacterCreator::getPrevClass()
{
	return prevClass;
}

//Character Equipment Getters
string GameCharacterCreator::getEquippedWeapon()
{
	return equippedWeapon;
}

string GameCharacterCreator::getCharacterWeapon()
{
	return characterWeapon;
}

string GameCharacterCreator::getArmorType()
{
	return armorType;
}

string GameCharacterCreator::getHeadType()
{
	return headType;
}

string GameCharacterCreator::getArmType()
{
	return armType;
}

string GameCharacterCreator::getLegType()
{
	return legType;
}

string GameCharacterCreator::getRightWeaponArmEquipped()
{
	return rightWeaponArmEquipped;
}

string GameCharacterCreator::getLeftWeaponArmEquipped()
{
	return leftWeaponArmEquipped;
}

string GameCharacterCreator::getLegArmor()
{
	return legArmor;
}

string GameCharacterCreator::getTorsoArmor()
{
	return torsoArmor;
}

string GameCharacterCreator::getHeadArmor()
{
	return headArmor;
}

string GameCharacterCreator::getSigilEquipped()
{
	return sigilEquipped;
}

string GameCharacterCreator::getArmBracer()
{
	return armBracers;
}

string GameCharacterCreator::getEquippedSecondWeapon()
{
	return equippedSecondWeapon;
}

//Character Stat Getters
double GameCharacterCreator::getCharacterHP()
{
	return characterHP;
}

double GameCharacterCreator::getCharacterSP()
{
	return characterSP;
}

double GameCharacterCreator::getCharacterStr()
{
	return characterStr;
}

double GameCharacterCreator::getCharacterAgi()
{
	return characterAgi;
}

double GameCharacterCreator::getCharacterVit()
{
	return characterVit;
}

double GameCharacterCreator::getCharacterInt()
{
	return characterInt;
}

double GameCharacterCreator::getCharacterDex()
{
	return characterDex;
}

double GameCharacterCreator::getCharacterLuk()
{
	return characterLuk;
}

double GameCharacterCreator::getWeaponLevel()
{
	return weaponLvl;
}

double GameCharacterCreator::getSecondWeaponLevel()
{
	return secondWeaponLvl;
}

double GameCharacterCreator::getArmorLvl()
{
	return armorLvl;
}

double GameCharacterCreator::getHeadArmorLvl()
{
	return headLvl;
}

double GameCharacterCreator::getLegArmorLvl()
{
	return greavesLvl;
}

double GameCharacterCreator::getArmBracerLvl()
{
	return bracerLvl;
}

double GameCharacterCreator::getSigilLvl()
{
	return sigilLvl;
}

//Stat Setters

//Character Info
void GameCharacterCreator::setEquippedWeapon(string eWep)
{
	equippedWeapon = eWep;
}

void GameCharacterCreator::setEquippedSecondWeapon(string eWep2)
{
	equippedSecondWeapon = eWep2;
}

void GameCharacterCreator::setEquipped(bool charEquipped)
{
	equipped = charEquipped;
}

void GameCharacterCreator::setCharacterClass(string cls)
{
	characterClass = cls;
}

void GameCharacterCreator::setCharacterRace(string cRace)
{
	characterRace = cRace;
}

void GameCharacterCreator::setFeralType(string fType)
{
	feralType = fType;
}

void GameCharacterCreator::setCharacterWeapon(string weapon)
{
	characterWeapon = weapon;
}

void GameCharacterCreator::setLevel(double lvl)
{
	level = lvl;
}

void GameCharacterCreator::setJobLevel(double jLvl)
{
	jobLevel = jLvl;
}

void GameCharacterCreator::setPrevClass(string fClass)
{
	prevClass = fClass;
}

//Character Equipment
void GameCharacterCreator::setArmorType(string aType)
{
	armorType = aType;
}

void GameCharacterCreator::setHeadType(string hType)
{
	headType = hType;
}

void GameCharacterCreator::setArmType(string arType)
{
	armType = arType;
}

void GameCharacterCreator::setLegType(string lType)
{
	legType = lType;
}

void GameCharacterCreator::setRightWeaponArmEquipped(string rEquip)
{
	rightWeaponArmEquipped = rEquip;
}

void GameCharacterCreator::setLeftWeaponArmEquipped(string lEquip)
{
	leftWeaponArmEquipped = lEquip;
}

void GameCharacterCreator::setTorsoEquipped(string eTorso)
{
	torsoArmor = eTorso;
}

void GameCharacterCreator::setLegArmor(string lArmor)
{
	legArmor = lArmor;
}

void GameCharacterCreator::setHeadArmor(string hArmor)
{
	headArmor = hArmor;
}

void GameCharacterCreator::setArmBracer(string aBracer)
{
	armBracers = aBracer;
}

void GameCharacterCreator::setSigilEquipped(string sgl)
{
	sigilEquipped = sgl;
}

void GameCharacterCreator::setWeaponLevel(double wepLvl)
{
	weaponLvl = wepLvl;
}

void GameCharacterCreator::setSecondWeaponLevel(double secondWepLvl)
{
	secondWeaponLvl = secondWepLvl;
}

void GameCharacterCreator::setHeadArmorLvl(double hArmLvl)
{
	headLvl = hArmLvl;
}

void GameCharacterCreator::setBracerLvl(double armBrLvl)
{
	bracerLvl = armBrLvl;
}

void GameCharacterCreator::setArmorLevel(double arLvl)
{
	armorLvl = arLvl;
}

void GameCharacterCreator::setLegArmorLvl(double legLvl)
{
	greavesLvl = legLvl;
}

void GameCharacterCreator::setSigilLvl(double sLvl)
{
	sigilLvl = sLvl;
}

//Character Stats
void GameCharacterCreator::setcharacterHP(double HP)
{
	characterHP = HP;
}

void GameCharacterCreator::setcharacterSP(double SP)
{
	characterSP = SP;
}

void GameCharacterCreator::setCharacterStr(double Str)
{
	characterStr = Str;
}

void GameCharacterCreator::setCharacterAgi(double Agi)
{
	characterAgi = Agi;
}

void GameCharacterCreator::setCharacterVit(double Vit)
{
	characterVit = Vit;
}

void GameCharacterCreator::setCharacterInt(double Int)
{
	characterInt = Int;
}

void GameCharacterCreator::setCharacterDex(double Dex)
{
	characterDex = Dex;
}

void GameCharacterCreator::setCharacterLuk(double Luk)
{
	characterLuk = Luk;
}

/*Assign each class their skills by opening the appropriate class skill text file
And feed them into an array and display them*/
void GameCharacterCreator::setClassSkills()
{
	string skill;

	if (characterWeapon == "Sword")
	{
		if (characterClass == "Warrior")
		{
			ifstream WarriorSkills;

			WarriorSkills.open("ClassSkills-Warrior.txt");

			cout << "\nAvailable Skills for the " << characterClass <<":\n " << endl;

			for(int i = 0; i < 6; ++i)
			{
				WarriorSkills >> firstClassSkills[i];
			}

			for (int i = 0; i < 3; ++i)
			{
				cout << firstClassSkills[i] << " ";
			}

			cout << endl << endl;

			for (int i = 3; i < 6; ++i)
			{
				cout << firstClassSkills[i] << " ";
			}

			cout << endl;

			WarriorSkills.close();
		}

		else if (characterClass == "Artisan")
		{
			ifstream ArtisanSkills;

			ArtisanSkills.open("ClassSkills-Artisan.txt");

			cout << "\nAvailable Skills for the " << characterClass << ":\n " << endl;

			for (int i = 0; i < 6; ++i)
			{
				ArtisanSkills >> firstClassSkills[i];
			}

			for (int i = 0; i < 3; ++i)
			{
				cout << firstClassSkills[i] << " ";
			}

			cout << endl << endl;

			for (int i = 3; i < 6; ++i)
			{
				cout << firstClassSkills[i] << " ";
			}

			cout << endl;

			ArtisanSkills.close();
		}
	}
	
	if (characterWeapon == "Daggers")
	{
		ifstream RenegadeSkills;

		RenegadeSkills.open("ClassSkills-Renegade.txt");

		cout << "\nAvailable Skills for the " << characterClass << ":\n " << endl;

		/*while (RenegadeSkills >> skill)
		{
			renegadeClassSkills.push_back(skill);
		}

		for (int i = 0; i < renegadeClassSkills.size() / 2; ++i)
		{
			cout << renegadeClassSkills[i] << " ";
		}
		cout << "\n\n";

		for (int i = renegadeClassSkills.size() / 2; i < renegadeClassSkills.size(); ++i)
		{
			cout << renegadeClassSkills[i] << " ";
		}*/

		for (int i = 0; i < 7; ++i)
		{
			RenegadeSkills >> renegadeClassSkills[i];
		}

		for (int i = 0; i <= 3; ++i)
		{
			cout << renegadeClassSkills[i] << " ";
		}

		cout << endl << endl;

		for (int i = 3; i <= 6; ++i)
		{
			cout << renegadeClassSkills[i] << " ";
		}

		cout << endl;

		RenegadeSkills.close();
	}

	else if (characterWeapon == "Gauntlets")
	{
		ifstream BreakerSkills;

		BreakerSkills.open("ClassSkills-Breaker.txt");

		cout << "\nAvailable Skills for the " << characterClass << ":\n " << endl;

		for (int i = 0; i < 6; ++i)
		{
			BreakerSkills >> firstClassSkills[i];
		}

		for (int i = 0; i < 3; ++i)
		{
			cout << firstClassSkills[i] << " ";
		}

		cout << endl << endl;

		for (int i = 3; i < 6; ++i)
		{
			cout << firstClassSkills[i] << " ";
		}

		cout << endl;

		BreakerSkills.close();
	}

	else if (characterWeapon == "Claws")
	{
		ifstream AssassinSkills;

		AssassinSkills.open("ClassSkills-Assassin.txt");

		cout << "\nAvailable Skills for the " << characterClass << ":\n " << endl;

		for (int i = 0; i < 6; ++i)
		{
			AssassinSkills >> firstClassSkills[i];
		}

		for (int i = 0; i < 3; ++i)
		{
			cout << firstClassSkills[i] << " ";
		}

		cout << endl << endl;

		for (int i = 3; i < 6; ++i)
		{
			cout << firstClassSkills[i] << " ";
		}

		cout << endl;

		AssassinSkills.close();
	}

	else if (characterWeapon == "Guns")
	{
		ifstream BulletSharkSkills;

		BulletSharkSkills.open("ClassSkills-BulletShark.txt");

		cout << "\nAvailable Skills for the " << characterClass << ":\n " << endl;

		for (int i = 0; i < 6; ++i)
		{
			BulletSharkSkills >> firstClassSkills[i];
		}

		for (int i = 0; i < 3; ++i)
		{
			cout << firstClassSkills[i] << " ";
		}

		cout << endl << endl;

		for (int i = 3; i < 6; ++i)
		{
			cout << firstClassSkills[i] << " ";
		}

		cout << endl;

		BulletSharkSkills.close();
	}

	else if (characterWeapon == "Bracelet")
	{
		ifstream EnergyMasterSkills;

		EnergyMasterSkills.open("ClassSkills-EnergyMaster.txt");

		cout << "\nAvailable Skills for the " << characterClass << ":\n " << endl;

		for (int i = 0; i <= 7; ++i)
		{
			EnergyMasterSkills >> energyMasterClassSkills[i];
		}

		for (int i = 0; i <= 4; ++i)
		{
			cout << energyMasterClassSkills[i] << " ";
		}

		cout << endl << endl;

		for (int i = 5; i <= 7; ++i)
		{
			cout << energyMasterClassSkills[i] << " ";
		}

		cout << endl;

		EnergyMasterSkills.close();
	}

	else if (characterWeapon == "SwordAndShield" || characterWeapon == "GreatSword")
	{
		ifstream GuardianSkills;

		GuardianSkills.open("ClassSkills-Guardian.txt");

		cout << "\nAvailable Skills for the " << characterClass << ":\n " << endl;

		for (int i = 0; i < 6; ++i)
		{
			GuardianSkills >> firstClassSkills[i];
		}

		for (int i = 0; i < 3; ++i)
		{
			cout << firstClassSkills[i] << " ";
		}

		cout << endl << endl;

		for (int i = 3; i < 6; ++i)
		{
			cout << firstClassSkills[i] << " ";
		}

		cout << endl;

		GuardianSkills.close();
	}

	else if (characterWeapon == "BowAndArrow" || characterWeapon == "CrossBow")
	{
		ifstream HunterSkills;

		HunterSkills.open("ClassSkills-Hunter.txt");

		cout << "\nAvailable Skills for the " << characterClass << ":\n " << endl;

		for (int i = 0; i < 6; ++i)
		{
			HunterSkills >> firstClassSkills[i];
		}

		for (int i = 0; i < 3; ++i)
		{
			cout << firstClassSkills[i] << " ";
		}

		cout << endl << endl;

		for (int i = 3; i < 6; ++i)
		{
			cout << firstClassSkills[i] << " ";
		}

		cout << endl;

		HunterSkills.close();
	}

	else if (characterWeapon == "Axes")
	{
		ifstream RavagerSkills;

		RavagerSkills.open("ClassSkills-Ravager.txt");

		cout << "\nAvailable Skills for the " << characterClass << ":\n " << endl;

		for (int i = 0; i < 6; ++i)
		{
			RavagerSkills >> firstClassSkills[i];
		}

		for (int i = 0; i < 3; ++i)
		{
			cout << firstClassSkills[i] << " ";
		}

		cout << endl << endl;

		for (int i = 3; i < 6; ++i)
		{
			cout << firstClassSkills[i] << " ";
		}

		cout << endl;

		RavagerSkills.close();
	}

	else if (characterWeapon == "Magic")
	{
		ifstream SageSkills;

		SageSkills.open("ClassSkills-Sage.txt");

		cout << "\nAvailable Skills for the " << characterClass << ":\n " << endl;

		for (int i = 0; i < 6; ++i)
		{
			SageSkills >> firstClassSkills[i];
		}

		for (int i = 0; i < 3; ++i)
		{
			cout << firstClassSkills[i] << " ";
		}

		cout << endl << endl;

		for (int i = 3; i < 6; ++i)
		{
			cout << firstClassSkills[i] << " ";
		}

		cout << endl;

		SageSkills.close();
	}
}

/*Take character skill array and append them to Player Character Profile text file*/
void GameCharacterCreator::getClassSkills()
{
	fstream skills;

	skills.open("PlayerCharacterProfile.txt", ios::app);

	skills << "Available Skills for: " << getCharacterClass() << "\n\n**********************\n" << endl;

	if (getCharacterClass() == "Renegade")
	{
		for (int i = 0; i <= 3; ++i)
		{
			skills << renegadeClassSkills[i] << " ";
		}

		skills << endl << endl;

		for (int i = 4; i <= 6; ++i)
		{
			skills << renegadeClassSkills[i] << " ";
		}
	}

	else if (getCharacterClass() == "EnergyMaster")
	{
		for (int i = 0; i <= 4; ++i)
		{
			skills << energyMasterClassSkills[i] << " ";
		}

		skills << endl << endl;

		for (int i = 4; i < 8; ++i)
		{
			skills << energyMasterClassSkills[i] << " ";
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		skills << firstClassSkills[i] << " ";
	}

	skills << endl << endl;

	for (int i = 3; i < 6; ++i)
	{
		skills << firstClassSkills[i] << " ";
	}

	skills << endl;

	skills << "\n**********************\n" << endl;

	skills.close();
}

/*Assign each elevated class their skills by opening the appropriate class skill text file
And feed them into an array and display them*/
void GameCharacterCreator::setSecondClassSkills()
{
	string skill;

	if (getCharacterWeapon() == "Sword")
	{
		if (getCharacterClass() == "BladeDancer")
		{
			ifstream BladeDancerSkills;

			BladeDancerSkills.open("ClassSkills-BladeDancer.txt");

			cout << "\nAvailable Skills for the " << characterClass << ":\n " << endl;

			for (int i = 0; i <= 6; ++i)
			{
				BladeDancerSkills >> secondClassSkills[i];
			}

			for (int i = 0; i < 3; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl << endl;

			for (int i = 3; i <= 6; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl;

			BladeDancerSkills.close();
		}

		else if (getCharacterClass() == "Alchemist")
		{
			ifstream AlchemistSkills;

			AlchemistSkills.open("ClassSkills-Alchemist.txt");

			cout << "\nAvailable Skills for the " << getCharacterClass() << ":\n " << endl;

			for (int i = 0; i <= 6; ++i)
			{
				AlchemistSkills >> secondClassSkills[i];
			}

			for (int i = 0; i <= 3; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl << endl;

			for (int i = 4; i < 7; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl;

			AlchemistSkills.close();
		}

		else if (getCharacterClass() == "Engineer")
		{
			ifstream EngineerSkills;

			EngineerSkills.open("ClassSkills-Engineer.txt");

			cout << "\nAvailable Skills for the " << getCharacterClass() << ":\n " << endl;

			for (int i = 0; i <= 6; ++i)
			{
				EngineerSkills >> secondClassSkills[i];
			}

			for (int i = 0; i <= 3; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl << endl;

			for (int i = 4; i < 7; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl;

			EngineerSkills.close();
		}
	}

	if (getCharacterWeapon() == "Spear")
	{
		if (getCharacterClass() == "Gladiator")
		{
			ifstream GladiatorSkills;

			GladiatorSkills.open("ClassSkills-Gladiator.txt");

			cout << "\nAvailable Skills for the " << characterClass << ":\n " << endl;

			for (int i = 0; i <= 6; ++i)
			{
				GladiatorSkills >> secondClassSkills[i];
			}

			for (int i = 0; i < 3; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl << endl;

			for (int i = 3; i <= 6; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl;

			GladiatorSkills.close();
		}
	}

	if (getCharacterWeapon() == "Gauntlets")
	{
		if(getCharacterClass() == "Monk")
		{
			ifstream MonkSkills;

			MonkSkills.open("ClassSkills-Monk.txt");

			cout << "\nAvailable Skills for the " << getCharacterClass() << ":\n " << endl;

			for (int i = 0; i <= 6; ++i)
			{
				MonkSkills >> secondClassSkills[i];
			}

			for (int i = 0; i <= 3; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl << endl;

			for (int i = 4; i < 7; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl;

			MonkSkills.close();
		}

		else if (getCharacterClass() == "Dominator")
		{
			ifstream DominatorSkills;

			DominatorSkills.open("ClassSkills-Dominator.txt");

			cout << "\nAvailable Skills for the " << getCharacterClass() << ":\n " << endl;

			for (int i = 0; i <= 6; ++i)
			{
				DominatorSkills >> secondClassSkills[i];
			}

			for (int i = 0; i <= 3; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl << endl;

			for (int i = 4; i < 7; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl;

			DominatorSkills.close();
		}
	}

	if (getCharacterWeapon() == "Guns" || getCharacterWeapon() == "GunSaber")
	{
		if (getCharacterClass() == "Desperado")
		{
			ifstream DesperadoSkills;

			DesperadoSkills.open("ClassSkills-Monk.txt");

			cout << "\nAvailable Skills for the " << getCharacterClass() << ":\n " << endl;

			for (int i = 0; i <= 6; ++i)
			{
				DesperadoSkills >> secondClassSkills[i];
			}

			for (int i = 0; i <= 3; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl << endl;

			for (int i = 4; i < 7; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl;

			DesperadoSkills.close();
		}

		else if (getCharacterClass() == "Mercenary")
		{
			ifstream MercenarySkills;

			MercenarySkills.open("ClassSkills-Mercenary.txt");

			cout << "\nAvailable Skills for the " << getCharacterClass() << ":\n " << endl;

			for (int i = 0; i <= 6; ++i)
			{
				MercenarySkills >> secondClassSkills[i];
			}

			for (int i = 0; i <= 3; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl << endl;

			for (int i = 4; i < 7; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl;

			MercenarySkills.close();
		}
	}

	if (getCharacterWeapon() == "Daggers" || getCharacterWeapon() == "FumaShuriken")
	{
		if (getCharacterClass() == "Shinobi")
		{
			ifstream ShinobiSkills;

			ShinobiSkills.open("ClassSkills-Shinobi.txt");

			cout << "\nAvailable Skills for the " << getCharacterClass() << ":\n " << endl;

			for (int i = 0; i <= 6; ++i)
			{
				ShinobiSkills >> secondClassSkills[i];
			}

			for (int i = 0; i <= 3; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl << endl;

			for (int i = 4; i < 7; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl;

			ShinobiSkills.close();
		}

		else if (getCharacterClass() == "Rebel")
		{
			ifstream RebelSkills;

			RebelSkills.open("ClassSkills-Rebel.txt");

			cout << "\nAvailable Skills for the " << getCharacterClass() << ":\n " << endl;

			for (int i = 0; i <= 6; ++i)
			{
				RebelSkills >> secondClassSkills[i];
			}

			for (int i = 0; i <= 3; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl << endl;

			for (int i = 4; i < 7; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl;

			RebelSkills.close();
		}
	}

	if (getCharacterWeapon() == "Axes")
	{
		if (getCharacterClass() == "Raider")
		{
			ifstream RaiderSkills;

			RaiderSkills.open("ClassSkills-Raider.txt");

			cout << "\nAvailable Skills for the " << characterClass << ":\n " << endl;

			for (int i = 0; i <= 6; ++i)
			{
				RaiderSkills >> secondClassSkills[i];
			}

			for (int i = 0; i < 3; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl << endl;

			for (int i = 3; i <= 6; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl;

			RaiderSkills.close();
		}

		else if (getCharacterClass() == "Savager")
		{
			ifstream SavagerSkills;

			SavagerSkills.open("ClassSkills-Savager.txt");

			cout << "\nAvailable Skills for the " << characterClass << ":\n " << endl;

			for (int i = 0; i <= 6; ++i)
			{
				SavagerSkills >> secondClassSkills[i];
			}

			for (int i = 0; i < 3; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl << endl;

			for (int i = 3; i <= 6; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl;

			SavagerSkills.close();
		}
	}

	if (getCharacterWeapon() == "Claws")
	{
		if (getCharacterClass() == "ShadowWalker")
		{
			ifstream ShadowWalkerSkills;

			ShadowWalkerSkills.open("ClassSkills-ShadowWalker.txt");

			cout << "\nAvailable Skills for the " << characterClass << ":\n " << endl;

			for (int i = 0; i <= 6; ++i)
			{
				ShadowWalkerSkills >> secondClassSkills[i];
			}

			for (int i = 0; i < 3; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl << endl;

			for (int i = 3; i <= 6; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl;

			ShadowWalkerSkills.close();
		}

		else if (getCharacterClass() == "Executioner")
		{
			ifstream ExecutionerSkills;

			ExecutionerSkills.open("ClassSkills-Executioner.txt");

			cout << "\nAvailable Skills for the " << characterClass << ":\n " << endl;

			for (int i = 0; i <= 6; ++i)
			{
				ExecutionerSkills >> secondClassSkills[i];
			}

			for (int i = 0; i < 3; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl << endl;

			for (int i = 3; i <= 6; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl;

			ExecutionerSkills.close();
		}
	}

	if (getCharacterWeapon() == "Magic")
	{
		if (getCharacterClass() == "Shaman")
		{
			ifstream ShamanSkills;

			ShamanSkills.open("ClassSkills-Shaman.txt");

			cout << "\nAvailable Skills for the " << characterClass << ":\n " << endl;

			for (int i = 0; i <= 6; ++i)
			{
				ShamanSkills >> secondClassSkills[i];
			}

			for (int i = 0; i < 3; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl << endl;

			for (int i = 3; i <= 6; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl;

			ShamanSkills.close();
		}

		else if (getCharacterClass() == "SoulWielder")
		{
			ifstream SoulWielderSkills;

			SoulWielderSkills.open("ClassSkills-SoulWielder.txt");

			cout << "\nAvailable Skills for the " << characterClass << ":\n " << endl;

			for (int i = 0; i <= 6; ++i)
			{
				SoulWielderSkills >> secondClassSkills[i];
			}

			for (int i = 0; i < 3; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl << endl;

			for (int i = 3; i <= 6; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl;

			SoulWielderSkills.close();
		}
	}

	if (getCharacterWeapon() == "BowAndArrow" || getCharacterWeapon() == "CrossBow")
	{
		if (getCharacterClass() == "ShotMeister")
		{
			ifstream ShotMeisterSkills;

			ShotMeisterSkills.open("ClassSkills-ShotMeister.txt");

			cout << "\nAvailable Skills for the " << characterClass << ":\n " << endl;

			for (int i = 0; i <= 6; ++i)
			{
				ShotMeisterSkills >> secondClassSkills[i];
			}

			for (int i = 0; i < 3; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl << endl;

			for (int i = 3; i <= 6; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl;

			ShotMeisterSkills.close();
		}

		else if (getCharacterClass() == "BeastKaiser")
		{
			ifstream BeastKaiserSkills;

			BeastKaiserSkills.open("ClassSkills-BeastKaiser.txt");

			cout << "\nAvailable Skills for the " << characterClass << ":\n " << endl;

			for (int i = 0; i <= 6; ++i)
			{
				BeastKaiserSkills >> secondClassSkills[i];
			}

			for (int i = 0; i < 3; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl << endl;

			for (int i = 3; i <= 6; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl;

			BeastKaiserSkills.close();
		}
	}

	if (getCharacterWeapon() == "GreatSword" || getCharacterWeapon() == "SwordAndShield")
	{
		if (getCharacterClass() == "Knight")
		{
			ifstream KnightSkills;

			KnightSkills.open("ClassSkills-Knight.txt");

			cout << "\nAvailable Skills for the " << characterClass << ":\n " << endl;

			for (int i = 0; i <= 6; ++i)
			{
				KnightSkills >> secondClassSkills[i];
			}

			for (int i = 0; i < 3; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl << endl;

			for (int i = 3; i <= 6; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl;

			KnightSkills.close();
		}

		else if (getCharacterClass() == "Templar")
		{
			ifstream TemplarSkills;

			TemplarSkills.open("ClassSkills-Templar.txt");

			cout << "\nAvailable Skills for the " << characterClass << ":\n " << endl;

			for (int i = 0; i <= 6; ++i)
			{
				TemplarSkills >> secondClassSkills[i];
			}

			for (int i = 0; i < 3; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl << endl;

			for (int i = 3; i <= 6; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl;

			TemplarSkills.close();
		}
	}

	if (getCharacterWeapon() == "Bracelet" || getCharacterWeapon() == "Bracelet & Grimoire")
	{
		if (getCharacterClass() == "Sorcerer")
		{
			ifstream SorcererSkills;

			SorcererSkills.open("ClassSkills-Sorcerer.txt");

			cout << "\nAvailable Skills for the " << characterClass << ":\n " << endl;

			for (int i = 0; i <= 6; ++i)
			{
				SorcererSkills >> secondClassSkills[i];
			}

			for (int i = 0; i < 3; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl << endl;

			for (int i = 3; i <= 6; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl;

			SorcererSkills.close();
		}

		else if (getCharacterClass() == "Occulter")
		{
			ifstream OcculterSkills;

			OcculterSkills.open("ClassSkills-Occulter.txt");

			cout << "\nAvailable Skills for the " << characterClass << ":\n " << endl;

			for (int i = 0; i <= 6; ++i)
			{
				OcculterSkills >> secondClassSkills[i];
			}

			for (int i = 0; i < 3; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl << endl;

			for (int i = 3; i <= 6; ++i)
			{
				cout << secondClassSkills[i] << " ";
			}

			cout << endl;

			OcculterSkills.close();
		}
	}
}

/*Take character skill array and append them to Player Character Profile text file*/
void GameCharacterCreator::getSecondClassSkills()
{
	fstream skills;
	fstream prevSkills;

	skills.open("PlayerCharacterProfile.txt", ios::app);

	if (getPrevClass() == "Warrior")
	{
		prevSkills.open("ClassSkills-Warrior.txt");

		skills << "Available Skills for: " << getPrevClass() << "\n\n**********************\n" << endl;

		cout << "\n\n**********************\n" << endl;

		cout << "Available Skills for: " << getPrevClass() << "\n\n**********************\n" << endl;

		for (int i = 0; i < 6; ++i)
		{
			prevSkills >> firstClassSkills[i];
		}

		cout << endl;

		for (int i = 0; i < 3; ++i)
		{
			skills << firstClassSkills[i] << " ";
			cout << firstClassSkills[i] << " ";
		}

		skills << endl << endl;
		cout << endl << endl;

		for (int i = 3; i < 6; ++i)
		{
			skills << firstClassSkills[i] << " ";
			cout << firstClassSkills[i] << " ";
		}

		skills << endl;
		cout << endl;

		skills << "\n**********************\n" << endl;
		cout << "\n**********************\n" << endl;

		prevSkills.close();
	}

	else if (getPrevClass() == "Artisan")
	{
		prevSkills.open("ClassSkills-Artisan.txt");

		skills << "Available Skills for: " << getPrevClass() << "\n\n**********************\n" << endl;

		cout << "\n\n**********************\n" << endl;

		cout << "Available Skills for: " << getPrevClass() << "\n\n**********************\n" << endl;

		for (int i = 0; i < 6; ++i)
		{
			prevSkills >> firstClassSkills[i];
		}

		cout << endl;

		for (int i = 0; i < 3; ++i)
		{
			skills << firstClassSkills[i] << " ";
			cout << firstClassSkills[i] << " ";
		}

		skills << endl << endl;
		cout << endl << endl;

		for (int i = 3; i < 6; ++i)
		{
			skills << firstClassSkills[i] << " ";
			cout << firstClassSkills[i] << " ";
		}

		skills << endl;
		cout << endl;

		skills << "\n**********************\n" << endl;
		cout << "\n**********************\n" << endl;

		prevSkills.close();
	}

	else if (getPrevClass() == "Breaker")
	{
		prevSkills.open("ClassSkills-Breaker.txt");

		skills << "Available Skills for: " << getPrevClass() << "\n\n**********************\n" << endl;

		cout << "\n\n**********************\n" << endl;

		cout << "Available Skills for: " << getPrevClass() << "\n\n**********************\n" << endl;

		for (int i = 0; i < 6; ++i)
		{
			prevSkills >> firstClassSkills[i];
		}

		cout << endl;

		for (int i = 0; i < 3; ++i)
		{
			skills << firstClassSkills[i] << " ";
			cout << firstClassSkills[i] << " ";
		}

		skills << endl << endl;
		cout << endl << endl;

		for (int i = 3; i < 6; ++i)
		{
			skills << firstClassSkills[i] << " ";
			cout << firstClassSkills[i] << " ";
		}

		skills << endl;
		cout << endl;

		skills << "\n**********************\n" << endl;
		cout << "\n**********************\n" << endl;

		prevSkills.close();
	}

	else if (getPrevClass() == "BulletShark")
	{
		prevSkills.open("ClassSkills-BulletShark.txt");

		skills << "Available Skills for: " << getPrevClass() << "\n\n**********************\n" << endl;

		cout << "\n\n**********************\n" << endl;

		cout << "Available Skills for: " << getPrevClass() << "\n\n**********************\n" << endl;

		for (int i = 0; i < 6; ++i)
		{
			prevSkills >> firstClassSkills[i];
		}

		cout << endl;

		for (int i = 0; i < 3; ++i)
		{
			skills << firstClassSkills[i] << " ";
			cout << firstClassSkills[i] << " ";
		}

		skills << endl << endl;
		cout << endl << endl;

		for (int i = 3; i < 6; ++i)
		{
			skills << firstClassSkills[i] << " ";
			cout << firstClassSkills[i] << " ";
		}

		skills << endl;
		cout << endl;

		skills << "\n**********************\n" << endl;
		cout << "\n**********************\n" << endl;

		prevSkills.close();
	}

	else if (getPrevClass() == "Renegade")
	{
		prevSkills.open("ClassSkills-Renegade.txt");

		skills << "Available Skills for: " << getPrevClass() << "\n\n**********************\n" << endl;

		cout << "\n\n**********************\n" << endl;

		cout << "Available Skills for: " << getPrevClass() << "\n\n**********************\n" << endl;

		for (int i = 0; i < 6; ++i)
		{
			prevSkills >> firstClassSkills[i];
		}

		cout << endl;

		for (int i = 0; i < 3; ++i)
		{
			skills << firstClassSkills[i] << " ";
			cout << firstClassSkills[i] << " ";
		}

		skills << endl << endl;
		cout << endl << endl;

		for (int i = 3; i < 6; ++i)
		{
			skills << firstClassSkills[i] << " ";
			cout << firstClassSkills[i] << " ";
		}

		skills << endl;
		cout << endl;

		skills << "\n**********************\n" << endl;
		cout << "\n**********************\n" << endl;

		prevSkills.close();
	}

	else if (getPrevClass() == "Ravager")
	{
		prevSkills.open("ClassSkills-Ravager.txt");

		skills << "Available Skills for: " << getPrevClass() << "\n\n**********************\n" << endl;

		cout << "\n\n**********************\n" << endl;

		cout << "Available Skills for: " << getPrevClass() << "\n\n**********************\n" << endl;

		for (int i = 0; i < 6; ++i)
		{
			prevSkills >> firstClassSkills[i];
		}

		cout << endl;

		for (int i = 0; i < 3; ++i)
		{
			skills << firstClassSkills[i] << " ";
			cout << firstClassSkills[i] << " ";
		}

		skills << endl << endl;
		cout << endl << endl;

		for (int i = 3; i < 6; ++i)
		{
			skills << firstClassSkills[i] << " ";
			cout << firstClassSkills[i] << " ";
		}

		skills << endl;
		cout << endl;

		skills << "\n**********************\n" << endl;
		cout << "\n**********************\n" << endl;

		prevSkills.close();
	}

	else if (getPrevClass() == "Assassin")
	{
		prevSkills.open("ClassSkills-Assassin.txt");

		skills << "Available Skills for: " << getPrevClass() << "\n\n**********************\n" << endl;

		cout << "\n\n**********************\n" << endl;

		cout << "Available Skills for: " << getPrevClass() << "\n\n**********************\n" << endl;

		for (int i = 0; i < 6; ++i)
		{
			prevSkills >> firstClassSkills[i];
		}

		cout << endl;

		for (int i = 0; i < 3; ++i)
		{
			skills << firstClassSkills[i] << " ";
			cout << firstClassSkills[i] << " ";
		}

		skills << endl << endl;
		cout << endl << endl;

		for (int i = 3; i < 6; ++i)
		{
			skills << firstClassSkills[i] << " ";
			cout << firstClassSkills[i] << " ";
		}

		skills << endl;
		cout << endl;

		skills << "\n**********************\n" << endl;
		cout << "\n**********************\n" << endl;

		prevSkills.close();
	}

	else if (getPrevClass() == "Sage")
	{
		prevSkills.open("ClassSkills-Sage.txt");

		skills << "Available Skills for: " << getPrevClass() << "\n\n**********************\n" << endl;

		cout << "\n\n**********************\n" << endl;

		cout << "Available Skills for: " << getPrevClass() << "\n\n**********************\n" << endl;

		for (int i = 0; i < 6; ++i)
		{
			prevSkills >> firstClassSkills[i];
		}

		cout << endl;

		for (int i = 0; i < 3; ++i)
		{
			skills << firstClassSkills[i] << " ";
			cout << firstClassSkills[i] << " ";
		}

		skills << endl << endl;
		cout << endl << endl;

		for (int i = 3; i < 6; ++i)
		{
			skills << firstClassSkills[i] << " ";
			cout << firstClassSkills[i] << " ";
		}

		skills << endl;
		cout << endl;

		skills << "\n**********************\n" << endl;
		cout << "\n**********************\n" << endl;

		prevSkills.close();
	}

	else if (getPrevClass() == "Hunter")
	{
		prevSkills.open("ClassSkills-Hunter.txt");

		skills << "Available Skills for: " << getPrevClass() << "\n\n**********************\n" << endl;

		cout << "\n\n**********************\n" << endl;

		cout << "Available Skills for: " << getPrevClass() << "\n\n**********************\n" << endl;

		for (int i = 0; i < 6; ++i)
		{
			prevSkills >> firstClassSkills[i];
		}

		cout << endl;

		for (int i = 0; i < 3; ++i)
		{
			skills << firstClassSkills[i] << " ";
			cout << firstClassSkills[i] << " ";
		}

		skills << endl << endl;
		cout << endl << endl;

		for (int i = 3; i < 6; ++i)
		{
			skills << firstClassSkills[i] << " ";
			cout << firstClassSkills[i] << " ";
		}

		skills << endl;
		cout << endl;

		skills << "\n**********************\n" << endl;
		cout << "\n**********************\n" << endl;

		prevSkills.close();
	}

	else if (getPrevClass() == "Guardian")
	{
		prevSkills.open("ClassSkills-Guardian.txt");

		skills << "Available Skills for: " << getPrevClass() << "\n\n**********************\n" << endl;

		cout << "\n\n**********************\n" << endl;

		cout << "Available Skills for: " << getPrevClass() << "\n\n**********************\n" << endl;

		for (int i = 0; i < 6; ++i)
		{
			prevSkills >> firstClassSkills[i];
		}

		cout << endl;

		for (int i = 0; i < 3; ++i)
		{
			skills << firstClassSkills[i] << " ";
			cout << firstClassSkills[i] << " ";
		}

		skills << endl << endl;
		cout << endl << endl;

		for (int i = 3; i < 6; ++i)
		{
			skills << firstClassSkills[i] << " ";
			cout << firstClassSkills[i] << " ";
		}

		skills << endl;
		cout << endl;

		skills << "\n**********************\n" << endl;
		cout << "\n**********************\n" << endl;

		prevSkills.close();
	}

	else if (getPrevClass() == "EnergyMaster")
	{
		prevSkills.open("ClassSkills-EnergyMaster.txt");

		skills << "Available Skills for: " << getPrevClass() << "\n\n**********************\n" << endl;

		cout << "\n\n**********************\n" << endl;

		cout << "Available Skills for: " << getPrevClass() << "\n\n**********************\n" << endl;

		for (int i = 0; i < 6; ++i)
		{
			prevSkills >> firstClassSkills[i];
		}

		cout << endl;

		for (int i = 0; i < 3; ++i)
		{
			skills << firstClassSkills[i] << " ";
			cout << firstClassSkills[i] << " ";
		}

		skills << endl << endl;
		cout << endl << endl;

		for (int i = 3; i < 6; ++i)
		{
			skills << firstClassSkills[i] << " ";
			cout << firstClassSkills[i] << " ";
		}

		skills << endl;
		cout << endl;

		skills << "\n**********************\n" << endl;
		cout << "\n**********************\n" << endl;

		prevSkills.close();
	}

	skills << "Available Skills for: " << getCharacterClass() << "\n\n**********************\n" << endl;

	for (int i = 0; i < 4; ++i)
	{
		skills << secondClassSkills[i] << " ";
	}

	skills << endl << endl;

	for (int i = 4; i < 7; ++i)
	{
		skills << secondClassSkills[i] << " ";
	}

	skills << endl;

	skills << "\n**********************\n" << endl;

	skills.close();
}

/*Class Function to allow for Class Evolution; 
Open text files for both Class Branches and feed them into string vectors
Assign each a number and display for player to choose from*/
void GameCharacterCreator::characterClassChanger()
{
	string classFirstBranch;
	string classSecondBranch;

	string characterCurrClass;

	double classChoice;

	ifstream firstBranch;
	ifstream secondBranch;

	firstBranch.open("PlayerCharacterClassFirstBranch.txt");
	secondBranch.open("PlayerCharacterClassSecondBranch.txt");

	vector<string> playerSecondClassFB;
	vector<string> playerSecondClassSB;
	
	while (firstBranch >> classFirstBranch)
	{
		playerSecondClassFB.push_back(classFirstBranch);
	}

	while (secondBranch >> classSecondBranch)
	{
		playerSecondClassSB.push_back(classSecondBranch);
	}

	cout << "\n-----------------------------------------------" << endl;

	for (int i = 0; i < playerSecondClassFB.size() / 2; ++i)
	{
		cout <<" "<< playerSecondClassFB[i] << " ";
	}

	cout << endl << endl;

	for (int i = playerSecondClassFB.size() / 2; i < playerSecondClassFB.size(); ++i)
	{
		cout <<" " << playerSecondClassFB[i] << " ";
	}

	cout << "\n-----------------------------------------------" << endl;

	cout << endl;

	cout << "\n-----------------------------------------------" << endl;

	for (int i = 0; i < playerSecondClassSB.size() / 2; ++i)
	{
		cout << " " <<  playerSecondClassSB[i] << " ";
	}

	cout << endl << endl;

	for (int i = playerSecondClassSB.size() / 2; i < playerSecondClassSB.size(); ++i)
	{
		cout << " " << playerSecondClassSB[i] << " ";
	}

	cout << "\n-----------------------------------------------" << endl;
	cout << endl << endl;

	characterCurrClass = getCharacterClass();

	//Warrior class change
	if (characterCurrClass == "Warrior")
	{
		cout << "Choose between these two Class choices: " << endl;

		cout << "\n" << playerSecondClassFB[0] << " 0" << " or " << playerSecondClassSB[0] <<" 1" << endl;

		cin >> classChoice;

		//Gladiator
		if (classChoice == 0)
		{
			setCharacterClass(playerSecondClassFB[0]);

			characterStr = characterStr + 50;

			setJobLevel(1);

			setPrevClass(characterCurrClass);
		}

		//BladeDancer
		else if (classChoice == 1)
		{
			setCharacterClass(playerSecondClassSB[0]);

			characterAgi = characterAgi + 50;

			setJobLevel(1);

			setPrevClass(characterCurrClass);
		}
		
	}

	//Artisan Class change
	else if (characterCurrClass == "Artisan")
	{
		cout << "Choose between these two Class choices: " << endl;

		cout << "\n" << playerSecondClassFB[1] << " 0" << " or " << playerSecondClassSB[1] << " 1" << endl;

		cin >> classChoice;

		//Alchemist
		if (classChoice == 0)
		{
			setCharacterClass(playerSecondClassFB[1]);

			characterInt = characterInt + 50;

			setJobLevel(1);

			setPrevClass(characterCurrClass);
		}

		//Engineer
		else if (classChoice == 1)
		{
			setCharacterClass(playerSecondClassSB[1]);

			characterStr = characterStr + 50;

			setJobLevel(1);

			setPrevClass(characterCurrClass);
		}
	}

	//Breaker Class change
	else if (characterClass == "Breaker")
	{
		cout << "Choose between these two Class choices: " << endl;

		cout << "\n" << playerSecondClassFB[2] << " 0" << " or " << playerSecondClassSB[2] << " 1" << endl;

		cin >> classChoice;

		//Monk
		if (classChoice == 0)
		{
			setCharacterClass(playerSecondClassFB[2]);

			characterDex = characterDex + 50;

			setJobLevel(1);

			setPrevClass(characterCurrClass);
		}

		//Dominator
		else if (classChoice == 1)
		{
			setCharacterClass(playerSecondClassSB[2]);

			characterStr = characterStr + 50;

			setJobLevel(1);

			setPrevClass(characterCurrClass);
		}
	}

	//BulletShark Class change
	else if (characterClass == "BulletShark")
	{
		cout << "Choose between these two Class choices: " << endl;

		cout << "\n" << playerSecondClassFB[3] << " 0" << " or " << playerSecondClassSB[3] << " 1" << endl;

		cin >> classChoice;

		//Desperado
		if (classChoice == 0)
		{
			setCharacterClass(playerSecondClassFB[3]);

			characterDex = characterDex + 50;

			setJobLevel(1);

			setPrevClass(characterCurrClass);
		}

		 //Mercenary
		else if (classChoice == 1)
		{
			setCharacterClass(playerSecondClassSB[3]);

			characterAgi = characterAgi + 50;

			setJobLevel(1);

			setPrevClass(characterCurrClass);

			setCharacterWeapon("GunSaber");
		}
	}

	//Renegade class change
	else if (characterClass == "Renegade")
	{
		cout << "Choose between these two Class choices: " << endl;

		cout << "\n" << playerSecondClassFB[4] << " 0" << " or " << playerSecondClassSB[4] << " 1" << endl;

		cin >> classChoice;

		//Shinobi
		if (classChoice == 0)
		{
			setCharacterClass(playerSecondClassFB[4]);

			characterAgi = characterAgi + 50;

			setJobLevel(1);

			setPrevClass(characterCurrClass);
		}

		//Rebel
		else if (classChoice == 1)
		{
			setCharacterClass(playerSecondClassSB[4]);

			characterStr = characterStr + 50;

			setJobLevel(1);

			setPrevClass(characterCurrClass);
		}
	}

	//Guardian Class change
	else if (characterClass == "Guardian")
	{
		cout << "Choose between these two Class choices: " << endl;

		cout << "\n" << playerSecondClassFB[5] << " 0" << " or " << playerSecondClassSB[5] << " 1" << endl;

		cin >> classChoice;

		//Knight
		if (classChoice == 0)
		{
			setCharacterClass(playerSecondClassFB[5]);

			characterVit = characterVit + 50;

			setJobLevel(1);

			setPrevClass(characterCurrClass);
		}

		//Templar
		else if (classChoice == 1)
		{
			setCharacterClass(playerSecondClassSB[5]);

			characterStr = characterStr + 50;

			setJobLevel(1);

			setPrevClass(characterCurrClass);
		}
	}

	//EnergyMaster class change
	else if (characterClass == "EnergyMaster")
	{
		cout << "Choose between these two Class choices: " << endl;

		cout << "\n" << playerSecondClassFB[6] << " 0" << " or " << playerSecondClassSB[6] << " 1" << endl;

		cin >> classChoice;

		//Sorcerer
		if (classChoice == 0)
		{
			setCharacterClass(playerSecondClassFB[6]);

			characterInt = characterInt + 50;

			setJobLevel(1);

			setPrevClass(characterCurrClass);
		}

		//Occulter
		else if (classChoice == 1)
		{
			setCharacterClass(playerSecondClassSB[6]);

			characterDex = characterDex + 50;

			setJobLevel(1);

			setPrevClass(characterCurrClass);
		}

	}

	//Ravager class change
	else if (characterClass == "Ravager")
	{
		cout << "Choose between these two Class choices: " << endl;

		cout << "\n" << playerSecondClassFB[7] << " 0" << " or " << playerSecondClassSB[7] << " 1" << endl;

		cin >> classChoice;

		//Raider
		if (classChoice == 0)
		{
			setCharacterClass(playerSecondClassFB[7]);

			characterDex = characterDex + 50;

			setJobLevel(1);

			setPrevClass(characterCurrClass);
		}

		//Savager
		else if (classChoice == 1)
		{
			setCharacterClass(playerSecondClassSB[7]);

			characterStr = characterStr + 50;

			setJobLevel(1);

			setPrevClass(characterCurrClass);
		}
	}
	
	//Hunter class change
	else if (characterClass == "Hunter")
	{
		cout << "Choose between these two Class choices: " << endl;

		cout << "\n" << playerSecondClassFB[8] << " 0" << " or " << playerSecondClassSB[8] << " 1" << endl;

		cin >> classChoice;

		//BeastKaiser
		if (classChoice == 0)
		{
			setCharacterClass(playerSecondClassFB[8]);

			characterDex = characterDex + 50;

			setJobLevel(1);

			setPrevClass(characterCurrClass);
		}

		//ShotMeister
		else if (classChoice == 1)
		{
			setCharacterClass(playerSecondClassSB[8]);

			characterAgi = characterAgi + 50;

			setJobLevel(1);

			setPrevClass(characterCurrClass);
		}
	}
	
	//Sage class change
	else if (characterClass == "Sage")
	{
		cout << "Choose between these two Class choices: " << endl;

		cout << "\n" << playerSecondClassFB[9] << " 0" << " or " << playerSecondClassSB[9] << " 1" << endl;

		cin >> classChoice;

		//SoulWielder
		if (classChoice == 0)
		{
			setCharacterClass(playerSecondClassFB[9]);

			characterInt = characterInt + 50;

			setJobLevel(1);

			setPrevClass(characterCurrClass);
		}

		//Shaman
		else if (classChoice == 1)
		{
			setCharacterClass(playerSecondClassSB[9]);

			characterDex = characterDex + 50;

			setJobLevel(1);

			setPrevClass(characterCurrClass);
		}
	}

	//Assassin class change
	else if (characterClass == "Assassin")
	{
		cout << "Choose between these two Class choices: " << endl;

		cout << "\n" << playerSecondClassFB[10] << " 0" << " or " << playerSecondClassSB[10] << " 1" << endl;

		cin >> classChoice;

		//ShadowWalker
		if (classChoice == 0)
		{
			setCharacterClass(playerSecondClassFB[10]);

			characterAgi = characterAgi + 50;

			setJobLevel(1);

			setPrevClass(characterCurrClass);
		}

		//Executioner
		else if (classChoice == 1)
		{
			setCharacterClass(playerSecondClassSB[10]);

			characterStr = characterStr + 50;

			setJobLevel(1);

			setPrevClass(characterCurrClass);
		}
	}

	cout << "Class Changed!" << endl;

	firstBranch.close();
	secondBranch.close();
}

/*void GameCharacterCreator::useClassSkills()
{
	if (getCharacterClass() == "Renegade")
	{
		struct Renegade
		{
			string skillOne;
			int spCost = 10;
			bool active = true;

			string skillTwo;
			int spCost = 10;
			bool active = true;

			string skillThree;
			bool active = false;

			string skillFour;
			int spCost = 5;
			bool active = true;

			string skillFive;
			int spCost = 15;
			bool active = true;

			string skillSix;
			int spCost = 15;
			bool active = true;

			string skillSeven;
			int spCost = 5;
			bool active = true;
		};

		Renegade skills;

		skills.skillOne = firstClassSkills[0];
		skills.skillTwo = firstClassSkills[1];
		skills.skillThree = firstClassSkills[2];
		skills.skillFour = firstClassSkills[3];
		skills.skillFive = firstClassSkills[4];
		skills.skillSix = firstClassSkills[5];
		skills.skillSeven = firstClassSkills[6];
	}
}*/

/*void GameCharacterCreator::generateFight()
{
	bool fightMode = true;

	do
	{
		enemyGenerate()
	} while (fightMode == true);*
}*/

GameCharacterCreator::~GameCharacterCreator()
{
	cout << "\a" << endl;
}
