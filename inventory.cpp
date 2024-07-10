// CSCI 1300 Spring 2022
// Author: Aaron Van & D'Shawn Burkes
// Recitation: 201 - Tiffany Phan
// Project 3 - inventory.cpp ...

#include <iostream>
#include <string>
#include <fstream>
#include "Inventory.h"
#include "Resource.h"
#include "Player.h"
using namespace std;

// default constructor
Inventory::Inventory(){
    medKit = "";
    suit = 1;
    weapon1 = "";
    weapon2 = "";
    weapon3 = "";
    maxCapicity = 0;
    fuelTank = 200000;
    inventorySize = 0;
    fuelTankCapacity = 400000;
    // vector <int> inventory;
}

// parameterized constructor
Inventory::Inventory(string medKit_, int suit_, string weapon1_, string weapon2_, string weapon3_, int maxCapicity_, int fuelTank_, int inventorySize_){
    medKit = medKit_;
    suit = suit_;
    weapon1 = weapon1_;
    weapon2 = weapon2_;
    weapon3 = weapon3_;
    maxCapicity = maxCapicity_;
    fuelTank = fuelTank_;
    inventorySize = inventorySize_;
}

// getters
string Inventory::getMedKit(){
    return medKit;
}
int Inventory::getSuit(){
    return suit;
}
string Inventory::getWeapon1(){
    return weapon1;
}
string Inventory::getWeapon2(){
    return weapon2;
}
string Inventory::getWeapon3(){
    return weapon3;
}
int Inventory::getMaxCapicity(){
    return maxCapicity;
}
int Inventory::getInventorySize(){
    return inventorySize;
}
int Inventory::getFuelTank(){
    return fuelTank;
}
int Inventory::getFuelTankCapicity(){
    return fuelTankCapacity;
}
int Inventory::getSuitHealth(){
    return suitHealth;
}
int Inventory::getHabitablePlanets(){
    return habitablePlanets;
}
int Inventory::getHumansSaved(){
    return humansSaved;
}

// setters
void Inventory::setMedicalItems(string medKit_){
    medKit = medKit_;
}
void Inventory::setSuit(int suit_){
    suit = suit_;
}
void Inventory::setWeapon1(string weapon1_){
    weapon1 = weapon1_;
}
void Inventory::setWeapon2(string weapon2_){
    weapon2 = weapon2_;
}
void Inventory::setWeapon3(string weapon3_){
    weapon3 = weapon3_;
}
void Inventory::setMaxCapicity(int maxCapicity_){
    maxCapicity = maxCapicity_;
}        
void Inventory::setInventorySize(int inventorySize_){
    inventorySize = inventorySize_;
}
void Inventory::setFuelTank(int fuelTank_){
    fuelTank = fuelTank_;
}
void Inventory::setSuitHealth(int suitHealth_){
    suitHealth = suitHealth_;
}
void Inventory::setHabitablePlanets(int habitablePlanets_){
    habitablePlanets = habitablePlanets_;
}
void Inventory::setHumansSaved(int humansSaved_){
    humansSaved = humansSaved_;
}
void Inventory::misfortunes(string filename){
    int lines_ = 0, random = 0, health, suitHealth;
    char choice;
    vector<string> misfor;
    string line = "";

    ifstream fin;

    // opens file
    fin.open(filename);

    // loops through file
    while(getline(fin, line)){
        lines_++;
        misfor.push_back(line);
    }

    // set starting point for rand function
    srand(time(NULL));

    // saves position of the random misfortune
    random = rand()%lines_;
    Player play;
    Inventory inven;

    // if-else statement to determine the outcome of each random misfortune
    if(misfor[random] == "space sickness"){
        health = 30;
        suitHealth = 0;
        cout << "Oh no! You have "<< misfor[random] << ". Your health decreased by " << health << "%." << "Your space suit health decreased by " << suitHealth << "%." <<endl;
        play.setHealth(play.getHealth() - 30);
        
    }
    else if(misfor[random] == "fall into a crater"){
        health = 50;
        suitHealth = (50-10*inven.getSuit());
        cout << "Oh no! You have "<< misfor[random] << ". Your health decreased by " << health << "%." << "Your space suit health decreased by " << suitHealth << "%." <<endl;
        play.setHealth(play.getHealth() - 50);
        inven.setSuitHealth(inven.getSuitHealth() - 50*inven.getSuit());
    }
    else if(misfor[random] == "weather storm"){
        health = 10;
        suitHealth = (50-10*inven.getSuit());
        cout << "Oh no! You have encountered a "<< misfor[random] << ". Your health decreased by " << health << "%." << "Your space suit health decreased by " << suitHealth << "%." << endl;
        play.setHealth(play.getHealth() - 10);
        inven.setSuitHealth(inven.getSuitHealth() - 50*inven.getSuit());
    }
}