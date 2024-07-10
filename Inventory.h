// CSCI 1300 Spring 2022
// Author: Aaron Van & D'Shawn Burkes
// Recitation: 201 - Tiffany Phan
// Project 3 - Inventory.h ...
#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Inventory
{
    private:
        string medKit;
        int suit = 1; // level suit
        string weapon1;
        int suitHealth = 100;
        string weapon2;
        string weapon3;
        int maxCapicity;
        // vector <int> inventory;
        int fuelTank = 200000;
        int inventorySize;
        int fuelTankCapacity = 400000;
        int habitablePlanets;
        int humansSaved;
    
    public:

        // default constructor
        Inventory(); 

        // parameterized constructor
        Inventory(string, int, string, string, string, int, int, int);
        
        // getters
        string getMedKit();
        int getSuit();
        string getWeapon1();
        string getWeapon2();
        string getWeapon3();
        int getMaxCapicity(); // max size inventory can
        int getInventorySize(); // actual size of inventory
        int getFuelTank();
        int getFuelTankCapicity();
        int getSuitHealth();
        int getHabitablePlanets();
        int getHumansSaved();

        // setters 
        void setMedicalItems(string);
        void setSuit(int);
        void setWeapon1(string);
        void setWeapon2(string);
        void setWeapon3(string);
        void setMaxCapicity(int);        
        void setInventorySize(int);
        void setFuelTank(int);
        void setSuitHealth(int);
        void setHabitablePlanets(int);
        void setHumansSaved(int);

        void misfortunes(string);
};

#endif