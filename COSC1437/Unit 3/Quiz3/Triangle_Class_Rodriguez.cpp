/*  Programmer : John-David Rodriguez
    Course: COSC-1437
    Date: 11/12/2021
    IDE: Microsoft Visual Studio
    Description:  Write the appropriate Objected Oriented Class Definition and code to calculate the area of Instances of the Triangle Class. 
                  In int main() write the appropriate code to accept the base and height of 3 Instances of the Triangle Class
                  Echo to the user the values that he/she provide for base and height in each of the 3 triangles, and the calculated area of each. 
                  Output to the screen also the totalArea of the 3 Triangles combined. 
*/


#include <iostream>
#include "Input_Validation_Extended.h"      //no cin waka waka



using namespace std;




class Triangle				//Create a triangle class
{
private: 
    double base;
    double height;

public:
    Triangle()  //Default constructor
    {
        base = 0.0;
        height = 0.0;
    }
    Triangle(double b, double h)
    {
        base = b;
        height = h;
    }
    //LIKE DR T SAYS " YOUR SETTERS AND YOUR GETTERS " 
    void setBase(double b) { base = b; }
    void setHeight(double h) { height = h; }
    double getBase() const { return base; }
    double getHeight() const { return height; }
    double getArea() const { return (.5 * base * height); }
    
    
};


int main()
{

    //local variables
    double bLocal = 0.0;    //for triangle 1
    double hLocal = 0.0;    //for triangle 1
    double b2Local = 0.0;   //for triangle 2
    double h2Local = 0.0;   //for triangle 2
    double b3Local = 0.0;   //for triangle 3
    double h3Local = 0.0;   //for triangle 3


    //get triangle 1 parameters
    cout << "\n Please enter a Base for Triangle 1 : " << endl;
    bLocal = validateDouble(bLocal);      //get base from user
    cout << "\n Please enter a Height for Triangle 1: " << endl;
    hLocal = validateDouble(hLocal);    //get height from user

    Triangle t(bLocal, hLocal);     //create instance 1

     cout << " The Base for Triangle 1 is : " << t.getBase() << endl;
     cout << " The Height for Triangle 1 is : " << t.getHeight() << endl;
     cout << " And the area for Triangle 1 is : " << t.getArea() << endl;
        
      //get triangle 2 parameters
     cout << "\n Please enter a base for Triangle 2: " << endl;
     b2Local = validateDouble(b2Local);
     cout << "\n Please enter a Height for Triangle 2: " << endl;
     h2Local = validateDouble(h2Local);

    Triangle t2(b2Local, h2Local);    //Create instance 2

    cout << "The Base for Triangle 2 is: " << t2.getBase() << endl;
    cout << "The Height for Triangle 2 is: " << t2.getHeight() << endl;
    cout << "And the area for Triangle 2 is: " << t2.getArea() << endl;

    //get triangle 3 parameters
    
    cout << "\n Please enter a Base for Triangle 3: " << endl;
    b3Local = validateDouble(b3Local);
    cout << "\n Please enter a Height for Triangle 3:" << endl;
    h3Local = validateDouble(h3Local);

    Triangle t3(b3Local, h3Local);  //create instance 3

    cout << "The Base for Triangle 3 is: " << t3.getBase() << endl;
    cout << "The Height for Triangle 3 is: " << t3.getHeight() << endl;
    cout << "And the area for Triangle 3 is: " << t3.getArea() << endl;

    //Display TotalArea
    cout << "The Total Area for all Triangles is : " << t.getArea() + t2.getArea() + t3.getArea() << endl;



    return 0;
}