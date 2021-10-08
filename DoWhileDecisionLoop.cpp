/*  John-David Rodriguez, C++ Builder
Purpose of program :
1) Declare a variable of type char called decision.
2) Accept input from the user for in the variable decision
3) If decision equals 'y' or if decision equals 'Y' output yes to the screen
4) otherwise If decision equals 'n' or if decision equals 'N' ouput no to the screen
5) otherwise If decision equals 'e' or if decision equal 'E' ouput exit to the screen
6) In all other cases, else, output invalid entry to the screen.
7) Put this all around a do-while loop whose exit condition is 'E' or 'e' for exit. Be sure to let the user know what the exit condition.
*/

#include <iostream>
#include <string>
using namespace std;

int main(){

//Declaring Variables
char decision;
int i = 0;  //Counter Variable

//Asking User for Decision
cout<<"Please enter your decision"<<endl;
//Getting input from user
cin>>decision;

//Starting Do-While Statement



   do {
        if (decision == 'e') {
            cout<<"Exiting Program"<<endl;
			break;

		}
		if (decision == 'y'){
            cout<<"yes"<<endl;
		}
		if (decision =='Y'){
			cout<<"yes"<<endl;
		}
		if (decision == 'n'){
			cout<<"no"<<endl;
		}
		if (decision == 'N'){
            cout<<"no"<<endl;
		}
		if (decision =='E'){
			cout<<"Exiting Program"<<endl;
            break;
		}
		else
            cout<<"Invalud entry"<<endl;

		i++;
	} while (i < 10);






     system("pause");
}
