// CSCI 1300 Spring 2022
// Author: Aaron Van & D'Shawn Burkes
// Recitation: 201 - Tiffany Phan
// Project 3 - player.cpp ...

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Player.h"
using namespace std;



// default constructor
Player::Player(){
    playerName = "";
    memberName1 = "";
    memberName2 = "";
    movement = "";
    int health = 100;
    // vector <int> playerStats;
}

// parameterized constructor
Player::Player(string playerName_, string memberName1_, string memberName2_, string movement_, int health_){
    playerName = playerName_;
    memberName1 = memberName1_;
    memberName2 = memberName2_;
    movement = movement_;
    health = health_;
    // playerStats = playerStats_;
}

// getters
string Player::getPlayerName(){
    return playerName;
}
string Player::getMemberName1(){
    return memberName1;
}
string Player::getMemberName2(){
    return memberName2;
}
string Player::getMovement(){
    return movement;
}
int Player::getHealth(){
    return health;
}

// setters
void Player::setPlayerName(string playerName_){
    playerName = playerName_;
}
void Player::setMemberName1(string memberName1_){
    memberName1 = memberName1_;
}
void Player::setMemberName2(string memberName2_){
    memberName2 = memberName2_;
}
void Player::setMovement(string movement_){
    movement = movement_;
}
void Player::setHealth(int health_){
    health = health_;
}

/**
 * Algorithm: Split an array at each dilimiter, represented by a comma.  
 * 1. Accpet inputString, seperator, arr[], size which are passed through int function, split.
 * 2. Create variable newStr to store the string before a dilimeter and variables counter1, counter2, counter3 to keep track/count of the characters before the dilimiters to be stored in the newStr.
 * 3. Create if statement to check for a empty string, if true, return a value of 0 and exit. If false run body of if statement.
 * 4. Inside if statement, create nested for loop to check each index up until the length of the inputString, which stores strings and the dilimiters.
 * 5. Inside for loop, create nested if statment to check if the character in index i is a comma, the dilimiter or the end of the array. If true, set counter1 equal to 1 to print out the string before the dilimiter and increment i as arr[i] and then set it back to zero to run loop again.
 * 6. After setting the counter1 back to 0, if the length of the string before the dilimiter is = 0, return 0. If it doesn't equal 0, store the string before the dilimiter in newStr and erase the string and keep looping until the end of the array or another dilimiter.
 * 7. If the index is not a dilimiter, store each character into newStr.
 * Parameters: inputString (string), seperator (char), arr[] (string), size (int)
 * Return: Counter 2, depending on the value of the if statement
 */
int split (string inputString, char seperator, string arr[], int size){
    string newStr = ""; // to store the indexes before a dilimiter
    int counter1 = 0, counter2 = 0, counter3 = 0; // counters used to keep track of the strings being split

    if (inputString.length() != 0){ // checks for empty array
        for (int i = 0; i <= inputString.length(); i++){ 
            if (inputString[i] == seperator || inputString[i] == '\0'){ // checks to see if index i is a seperator or the end of the array
                if (counter1 == 1){ // if inputString at index i is seperator or end of array, print and store the string before the dilimiter
                    counter1--; // reset 
                        if (newStr.length() != 0){ // checks to see if the new stored string is 0
                            if (size < counter2){ // checks if the number of split peices is less than counter2 
                                counter2 = -1;
                                return counter2; // returns -1
                            }
                            if (counter3 < size){
                                arr[counter3] = newStr; // if it isn't, set the string before split to variable newStr
                                counter3++;
                            }
                            counter2++;
                        }
                        newStr.erase(0, newStr.length()); // erase the string
                }
            }
            else{
                newStr += inputString[i]; // accepts charater if it isn't a dilimiter
                counter1 = 1; //checks for next dilimiter to see if it is incremented
            }
        }
    }
    else{
        return counter2; // returns 0
    }
    return counter2; // returns number of splits
}

/**
* Algorithm: reads crewmates from file
* 1. open file
* 2. check if the file was opened successfully
* 3. loop through the file
* 4. get line from file
* 5. split the line into an array of name and ability
* 6. add the information into their respective arrays
* 7. close file
* Parameters: filename (string)
* Return: void
*/
void Player::readCrewMates(string filename){
    ifstream fin;

    // opens file
    fin.open(filename);
    int i = 0;
    string line = "";
    string tempCrew[2]; 

    // checks if the file was open successfully
    if (fin.is_open()){

        // loops through the file
        while (!fin.eof()){

            // gets line from file
            getline(fin, line);

            // splits the line into an array
            split(line, ';', tempCrew, 2);

            // saves crewmates name
            crew[i] = tempCrew[0];

            // saves crewmates ability
            abilities[i] = tempCrew[1];
            i++;
        }
    }   
    // closes file
    fin.close();
}

/**
 * Algorithm: prints the crewmates menu 
 * 1. read the crewmates file
 * 2. print the crewmate options
 * 3. loop through the user choices
 * 4. get user choice
 * 5. check which option user chose
 * 6. set the name of crewmate
 * 7. print the other options of crewmates
 * 8. get user choice
 * 9. loop through user user choices
 * 10. check which option user chose
 * 11. set the name of crewmate
 * 12. break loop
 * 13. break loop
 * Parameters: none
 * Return: void
 */
void Player::crewMenu(){
    int choice;

    // reads the crewmate file
    readCrewMates("crewmates.txt");
    cout << "Pick a crewmate to help you with your journey!" << endl << endl;

    // prints the crewmate options
    for (int i = 0; i < 6; i++){
        cout << (i+1) << ". " << crew[i] << endl;
        cout << "Ability: " << abilities[i] << endl << endl;
    }
    int i = 0;
    int x = 0;

    // loops through user choice for first crewmate
    while (i < 2){

        // gets user choice
        cin >> choice;
        cin.ignore();

        // checks which option the user chose
        if (choice == 1){

            // sets the name of the first crewmate
            setMemberName1(crew[0]);
            cout << "Great choice! " << memberName1 << " will bring a lot to your team. Pick your last crewmate." << endl << endl;
            
            // prints the other options for crewmates
            for (int i = 1; i < 6; i++){
                cout << (i+1) << ". " << crew[i] << endl;
                cout << "Ability: " << abilities[i] << endl << endl;
            }

            // gets user choice
            cin >> choice;
            cin.ignore();

            // loops through the choice of user for second crewmate
            while (x < 2){

                // checks the option user chose
                if (choice == 2){

                    // sets the name of the second crewmate
                    setMemberName2(crew[1]);

                    // breaks loop
                    x = 2;
                }
                else if (choice == 3){
                    setMemberName2(crew[2]);
                    x = 2;
                }
                else if (choice == 4){
                    setMemberName2(crew[3]);
                    x = 2;
                }
                else if (choice == 5){
                    setMemberName2(crew[4]);
                    x = 2;
                }
                else if (choice == 6){
                    setMemberName2(crew[5]);
                    x = 2;
                }
                else {
                    cout << "Invalid input." << endl;
                    cin >> choice;
                    cin.ignore();
                }
            }
            // breaks loop
            i = 2;
        }
        else if (choice == 2){
            setMemberName1(crew[1]);
            cout << "Great choice! " << memberName1 << " will bring a lot to your team. Pick your last crewmate." << endl << endl;
            for (int i = 0; i < 1; i++){
                cout << (i+1) << ". " << crew[i] << endl;
                cout << "Ability: " << abilities[i] << endl << endl;
            }
            for (int i = 2; i < 6; i++){
                cout << (i+1) << ". " << crew[i] << endl;
                cout << "Ability: " << abilities[i] << endl << endl;
            }
            cin >> choice;
            cin.ignore();
            while (x < 2){
                if (choice == 1){
                    setMemberName2(crew[0]);
                    x = 2;
                }
                else if (choice == 3){
                    setMemberName2(crew[2]);
                    x = 2;
                }
                else if (choice == 4){
                    setMemberName2(crew[3]);
                    x = 2;
                }
                else if (choice == 5){
                    setMemberName2(crew[4]);
                    x = 2;
                }
                else if (choice == 6){
                    setMemberName2(crew[5]);
                    x = 2;
                }
                else {
                    cout << "Invalid input." << endl;
                    cin >> choice;
                    cin.ignore();
                }
            }
            i = 2;
        }
        else if (choice == 3){
            setMemberName1(crew[2]);
            cout << "Great choice! " << memberName1 << " will bring a lot to your team. Pick your last crewmate." << endl << endl;
            for (int i = 0; i < 2; i++){
                cout << (i+1) << ". " << crew[i] << endl;
                cout << "Ability: " << abilities[i] << endl << endl;
            }
            for (int i = 3; i < 6; i++){
                cout << (i+1) << ". " << crew[i] << endl;
                cout << "Ability: " << abilities[i] << endl << endl;
            }
            cin >> choice;
            cin.ignore();
            while (x < 2){
                if (choice == 1){
                    setMemberName2(crew[0]);
                    x = 2;
                }
                else if (choice == 2){
                    setMemberName2(crew[1]);
                    x = 2;
                }
                else if (choice == 4){
                    setMemberName2(crew[3]);
                    x = 2;
                }
                else if (choice == 5){
                    setMemberName2(crew[4]);
                    x = 2;
                }
                else if (choice == 6){
                    setMemberName2(crew[5]);
                    x = 2;
                }
                else {
                    cout << "Invalid input." << endl;
                    cin >> choice;
                    cin.ignore();
                }
            }
            i = 2;
        }
        else if (choice == 4){
            setMemberName1(crew[3]);
            cout << "Great choice! " << memberName1 << " will bring a lot to your team. Pick your last crewmate." << endl << endl;
            for (int i = 0; i < 3; i++){
                cout << (i+1) << ". " << crew[i] << endl;
                cout << "Ability: " << abilities[i] << endl << endl;
            }
            for (int i = 4; i < 6; i++){
                cout << (i+1) << ". " << crew[i] << endl;
                cout << "Ability: " << abilities[i] << endl << endl;
            }
            cin >> choice;
            cin.ignore();
            while (x < 2){
                if (choice == 1){
                    setMemberName2(crew[0]);
                    x = 2;
                }
                else if (choice == 2){
                    setMemberName2(crew[1]);
                    x = 2;
                }
                else if (choice == 3){
                    setMemberName2(crew[2]);
                    x = 2;
                }
                else if (choice == 5){
                    setMemberName2(crew[4]);
                    x = 2;
                }
                else if (choice == 6){
                    setMemberName2(crew[5]);
                    x = 2;
                }
                else {
                    cout << "Invalid input." << endl;
                    cin >> choice;
                    cin.ignore();
                }
            }
            i = 2;
        }
        else if (choice == 5){
            setMemberName1(crew[4]);
            cout << "Great choice! " << memberName1 << " will bring a lot to your team. Pick your last crewmate." << endl << endl;
            for (int i = 0; i < 4; i++){
                cout << (i+1) << ". " << crew[i] << endl;
                cout << "Ability: " << abilities[i] << endl << endl;
            }
            for (int i = 5; i < 6; i++){
                cout << (i+1) << ". " << crew[i] << endl;
                cout << "Ability: " << abilities[i] << endl << endl;
            }
            cin >> choice;
            cin.ignore();
            while (x < 2){
                if (choice == 1){
                    setMemberName2(crew[0]);
                    x = 2;
                }
                else if (choice == 2){
                    setMemberName2(crew[1]);
                    x = 2;
                }
                else if (choice == 3){
                    setMemberName2(crew[2]);
                    x = 2;
                }
                else if (choice == 4){
                    setMemberName2(crew[3]);
                    x = 2;
                }
                else if (choice == 6){
                    setMemberName2(crew[5]);
                    x = 2;
                }
                else {
                    cout << "Invalid input." << endl;
                    cin >> choice;
                    cin.ignore();
                }
            }
            i = 2;
        }
        else if (choice == 6){
            setMemberName1(crew[5]);
            cout << "Great choice! " << memberName1 << " will bring a lot to your team. Pick your last crewmate." << endl << endl;
            for (int i = 0; i < 5; i++){
                cout << (i+1) << ". " << crew[i] << endl;
                cout << "Ability: " << abilities[i] << endl << endl;
            }
            cin >> choice;
            cin.ignore();
            while (x < 2){
                if (choice == 1){
                    setMemberName2(crew[0]);
                    x = 2;
                }
                else if (choice == 2){
                    setMemberName2(crew[1]);
                    x = 2;
                }
                else if (choice == 3){
                    setMemberName2(crew[2]);
                    x = 2;
                }
                else if (choice == 4){
                    setMemberName2(crew[3]);
                    x = 2;
                }
                else if (choice == 5){
                    setMemberName2(crew[4]);
                    x = 2;
                }
                else {
                    cout << "Invalid input." << endl;
                    cin >> choice;
                    cin.ignore();
                }
            }
            i = 2;
        }
        else {
            cout << "Invalid input." << endl;
            cin >> choice;
            cin.ignore();
        }
    }
    cout << "You have a very impressive crew. With your leadership, you will be sure to succeed." << endl;
}