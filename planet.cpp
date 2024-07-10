// CSCI 1300 Spring 2022
// Author: Aaron Van & D'Shawn Burkes
// Recitation: 201 - Tiffany Phan
// Project 3 - planet.cpp ...

#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <vector>
#include <cctype>
#include <ctime>
#include <fstream>
#include <string>
#include <sstream>
#include "Planet.h"
using namespace std;

// default constructor
Planet::Planet(){
    planetName = "";
    planetWormHole = "";
    habitability = "";
    planetSize = 0;
    planetCapicity = 0;
    planetDist = 0;
    fuelUsage = 0;
}

// parameterized constructor
Planet::Planet(string planetName_, string planetWormHole_, string habitabilitiy_, int planetSize_, int planetCapicity_, int planetDist_, int fuelUsage_){
    planetName = planetName_;
    planetWormHole = planetWormHole_;
    habitability = habitabilitiy_;
    planetSize = planetSize_;
    planetCapicity = planetCapicity_;
    planetDist = planetDist_;
    fuelUsage = fuelUsage_;
}

// getters
string Planet::getPlanetName(){
    return planetName;
}
string Planet::getPlanetWormHole(){
    return planetWormHole;
}
string Planet::getHabitability(){
    return habitability;
}
int Planet::getPlanetSize(){
    return planetSize;
}
int Planet::getPlanetCapicity(){
    return planetCapicity;
}
int Planet::getPlanetDist(){
    return planetDist;
}
int Planet::getFuelUsage(){
    return fuelUsage;
}

// setters
/*
* Algorithm: setPlanetName is a function to generate a random number (1-9) and a random capital letter (A-Z)
* 1. Create a for loop to create a name for the a planet consisting of 6 random numbers and letters
* 2. Using a rand function to choose a random number bewteen 0-26
* 3. Whatever number that is generated from numbers 0-26, add 48 to convert to ascii value 
* 4. Store random letter and loop agian until 6 random letters and numbers are generated
* Parameters: planetName_ (string)
* Return: void
*/
void Planet::setPlanetName(string planetName_){
    char character;
    string one = "";
    int letter;

    // loops to create 6 random numbers and letters
    for(int i = 0; i < 7; i++){
        
        // gets a rand number between 0-26
        letter = rand() % 26; // 26 letters in alphabet
        
        // 
        if(letter >= 0 && letter <= 9){ 
            letter = letter + 48;
            character = letter;
        }
        // 
        else if(letter > 0 && letter < 26){
            letter = letter + 65;
            character = letter;
        }
    }
    // sets planet name
    planetName = planetName_ + character;    
}

void Planet::setPlanetWormHole(string planetWormHole_){
    planetWormHole = planetWormHole_;
}

void Planet::setHabitability(string habitability_){
    habitability = habitability_;
}

/**
 * Algorithm: Pick a random number between 1-8 in increments of 0.5
 * 1. Use rand and srand function to choose random number
 * 2. Create an array of a double and store all possible outcomes that the rand function can produce
 * 3. Once random number is chosen, set planet size to that number
 * Parameters: none
 * Return: void 
 */
void Planet::setPlanetSize(int planetSize_){
    srand(time(0));
    double arr[16] = {1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8};
    planetSize_ = (rand() % 16); // random number between 1-16 from values in array
       
    planetSize = planetSize_;
}

/**
 * Algorithm: Calculate the planet capicity based on the planet size determined above
 * 1. Take planetSize which was determined in setPlanetSize and multiple by 615 to determine the max capicity of the planet
 * 2. Once calculated, set calculated number to planetCapicity
 * Parameters: none
 * return: void
 */
void Planet::setPlanetCapicity(int planetCapicity_){
    planetCapicity_ = planetSize * 615; // calculation to determine planet cap
    planetCapicity = planetCapicity_;
}

void Planet::setPlanetDist(int planetDist_){
    planetDist = planetDist_;
}

/**
 * Algorithm: Calculate the amount of fuel user has left after each travel
 * 1. No matter what planet they travel to, the first travel will have a fixed amount of 50000 gallons of fuel usage 
 * 2. Every travel after the 1st will be calculated using formula given to us in the github
 * Parameters: none
 * return: void
 */
void Planet::setFuelUsage(int fuelUsage_){
    fuelUsage = fuelUsage - 50000;
    fuelUsage = fuelUsage_ * fuelUsage_/1000000 + fuelUsage_;
}