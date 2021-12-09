/*  Programmer : John-David Rodriguez
    Course: COSC-1437
    Date: 12/7/2021
    IDE: Microsoft Visual Studio
    Description:   Use of knowledge of C++ and Recursion to Solve the Towers of Hanoi problem (Goal: Research what this is, and solve it).
                   Also:  Write a recursive function factorialR that will generate factorials based upon the user starting point (validated) input from the keyboard.
                   i.e. When the user enters, 4, the function should multiply 4 x 3 x 2 x 1, and output the result of 24. 
*/


/*Definition of Recursion :
    
    Recursion is when a function is called within the same function. A function that calls itself is a recursive function.

*/

#include <iostream>
#include "Input_Validation_Extended.h"
using namespace std;




void towerOfHanoi(int n, char from_rod,
    char to_rod, char aux_rod)
{
    if (n == 1)
    {
        cout << "Move disk 1 from rod " << from_rod <<
            " to rod " << to_rod << endl;
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod <<
        " to rod " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int factorialR(int a)
{
    if (a == 0)
        return 1;
    return a * factorialR(a - 1);
}


int main()
{
    int n = 4; // Number of disks
    int num;  //variable for factorial
    towerOfHanoi(n, 'A', 'C', 'B'); //  names of rods
    cout << "\n\nPlease enter a number to find factorial of: " << endl;
    num = validateInt(num);
    cout << "\n\nFactorial of " << num << " is " << factorialR(num) << endl;
    
    return 0;

}

