// CSCI 1300 Spring 2022
// Author: Aaron Van & D'Shawn Burkes
// Recitation: 201 - Tiffany Phan
// Project 3 - project3.cpp ...

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Inventory.h"
#include "Planet.h"
#include "Player.h"
#include "Resource.h"
#include "Map.h"
using namespace std;

/**
 * Algorithm: Split1 an array at each dilimiter, represented by a comma.  
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
int split1 (string inputString, char seperator, string arr[], int size){
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

/*
* Algorithm: reads a random question and the possible answers from the file then prints them out for the user to choose a answer
* 1. open file
* 2. loop through questions file
* 3. get random position
* 4. split question and answers
* 5. split answers
* 6. get user answer
* 7. check if the user chose correct answer
* 8. loop through planet traits file
* 9. get random planet trait
* Parameters: none
* Return: void
*/
void readQuestions(string filename){
    Player play;
    int health;
    int lines_ = 0, lines2_ = 0, random = 0;
    char choice;
    vector<string> questions;
    vector<string> habit;
    string temparr1[2], temparr2[4], line = "", line2 = "";

    ifstream fin;

    // opens file
    fin.open(filename);

    // loops through file
    while(getline(fin, line)){
        lines_++;
        questions.push_back(line);
    }

    // set starting point for rand function
    srand(time(NULL));

    // saves position of the random question
    random = rand()%lines_;
    
    // splits up question and answers
    split1(questions[random], ';', temparr1, 2);
    cout << temparr1[0] << endl;

    // splits up answer choices
    string answer = temparr1[1];
    split1(answer, ',', temparr2, 4);
    cout << "a. " << temparr2[0] << endl;
    cout << "b. " << temparr2[1] << endl;
    cout << "c. " << temparr2[2] << endl;
    cout << "d. " << temparr2[3] << endl;
    cin >> choice;
    cin.ignore();

    // closes file
    fin.close();
    
    // if-else statment to determine outcome of user inputted answer 
    if(choice == 'a'){
        ifstream fin;

        // opens file
        fin.open("hab.txt");
        
        // checks if the file opened successfully
        if (fin.is_open()){

            // loops through file
            while(getline(fin, line2)){
                lines2_++;
                habit.push_back(line2);
            }

            // set starting point for rand function
            srand(time(NULL));

            // saves position of the random planet trait
            int ran = rand()%lines2_;
            cout << "Correct answer!" << endl;
            cout << "You just discovered that this planet has " << habit[ran] << ". This is a great sign. This discovery has been added to your log book." << endl;
        }
        // closes file
        fin.close();
    }
    else if(choice == 'b' || choice == 'c' || choice == 'd'){
        cout << "Incorrect answer! Reduced your health by 1% because of frustration." << endl;
        play.setHealth(play.getHealth() - 1);
        
    }
    else {
        cout << "Invalid input." << endl;// invalid input
    }
}

void alienEncounter(string filename){
    int line1 = 0, rando = 0;
    char choice;
    vector<string> alienName;
    string line = "";

    ifstream fin;

    // opens file
    fin.open(filename);

    // loops through file
    while(getline(fin, line)){
        line1++;
        alienName.push_back(line);
    }

    // set starting point for rand function
    srand(time(NULL));

    // saves position of the random alien name
    rando = rand()%line1;
    cout << "You just ran into " << alienName[rando] << "! Think you can beat this dangerous alien for helping save humanity?" << endl;
}

/**
 * Algorithm: A map menu to display map with all spawns when user calls for map to select a movement
 * 1. 
 * Parameters: None
 * Return: Void
 */
void mapMenu(){
    Map map;
    Player play;
    Inventory inven;
    Resource res;
    Planet plan;
    int choice;
    string name;
    string enter = "";
    cout << "Welcome, please enter the user's name: " << endl;
    cin >> name;
    play.setPlayerName(name);
    cin.ignore();
    cout << "Press enter to continue." << endl;
    getline(cin, enter);
    
    int r, c, t, i = 0;
    srand(time(NULL));
    while (i < 7){
        r = rand()%12;
        c = rand()%12;
        t = rand()%6;
        if (map.spawnSite(r, c, t) == true){
            map.spawnSite(r, c, t);
            i++;
        }
    }
    i = 0;
    srand(time(NULL));
    int nM = rand()%5 + 4;
    while (i < nM){
        srand(time(NULL));
        r = rand()%12;
        c = rand()%12;
        t = rand()%3;
        if (map.spawnMisfortune(r, c, t) == true){
            map.spawnMisfortune(r, c, t);
            map.revealMisfortune(r, c);
            i++;
        }
    }
    i = 0;
    srand(time(NULL));
    while (i < 1){
        r = rand()%12;
        c = rand()%12;
        if (map.spawnNPC(r, c) == true){
            map.spawnNPC(r, c);
            i++;
        }
    }
    i = 0;
    map.displayMap();
    while (i < 2){
        cout << "Select one: " << endl << "1. Move" << endl << "2. View status" << endl << "3. View log book" << endl << "4. Resource center" << endl << "5. Report planet as habitable" << endl << "6. Enter wormhole to next to next planet" << endl << "7. Give up" << endl;
        cin >> choice;
        cin.ignore();
        switch(choice){
            case 1:{
                map.displayMap();
                int j = 0;
                char input;
                while (j < 2){
                    cout << "Select one: w. up s. down d. right a. left m. menu" << endl;
                    cin >> input;
                    cin.ignore();
                    if(input == 'w'){
                        if (map.getPlayerRowPosition() < 12 and map.getPlayerRowPosition() >= 0){
                            map.executeMove('w');
                            if (map.isSiteLocation() == true){
                                readQuestions("questions.txt");
                            } 
                            else if (map.isMisfortuneLocaton() == true){
                                inven.misfortunes("misfortunes.txt");
                            }
                            else if (map.isNPCLocation() == true){
                                alienEncounter("alien_names.txt");
                            }
                            map.displayMap();
                            res.setMoney(res.getMoney()+50);
                        }
                        else {
                            cout << "Out of range of map" << endl;
                        }
                    }
                    else if(input == 's'){
                        if (map.getPlayerRowPosition() < 12 and map.getPlayerRowPosition() >= 0){
                            map.executeMove('s');
                            if (map.isSiteLocation() == true){
                                readQuestions("questions.txt");
                                
                            } 
                            else if (map.isMisfortuneLocaton() == true){

                            }
                            else if (map.isNPCLocation() == true){

                            }
                            map.displayMap();
                            res.setMoney(res.getMoney()+50);
                        }
                        else {
                            cout << "Out of range of map" << endl;
                        }
                    }
                    else if(input == 'd'){
                        if (map.getPlayerColPosition() < 12 and map.getPlayerColPosition() >= 0){
                            map.executeMove('d');
                            if (map.isSiteLocation() == true){
                                readQuestions("questions.txt");
                                
                            } 
                            else if (map.isMisfortuneLocaton() == true){

                            }
                            else if (map.isNPCLocation() == true){

                            }
                            map.displayMap();
                            res.setMoney(res.getMoney()+50);
                        }
                        else {
                            cout << "Out of range of map" << endl;
                        }
                    }
                    else if(input == 'a'){
                        if (map.getPlayerColPosition() < 12 and map.getPlayerColPosition() >= 0){
                            map.executeMove('a');
                            if (map.isSiteLocation() == true){
                                readQuestions("questions.txt");
                                
                            } 
                            else if (map.isMisfortuneLocaton() == true){

                            }
                            else if (map.isNPCLocation() == true){

                            }
                            map.displayMap();
                            res.setMoney(res.getMoney()+50);
                        }
                        else {
                            cout << "Out of range of map" << endl;
                        }
                    }
                    else if(input == 'm'){
                        j = 2;
                    }
                    else{
                        cout << "Invalid input" << endl;
                    }
                }
                break;
            }
            case 2:{
                while(true){
                    int choice;
                    cout << "1. Health Status" << endl << "2. Planets Status" << endl << "3. Humans Saved and Perished" << endl << "4. Materials Status" << endl << "5. Return to main menu" << endl;
                    cin >> choice;
                    cin.ignore();
                    if(choice == 1){
                        cout << "Health:" << endl;
                        double bar = play.getHealth() / 5;
                        for (int y = 0; y <= bar; y++){
                            cout << "_";
                        }
                        cout << play.getHealth() << "%" << endl;
                        cout << "Space Suit Health:" << endl;
                        bar = inven.getSuitHealth() / 5;
                        for (int y = 0; y <= bar; y++){
                            cout << "_";
                        }
                        cout << inven.getSuitHealth() << "%" << endl;
                        bar = inven.getFuelTank() / 20000;
                        cout << "Fuel tank:" << endl;
                        for (int y = 0; y < bar; y++){
                            cout << "_";
                        }
                        cout << inven.getFuelTankCapicity()/inven.getFuelTank() << "%" << endl;
                    }
                    else if(choice == 2){
                        cout << "Planets explored: " << endl;
                        cout << "Planets accurately reported habitable: " << inven.getHabitablePlanets() << endl;
                        cout << "Planets inaccurately reported habitable: 0" << endl;
                    }
                    else if(choice == 3){
                        cout << "Humans saved (in millions): " << inven.getHumansSaved() << endl;
                        cout << "Humans perished (in millions): 0" << endl;
                    }
                    else if(choice == 4){
                        cout << "- Money - " << res.getMoney() << endl;
                        cout << "- WEAPONS - " << res.getWeapon() << endl << "  1. Light Saber - " << inven.getWeapon1() << endl << "  2. Blaster - " << inven.getWeapon2() << endl << "  3. Beam Gun - " << inven.getWeapon3() << endl;
                        cout << "- TRANSLATOR - " << res.getTranslator() << endl;
                        cout << "- SPACE SUIT GRADE " << inven.getSuit() << endl;
                        cout << "- MEDICAL KITS - " << inven.getMedKit() << endl;
                        cout << "- FUEL - " << res.getFuel() << " Gallons" << endl; 
                    }
                    else if(choice == 5){
                        break;
                    }
                    else{
                        cout << "invalid input" << endl;
                        cout << "1. Health Status" << endl << "2. Planets Status" << endl << "3. Humans Saved and Perished" << endl << "4. Materials Status" << endl;
                        cin >> choice;
                        cin.ignore();
                    }
                }
                break;
            }
            case 3:{
                cout << play.getPlayerName() << "'s Log book page # 1: Planet " << plan.getPlanetName() << endl;
                cout << "Planet size (in diameter of 1000 kms): " << plan.getPlanetSize() << endl;
                cout << "Planet's carrying capacity (in millions): " << plan.getPlanetCapicity() << endl;
                cout << "Habitable traits discovered: " << endl;
                cout << "Non-habitable traits discovered: " << endl;
                cout << "Friendly alien assessment: " << endl;
                break;
            }
            case 4:{
                res.resourceCenter();
                break;
            }
            case 5:{
                char yN;
                cout << "Are you sure you want to report back to mission control that this planet is habitable? As a reminder, here is your log book: " << endl;
                cout << play.getPlayerName() << " Log Book page # 1: " << plan.getPlanetName() << endl;
                cout << "Planet size (in diameter of 1000 kms): " << plan.getPlanetSize() << endl;
                cout << "Planet’s carrying capacity (in millions): " << plan.getPlanetCapicity() << endl;
                cout << "Habitable traits discovered: " << endl;
                cout << "Non-habitable traits discovered: " << endl;
                cout << "Friendly alien assessment: " << endl;

                cout << endl << "Reporting this planet is irreversible. If the planet is in fact habitable, you will save " << plan.getPlanetCapicity() << " million people! If it’s not, the people sent to this planet will die." << endl;
                cout << "Ready to report? [y/n]" << endl;
                cin >> yN;
                cin.ignore();
                if (yN == 'y'){
                    // enter wormhole
                }
                else {
                    break;
                }
                break;
            }
            case 6:{
                char yN;
                cout << "Are you sure you want to enter this wormhole? You will start a new page in your log book and you will lose fuel. Enter wormhole? [y/n]" << endl;
                cin >> yN;
                if( yN == 'y'){
                    if(inven.getFuelTank() < plan.getFuelUsage()){
                        //cout << "You are about to travel to planet " << plan.getPlanetName() << " but you do not have sufficient fuel to travel. You will need to " << mm << " more gallons of fuel to travel to this planet, which costs " << mm << ". Go ahead and make the purchase? [y/n]" << endl;
                        cin >> yN;
                        if(yN == 'y'){
                            res.resourceCenter();
                        }
                        else if(yN == 'n'){
                            cout << "You are not moving to the next planet as you have declined the payment. Redirecting you to the current planet…" << endl;
                        } 
                        else{
                        }
                    }
                    else{
                        cout << "You are entering the wormhole in 3...2...1..." << endl;
                    }
                }
                else if(yN == 'n'){
                    cout << "You are not moving to the next planet as you have declined the payment. Redirecting you to the current planet…" << endl;
                }
                else{
                    cout << "Invalid input." << endl;
                    cin >> yN;
                }
            }
            case 7:{
                char yN;
                cout << "Are you sure you want to give up? [y/n]" << endl;
                cin >> yN;
                if(yN == 'y'){
                    cout << "It is disappointing to hear that you have quit, humanity was depending on you." << endl;
                }
                else if(yN == 'n'){
                    map.displayMap();
                    cout << "Select one: " << endl << "1. Move" << endl << "2. View status" << endl << "3. View log book" << endl << "4. Resource center" << endl << "5. Report planet as habitable" << endl << "6. Enter wormhole to next to next planet" << endl << "7. Give up" << endl;
                    cin >> choice;
                    cin.ignore();
                }
                else{
                    cout << "Invalid input." << endl;
                    cin >> yN;
                }
                i = 2;
                break;
            }
            default:{
                cout << "Enter valid input." << endl;
                break;
            }
        }
    }
}

int main(){
    // inventory.setWeapon1("lightsaber");
    // cout << "Press enter to to continue." << endl;
    // getline(cin, enter);
    // res.resourceCenter();
    // cout << "Press enter to to continue." << endl;
    // getline(cin, enter);
    // play.crewMenu();
    mapMenu();
    return 0;
}