// GamePlayerCharacterCreator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <iterator>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <filesystem>

#include "GameCharacterCreatorHeader.h"

#include "EnemyCreatorHeader.h"

using namespace std;

//Prototypes
string classSelector(int wNum);

void characterUploader();

int main()
{
    int weaponNum;
    const int arraySize = 6;

    string playerName;
    string classSelect;
    string weaponType;
    string fileContent;
    string skills[arraySize];
    //string testWeapon = "Hunter";

    char userInput;
    char weaponChangeInput;

    /*int compareNum;
    int levelRandomizer;
    int randResult;*/

    vector<string> weapons;
    
    ifstream playerWeapons;

    ofstream playerCharacterFileOUT;
    ofstream playerCharacterMetaFileOUT;

    //Give player option to create a character or upload a created one.
    cout << "Create a character (c) or upload a character (u): ";
    cin >> userInput;

    //If player chooses to create a character
    if (userInput == 'c')
    {
        //Create and open text file for Character Profile
        playerCharacterFileOUT.open("PlayerCharacterProfile.txt");
        
        /*Open the Character Class Weapons text file 
        and feed the file contents into the Weapons string vector */
        playerWeapons.open("CharacterWeapons.txt");

        while (playerWeapons >> fileContent)
        {
            weapons.push_back(fileContent);
        }

        //Display the vector and ask for player's input
        cout << "Select which weapon to use; Press Enter to begin: \n" << endl;
        cin.ignore().get();

        for (int i = 0; i < weapons.size() / 2; ++i)
        {
            cout << i << " - " << weapons[i] << " | ";
        }

        cout << "\n\n";

        for (int i = weapons.size() / 2; i < weapons.size(); ++i)
        {
            cout << i << " - " << weapons[i] << " | ";
        }

        cout << "\n\n";
        cin >> weaponNum;

        /*Call functionand take the user's choice as argument to determine class
          and return class to variable*/
        classSelect = classSelector(weaponNum);

        //Player enter's the character's name
        cout << "\nEnter character name: " << endl;
        cin >> playerName;

        //Create object for the GameCharacterCreator Class and pass arguments to object
        GameCharacterCreator playerCharacter(playerName, classSelect, weaponNum, 50, 50);

        //Call Class functions to create character, choose race, and weapon
        playerCharacter.generate();
        playerCharacter.generateRace();
        playerCharacter.generateWeapons();
        
        //Give player option to equip armor, headgear, leg gear, and tatoo
        cout << "\nEquip Torso Armor? Y/N" << endl;
        cin >> userInput;

        if (tolower(userInput == 'y'))
        {
            playerCharacter.generateEquippedTorso();
        }

        cout << "\nEquip HeadGear? Y/N" << endl;
        cin >> userInput;

        if (tolower(userInput == 'y'))
        {
            playerCharacter.generateHeadGear();
        }

        cout << "\nEquip Leg Armor? Y/N" << endl;
        cin >> userInput;

        if (tolower(userInput == 'y'))
        {
            playerCharacter.generateLegArmor();
        }

        /*If the selected character weapon isn't 1 (meaning Gauntlets), 
        give player option to equip bracer*/
        if (weaponNum != 1)
        {
            cout << "\nEquip Bracer? Y/N" << endl;
            cin >> userInput;

            if (tolower(userInput == 'y'))
            {
                playerCharacter.generateArmBracer();
            }
        }
        
        /*If the character weapon is Gauntlets, 
        omit ability to select Bracerand set the Arm Type to Gauntlets*/
        else
        {
            playerCharacter.setArmType("Gauntlets");
        }
        
        cout << "\nEquip Sigil? Y/N" << endl;
        cin >> userInput;

        if (tolower(userInput == 'y'))
        {
            playerCharacter.generateSigil();
        }

        /*Output all character information to the player character profile text file
          Including: Name, Level, Class, Job Level, Weapon, Armor, Bracer, leg armor archetypes, Race
          Character stats, and currently equipped armor, tatoo, and weapons*/

        playerCharacterFileOUT << "Character Info: " << endl;

        playerCharacterFileOUT << "\n**********************" << endl;

        playerCharacterFileOUT << "Name: " << playerCharacter.getName() << endl;
        playerCharacterFileOUT << "Level: " << playerCharacter.getLevel() << endl;
        playerCharacterFileOUT << "Class: " << playerCharacter.getCharacterClass() << endl;
        playerCharacterFileOUT << "Job Level: " << playerCharacter.getJobLevel() << endl;
        playerCharacterFileOUT << "\nCharacter Weapon: " << endl;
        playerCharacterFileOUT << "\n" << playerCharacter.getCharacterWeapon() << endl;
        playerCharacterFileOUT << "\nArmor Type: " << endl;
        playerCharacterFileOUT << "\n" << playerCharacter.getArmorType() << endl;
        playerCharacterFileOUT << "\nBracer Type: " << endl;
        playerCharacterFileOUT << "\n" << playerCharacter.getArmType() << endl;
        playerCharacterFileOUT << "\nLegArmor Type: " << endl;
        playerCharacterFileOUT << "\n" << playerCharacter.getLegType() << endl;
        playerCharacterFileOUT << "\nAncestry: " << endl;
        playerCharacterFileOUT << "\n" << playerCharacter.getCharacterRace() << endl;

        if (playerCharacter.getCharacterRace() == "Feral")
        {
            playerCharacterFileOUT << " (Type: " << playerCharacter.getFeralType() << " )" << endl;
        }

        playerCharacterFileOUT << "\n**********************\n" << endl;

        playerCharacterFileOUT << "Character Stats: " << endl;

        playerCharacterFileOUT << "\n**********************" << endl;
        playerCharacterFileOUT << "HP: " << playerCharacter.getCharacterHP() << endl;
        playerCharacterFileOUT << "SP: " << playerCharacter.getCharacterSP() << endl;
        playerCharacterFileOUT << "Strength: " << playerCharacter.getCharacterStr() << endl;
        playerCharacterFileOUT << "Agility: " << playerCharacter.getCharacterAgi() << endl;
        playerCharacterFileOUT << "Vitality: " << playerCharacter.getCharacterVit() << endl;
        playerCharacterFileOUT << "Dexterity: " << playerCharacter.getCharacterDex() << endl;
        playerCharacterFileOUT << "Intelligence: " << playerCharacter.getCharacterInt() << endl;
        playerCharacterFileOUT << "Luck: " << playerCharacter.getCharacterLuk() << endl;

        playerCharacterFileOUT << "\n**********************" << endl;

        playerCharacterFileOUT << "Character Equipment: " << endl;

        playerCharacterFileOUT << "\n**********************" << endl;
        playerCharacterFileOUT << "\n" << "Equipped Weapon: " << playerCharacter.getEquippedWeapon() << endl;
        playerCharacterFileOUT << "\n" << "Equipped Weapon Level: " << playerCharacter.getWeaponLevel() << endl;
        playerCharacterFileOUT << "\n" << "Equipped Second Weapon: " << playerCharacter.getEquippedSecondWeapon() << endl;
        playerCharacterFileOUT << "\n" << "Equipped Second Weapon Level: " << playerCharacter.getSecondWeaponLevel() << endl;
        playerCharacterFileOUT << "\n" << "Equipped Armor: " << playerCharacter.getTorsoArmor() << endl;
        playerCharacterFileOUT << "\n" << "Equipped Armor Level: " << playerCharacter.getArmorLvl() << endl;
        playerCharacterFileOUT << "\n" << "Equipped Helm: " << playerCharacter.getHeadArmor() << endl;
        playerCharacterFileOUT << "\n" << "Equipped Helm Level: " << playerCharacter.getHeadArmorLvl() << endl;
        playerCharacterFileOUT << "\n" << "Equipped Bracer: " << playerCharacter.getArmBracer() << endl;
        playerCharacterFileOUT << "\n" << "Equipped Bracer Level: " << playerCharacter.getArmBracerLvl() << endl;
        playerCharacterFileOUT << "\n" << "Equipped Leg Armor: " << playerCharacter.getLegArmor() << endl;
        playerCharacterFileOUT << "\n" << "Equipped Leg Armor Level: " << playerCharacter.getLegArmorLvl() << endl;
        playerCharacterFileOUT << "\n" << "Equipped Sign: " << playerCharacter.getSigilEquipped() << endl;
        playerCharacterFileOUT << "\n" << "Equipped Sign Level: " << playerCharacter.getLegArmorLvl() << endl;
        playerCharacterFileOUT << "\n**********************\n" << endl;

        playerCharacterFileOUT << "Character Body: " << endl;
        playerCharacterFileOUT << "\n**********************\n" << endl;
        playerCharacterFileOUT << "\n" << "Equipped Right Weapon Arm: " << playerCharacter.getRightWeaponArmEquipped() << endl;
        playerCharacterFileOUT << "\n" << "Equipped Left Weapon Arm: " << playerCharacter.getLeftWeaponArmEquipped() << endl;
        playerCharacterFileOUT << "\n" << "Equipped Torso Armor: " << playerCharacter.getTorsoArmor() << endl;
        playerCharacterFileOUT << "\n" << "Equipped Leg Armor: " << playerCharacter.getLegArmor() << endl;
        playerCharacterFileOUT << "\n" << "Equipped HeadGear: " << playerCharacter.getHeadArmor() << endl;
        playerCharacterFileOUT << "\n" << "Equipped Sign: " << playerCharacter.getSigilEquipped() << endl;
        playerCharacterFileOUT << "\n" << "Equipped Bracer:  " << playerCharacter.getArmBracer() << endl;
        playerCharacterFileOUT << "\n**********************\n" << endl;

        cout << endl;

        //Close text files
        playerCharacterFileOUT.close();
        playerWeapons.close();

        //Give player the option to elevate to next class associated with their current class
        cout << "Change Class? N/Y" << endl;
        cin >> userInput;

        cout << endl;

        /*If player wishes to elevate to next class, 
        call class function to display next classes to elevate to.*/
        if (tolower(userInput) == 'y')
        {
            playerCharacter.characterClassChanger();

            //Blade Dancer and Gladiator are a part of the Warrior class tree
            if (playerCharacter.getCharacterClass() == "BladeDancer")
            {
                //Blade Dancer is a Dual-Wielder, automatically change weapons
                cout << "\nChange Weapons: " << endl;

                playerCharacter.generateWeapons();
            }

            /*Changing to Gladiator changes weapon class to Spear from Sword
            Automatically trigger weapon change*/
            else if (playerCharacter.getCharacterClass() == "Gladiator")
            {
                cout << "\n Change Weapon Class to from Sword to Spear? Y/N" << endl;
                cin >> weaponChangeInput;

                if (tolower(weaponChangeInput == 'y'))
                {
                    playerCharacter.setCharacterWeapon("Spear");
                    playerCharacter.generateWeapons();
                }
            }

            /*Shinobi elevates from Renegade and can continue to Dual-Wield Daggers
            or switch to Solo-Wield with Fuma Shurikens*/
            if (playerCharacter.getCharacterClass() == "Shinobi")
            {
                cout << "Change Weapon Class from Daggers to Fuma Shuriken? Y/N" << endl;
                cin >> weaponChangeInput;

                if (tolower(weaponChangeInput == 'y'))
                {
                    playerCharacter.setCharacterWeapon("FumaShuriken");
                    playerCharacter.generateWeapons();
                }
            }

            else if (playerCharacter.getCharacterClass() == "Shinobi" && weaponChangeInput == 'n')
            {
                cout << "\nChange Weapons? Y/N" << endl;
                cin >> userInput;

                if (tolower(userInput == 'y'))
                {
                    playerCharacter.generateWeapons();
                }
            }
            
            /*Knight elevates from Guardian and give player option to change from a Sword and Shield to a GreatSword
            And change weapons if chosen to do so*/
            if (playerCharacter.getCharacterClass() == "Knight" && playerCharacter.getCharacterWeapon() == "SwordAndShield")
            {
                cout << "Change Weapon Class from SwordAndShield to GreatSword? Y / N" << endl;
                cin >> weaponChangeInput;

                if (tolower(weaponChangeInput == 'y'))
                {
                    playerCharacter.setCharacterWeapon("GreatSword");
                    playerCharacter.generateWeapons();
                }
            }

            /*Knight elevates from Guardian and give player option to change from a GreatSword to Sword and Shield
            And change weapons if chosen to do so*/
            else if (playerCharacter.getCharacterClass() == "Knight" && playerCharacter.getCharacterWeapon() == "GreatSword")
            {
                cout << "Change Weapon Class from GreatSword to SwordAndShield? Y / N" << endl;
                cin >> weaponChangeInput;

                if (tolower(weaponChangeInput == 'y'))
                {
                    playerCharacter.setCharacterWeapon("SwordAndShield");
                    playerCharacter.generateWeapons();
                }
            }

            /*Templar elevates from Guardian and give player option to change from a Sword and Shield to a GreatSword
            And change weapons if chosen to do so*/
            if (playerCharacter.getCharacterClass() == "Templar" && playerCharacter.getCharacterWeapon() == "SwordAndShield")
            {
                cout << "Change Weapon Class from SwordAndShield to GreatSword? Y / N" << endl;
                cin >> weaponChangeInput;

                if (tolower(weaponChangeInput == 'y'))
                {
                    playerCharacter.setCharacterWeapon("GreatSword");
                    playerCharacter.generateWeapons();
                }
            }

            /*Templar elevates from Guardian and give player option to change from a GreatSword to Sword and Shield
            And change weapons if chosen to do so*/
            else if (playerCharacter.getCharacterClass() == "Templar" && playerCharacter.getCharacterWeapon() == "GreatSword")
            {
                cout << "Change Weapon Class from GreatSword to SwordAndShield? Y / N" << endl;
                cin >> weaponChangeInput;

                if (tolower(weaponChangeInput == 'y'))
                {
                    playerCharacter.setCharacterWeapon("SwordAndShield");
                    playerCharacter.generateWeapons();
                }
            }

            /*ShotMeister elevates from Guardian and give player option to change from a CrossBow to Sword and Shield
            And change weapons if chosen to do so*/
            if (playerCharacter.getCharacterClass() == "ShotMeister" && playerCharacter.getCharacterWeapon() == "CrossBow")
            {
                cout << "Change Weapon Class from CrossBow to BowAndArrow? Y / N" << endl;
                cin >> weaponChangeInput;

                if (tolower(weaponChangeInput == 'y'))
                {
                    playerCharacter.setCharacterWeapon("BowAndArrow");
                    playerCharacter.generateWeapons();
                }
            }

            /*ShotMeister elevates from Guardian and give player option to change from a Bow and Arrow to CrossBow
            And change weapons if chosen to do so*/
            else if (playerCharacter.getCharacterClass() == "ShotMeister" && playerCharacter.getCharacterWeapon() == "BowAndArrow")
            {
                cout << "Change Weapon Class from BowAndArrow to CrossBow? Y / N" << endl;
                cin >> weaponChangeInput;

                if (tolower(weaponChangeInput == 'y'))
                {
                    playerCharacter.setCharacterWeapon("CrossBow");
                    playerCharacter.generateWeapons();
                }
            }

            /*BeastKaiser elevates from Hunter and give player option to change from a CrossBow to Sword and Shield
            And change weapons if chosen to do so*/
            if (playerCharacter.getCharacterClass() == "BeastKaiser" && playerCharacter.getCharacterWeapon() == "CrossBow")
            {
                cout << "Change Weapon Class from CrossBow to BowAndArrow? Y / N" << endl;
                cin >> weaponChangeInput;

                if (tolower(weaponChangeInput == 'y'))
                {
                    playerCharacter.setCharacterWeapon("BowAndArrow");
                    playerCharacter.generateWeapons();
                }
            }

            /*BeastKaiser elevates from Hunter and give player option to change from a Bow and Arrow to CrossBow
            And change weapons if chosen to do so*/
            else if (playerCharacter.getCharacterClass() == "BeastKaiser" && playerCharacter.getCharacterWeapon() == "BowAndArrow")
            {
                cout << "Change Weapon Class from BowAndArrow to CrossBow? Y / N" << endl;
                cin >> weaponChangeInput;

                if (tolower(weaponChangeInput == 'y'))
                {
                    playerCharacter.setCharacterWeapon("CrossBow");
                    playerCharacter.generateWeapons();
                }
            }

            /*If the chosen next class isn't any of the classes listed, 
            simply give option to change weapons*/
            else if (playerCharacter.getCharacterClass() != "Shinobi" &&
                playerCharacter.getCharacterClass() != "Knight" &&
                playerCharacter.getCharacterClass() != "Templar" &&
                playerCharacter.getCharacterClass() != "ShotMeister" &&
                playerCharacter.getCharacterClass() != "BeastKaiser" &&
                playerCharacter.getCharacterClass() != "BladeDancer" &&
                playerCharacter.getCharacterClass() != "Gladiator")
            {
                cout << "\nChange Weapons? Y/N" << endl;
                cin >> userInput;

                if (tolower(userInput == 'y'))
                {
                    playerCharacter.generateWeapons();
                }
            }

            //Give option to change armor, Headgear, etc
            cout << "\nChange Torso Armor? Y/N" << endl;
            cin >> userInput;

            if (tolower(userInput == 'y'))
            {
                playerCharacter.generateEquippedTorso();
            }

            cout << "\nChange HeadGear? Y/N" << endl;
            cin >> userInput;

            if (tolower(userInput == 'y'))
            {
                playerCharacter.generateHeadGear();
            }

            cout << "\nChange Bracer? Y/N" << endl;
            cin >> userInput;

            if (tolower(userInput == 'y'))
            {
                playerCharacter.generateArmBracer();
            }

            cout << "\nChange Leg Armor? Y/N" << endl;
            cin >> userInput;

            if (tolower(userInput == 'y'))
            {
                playerCharacter.generateLegArmor();
            }

            cout << "\nChange Sigil? Y/N" << endl;
            cin >> userInput;

            if (tolower(userInput == 'y'))
            {
                playerCharacter.generateSigil();
            }

            /*Delete original Player Character Profile text file and create new one
              and output all character info into it*/
            remove("PlayerCharacterProfile.txt");

            playerCharacterFileOUT.open("PlayerCharacterProfile.txt");

            playerCharacterFileOUT << "Character Info: " << endl;

            playerCharacterFileOUT << "\n**********************" << endl;

            playerCharacterFileOUT << "Name: " << playerCharacter.getName() << endl;
            playerCharacterFileOUT << "Level: " << playerCharacter.getLevel() << endl;
            playerCharacterFileOUT << "Class: " << playerCharacter.getCharacterClass() << endl;
            playerCharacterFileOUT << "Job Level: " << playerCharacter.getJobLevel() << endl;
            playerCharacterFileOUT << "\nCharacter Weapon: " << endl;
            playerCharacterFileOUT << "\n" << playerCharacter.getCharacterWeapon() << endl;
            playerCharacterFileOUT << "\nArmor Type: " << endl;
            playerCharacterFileOUT << "\n" << playerCharacter.getArmorType() << endl;
            playerCharacterFileOUT << "\nBracer Type: " << endl;
            playerCharacterFileOUT << "\n" << playerCharacter.getArmType() << endl;
            playerCharacterFileOUT << "\nLegArmor Type: " << endl;
            playerCharacterFileOUT << "\n" << playerCharacter.getLegType() << endl;
            playerCharacterFileOUT << "\nAncestry: " << endl;
            playerCharacterFileOUT << "\n" << playerCharacter.getCharacterRace() << endl;

            if (playerCharacter.getCharacterRace() == "Feral")
            {
                playerCharacterFileOUT << " (Type: " << playerCharacter.getFeralType() << " )" << endl;
            }

            playerCharacterFileOUT << "\n**********************\n" << endl;

            playerCharacterFileOUT << "Character Stats: " << endl;

            playerCharacterFileOUT << "\n**********************" << endl;
            playerCharacterFileOUT << "HP: " << playerCharacter.getCharacterHP() << endl;
            playerCharacterFileOUT << "SP: " << playerCharacter.getCharacterSP() << endl;
            playerCharacterFileOUT << "Strength: " << playerCharacter.getCharacterStr() << endl;
            playerCharacterFileOUT << "Agility: " << playerCharacter.getCharacterAgi() << endl;
            playerCharacterFileOUT << "Vitality: " << playerCharacter.getCharacterVit() << endl;
            playerCharacterFileOUT << "Dexterity: " << playerCharacter.getCharacterDex() << endl;
            playerCharacterFileOUT << "Intelligence: " << playerCharacter.getCharacterInt() << endl;
            playerCharacterFileOUT << "Luck: " << playerCharacter.getCharacterLuk() << endl;

            playerCharacterFileOUT << "\n**********************" << endl;

            playerCharacterFileOUT << "Character Equipment: " << endl;

            playerCharacterFileOUT << "\n**********************" << endl;

            playerCharacterFileOUT << "\n" << "Equipped Weapon: " << playerCharacter.getEquippedWeapon() << endl;
            playerCharacterFileOUT << "\n" << "Equipped Weapon Level: " << playerCharacter.getWeaponLevel() << endl;
            playerCharacterFileOUT << "\n" << "Equipped Second Weapon: " << playerCharacter.getEquippedSecondWeapon() << endl;
            playerCharacterFileOUT << "\n" << "Equipped Second Weapon Level: " << playerCharacter.getSecondWeaponLevel() << endl;
            playerCharacterFileOUT << "\n" << "Equipped Armor: " << playerCharacter.getTorsoArmor() << endl;
            playerCharacterFileOUT << "\n" << "Equipped Armor Level: " << playerCharacter.getArmorLvl() << endl;
            playerCharacterFileOUT << "\n" << "Equipped Helm: " << playerCharacter.getHeadArmor() << endl;
            playerCharacterFileOUT << "\n" << "Equipped Helm Level: " << playerCharacter.getHeadArmorLvl() << endl;
            playerCharacterFileOUT << "\n" << "Equipped Bracer: " << playerCharacter.getArmBracer() << endl;
            playerCharacterFileOUT << "\n" << "Equipped Bracer Level: " << playerCharacter.getArmBracerLvl() << endl;
            playerCharacterFileOUT << "\n" << "Equipped Leg Armor: " << playerCharacter.getLegArmor() << endl;
            playerCharacterFileOUT << "\n" << "Equipped Leg Armor Level: " << playerCharacter.getLegArmorLvl() << endl;
            playerCharacterFileOUT << "\n" << "Equipped Sign: " << playerCharacter.getSigilEquipped() << endl;
            playerCharacterFileOUT << "\n" << "Equipped Sign Level: " << playerCharacter.getSigilLvl() << endl;
            playerCharacterFileOUT << "\n**********************\n" << endl;

            playerCharacterFileOUT << "Character Body: " << endl;
            playerCharacterFileOUT << "\n**********************\n" << endl;
            playerCharacterFileOUT << "\n" << "Equipped Right Weapon Arm: " << playerCharacter.getRightWeaponArmEquipped() << endl;
            playerCharacterFileOUT << "\n" << "Equipped Left Weapon Arm: " << playerCharacter.getLeftWeaponArmEquipped() << endl;
            playerCharacterFileOUT << "\n" << "Equipped Torso Armor: " << playerCharacter.getTorsoArmor() << endl;
            playerCharacterFileOUT << "\n" << "Equipped HeadGear: " << playerCharacter.getHeadArmor() << endl;
            playerCharacterFileOUT << "\n" << "Equipped Leg Armor: " << playerCharacter.getLegArmor() << endl;
            playerCharacterFileOUT << "\n" << "Equipped Sign: " << playerCharacter.getSigilEquipped() << endl;
            playerCharacterFileOUT << "\n" << "Equipped Bracer:  " << playerCharacter.getArmBracer() << endl;
            playerCharacterFileOUT << "\n**********************\n" << endl;

            playerCharacterFileOUT.close();

            cout << "\nCharacter Created! " << endl;

           playerCharacterMetaFileOUT.open("PlayerCharacterMetaFile.txt");

           playerCharacterMetaFileOUT << playerCharacter.getName() << " ";
           playerCharacterMetaFileOUT << playerCharacter.getCharacterClass() << " ";
           playerCharacterMetaFileOUT << playerCharacter.getCharacterWeapon() << " ";
           playerCharacterMetaFileOUT << playerCharacter.getArmorType() << " ";
           playerCharacterMetaFileOUT << playerCharacter.getArmType() << " ";
           playerCharacterMetaFileOUT << playerCharacter.getLegType() << " ";
           playerCharacterMetaFileOUT << playerCharacter.getEquippedWeapon() << " ";
           playerCharacterMetaFileOUT << playerCharacter.getEquippedSecondWeapon() << " ";
           playerCharacterMetaFileOUT << playerCharacter.getTorsoArmor() << " ";
           playerCharacterMetaFileOUT << playerCharacter.getHeadArmor() << " ";
           playerCharacterMetaFileOUT << playerCharacter.getArmBracer() << " ";
           playerCharacterMetaFileOUT << playerCharacter.getLegArmor() << " ";
           playerCharacterMetaFileOUT << playerCharacter.getSigilEquipped() << " ";
           playerCharacterMetaFileOUT << playerCharacter.getCharacterRace() << " ";

           if (playerCharacter.getCharacterRace() == "Feral")
           {
               playerCharacterMetaFileOUT << playerCharacter.getFeralType() << " ";
           }

           playerCharacterMetaFileOUT << playerCharacter.getLevel() << " ";
           playerCharacterMetaFileOUT << playerCharacter.getJobLevel() << " ";
           playerCharacterMetaFileOUT << playerCharacter.getCharacterHP() << " ";
           playerCharacterMetaFileOUT << playerCharacter.getCharacterSP() << " ";
           playerCharacterMetaFileOUT << playerCharacter.getCharacterStr() << " ";
           playerCharacterMetaFileOUT << playerCharacter.getCharacterAgi() << " ";
           playerCharacterMetaFileOUT << playerCharacter.getCharacterVit() << " ";
           playerCharacterMetaFileOUT << playerCharacter.getCharacterInt() << " ";
           playerCharacterMetaFileOUT << playerCharacter.getCharacterDex() << " ";
           playerCharacterMetaFileOUT << playerCharacter.getCharacterLuk() << " ";
           playerCharacterMetaFileOUT << playerCharacter.getArmorLvl() << " ";
           playerCharacterMetaFileOUT << playerCharacter.getHeadArmorLvl() << " ";
           playerCharacterMetaFileOUT << playerCharacter.getArmBracerLvl() << " ";
           playerCharacterMetaFileOUT << playerCharacter.getLegArmorLvl() << " ";
           playerCharacterMetaFileOUT << playerCharacter.getWeaponLevel() << " ";
           playerCharacterMetaFileOUT << playerCharacter.getSecondWeaponLevel() << " ";
           playerCharacterMetaFileOUT << playerCharacter.getSigilLvl() << " ";

           playerCharacterMetaFileOUT.close();
        }

        //If player chooses to not elevate to next class, output all information to PC Metadata File
        else if (tolower(userInput) == 'n')
        {
            cout << "Character Created! " << endl;

            playerCharacterMetaFileOUT.open("PlayerCharacterMetaFile.txt");

            playerCharacterMetaFileOUT << playerCharacter.getName() << " ";
            playerCharacterMetaFileOUT << playerCharacter.getCharacterClass() << " ";
            playerCharacterMetaFileOUT << playerCharacter.getCharacterWeapon() << " ";
            playerCharacterMetaFileOUT << playerCharacter.getArmorType() << " ";
            playerCharacterMetaFileOUT << playerCharacter.getArmType() << " ";
            playerCharacterMetaFileOUT << playerCharacter.getLegType() << " ";
            playerCharacterMetaFileOUT << playerCharacter.getEquippedWeapon() << " ";
            playerCharacterMetaFileOUT << playerCharacter.getEquippedSecondWeapon() << " ";
            playerCharacterMetaFileOUT << playerCharacter.getTorsoArmor() << " ";
            playerCharacterMetaFileOUT << playerCharacter.getHeadArmor() << " ";
            playerCharacterMetaFileOUT << playerCharacter.getArmBracer() << " ";
            playerCharacterMetaFileOUT << playerCharacter.getLegArmor() << " ";
            playerCharacterMetaFileOUT << playerCharacter.getSigilEquipped() << " ";
            playerCharacterMetaFileOUT << playerCharacter.getCharacterRace() << " ";

            if (playerCharacter.getCharacterRace() == "Feral")
            {
                playerCharacterMetaFileOUT << playerCharacter.getFeralType() << " ";
            }

            playerCharacterMetaFileOUT << playerCharacter.getLevel() << " ";
            playerCharacterMetaFileOUT << playerCharacter.getJobLevel() << " ";
            playerCharacterMetaFileOUT << playerCharacter.getCharacterHP() << " ";
            playerCharacterMetaFileOUT << playerCharacter.getCharacterSP() << " ";
            playerCharacterMetaFileOUT << playerCharacter.getCharacterStr() << " ";
            playerCharacterMetaFileOUT << playerCharacter.getCharacterAgi() << " ";
            playerCharacterMetaFileOUT << playerCharacter.getCharacterVit() << " ";
            playerCharacterMetaFileOUT << playerCharacter.getCharacterInt() << " ";
            playerCharacterMetaFileOUT << playerCharacter.getCharacterDex() << " ";
            playerCharacterMetaFileOUT << playerCharacter.getCharacterLuk() << " ";
            playerCharacterMetaFileOUT << playerCharacter.getArmorLvl() << " ";
            playerCharacterMetaFileOUT << playerCharacter.getHeadArmorLvl() << " ";
            playerCharacterMetaFileOUT << playerCharacter.getArmBracerLvl() << " ";
            playerCharacterMetaFileOUT << playerCharacter.getLegArmorLvl() << " ";
            playerCharacterMetaFileOUT << playerCharacter.getWeaponLevel() << " ";
            playerCharacterMetaFileOUT << playerCharacter.getSecondWeaponLevel() << " ";
            playerCharacterMetaFileOUT << playerCharacter.getSigilLvl() << " ";
            playerCharacterMetaFileOUT.close();
        }     

        //Display class skills and also output to Profile text file
        if (playerCharacter.getPrevClass() == "Null")
        {
            playerCharacter.setClassSkills();
            playerCharacter.getClassSkills();
        }
        
        if (playerCharacter.getCharacterClass() == "Gladiator")
        {
            playerCharacter.setSecondClassSkills();
            playerCharacter.getSecondClassSkills();
        }

        else if (playerCharacter.getCharacterClass() == "BladeDancer")
        {
            playerCharacter.setSecondClassSkills();
            playerCharacter.getSecondClassSkills();
        }

        else if (playerCharacter.getCharacterClass() == "Alchemist")
        {
            playerCharacter.setSecondClassSkills();
            playerCharacter.getSecondClassSkills();
        }

        else if (playerCharacter.getCharacterClass() == "Engineer")
        {
            playerCharacter.setSecondClassSkills();
            playerCharacter.getSecondClassSkills();
        }

        else if (playerCharacter.getCharacterClass() == "Monk")
        {
            playerCharacter.setSecondClassSkills();
            playerCharacter.getSecondClassSkills();
        }

        else if (playerCharacter.getCharacterClass() == "Dominator")
        {
            playerCharacter.setSecondClassSkills();
            playerCharacter.getSecondClassSkills();
        }

        else if (playerCharacter.getCharacterClass() == "Desperado")
        {
            playerCharacter.setSecondClassSkills();
            playerCharacter.getSecondClassSkills();
        }

        else if (playerCharacter.getCharacterClass() == "Mercenary")
        {
            playerCharacter.setSecondClassSkills();
            playerCharacter.getSecondClassSkills();
        }

        else if (playerCharacter.getCharacterClass() == "Shinobi")
        {
            playerCharacter.setSecondClassSkills();
            playerCharacter.getSecondClassSkills();
        }

        else if (playerCharacter.getCharacterClass() == "Rebel")
        {
            playerCharacter.setSecondClassSkills();
            playerCharacter.getSecondClassSkills();
        }

        else if (playerCharacter.getCharacterClass() == "Raider")
        {
            playerCharacter.setSecondClassSkills();
            playerCharacter.getSecondClassSkills();
        }

        else if (playerCharacter.getCharacterClass() == "Savager")
        {
            playerCharacter.setSecondClassSkills();
            playerCharacter.getSecondClassSkills();
        }

        else if (playerCharacter.getCharacterClass() == "Shaman")
        {
            playerCharacter.setSecondClassSkills();
            playerCharacter.getSecondClassSkills();
        }

        else if (playerCharacter.getCharacterClass() == "SoulWielder")
        {
            playerCharacter.setSecondClassSkills();
            playerCharacter.getSecondClassSkills();
        }

        else if (playerCharacter.getCharacterClass() == "BeastKaiser")
        {
            playerCharacter.setSecondClassSkills();
            playerCharacter.getSecondClassSkills();
        }

        else if (playerCharacter.getCharacterClass() == "ShotMeister")
        {
            playerCharacter.setSecondClassSkills();
            playerCharacter.getSecondClassSkills();
        }

        else if (playerCharacter.getCharacterClass() == "Knight")
        {
            playerCharacter.setSecondClassSkills();
            playerCharacter.getSecondClassSkills();
        }

        else if (playerCharacter.getCharacterClass() == "Templar")
        {
            playerCharacter.setSecondClassSkills();
            playerCharacter.getSecondClassSkills();
        }
        
        else if (playerCharacter.getCharacterClass() == "Occulter")
        {
            playerCharacter.setSecondClassSkills();
            playerCharacter.getSecondClassSkills();
        }

        else if (playerCharacter.getCharacterClass() == "Sorcerer")
        {
            playerCharacter.setSecondClassSkills();
            playerCharacter.getSecondClassSkills();
        }

        else if (playerCharacter.getCharacterClass() == "ShadowWalker")
        {
            playerCharacter.setSecondClassSkills();
            playerCharacter.getSecondClassSkills();
        }

        else if (playerCharacter.getCharacterClass() == "Executioner")
        {
            playerCharacter.setSecondClassSkills();
            playerCharacter.getSecondClassSkills();
        }
    }

    //If player chooses to upload created character, call function to upload from Metadata file
    else if (userInput == 'u')
    {
        characterUploader();
    }

    /*cout << "Fight an enemy?" << endl;
    cin >> userInput;

    if (tolower(userInput) == 'y')
    {
        //generateFight();
    }*/

    cin.get();
}

string classSelector(int wNum)
{
    string fileContent2;
    string charClass;
    char classInput;

    vector<string> characterClass;

    ifstream characterClassFile;

    cout << "\nAvailable Character Classes:\n" << endl;

    characterClassFile.open("PlayerCharacterClasses.txt");

    while (characterClassFile >> fileContent2)
    {
        characterClass.push_back(fileContent2);
    }

    for (int i = 0; i < characterClass.size() / 2; ++i)
    {
        cout << i << ") " << characterClass[i] << " ";
    }

    cout << "\n";

    for (int i = characterClass.size() / 2; i < characterClass.size(); ++i)
    {
        cout << i << ") " << characterClass[i] << " ";
    }

    cout << "\n\n";

    if (wNum == 0)//Sword -> Warrior or Artisan
    {
        cout << "Warrior 'w' or Artisan 'a' ? " << endl;
        cin >> classInput;

        switch (classInput)
        {
            case'w':

                charClass = characterClass[0];
            break;

            case'a':

                charClass = characterClass[1];
            break;

            default:
                cout << "Invalid class choice..." << endl;
                exit(0);
        }
    }

    else if (wNum == 1)//Gauntlets -> Breaker
    {
        charClass = characterClass[2];
    }

    else if (wNum == 2)//Guns -> TriggerMaster
    {
        charClass = characterClass[3];
    }

    else if (wNum == 3)//Daggers -> Renegade
    {
        charClass = characterClass[4];
    }

    else if (wNum == 4 || wNum == 5)//Sword and Shield or GreatSword -> Guardian
    {
        charClass = characterClass[5];
    }

    else if (wNum == 6)//Bracelet -> EnergyMaster
    {
        charClass = characterClass[6];
    }

    else if (wNum == 7)//Axes -> Ravager
    {
        charClass = characterClass[7];
    }

    else if (wNum == 8 || wNum == 9)//Bow and Arrow or CrossBow -> Hunter
    {
        charClass = characterClass[8];
    }

    else if (wNum == 10)//Magic -> Sage
    {
        charClass = characterClass[9];
    }

    else if (wNum == 11)//Claws -> Assassin
    {
        charClass = characterClass[10];
    }

    return charClass;

    characterClassFile.close();
}

//Function to upload created character with Metadata file
void characterUploader()
{
    string createdPlayerName;
    string playerClass;
    string weaponType;
    string aType;
    string bType;
    string legType;
    string equippedMainWep;
    string equippedOffWep;
    string equippedArmor;
    string equippedHelm;
    string equippedBracer;
    string equippedLeg;
    string equippedSign;
    string race;
    string raceType;
    string classSearch;
    string classSecondSearch;

    double charLvl; 
    double charJobLvl; 
    double charHP; 
    double charSP; 
    double charStr; 
    double charAgi; 
    double charVit; 
    double charInt; 
    double charDex; 
    double charLuk;
    double armorLevel; 
    double headLevel; 
    double armLevel; 
    double legLevel; 
    double firstWepLevel; 
    double secondWepLevel; 
    double signLevel;

    //bool found = false;

    ifstream playerCharacterFileIN;
    ifstream characterFirstBranch;
    ifstream characterSecondBranch;

    //Open metadata file
    playerCharacterFileIN.open("PlayerCharacterMetaFile.txt");
    /*characterFirstBranch.open("PlayerCharacterClassFirstBranch.txt");
    characterSecondBranch.open("PlayerCharacterClassSecondBranch.txt");*/

    //Feed all information from Metadata file into the appropriate variables in sequence
    while (playerCharacterFileIN >> createdPlayerName)
    {
        playerCharacterFileIN >> playerClass;
        playerCharacterFileIN >> weaponType;
        playerCharacterFileIN >> aType;
        playerCharacterFileIN >> bType;
        playerCharacterFileIN >> legType;
        playerCharacterFileIN >> equippedMainWep;
        playerCharacterFileIN >> equippedOffWep;
        playerCharacterFileIN >> equippedArmor;
        playerCharacterFileIN >> equippedHelm;
        playerCharacterFileIN >> equippedBracer;
        playerCharacterFileIN >> equippedLeg;
        playerCharacterFileIN >> equippedSign;
        playerCharacterFileIN >> race;
        playerCharacterFileIN >> raceType;
        playerCharacterFileIN >> charLvl;
        playerCharacterFileIN >> charJobLvl;
        playerCharacterFileIN >> charHP;
        playerCharacterFileIN >> charSP;
        playerCharacterFileIN >> charStr;
        playerCharacterFileIN >> charAgi;
        playerCharacterFileIN >> charVit;
        playerCharacterFileIN >> charInt;
        playerCharacterFileIN >> charDex;
        playerCharacterFileIN >> charLuk;
        playerCharacterFileIN >> armorLevel;
        playerCharacterFileIN >> headLevel;
        playerCharacterFileIN >> armLevel;
        playerCharacterFileIN >> legLevel;
        playerCharacterFileIN >> firstWepLevel;
        playerCharacterFileIN >> secondWepLevel;
        playerCharacterFileIN >> signLevel;
    }

    //Create class object to upload character with all required arguments
    GameCharacterCreator playerCharacter(createdPlayerName, playerClass, weaponType, aType, bType, legType, equippedMainWep, equippedOffWep, equippedArmor, 
        equippedHelm, equippedBracer, equippedLeg, equippedSign, race, raceType, charLvl, charJobLvl, charHP, charSP, charStr, charAgi, charVit, charInt, charDex,
        charLuk, armorLevel, headLevel, armLevel, legLevel, firstWepLevel, secondWepLevel, signLevel);

    //Display
    cout << "\n******************************" << endl;
    cout << "Name: " << playerCharacter.getName() << endl;
    cout << "Level: " << playerCharacter.getLevel() << endl;
    cout << "Class: " << playerCharacter.getCharacterClass() << endl;
    cout << "Job Level: " << playerCharacter.getJobLevel() << endl;
    cout << "\nCharacter Weapon: " << endl;
    cout << "\n" << playerCharacter.getCharacterWeapon() << endl;
    cout << "\nArmor Type: " << endl;
    cout << "\n" << playerCharacter.getArmorType() << endl;
    cout << "\nBracer Type: " << endl;
    cout << "\n" << playerCharacter.getArmType() << endl;
    cout << "\nLegArmor Type: " << endl;
    cout << "\n" << playerCharacter.getLegType() << endl;
    cout << "\nAncestry: " << endl;
    cout << "\n" << playerCharacter.getCharacterRace() << endl;

    if (playerCharacter.getCharacterRace() == "Feral")
    {
        cout << " (Type: " << playerCharacter.getFeralType() << " )" << endl;
    }

    cout << "\n**********************\n" << endl;

    cout << "Character Stats: " << endl;

    cout << "\n**********************" << endl;
    cout << "HP: " << playerCharacter.getCharacterHP() << endl;
    cout << "SP: " << playerCharacter.getCharacterSP() << endl;
    cout << "Strength: " << playerCharacter.getCharacterStr() << endl;
    cout << "Agility: " << playerCharacter.getCharacterAgi() << endl;
    cout << "Vitality: " << playerCharacter.getCharacterVit() << endl;
    cout << "Dexterity: " << playerCharacter.getCharacterDex() << endl;
    cout << "Intelligence: " << playerCharacter.getCharacterInt() << endl;
    cout << "Luck: " << playerCharacter.getCharacterLuk() << endl;

    cout << "\n**********************" << endl;

    cout << "Character Equipment: " << endl;

    cout << "\n**********************" << endl;
    cout << "\n" << "Equipped Weapon: " << playerCharacter.getEquippedWeapon() << endl;
    cout << "\n" << "Equipped Weapon Level: " << playerCharacter.getWeaponLevel() << endl;
    cout << "\n" << "Equipped Second Weapon: " << playerCharacter.getEquippedSecondWeapon() << endl;
    cout << "\n" << "Equipped Second Weapon Level: " << playerCharacter.getSecondWeaponLevel() << endl;
    cout << "\n" << "Equipped Armor: " << playerCharacter.getTorsoArmor() << endl;
    cout << "\n" << "Equipped Armor Level: " << playerCharacter.getArmorLvl() << endl;
    cout << "\n" << "Equipped Helm: " << playerCharacter.getHeadArmor() << endl;
    cout << "\n" << "Equipped Helm Level: " << playerCharacter.getHeadArmorLvl() << endl;
    cout << "\n" << "Equipped Bracer: " << playerCharacter.getArmBracer() << endl;
    cout << "\n" << "Equipped Bracer Level: " << playerCharacter.getArmBracerLvl() << endl;
    cout << "\n" << "Equipped Leg Armor: " << playerCharacter.getLegArmor() << endl;
    cout << "\n" << "Equipped Leg Armor Level: " << playerCharacter.getLegArmorLvl() << endl;
    cout << "\n" << "Equipped Sign: " << playerCharacter.getSigilEquipped() << endl;
    cout << "\n" << "Equipped Sign Level: " << playerCharacter.getLegArmorLvl() << endl;
    cout << "\n**********************\n" << endl;

    cout << "Character Body: " << endl;
    cout << "\n**********************\n" << endl;
    cout << "\n" << "Equipped Right Weapon Arm: " << playerCharacter.getRightWeaponArmEquipped() << endl;
    cout << "\n" << "Equipped Left Weapon Arm: " << playerCharacter.getLeftWeaponArmEquipped() << endl;
    cout << "\n" << "Equipped Torso Armor: " << playerCharacter.getTorsoArmor() << endl;
    cout << "\n" << "Equipped Leg Armor: " << playerCharacter.getLegArmor() << endl;
    cout << "\n" << "Equipped HeadGear: " << playerCharacter.getHeadArmor() << endl;
    cout << "\n" << "Equipped Sign: " << playerCharacter.getSigilEquipped() << endl;
    cout << "\n" << "Equipped Bracer:  " << playerCharacter.getArmBracer() << endl;
    cout << "\n**********************\n" << endl;

    cout << endl;

    /*cout << "Available Skills for: " << playerCharacter.getCharacterClass() << "\n**********************\n" << endl;
    
    while (characterFirstBranch >> classSearch)
    {
        if (playerCharacter.getCharacterClass() == classSearch)
        {
            found = true;

            playerCharacter.getSecondClassSkills();
        }

        else
        {
            playerCharacter.getClassSkills();
        }
    }

    while (characterSecondBranch >> classSecondSearch)
    {
        if (playerCharacter.getCharacterClass() == classSecondSearch)
        {
            found = true;

            playerCharacter.getSecondClassSkills();
        }

        else
        {
            playerCharacter.getClassSkills();
        }
    }

    cout << "\n**********************\n" << endl;*/

    //Close file
    playerCharacterFileIN.close();

    //Display skills
    if (playerCharacter.getPrevClass() == "Null")
    {
        playerCharacter.setClassSkills();
        playerCharacter.getClassSkills();
    }

    if (playerCharacter.getCharacterClass() == "Gladiator")
    {
        playerCharacter.setSecondClassSkills();
        playerCharacter.getSecondClassSkills();
    }

    else if (playerCharacter.getCharacterClass() == "BladeDancer")
    {
        playerCharacter.setSecondClassSkills();
        playerCharacter.getSecondClassSkills();
    }

    else if (playerCharacter.getCharacterClass() == "Alchemist")
    {
        playerCharacter.setSecondClassSkills();
        playerCharacter.getSecondClassSkills();
    }

    else if (playerCharacter.getCharacterClass() == "Engineer")
    {
        playerCharacter.setSecondClassSkills();
        playerCharacter.getSecondClassSkills();
    }

    else if (playerCharacter.getCharacterClass() == "Monk")
    {
        playerCharacter.setSecondClassSkills();
        playerCharacter.getSecondClassSkills();
    }

    else if (playerCharacter.getCharacterClass() == "Dominator")
    {
        playerCharacter.setSecondClassSkills();
        playerCharacter.getSecondClassSkills();
    }

    else if (playerCharacter.getCharacterClass() == "Desperado")
    {
        playerCharacter.setSecondClassSkills();
        playerCharacter.getSecondClassSkills();
    }

    else if (playerCharacter.getCharacterClass() == "Mercenary")
    {
        playerCharacter.setSecondClassSkills();
        playerCharacter.getSecondClassSkills();
    }

    else if (playerCharacter.getCharacterClass() == "Shinobi")
    {
        playerCharacter.setSecondClassSkills();
        playerCharacter.getSecondClassSkills();
    }

    else if (playerCharacter.getCharacterClass() == "Rebel")
    {
        playerCharacter.setSecondClassSkills();
        playerCharacter.getSecondClassSkills();
    }

    else if (playerCharacter.getCharacterClass() == "Raider")
    {
        playerCharacter.setSecondClassSkills();
        playerCharacter.getSecondClassSkills();
    }

    else if (playerCharacter.getCharacterClass() == "Savager")
    {
        playerCharacter.setSecondClassSkills();
        playerCharacter.getSecondClassSkills();
    }

    else if (playerCharacter.getCharacterClass() == "Shaman")
    {
        playerCharacter.setSecondClassSkills();
        playerCharacter.getSecondClassSkills();
    }

    else if (playerCharacter.getCharacterClass() == "SoulWielder")
    {
        playerCharacter.setSecondClassSkills();
        playerCharacter.getSecondClassSkills();
    }

    else if (playerCharacter.getCharacterClass() == "BeastKaiser")
    {
        playerCharacter.setSecondClassSkills();
        playerCharacter.getSecondClassSkills();
    }

    else if (playerCharacter.getCharacterClass() == "ShotMeister")
    {
        playerCharacter.setSecondClassSkills();
        playerCharacter.getSecondClassSkills();
    }

    else if (playerCharacter.getCharacterClass() == "Knight")
    {
        playerCharacter.setSecondClassSkills();
        playerCharacter.getSecondClassSkills();
    }

    else if (playerCharacter.getCharacterClass() == "Templar")
    {
        playerCharacter.setSecondClassSkills();
        playerCharacter.getSecondClassSkills();
    }

    else if (playerCharacter.getCharacterClass() == "Occulter")
    {
        playerCharacter.setSecondClassSkills();
        playerCharacter.getSecondClassSkills();
    }

    else if (playerCharacter.getCharacterClass() == "Sorcerer")
    {
        playerCharacter.setSecondClassSkills();
        playerCharacter.getSecondClassSkills();
    }

    else if (playerCharacter.getCharacterClass() == "ShadowWalker")
    {
        playerCharacter.setSecondClassSkills();
        playerCharacter.getSecondClassSkills();
    }


    else if (playerCharacter.getCharacterClass() == "Executioner")
    {
        playerCharacter.setSecondClassSkills();
        playerCharacter.getSecondClassSkills();
    }

    /*characterFirstBranch.close();
    characterSecondBranch.close();*/
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
