/*  Programmer : John-David Rodriguez
    Course: COSC-1437
    Date: 12/1/2021
    IDE: Microsoft Visual Studio
    Description:   Object-Oriented, Vector, Menu-Driven Restaurant Program Bringing all elements of the class together in one program.

*/

#include <iostream>
#include<string>
#include<vector>
#include<iomanip>
#include <cmath>
#include <conio.h>
#include <fstream>
using namespace std;

/*struct MenuItem
{
  string name;
  double itemCost; 
  string desc; 
  char addLetter; 
  char removeLetter;
  int count; 
};*/

class MenuItem                     //convert struct to a class
{
public:
    string name;
    double itemCost;
    string desc;
    char addLetter;
    char removeLetter;
    int count;

public:
    MenuItem()             //default constructor
    {
        name = "item";
        itemCost = 0.0;
        desc = "description";
        addLetter = 'a';
        removeLetter = 'b';
        count = 1;
    }
    MenuItem(string n, double ic,string dsc,char al,char rl,int c)
    {
        name = n;
        itemCost = ic;
        desc = dsc;
        addLetter = al;
        removeLetter = rl;
        count = c;
    }

    //create setters and getters
    void setName(string n) { name = n; }
    void setItemCost(double ic) { itemCost = ic; }
    void setDesc(string dsc) { desc = dsc; }
    void setaddLetter(char al) { addLetter = al; }
    void setremoveLetter(char rl) { removeLetter = rl; }
    void setCount(int c) { count = c; }
    //now the getters
    string getName() const { return name;}
    double getItemCost() const { return itemCost; }
    string getDesc() const { return desc; }
    char getaddLetter() const { return addLetter; }
    char getremoveLetter() const { return removeLetter; }
    int getCount() const { return count; }

};











//function definitions
void populateMenu(vector<MenuItem>& entireMenu)
{
    //put some default values in our Menu
    const int numItems = 7;
    MenuItem Item1;
    MenuItem Item2;
    MenuItem Item3;
    MenuItem Item4;
    MenuItem Item5;
    MenuItem Item6;
    MenuItem Item7;

    entireMenu.push_back(Item1); //add to the end of list the Item1
    entireMenu.push_back(Item2); //add to the end of list the Item2
    entireMenu.push_back(Item3); //add to the end of list the Item3
    entireMenu.push_back(Item4); //add to the end of list the Item4
    entireMenu.push_back(Item5); //add to the end of list the Item5
    entireMenu.push_back(Item6); //add to the end of list the Item6
    entireMenu.push_back(Item7); //add to the end of list the Item7

    vector<string> defaultMenuNames = { "Green Tea", "Burrito", "Item 3", "Item 4", "Item 5", "Item 6", "Item 7" };
    vector<char> defaultAddLetters = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
    vector<char> defaultRemoveLetters = { 'a', 'b', 'c', 'd', 'e', 'f', 'g' };

    for (int i = 0; i < numItems; i++)
    {
        //add each item to the default list efficiently 
        entireMenu[i].name = defaultMenuNames[i];
        entireMenu[i].addLetter = defaultAddLetters[i];
        entireMenu[i].removeLetter = defaultRemoveLetters[i];
        entireMenu[i].itemCost = (3.00 + i); //set a random starter cost for each item
        entireMenu[i].count = 0; //initialze all counts to 0
        entireMenu[i].desc = "delicious"; //set all default desc to "delicous"
    }


}

void showMenu(vector<MenuItem>& m)
{
    cout << fixed << setprecision(2);//set doubles to 2 decimal places
    cout << "DrT's Effcient Menu" << endl;
    cout << "ADD  \tNAME \t COST \tREMOVE\tCOUNT\tDESC" << endl;
    for (int i = 0; i < m.size(); i++)
    {
        cout << m[i].addLetter << ")" << setw(10) << m[i].name
            << setw(5) << "$" << m[i].itemCost << setw(5) << "(" << m[i].removeLetter
            << ")" << setw(7) << m[i].count << setw(13) << m[i].desc
            << endl;
    }

}

void acceptOrder(vector<MenuItem>& m)
{
    char option = '\0';// the user-selected menu item
    double subtotal = 0.0;
    double tip = 0.0;
    double tax = subtotal*(0.0825);
    double totaldue = subtotal + tip + tax;
    


    do
    {
        cout << "\nPlease choose an item (x to Exit): ";
        cin >> option;

        for (int i = 0; i < m.size(); i++)
        {
            if (option == m[i].addLetter)
            {
                cout << "\nMenu Item " << m[i].addLetter << " selected.";
                m[i].count++; //increment the count by 1
                cout << "\033[2J\033[1;1H"; //clear screen 
                cout << "\n1 UP on " << m[i].name << endl;
                subtotal += m[i].itemCost; //increment the subtotal by the cost of the item 
                showMenu(m); //show the updated menu
                cout << "\nSubtotal: $" << subtotal << endl;
            }
            else if (option == m[i].removeLetter)
            {
                cout << "\nRemove Item " << m[i].removeLetter << " selected.";
                if (m[i].count > 0) //subtract if and only if the count is > 0
                {
                    m[i].count--; //decrement the count by 1
                    cout << "\033[2J\033[1;1H"; //clear screen 
                    cout << "\n1 DOWN on " << m[i].name << endl;
                    subtotal -= m[i].itemCost; //decrement the subtotal by the cost of the item
                    showMenu(m); //show the updated menu
                    cout << "\nSubtotal: $" << subtotal << endl;
                }
                else //the the user why you blocked item removal 
                {

                    cout << "\nItem count must be > 0 to remove: " << m[i].name << endl;
                }
            }
            else if (
                option != m[i].addLetter &&
                option != m[i].removeLetter &&
                option != 'x' &&
                option != 'X'
                ) //test for all of my valid inputs
            {
                if (i == 0)
                {
                    cout << "\nInvalid input (" << option << "). Please try again." << endl;
                }
            }
        }
    } while (option != 'x' && option != 'X');
    cout << "\nThank you for placing your order." << endl;
    //handle the tip process here
    cout << "Please enter a tip amount we suggest 20% or more:  " << endl;
    cin >> tip;
    
  

    //Credit Card or cash?
    cout << "\nAre you paying with cash or card?: " << endl;
    cout << "Press A for credit card and B for cash: " << endl;
    cin >> option;
    if (option == 'A')
    {
        cout << "\nProcessing Credit Card Payment....." << endl;
        }
    else if (option == 'B')
    {
        cout << "\nCalculating change..... " << endl;

    }



   
    //handle reciept generation here
   
    cout << "\nYour total due is as follows: " << endl;
    cout << "Subtotal: " << subtotal << endl;
    cout << "Tax: " << tax << endl;
    cout << "Tip: " << tip << endl;
    cout << "Total: " << totaldue << endl;
    

    //now printing to receipt text file
    ofstream myfile;
    myfile.open("receipt.txt");
    myfile << "Writing this to a file. \n" << "Your Subtotal Is: " << subtotal << endl << "Your Tax is: " << tax << endl << "Your Tip is : " << tip << endl << "Your Total paid is: " << totaldue << endl;
    myfile.close();

    
   
    
}

void printReceipt(vector<MenuItem>& m)
{

    //local variables
    double subtotal = 0.0 ;
    double tax = 0.0;
    double tip = 0.0;
    double totaldue = tax + tip + subtotal;

    cout << "\nPrinting your Receipt!!" << endl;
    cout << "Totals are as follows: " << endl;
    cout << "\nYour total due is as follows: " << endl;
    cout << "Subtotal: " << subtotal << endl;
    cout << "Tax: " << tax << endl;
    cout << "Tip: "<< tip <<endl;
    cout << "Total: " << totaldue << endl;




}

int main()
{
    vector<MenuItem> wholeMenu;
    system("color A1"); //for some color
    populateMenu(wholeMenu); //put some default values in the menu
    showMenu(wholeMenu); //print the current data of the menu on screen 
    acceptOrder(wholeMenu);
    
    return 0;
}