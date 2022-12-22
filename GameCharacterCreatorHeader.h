#pragma once

#include<string>

using namespace std;

class GameCharacterCreator
{
	private:
		string characterName;
		string characterWeapon;
		string characterClass;
		string characterRace;
		string feralType;
		//string weaponClass;
		string equippedWeapon;
		string equippedSecondWeapon;
		string rightWeaponArmEquipped;
		string leftWeaponArmEquipped;
		string armBracers;
		string legArmor;
		string torsoArmor;
		string headArmor;
		string sigilEquipped;
		string armorType;
		string headType;
		string armType;
		string legType;
		string firstClassSkills[6];
		string renegadeClassSkills[7];
		string energyMasterClassSkills[8];
		string shinobiClassSkills[9];
		//vector<string> renegadeClassSkills;
		string secondClassSkills[7];
		string SorcererClassSkills[8];
		string prevClass;
		string homunculusPartner;
		string beastPartner;

		bool equipped = false;
		bool enabled = false;

		double level;
		double jobLevel;
		double characterHP;
		double characterSP;
		double characterStr;
		double characterAgi;
		double characterInt;
		double characterVit;
		double characterDex;
		double characterLuk;
		double weaponLvl;
		double secondWeaponLvl;
		double armorLvl;
		double greavesLvl;
		double bracerLvl;
		double headLvl;
		double sigilLvl;

		int weaponID;

	public:
		GameCharacterCreator(string name, string selectedClass, int wID, double lvl, double jLvl);
		GameCharacterCreator();
		GameCharacterCreator(string name, string currentClass, string wepType, string torsoType, string bracerType, string legType,
			string equippedFWeapon, string equippedRWeapon, string equippedTorso, string equippedHead,
			string equippedBracer, string equippedLegArmor, string equippedSigil, string charRace, string rType,
			double lvl, double jLvl, double cHP, double cSP, double cStr, double cAgi, double cVit, double cInt, double cDex, double cLuk,
			double armorLevel, double headLevel, double armLevel, double legLevel, double fWepLvl, double rWepLvl, double sigilLvl);

		void generate();
		void generateEquippedTorso();
		void generateWeapons();
		void generateHeadGear();
		void generateArmBracer();
		void generateLegArmor();
		void generateSigil();
		void generateRace();

		string getName();
		string getCharacterClass();
		string getCharacterRace();
		string getFeralType();
		string getCharacterWeapon();
		//string getWeaponClass();
		string getEquippedWeapon();
		string getEquippedSecondWeapon();
		string getRightWeaponArmEquipped();
		string getLeftWeaponArmEquipped();
		string getLegArmor();
		string getTorsoArmor();
		string getHeadArmor();
		string getArmBracer();
		string getSigilEquipped();
		string getArmorType();
		string getHeadType();
		string getArmType();
		string getLegType();
		string getPrevClass();
		string getHomunculus();
		string getBeastPartner();

		bool getEquipped();

		double getLevel();
		double getJobLevel();
		double getCharacterHP();
		double getCharacterSP();
		double getCharacterStr();
		double getCharacterAgi();
		double getCharacterInt();
		double getCharacterVit();
		double getCharacterDex();
		double getCharacterLuk();
		double getWeaponLevel();
		double getSecondWeaponLevel();
		double getArmorLvl();
		double getHeadArmorLvl();
		double getArmBracerLvl();
		double getLegArmorLvl();
		double getSigilLvl();

		int getWeaponID();

		void setEquipped(bool equipped);

		void setEquippedWeapon(string eWeapon);
		void setEquippedSecondWeapon(string eWeapon2);
		void setCharacterClass(string cls);
		void setCharacterRace(string cR);
		void setFeralType(string fT);
		//void setWeaponClass(string wCls);
		void setCharacterWeapon(string weapon);
		void setBeastPartner(string beast);
		void getHomunculus(string hom);

		void setLevel(double lvl);
		void setJobLevel(double jLvl);
		void setWeaponLevel(double wepLvl);
		void setSecondWeaponLevel(double secondWepLvl);
		void setArmorLevel(double arLvl);
		void setHeadArmorLvl(double hArLvl);
		void setBracerLvl(double aBrLvl);
		void setLegArmorLvl(double lArmLvl);
		void setSigilLvl(double signLvl);
		void setcharacterHP(double HP);
		void setcharacterSP(double SP);
		void setCharacterStr(double Str);
		void setCharacterAgi(double Agi);
		void setCharacterInt(double Int);
		void setCharacterVit(double Vit);
		void setCharacterDex(double Dex);
		void setCharacterLuk(double Luk);

		void setWeaponID(int wepID);

		void setRightWeaponArmEquipped(string rAEquipment);
		void setLeftWeaponArmEquipped(string lAEquipment);
		void setLegArmor(string legEquipment);
		void setHeadArmor(string hEquipment);
		void setSigilEquipped(string garmEquipment);
		void setTorsoEquipped(string tEquipment);
		void setArmBracer(string armBr);
		void setArmorType(string aType);
		void setHeadType(string hType);
		void setArmType(string aBr);
		void setLegType(string lType);
		void setPrevClass(string fCls);

		void setClassSkills();
		void getClassSkills();
		void setSecondClassSkills();
		void getSecondClassSkills();

		//void useClassSkills();
		//void generateFight();

		void characterClassChanger();

		~GameCharacterCreator();
};