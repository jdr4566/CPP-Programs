/*  Programmer : John-David Rodriguez
    Course: COSC-1437
    Date: 10/20/2021
    IDE: Microsoft Visual Studio
    Description:   a decision program menu to help students who are taking a Physics (Mechanics) class perform simple foundation calculations
*/


//Define Header Files

#include <iostream>
#include <string>
#include <cstdlib>
#include "Function.h"
using namespace std;


int main()
{
    string option = ""; //the option local to int main()
    string color = "\x1b[" + to_string(32) + ";1m";
    string reset = "\x1b[0m";
    string motionOption = "";
    //loop until the user provides "e" or (&&) "E" as exit condition

    do
    {
        displayMenu(); //call a menu void function here
        cout << "\nPlease Select A Calculator: ";
        cout << color; //change text to green 
       //cin >> option; //getline(cin,option); //get the entire line
        option = validateString(option);
        cout << reset; //reset back to standard
        work(option); //call handleOption and pass the user option as an argument


    } while (option != "e" && option != "E"); //DeMorgan's Law!!! 
    cout << "\nGoodbye. Hasta luego." << endl;
    return 0;

    
}


