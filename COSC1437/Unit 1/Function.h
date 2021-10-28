#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//libraries
#include <iostream>
#include <string>
#include "Input_Validation_Extended.h" //For input validation
#include <cmath>
#include <iomanip>
using namespace std;

//Define Variables 
double ds;
double dt;
double v = (double)ds / (double)dt;  //Formula to calculate velocity
double dv;  //Variable for Acceleration
double a = (double)dv / (double)dt;   //Formula to calculate acceleration
double m;   //for mass
double g;   //for gravity
double weight = ((double)m * (double)g);
double mm = ((double)m * (double)dv); //Momentum total
double newt = ((double)m * (double)dv); //For Newton calculation
double s = (double)ds * (double)dt; //for motion 1 formula
double mv;  //for v initial position
double mvv; //for v final position
double ma;  //for acelleration
double ms;  //for first position
double mss; //for final position
double mv2 = mv + 2 * (double)ma * (mss - ms);//entire formula
double mxx = 0.5 * (mvv + mv);  //formula for Mv / V_bar

//Function Prototypes
void Velocity();        //Velocity Calculation  Function
void Acceleration();    //Acceleration Calculation Function
void Motion();          //Motion Calculation Function
void motionmenu();      //Motion sub-menu
void motionwork(string); //Motion menu work
void Newton();          //Newton's 2nd Law Calculation Function
void Weight();          //Weight Calculation Function
void Momentum();        //Momentum Calculation Function
void displayMenu();     //Function to display the main menu
void work(string);      //Function to do menu work!!
void cleanscreen();     //Function to clear the screen
void m1();              //Formula for motion calculation 1  (solve for v)
void m2();              //Formula for motion calculation 2  ( solve for s)
void m3();              //Formula for motion calculation 3
void m4();              //Formula for motion calculation 4


//Define Functions

void displayMenu()
{
    cout << "\t\n\n Welcome to the Physics Calculator by JD!!" << endl;
    cout << "\tA: Calculate Velocity" << endl;
    cout << "\tB: Calculate Acceleration" << endl;
    cout << "\tC: Calculate Motion" << endl;
    cout << "\tD: Calculate Newton's Second Law" << endl;
    cout << "\tF: Calculate Weight" << endl;
    cout << "\tG: Calculate Momentum" << endl;
    cout << "\tE: Exit Program" << endl;
    cout << "\tX: Clear Screen" << endl;
}

void Velocity()
{
    cout << "\nPlease enter the distance : " << endl;
    ds = validateDouble(ds);
    cout << "\nNow your time: " << endl;
    dt = validateDouble(dt);
    cout << "\nYour distance is : " << setprecision(4) << ds << " And your time is : " << dt << endl;
    cout << "\nVelocity calculated is : " << setprecision(4) << v << " km/hour\n\n\n" << endl;
}

void Acceleration()
{
    cout << "Please enter the Velocity : " << endl;
    dv = validateDouble(dv);
    cout << "Please enter the change in time: " << endl;
    dt = validateDouble(dt);
    cout << "Your Velocity entered is : " << setprecision(4) << dv << " And your change in time is : " << setprecision(4) << dt << endl;
    cout << "Acceleration calculated is : " << setprecision(4) << a << "m/s^2\n\n\n";
}

void motionmenu()   //Motion Sub-Menu
{
    cout << "\tMotion Calculator Sub-Menu" << endl;
    cout << "\tA.Ma = solve for v" << endl;
    cout << "\tB.Ms = solve for s" << endl;
    cout << "\tC.Mv2 = solve for v^2" << endl;
    cout << "\tD.Mv = solve for v_bar" << endl;
    cout << "\tE.Exit Motion Calculator" << endl;
    cout << "\tX.Clear Screen" << endl;

}


void motionwork(string)  //Motion Menu work
{ 
    string color = "\x1b[" + to_string(32) + ";1m";
    string reset = "\x1b[0m";
    string motionOption = "";
    
    
    motionmenu();
    cout << "What option would you like for motion?: ";
    
    motionOption = validateString(motionOption);    //get user selection

    if (motionOption == "A" || motionOption == "a")
    {
        cout << "Time to solve for V" << endl;
        m1();
    }
    else if (motionOption == "B" || motionOption == "b")
    {
        cout << "Time to solve for S" << endl;
        m2();   //function call
    }
    else if (motionOption == "C" || motionOption == "c")
    {
        cout << "Time to solve for V^2" << endl;
        m3();
    }
    else if (motionOption == "D" || motionOption == "d")
    {
        cout << "Time to solve for V_Bar" << endl;
        m4();
    }
    else if (motionOption == "E" || motionOption == "e")
    {
        cout << "Time to exit!!" << endl;
    }
    else if (motionOption == "X" || motionOption == "x")    //Clear Screen
    {
        cout << "Time to do some screen clearing!!" << endl;
        cleanscreen(); 
    }
   
    
}


void Motion()   //Do while loop and exit condition for motion sub-menu
{
    string color = "\x1b[" + to_string(32) + ";1m";
    string reset = "\x1b[0m";
    string motionOption = "";
    do
    {
        motionmenu(); //call a menu void function here
        cout << "\nPlease Select A Calculator: ";
        cout << color; //change text to green 
        motionOption = validateString(motionOption);
        cout << reset; //reset back to standard
        motionwork(motionOption); //call handleOption and pass the user option as an argument


    } while (motionOption != "e" && motionOption != "E"); //DeMorgan's Law!!!                      
    cout << "\nGoodbye. Hasta luego." << endl;

}

void m1()
{
    cout << "Please enter the mass: " << endl;
    m = validateDouble(m);
    cout << "Now the acceleration: " << endl;
    dv = validateDouble(dv);
    cout << "Mass entered : " << setprecision(4) << m << "  Acceleration entered: " << setprecision(4) << dv << endl;
    cout << "the total force is : " << setprecision(4) << mm << endl;
}

void m2()
{
    cout << "Please enter v the (constant) speed : " << endl;
    dv = validateDouble(dv);
    cout << "Now the time : " << endl;
    dt = validateDouble(dt);
    cout << "Constant speed entered : " << setprecision(4) << dv << "  time entered : " << setprecision(4) << dt << endl;
    cout << "The total displacement is : " << setprecision(4) << s << endl;
}

void m3()
{
   
    cout << "Please enter the initial velocity: " << endl;
    mv = validateDouble(mv);
    cout << "Now enter the acceleration: " << endl;
    ma = validateDouble(ma);
    cout << "Now enter the initial position: " << endl;
    ms = validateDouble(ms);
    cout << "And finally the final position: " << endl;
    mss = validateDouble(mss);
    cout << "Initial velocity entered : " << setprecision(4) << mv << "  Acceleration entered: " << setprecision(4) << ma << "  Initial position entered: " << setprecision(4) << ms << "  Final Position entered: " << setprecision(4) << mss << endl;
    cout << "Mv2 =  " << setprecision(4) << mv2 << endl;
}

void m4()
{
    cout << "Please enter the initial velocity : " << endl;
    mv = validateDouble(mv);
    cout << "Now enter the final velocity : " << endl;
    mvv = validateDouble(mvv);
    cout << "Initial velocity entered : " << setprecision(4) << mv << " final velocity entered : " << setprecision(4) << mvv << endl;
    cout << "Mv = : " << setprecision(4) << mxx << endl;

}
void Newton()
{
    cout << "Please enter the mass: " << endl;
    m = validateDouble(m);
    cout << "Now enter the acceleration" << endl;
    dv = validateDouble(dv);
    cout << "Mass entered : " << setprecision(4) << m << "  Acceleration entered: " << setprecision(4) << dv << endl;
    cout << "\nTotal Force : " << setprecision(4) << newt << " kg m/s^2" << endl;
}

void Weight()
{
    cout << "Please enter the mass: " << endl;
    m = validateDouble(m);
    cout << "Now enter the gravity: " << endl;
    g = validateDouble(g);
    cout << "Mass entered : " << setprecision(4) << m << "  Gravity entered: " << setprecision(4) << g << endl;
    cout << "\nTotal Weight is = " << setprecision(4) << weight << " lbs" << endl;
}

void Momentum()
{
    cout << "Please enter the mass: " << endl;
    m = validateDouble(m);
    cout << "Now enter the velocity: " << endl;
    dv = validateDouble(dv);
    cout << "Mass entered : " << setprecision(4) << m << "  Velocity Entered: " << setprecision(4) << dv << endl;
    cout << "\n Total Momentum is = " << setprecision(4) << mm << " kg m/s" << endl;
}

void cleanscreen()      //Function will clear screen
{
    cout << "Flushing output stream..." << flush;
    system("CLS");
}



void work(string optionselected)
{
    if (optionselected == "A" || optionselected == "a")     //Start Velocity Function
    {
        cout << "Time to do some velocity calculations!!" << endl;
        Velocity();

    }
    else if (optionselected == "B" || optionselected == "b")    //Start Acceleration Function
    {
        cout << "Time to do some acceleration calculations!!" << endl;
        Acceleration();
    }
    else if (optionselected == "C" || optionselected == "c")    //Start Motion Function
    {
        cout << "Time to do some motion calculations!!" << endl;
        Motion(); //call Motion(); Dr_T

    }
    else if (optionselected == "D" || optionselected == "d")    //Start Newton's Function
    {
        cout << "Time to do some Newton's 2nd law calculations!!" << endl;
        Newton();
    }
    else if (optionselected == "E" || optionselected == "e")    //Exit Program
    {
        cout << "Time to exit!!!" << endl;
    }
    else if (optionselected == "F" || optionselected == "f")    //Start Weight Function
    {
        cout << "Time to do some weight calculations" << endl;
        Weight();
    }
    else if (optionselected == "G" || optionselected == "g")    //Start Momentum Function
    {
        cout << "Time to do some momentum calculations!!" << endl;
        Momentum();
    }
    else if (optionselected == "X" || optionselected == "x")    //Clear Screen
    {
        cout << "Time to do some screen clearing!!" << endl;
        cleanscreen();
    }


}

#endif