/*	Programer : JD Rodriguez
*	IDE :		Microsoft Visual Studio
*	Date:		10/16/2021
*	Description: Purpose of the program is to obtain the ASCII values of the key(s) that is pressed... 
*/


//Include Libraries / Header Files
#include <iostream>
#include <conio.h>

using namespace std;

//Create main function

int main() {
	
	//Define Variables
	char key_press;
	int ascii_value;

	//Start output to user
	cout << "/n/t/t/tPress Any Key To Check Its ASCII Value\n\n\t\t\tPress ESC to Exit\n\n\n";

	//Start While Loop
	while (1)
	{
		key_press = _getch();
		ascii_value = key_press;
		//Start if statement
		if (ascii_value == 27) // For ESC Break
			break;
		cout << "\t\t\tKey Pressed ------>    \"    " << key_press << "  \" ASCII Value = " << ascii_value << "\n\n";

	}

	return 0;
}




