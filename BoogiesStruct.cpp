/*  John-David Rodriguez  , C++ Builder
This program purpose is to create structs and print out data with functions
*/

#include <iostream >
#include <string>
using namespace std;

//Create a struct for boogies
struct boogies {
	string name;
	int age;

};

//Create a struct for favorite foods
struct food{
	string favfood;

};

//Create function  to print boogies information
void printboogiesinfo(boogies boogies) {
	cout<<"Your name is :  "<<boogies.name<<endl;
	cout<<"Your age is :  "<<boogies.age<<endl;

};

//Create Function to print favorite foods

void printfavfood ( food food) {
	cout<<"Your favorite food is  :  "<<food.favfood<<endl;

};
 //Main to call other functions and assign values to structs
int main()  {

	//Assigning value to boogies struct
	boogies boog1;
	boog1.name = "Boogies";
	boog1.age = 1001;



	//Assign value to food struct
	food fav1;
	fav1.favfood = "Pizza";

	//Calling the print functions

	printboogiesinfo(boog1);
	printfavfood(fav1);



    system("pause");
}
