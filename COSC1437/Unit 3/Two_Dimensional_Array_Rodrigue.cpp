//Student Name: John-David Rodriguez

//Teacher: Dr. Tyson McMillan

//Date:     11/4/2021

//A program to practice working with multi-dimensional arrays

#include <iostream>

using namespace std;

/*

Research Input data: go to http://www.weather.com (Links to an external site.)

Pick two cities of your choice. Fill in the temperature for the 7 days of this week of both cities. Fill in this text data table, which will be used in your program.

//Fort_Worth = 1, Dallas = 2  Replace City_One and City_Two with the names of your cities           //**Complete**

//Data Table

//City X, Day X: Temp

Fort_Worth, Day 1: 58

Fort_Worth, Day 2: 77

Fort_Worth, Day 3: 73

Fort_Worth, Day 4: 69

Fort_Worth, Day 5: 67

Fort_Worth, Day 6: 67

Fort_Worth, Day 7: 74

Dallas, Day 1: 57

Dallas, Day 2: 75

Dallas, Day 3: 72

Dallas, Day 4: 68

Dallas, Day 5: 66

Dallas, Day 6: 64

Dallas, Day 7: 73

*/



int main()

{

    const int CITY = 2;

    const int WEEK = 7;



    int temperature[CITY][WEEK];

    //Note your input data from the above

    cout << "Enter all temperature for a week of first city and then second city. \n";



    // Inserting the values into the temperature array

    //note for every dimension of the array you need a for loop 2 dimensions = 2 for loops

    for (int i = 0; i < CITY; ++i)

    {

        for (int j = 0; j < WEEK; ++j)

        {

            cout << "City " << i + 1 << ", Day " << j + 1 << " : ";

            cin >> temperature[i][j];

        }

    }



    cout << "\n\nDisplaying Temperatures:\n";



    // Accessing the values from the temperature array

    for (int i = 0; i < CITY; ++i)

    {

        for (int j = 0; j < WEEK; ++j)

        {

            cout << "City " << i + 1 << ", Day " << j + 1 << " = " << temperature[i][j] << endl;

        }

    }

    /*For up to 5 Points Extra Credit

       Expand this program:

     */


    //  1. Create a one dimensional array, cityOne[7] to store the 7 temperatures of city 1, assume that value 0 represents day 1, 1 represents day 2....

    int FortWorth[7];       //Created a one dimensional array of cityOne

    // 2. Create a on dimensional array, cityTwo[7] to store the 7 temperatures of city 2 , assume that value 0 represents day 1, 1 represents day 2....
    int Dallas[7];          //created a one dimensional array of cityTwo

    // 3. Using a for loop (or nested for loop), feed the data of CityOne[] and CityTwo[] into temperature[i][j], where i is index of the City Number, and j is the index of the temp for the day.

   /* int cityOne;
    int cityTwo;

    for (int i = 0; i < cityOne; ++i)
    {
        for (int j = 0; j < cityTwo; ++j)
        {
            
        }
    }
    */

    //4. print the results of temperature[i][j]; to the screen.
    //cout << "The temperatures are as follows: " << temperature[i][j] << endl;
    
    return 0;

}