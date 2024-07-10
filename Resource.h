// CSCI 1300 Spring 2022
// Author: Aaron Van & D'Shawn Burkes
// Recitation: 201 - Tiffany Phan
// Project 3 - Resource.h ...

#ifndef RESOURCE_H
#define RESOURCE_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Resource
{
    private:
        double money = 100000;
        int weaponPrice;
        int suitPrice;
        int fuel = 10000;
        int fuelPrice = 1000;
        int medKitPrice = 2000;
        int translatorPrice = 5000;
        int medicalSupply = 0;
        string weapon;
        int suit = 1;
        int translator = 0;
    
    public:
        Resource(); // default constructor
        Resource(double, int, int, int, int, string, int, int); // parameterized constructor

        // getters for Resource class
        double getMoney(); 
        int getWeaponPrice();
        int getSuitPrice();
        int getFuel();
        int getMedicalSupply();
        string getWeapon();
        int getSuit();
        int getTranslator();

        // setters for Resource class
        void setMoney(double);
        void setWeaponPrice(int);
        void setSuitPrice(int);
        void setFuel(int);
        void setMedicalSupply(int);
        void setWeapon(string);
        void setSuit(int);
        void setTranslator(int);

        // menus
        void resourceMenu();
        void weaponMenu();
        void suitMenu();
        void medkitMenu();
        void translatorMenu();
        void fuelMenu();
        void resourceCenter();
};

#endif