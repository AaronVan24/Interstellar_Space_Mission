// CSCI 1300 Spring 2022
// Author: Aaron Van & D'Shawn Burkes
// Recitation: 201 - Tiffany Phan
// Project 3 - Planet.h ...

#ifndef PLANET_H
#define PLANET_H

#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <vector>
#include <cctype>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Planet
{
    private:
        string planetName;
        string planetWormHole;
        string habitability; // does planet contain human life, y/n
        int planetSize;
        int planetCapicity;
        int planetDist; // planet distance
        int fuelUsage; // how much fuel needed to reach planet

    public:
        Planet(); //default constructor
        Planet(string, string, string, int, int, int, int); // parameterized constructor

        // getters
        string getPlanetName();
        string getPlanetWormHole();
        string getHabitability();
        int getPlanetSize();
        int getPlanetCapicity();
        int getPlanetDist();
        int getFuelUsage();

        // setters
        void setPlanetName(string);
        void setPlanetWormHole(string);
        void setHabitability(string);
        void setPlanetSize(int);
        void setPlanetCapicity(int);
        void setPlanetDist(int);
        void setFuelUsage(int);
};

#endif