/* John-David Rodriguez  COSC 1436-57001 , Dev C++
This program is made to take input from the user for the value of N (the stopping point) and prints out the first N ordinals, followed by Hello. 
*/

#include <iostream>
#include<iomanip>
#include "Input_Validation_Extended.h"

using namespace std;


int main()
{
int stop = 0;

while (stop != -1)
{


cout << "Hello this is a ordinal number generator" <<endl;

cout << "This program will continue to repeat Hello"<<endl;

cout << "Enter the number -1 to end the program"<<endl;

stop = validateInt(stop);


for (int hi = 1; hi <= stop; hi++)
{

if ((hi % 100) == 11 || ((hi % 100) == 12) || ((hi % 100) == 13))
{
cout << hi << "th hello\n";
}
else if ((hi % 10) == 1)
{
cout << hi << "st hello\n";
}
else if ((hi % 10) == 2)
{
cout << hi <<"nd hello\n";
}
else if ((hi % 10) == 3)
{
cout << hi <<"rd hello\n";
}
else
{
cout << hi <<"th hello\n";
}
}
}
return stop++;

return 0;
} 
