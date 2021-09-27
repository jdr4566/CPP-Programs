//Purpose of program is to understand pointers and use some basic ones


#include <iostream>
using namespace std;


int main(){
	 int fish = 5;

	 int *fishPointer;
     fishPointer = &fish;

	 cout <<"The memory address of int fish is : "<< fishPointer<<endl;

	 system("pause");

}


