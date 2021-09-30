/*  Date : 9-30-2021
	Programmer : Boogies
	Purpose : Basic Method Example
	IDE : C++ Builder
*/

#include <iostream>
#include <string>
using namespace std;

class foods {       //Create a class
	public:         //Access specifier
		void foodmethod(){   //Method defined inside the class
			cout<<"This is a method"<<endl;
		}
};




int main(){

 foods myObj;   //Create an object of foods
 myObj.foodmethod();    //Call Food Method


	system("pause");
}
