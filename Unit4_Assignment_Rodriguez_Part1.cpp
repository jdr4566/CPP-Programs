/* John-David Rodriguez  COSC 1436-57001 , Dev C++
This program is made to accept input from the user while the value entered does not equal -1 (the exit value) and will continue to loop
*/

#include <iostream>
using namespace std;




int main() {

//Declaring Variables
	
int counter =0;//Setting Counter
double n =0.0;


//Starting While Loop		//Part 1 of assignment

	while (n != -1.0) // Exit condition
	
	{
		cout<<"Please enter a -1 to end the program"<<endl;
			
			cin>>n; // Take Input from user
			
			cout<< n << " times " << n << " is " << n * n <<endl;
			
			cout<< n << " divided by "<< n << " is "<< n / n <<endl;
			
			cout<< " The output for   (n+3)/5 " << " is " << (n+3)/5<<endl;
			
			cout<< " The output for  [ ( (n+3)/5 ) + ( (n+7)/2 ) ]"<<" is "<< (((n + 3) /5 + ((n +7)/2 ))) <<endl;
			
			counter++;	//Adding +1 to counter
			
	}
	
	
	
	
	
	return 0;
}
