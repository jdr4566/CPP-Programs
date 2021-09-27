/*  John-David Rodriguez , COSC - 1436 - 57001 , Dev C++

    Write a program that will create an event structure and initializes all of its fields with data. 
    Dates and times do not need to be current but need to be valid date and times.

*/

#include <iostream>
#include <string>

using namespace std;

//Structure to define timeOfDay
struct timeOfDay{
  short Hour;
  short Minute;
  short Second;
};

//Structure to define appDate
struct appDate{
  short dayOfMonth;
  short month;
  int year;
};

//Structure to define event
struct event{
  string eventname;
  string timeOfDay;
  string appDate;
  bool isurgent;
};
       
//function to print timeOfDay
void printtimeOfDay(timeOfDay timeOfDay) {
  cout<< " The hour is  : " << timeOfDay.Hour<<endl;
  cout<< " The Minute is : " <<timeOfDay.Minute<<endl;
  cout<< " The Second is : " << timeOfDay.Second<<endl;
}


//function to print appDate
void printappdate(appDate appdate) {
  cout<<"The day of the month is : "<<appdate.dayOfMonth<<endl;
  cout<<"The month is : "<<appdate.month<<endl;
  cout<<"The year is : "<<appdate.year<<endl;
} 

//function to print event info
void printevent(event event){
  cout<<"The event name is : "<<event.eventname<<endl;
  cout<<"The time of day is : "<<event.timeOfDay<<endl;
  cout<<"The appDate is : "<<event.appDate<<endl;
}


//Main program to call functions and assign value to Structure above
int main()
{
    //Assigning values to timeOfDay struct
    timeOfDay time1;
    time1.Hour = 6;
    time1.Minute=30;
    time1.Second=45;

    //Assigning values to appDate struct
    appDate app1;
    app1.dayOfMonth=15;
    app1.month=11;
    app1.year=2021;

    //Assigning value to event struct
    event event1;
    event1.eventname = "JD's Birthday Party";
    event1.timeOfDay="11:00 PM";
    event1.appDate="November 15 2021";

    //Calling the print functions
    printtimeOfDay(time1);
    printappdate(app1);
    printevent(event1);
    
    
    
 return 0;   
}
