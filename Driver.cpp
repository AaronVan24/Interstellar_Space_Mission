// CSCI 1300 Spring 2022
// Author: Aaron Van & D'Shawn Burkes
// Recitation: 201 - Tiffany Phan
// Project 3 - Driver.cpp ...

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Player.h"
#include "Resource.h"
#include "Planet.h"
#include "Inventory.h"
using namespace std;

int main(){

cout << endl;

    // Player class
    Player play1;
    string playerName;
    string memberName1;
    string memberName2;
    string movement;
    int health;

    // tests all the setters and getters for Player class
    play1.setPlayerName("D'Shawn");
    cout << play1.getPlayerName() << endl;
    play1.setMemberName1("Esrom");
    cout << play1.getMemberName1() << endl;
    play1.setMemberName2("Lily");
    cout << play1.getMemberName2() << endl;
    play1.setMovement("up");
    cout << play1.getMovement() << endl;
    play1.setHealth(100);
    cout << play1.getHealth() << endl;

    cout << endl;

    // Planet class 
    Planet pl1;
    string planetName;
    string planetWormHole;
    string habitability;
    int planetSize;
    int planetCapicity;
    int planetDist;
    int fuelUsage; // gallons

    // tests setters and getters for Planet class
    pl1.setPlanetName("Venus");
    cout << pl1.getPlanetName() << endl;
    pl1.setPlanetWormHole("Venus Wormhole");
    cout << pl1.getPlanetWormHole() << endl;
    pl1.setHabitability("Yes");
    cout << pl1.getHabitability() << endl;
    pl1.setPlanetSize(100);
    cout << pl1.getPlanetSize() << endl;
    pl1.setPlanetCapicity(1000);
    cout << pl1.getPlanetCapicity() << endl;
    pl1.setPlanetDist(100);
    cout << pl1.getPlanetDist() << endl;
    pl1.setFuelUsage(100);
    cout << pl1.getFuelUsage() << endl;
    
    cout << endl;

    // Resource class
    Resource r1;
    double money;
    int weaponPrice;
    int suitPrice;
    int fuel;
    int medKitPrice;
    int translatorPrice;
    string medicalSupply;
    string weapon;
    string suit;
    int translator;

    // tests setters and getters for Resource class
    r1.setMoney(100000);
    cout << r1.getMoney() << endl;
    r1.setWeaponsPrice(1000);
    cout << r1.getWeaponPrice() << endl;
    r1.setSuitsPrice(5000);
    cout << r1.getSuitPrice() << endl;
    r1.setFuel(200000);
    cout << r1.getFuel() << endl;
    r1.setMedKitPrice(100);
    cout << r1.getMedKit() << endl;
    r1.setTranslatorPrice(100);
    cout << r1.getTranslatorPrice() << endl;
    r1.setMedicalSupply("Medkit");
    cout << r1.getMedicalSupply() << endl;
    r1.setWeapon("Beam Gun");
    cout << r1.getWeapon() << endl;
    r1.setSuit("Space Suit grade 2");
    cout << r1.getSuit() << endl;
    r1.setTranslator(100);
    cout << r1.getTranslator() << endl;

    cout << endl;

    // Inventory class
    Inventory inve;
    string medKit;
    //string suit;
    string weapon1;
    string weapon2;
    string weapon3;
    int maxCapicity;
    int fuelTank;
    int inventorySize;
    int fuelTankCapacity;
    
    // tests setters and getters for Inventory class
    inve.setMedicalItems("Medkit");
    cout << inve.getMedKit() << endl;
    inve.setSuit("Grade 5");
    cout << inve.getSuit() << endl;
    inve.setWeapon1("Light Saber");
    cout << inve.getWeapon1() << endl;
    inve.setWeapon2("Bat");
    cout << inve.getWeapon2() << endl;
    inve.setWeapon3("Beam Gun");
    cout << inve.getWeapon3() << endl;
    inve.setMaxCapicity(50);
    cout << inve.getMaxCapicity() << endl;
    inve.setInventorySize(18);
    cout << inve.getInventorySize() << endl;
    inve.setFuelTank(200);
    cout << inve.getFuelTank() << endl;
    
    return 0;
}
