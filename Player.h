// CSCI 1300 Spring 2022
// Author: Aaron Van & D'Shawn Burkes
// Recitation: 201 - Tiffany Phan
// Project 3 - Player.h ...

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Player
{
    private:
        string playerName;
        string memberName1;
        string memberName2;
        string movement;
        int health = 100;
        string crew[6];
        string abilities[6];

    public:
        Player(); // default constructor
        Player(string, string, string, string, int); // parameterized constructor

        // getters
        string getPlayerName();
        string getMemberName1();
        string getMemberName2();
        string getMovement();
        int getHealth();
        // int getPlayerStats();
        
        // setters
        void setPlayerName(string);
        void setMemberName1(string);
        void setMemberName2(string);
        void setMovement(string);
        void setHealth(int);
        // void setPlayerStats(vector <int> playerStats);

        // int split(string, char , string , int);

        // reads crewmate file
        void readCrewMates(string);

        // crewmate menu
        void crewMenu();

        

};

#endif