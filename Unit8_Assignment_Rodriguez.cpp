/*  John-David Rodriguez , COSC-1436- 57001 , C++ Builder
    Write a method that will update the vehicle color to “GREEN” if the year is after 2010 or RED if 2010 or earlier.
*/


#include <iostream>
#include <string>
using namespace std;

struct car  {           //Create Car Structure
	string make;
	string model;
	int Year;
	string color;
};


//Create function to determine car color
void showcarcolor(int year){
	car carinfo;
	if(year > 2010) {
		carinfo.color="Green";
		cout<<"The color of the vehicle is : "<< carinfo.color<<endl;
    }

	else if (year<2010){
	   carinfo.color="Red";
       cout<<"The color of the vehicle is : "<<carinfo.color<<endl;

	}

}



int main(){


	//Assign Structure values
	car carinfo;
	carinfo.make = "Toyota";
	carinfo.model= "Tundra";
	carinfo.Year = 2012;


	//Display output to user
	cout<<"The make of the vehicle is : "<<carinfo.make<<endl;
	cout<<"The model of the vehicle is : "<<carinfo.model<<endl;
    cout<<"The year of the vehicle is : "<<carinfo.Year<<endl;


	//Call Color Function
	 showcarcolor(2012);


  system("pause");
}


