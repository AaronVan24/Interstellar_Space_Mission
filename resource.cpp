// CSCI 1300 Spring 2022
// Author: Aaron Van & D'Shawn Burkes
// Recitation: 201 - Tiffany Phan
// Project 3 - resource.cpp ...

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Resource.h"
#include "Planet.h"
#include "Player.h"
#include "Map.h"
#include "Inventory.h"
using namespace std;

// default constructor
Resource::Resource(){
    money = 100000;
    weaponPrice = 0;
    suitPrice = 0;
    fuel = 0;
    medicalSupply = 0;
    weapon = "Light Saber";
    suit = 1;
    translator = 0;
}

// parameterized constructor
Resource::Resource(double money_, int weaponP_, int suitP_, int fuel_, int medSupply_, string weapon_, int suit_, int translator_){
    money = money_;
    weaponPrice = weaponP_;
    suitPrice = suitP_;
    fuel = fuel_;
    medicalSupply = medSupply_;
    weapon = weapon_;
    suit = suit_;
    translator = translator_;
}

// getters
double Resource::getMoney(){
    return money;
}
int Resource::getWeaponPrice(){
    return weaponPrice;
}
int Resource::getSuitPrice(){
    return suitPrice;
}
int Resource::getFuel(){
    return fuel;
}
int Resource::getMedicalSupply(){
    return medicalSupply;
}
string Resource::getWeapon(){
    return weapon;
}
int Resource::getSuit(){
    return suit;
}
int Resource::getTranslator(){
    return translator;
}

// setters
void Resource::setMoney(double money_){
    money = money_;
}
void Resource::setWeaponPrice(int weaponP_){
    weaponPrice = weaponP_;
}
void Resource::setSuitPrice(int suitP_){
    suitPrice = suitP_;
}
void Resource::setFuel(int fuel_){
    fuel = fuel_;
}
void Resource::setMedicalSupply(int medSupply_){
    medicalSupply = medSupply_;
}
void Resource::setWeapon(string weapon_){
    weapon = weapon_;
}
void Resource::setSuit(int suit_){
    suit = suit_;
}
void Resource::setTranslator(int translator_){
    translator = translator_;
}

/*
 * Algorithm: Menu to display a shop to allow user to purchase items.
 * 1. print check if user has a translator or not
 * 2. print menu
 * Return: void
 */
void Resource::resourceMenu(){
    if (translator == 0){
        cout << "Which item do you wish to buy?" << endl << "1. Weapon" << endl << "2. Translator" << endl << "3. Space suit" << endl << "4. Medical Kits" << endl << "5. Fuel" << endl << "6. Purchase and Leave" << endl;
    }
    else {
        cout << "Which item do you wish to buy?" << endl << "1. Weapon" << endl << "3. Space suit" << endl << "4. Medical Kits" << endl << "5. Fuel" << endl << "6. Purchase and Leave" << endl;
    }
}
/*
 * Algorithm: A menu to display different kinds of weapons user can select and purchase from, this menu will display when user enters weapons in main menu.
 * 1. Create a list of weapons user can select from, 1. light saber, 2. blaster, 3. beam gun
 * 2. Depending on what weapon they choose, code will direct user to correct if-else statement.
 * 3. Inside each if-else statement, it will ask for quantity and calculate amount of money user has left to spend
 * 4. Have if-else statements to check for enough user money for user to continue to keep spending
 * 5. Have a if-else statement to check if user input is a valid input, if not let user know and have them reenter an input
 * Parameters: none
 * Return: void
 */
void Resource::weaponMenu(){
    int choice;
    int quantity;
    int i = 0;
    string ownWeapons[2];
    while (i < 2){
        cout << "Which weapon type do you wish to buy?" << endl << "1. Light Saber: $1,000" << endl << "2. Blaster: $2,000" << endl << "3. Beam Gun: $5,000" << endl << "4. Go back to menu" << endl;
        cin >> choice;
        cin.ignore();
        if (choice == 1){
            setWeaponPrice(1000);
            cout << "How many Light Sabers would you like ($1,000 each)?" << endl;
            cin >> quantity;
            cin.ignore();
            if (quantity > 2){
                cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                cin >> quantity;
                cin.ignore();
            }
            else if (quantity < 1){
                cout << "Re-enter a valid quantity." << endl;
                cin >> quantity;
                cin.ignore();
            }
            if (money >= (quantity * weaponPrice)){
                money = money - (quantity * weaponPrice);
                cout << "You have $" << money << " left." << endl;
            }
            else {
                cout << "You do not have enough money for that." << endl;
            }
        }
        else if (choice == 2){
            setWeaponPrice(2000);
            cout << "How many Blasters would you like ($2,000 each)?" << endl;
            cin >> quantity;
            cin.ignore();
            if (quantity > 2){
                cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                cin >> quantity;
                cin.ignore();
            }
            else if (quantity < 1){
                cout << "Re-enter a valid quantity." << endl;
                cin >> quantity;
                cin.ignore();
            }
            if (money >= (quantity * weaponPrice)){
                money = money - (quantity * weaponPrice);
                cout << "You have $" << money << " left." << endl;
            }
            else {
                cout << "You do not have enough money for that." << endl;
            }
        }
        else if (choice == 3){
            setWeaponPrice(5000);
            cout << "How many Beam Guns would you like ($5,000 each)?" << endl;
            cin >> quantity;
            cin.ignore();
            if (quantity > 2){
                cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                cin >> quantity;
                cin.ignore();
            }
            else if (quantity < 1){
                cout << "Re-enter a valid quantity." << endl;
                cin >> quantity;
                cin.ignore();
            }
            if (money >= (quantity * weaponPrice)){
                money = money - (quantity * weaponPrice);
                cout << "You have $" << money << " left." << endl;
            }
            else {
                cout << "You do not have enough money for that." << endl;
            }
        }
        else if (choice == 4){
            i = 2;
        }
        else {
            cout << "Re-enter a valid option." << endl;
            cin >> choice;
            cin.ignore();
        }
    }
}

/* 
* Algorithm: prints the menu for the suits
* 1. check the level of the suit user has
* 2. print the option for suits available
* 3. get users choice
* 4. check which option user chose
* 5. check if suit is lower than suit level user is seeking
* 6. set suit price
* 7. check if user has enough money
* 8. set suit level
* 9. calculate money left
* 10. print user new level suit and how much money they have left
* Parameters: none
* Return: void
*/
void Resource::suitMenu(){
    int choice;
    if (suit < 2){
        cout << "1. Space suit grade 2: $5,000" << endl << "2. Space suit grade 3: $10,000" << endl << "3. Space suit grade 4: $15,000" << endl << "4. Space suit grade 5: $20,000" << endl; 
        cin >> choice;
        cin.ignore();
        if (choice < 1 || choice > 4){
            cout << "Enter a valid choice." << endl;
            cin >> choice;
            cin.ignore();
        }
    }
    else if (suit < 3 and suit > 1){
        cout << "2. Space suit grade 3: $10,000" << endl << "3. Space suit grade 4: $15,000" << endl << "4. Space suit grade 5: $20,000" << endl; 
        cin >> choice;
        cin.ignore();
        if (choice < 2 || choice > 4){
            cout << "Enter a valid choice." << endl;
            cin >> choice;
            cin.ignore();
        }
    }
    else if (suit < 4 and suit > 2){
        cout << "3. Space suit grade 4: $15,000" << endl << "4. Space suit grade 5: $20,000" << endl; 
        cin >> choice;
        cin.ignore();
        if (choice < 3 || choice > 4){
            cout << "Enter a valid choice." << endl;
            cin >> choice;
            cin.ignore();
        }
    }
    else if (suit < 5 and suit > 3){
        cout << "4. Space suit grade 5: $20,000" << endl; 
        cin >> choice;
        cin.ignore();
        if (choice != 4){
            cout << "Enter a valid choice." << endl;
            cin >> choice;
            cin.ignore();
        }
    }
    if (choice == 1){
        if (suit < 2){
            setSuitPrice((2 - suit) * 5000);
            if (money >= suitPrice){
                setSuit(2);
                money = money - suitPrice;
                cout << "Your spacesuit is now a grade 2." << endl;
                cout << "You have $" << money << " left." << endl;
            }
            else {
                cout << "You do not have enough money for that." << endl;
            }
        }
    }
    else if (choice == 2){
        if (suit < 3){
            setSuitPrice((3 - suit) * 5000);
            if (money >= suitPrice){
                setSuit(3);
                money = money - suitPrice;
                cout << "Your spacesuit is now a grade 3." << endl;
                cout << "You have $" << money << " left." << endl;
            }
            else {
                cout << "You do not have enough money for that." << endl;
            }
        }
    }
    else if (choice == 3){
        if (suit < 4){
            setSuitPrice((4 - suit) * 5000);
            if (money >= suitPrice){
                setSuit(4);
                money = money - suitPrice;
                cout << "Your spacesuit is now a grade 4." << endl;
                cout << "You have $" << money << " left." << endl;
            }
            else {
                cout << "You do not have enough money for that." << endl;
            }
        }
    }
    else if (choice == 4){
        if (suit < 5){
            setSuitPrice((5 - suit) * 5000);
            if (money >= suitPrice){
                setSuit(5);
                money = money - suitPrice;
                cout << "Your spacesuit is now a grade 5." << endl;
                cout << "You have $" << money << " left." << endl;
            }
            else {
                cout << "You do not have enough money for that." << endl;
            }
        }
    }
}

/*
* Algorithm: prints medkit menu
* 1. ask user how many they'd like to buy
* 2. check if the user has enough storage room for quantity wanted
* 3. check if the user has enough money
* 4. calculate the money left after
* 5. print the amount of money user has left
* Parameters: none
* Return: void
*/
void Resource::medkitMenu(){
    int quantity;
    cout << "How many medical kits would you like to purchase ($2,000 each)? You currently have " << medicalSupply << ", and can at most have 5." << endl;
    cin >> quantity;
    cin.ignore();
    if (medicalSupply + quantity > 5){
        cout << "You cannot have more than 5 kits. Re-enter a valid quantity." << endl;
        cin >> quantity;
        cin.ignore();
    }
    else {
        if (money >= medKitPrice * quantity){
            setMedicalSupply(medicalSupply + quantity);
            money = money - (medKitPrice * quantity);
            cout << "You have $" << money << " left." << endl;
        }
        else {
            cout << "You do not have enough money for that." << endl;
        }
    }
}

/**
 * Algorithm: Menu to ask user if they want to purchase a translator
 * 1. Using a if-else statement to determine if user wants to purchase translator
 * 2. If user enters the character 'y', check if user has enough money, if they do, calculate the amount of money they have left and let user know. Return to main menu
 * 3. If user selects charcter 'n', let user know the amount of money they have left and exit to main menu
 * 4. If user input is not 'y' or 'n', let user know that it is an invalid input and prompt user to reenter until valid input is inputted
 * Parameters: none
 * Return: void
 */
void Resource::translatorMenu(){
    int choice;
    cout << "Would you like to purchase a translator device (%5,000)? 1 for yes, 0 for no." << endl;
    cin >> choice;
    cin.ignore();
    int i = 0;
    while (i < 1){
        if (choice == 1){
            if (money >= translatorPrice){
                setTranslator(1);
                money = money - translatorPrice;
                cout << "You have $" << money << " left." << endl;
                i = 1;
            }
            else {
                cout << "You do not have enough money for that." << endl;
                i = 1;
            }
        }
        else if (choice == 0){
            cout << "You have $" << money << " left." << endl;
            i = 1;
        }
        else {
            cout << "Re-enter a valid option." << endl;
            cin >> choice;
            cin.ignore();
        }
    }
}

/*
* Algorithm: Menu to calculate fuel prices depending on amount of fuel user wants to purchase in multiples of 10000 gallons
* 1. Cout a statement to let user know the amount of fuel they currently have and the maximum amount of fuel they can have.
* 2. Prompt user to enter the amount of gallons of fuel they want to purchase in multiples of 10000
* 3. Create if-else statement to check that user inputted value is in multiples of 10000, if not prompt user to reenter value until valid input is inputted
* 4. Once valid input is inputted, check if they have enough money, if not let user know 
* 5. If user has enough money, then check if they have exceeded or will exceed the maximum fuel tank, if they will, let user know and prompt them to reenter a value
* 6. Keep running menu until user exits 
* 7. Once user exits, prompt user back to main menu 
* Parameters: none
* Return: void
*/
// void Resource::fuelMenu(){
//     int amount;
//     Inventory inve;
//     int tank = inve.getFuelTank();
//     int cap = inve.getFuelTankCapicity();
//     cout << "You have " << tank << " gallons of fuel. Your spacecraft can hold 300k gallons of fuel. How many gallons would you like to purchase ($1,000 per 10,000 gallons)? Input must be in multiples of 10000s." << endl;
//     cin >> amount;
//     cin.ignore();
//     if(amount % 10000){
//         if (amount < cap){
//             if (cap <= tank + amount){
//                 if (money >= amount * fuelPrice){
//                     money = money - (amount * fuelPrice);
//                     cout << "You have $" << money << " left." << endl;
//                 }
//                 else {
//                     cout << "You do not have enough money for that." << endl;
//                 }
//             }
//             else {
//                 cout << "The fuel tank is already at capacity! So you cannot buy more." << endl;
//             }
//         }
//         else {
//             cout << "You cannot buy more fuel than the fuel tank's capacity, which is 400K." << endl;
//         }
//     }
//     else {
//         cout << "Input must be in multiples of 10000s. Re-enter a valid quantity." << endl;
//         cin >> amount;
//         cin.ignore();
//     }
// }

/**
 * Algorithm: Menu used to call within other cpp files and used to keep all menus created above organized
 * 1. Create if-else statements to operate each section of code and called upon via user input
 * 2. Check for invalid inputs, if it is let user know and have them reenter an input until valid input
 * Parameters: none
 * Return: void
 */
void Resource::resourceCenter(){
    int choice = 0;
    string enter = "";
    cout << "WEAPONS. If your weapon breaks or if you lose your weapon during an event, you may need additional weapons to defend yourself!" << endl;
    cout << "TRANSLATOR. Allows you to communicate with friendly aliens to get their assessment of the planet and increases odds of winning against a hostile alien." << endl;
    cout << "SPACE SUIT. The better the spacesuit, the more durable and protective you will be during the mission and an alien attack." << endl;
    cout << "MEDICAL KITS. The more kits you have, the more times you can revive your health by 40%." << endl;
    cout << "FUEL. Fuel is an essential element for the spacecraft to travel to more planets." << endl;
    cout << endl << "You can spend all of your money here before you start your journey, or you can save some to spend on different resources along the way. You will also gain money for each turn as you move through the game." << endl;
    cout << endl << "Hit enter when you have understood." << endl;
    getline(cin, enter);

    while (choice != 7){
        resourceMenu();
        cin >> choice;
        cin.ignore();
        if (choice == 1){
            weaponMenu();
        }
        else if (choice == 2){
            translatorMenu();
        }
        else if (choice == 3){
            suitMenu();
        }
        else if (choice == 4){
            medkitMenu();
        }
        else if (choice == 5){
            // fuelMenu();
        }
        else if (choice == 6){
            choice = 7;
        }
        else {
            cout << "Enter a valid choice." << endl;
            cin >> choice;
            cin.ignore();
        }
    }
}