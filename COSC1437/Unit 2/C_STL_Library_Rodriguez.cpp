/*  Programmer : John-David Rodriguez
    Course: COSC-1437
    Date: 11/2/2021
    IDE: Microsoft Visual Studio
    Description:  Create a single main.cpp that contains code samples and implementations of each of the following topics
*/

#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
#include <stack>
#include <cassert>
#include <set>
#include <utility>
#include <map>

using namespace std;

//Credit https://www.geeksforgeeks.org/passing-vector-constructor-c/ clarifications added

class MyClassVector1            //Create MyClassVector1
{
private:
    vector<int> vec;
public:
    MyClassVector1(vector<int> v)  //parameterized constructor
    {
        vec = v;
    }
    void print()
    {
        /// print the value of vector 
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
    }
};

class MyClassVector2                //Create MyClassVector2
{
private:
    vector<int> vec2;
public:
    MyClassVector2(vector<int> v2)
    {
        vec2 = v2;
    }
    void print2()
    {
        //print value of vector2
        for (int i = 0; i < vec2.size(); i++)
        {
            cout << vec2[i] << " ";
        }
    }
};

class MyClassVector3            //Create MyClassVector3
{
private:
    vector<int> vec3;
public:
    MyClassVector3(vector<int> v3)
    {
        vec3 = v3;
    }
    void print3()
    {
        //print value of vector3
        for (int i = 0; i < vec3.size(); i++)
        {
            cout << vec3[i] << " ";
        }
    }
};

int main()
{
    /****Section_Name***Vectors*/
    //Write the base code for: 5. std::vector example
    vector<double> vd; //vd elments are floating point numbers
    vector<int> vi; //vi elements are integer numbers 
    vector<string> vs; //vs elements are string objects 

    //Expand this code to:

    //add 3 elements to the vd vector       **Complete**
    vd.push_back(15.44);
    vd.push_back(20.56);
    vd.push_back(30.56);
    vd.push_back(55.4);

    //add 3 elements to the vi vector       **Complete**
    vi.push_back(5);
    vi.push_back(6);
    vi.push_back(7);


   // add 3 elements to the vs vector   **Complete**
    vs.push_back("Hello");      //input must be string since vector dataype is string
    vs.push_back("World");
    vs.push_back("My name is JD");

   // display the 3 elements in the vd vector       **Complete**
    cout << "\nValues in vd: \n";
    for (double vals : vd)
    {
        cout << vals << endl;
    }
    cout << "\nAnother way to print vector: " << endl;
    for (int i = 0; i < vd.size(); i++)
    {
        cout << vd[i] << endl;
    }

    //display the 3 elements in the vi vector       **Complete**
    cout << "\nValue is vi: \n";
    for (int nmbs : vi)
    {
        cout << nmbs << endl;
    }

   // display the 3 elements in the vs vector       **Complete**
    cout << "\nValue of vs: \n";
    for (string wrds : vs)
    {
        cout << wrds << endl;
    }

    /****Section_Name***Vector_as_Class_Member*/
    //Credit https://www.geeksforgeeks.org/passing-vector-constructor-c/

    cout << "\nVector_as_Class_Member" << endl;         //MyClassVector1
    vector<int> vec;
    for (int i = 1; i <= 5; i++)
        vec.push_back(i);
    MyClassVector1 obj(vec);
    obj.print();


    cout << "\n Vector2_as_Class_Member" << endl;       //MyClassVector2
    vector<int> vec2;
    for (int i = 1; i <= 5; i++)
        vec2.push_back(i);
    MyClassVector2 obj2(vec2);
    obj2.print2();


    cout << "\n Vector3_as_Class_Member" << endl;       //MyClassVector3
    vector<int> vec3;
    for (int i = 1; i <= 5; i++)
        vec3.push_back(i);
    MyClassVector3 obj3(vec3);
    obj3.print3();


    //Continue with MyClassVector2 and MyClassVector3       **Complete**

  /****Section_Name***STL_Iterators*/

    vector <int> vint(10);   //Vector with 10 integer numbers
    vint[0] = 0;
    vint[1] = 1;
    vint[2] = 2;
    vint[3] = 3;
    vint[4] = 4;
    vint[5] = 5;
    vint[6] = 6;
    vint[7] = 7;
    vint[8] = 8;
    vint[9] = 9;
    //vint[10] = 10;

    //Now display the elements of the vector
    vector<int>::iterator it;
    for (it = vint.begin(); it != vint.end(); ++it) {
        cout << " " << *it;
    }


  /****Section_Name*** Stack*/
    stack<int> st;

    st.push(100);                   //Push number on the stack
    assert(st.size() == 1);         //verify one element is on the stack
    assert(st.top() == 100);        //verify element value

    st.top() = 456;                 //Assign new value
    assert(st.top() == 456);        


    st.pop();                       //Remove Element
    assert(st.empty() == true);


  //Write comments that help one better understand what the code is doing.

       //a stack is a container that can only insert or extract its elements from the top of the container, kinda like a pringles can..

  /****Section_Name**** Set*/
    set<int> iset;          //Set of unique integer numbers

    iset.insert(11);        //populate the set with some values
    iset.insert(-11);
    iset.insert(55);
    iset.insert(22);
    iset.insert(22);
    if (iset.find(55) != iset.end())    //Check to see if value is already stored
    {
        iset.insert(55);
    }
    assert(iset.size() == 4);   //Sanity check
    //set<int>::iterator it;
    /*for (it = iset.begin(); it != iset.end(); it++)
    {
        cout << " " << *it;
    }
    */
    //output would be -11 11 22 55
    //set elements are always sorted
    //a set is a container that holds unique elements



  /****Section_Name****Pair_Structure*/
    pair <string, string> strstr;           //a pair is like a cointer that holds exactly two elements
    strstr.first = "Hello";                 //first element
    strstr.second = "World";                //second element

    pair<int, string> intstr;               //a new pair
    intstr.first = 1;                       //first element
    intstr.second = "one";                  //second element

    pair<string, int> strint("two", 2);
    assert(strint.first == "two");          //Check argument
    assert(strint.second == 2);


  /****Section_Name**** Map_Insert*/
    typedef map<string, int> MapT;              //user insert() to put in a new item only if it was not already there
    typedef MapT::const_iterator MapIterT;

    MapT amap;
    pair<MapIterT, bool> result =
        amap.insert(make_pair("Fred", 45));
    assert(result.second == true);      //Checking argument
    
    result = amap.insert(make_pair("Fred", 54));            //Fred was already in the map and result.first
    assert(result.second == false);
    assert(result.first->second == 45);


  /****Section_Name****Map_Summary*/
    map<string, string> phone_book;     //create map called phone_book
    phone_book["411"] = "Directory";    //Setting values
    phone_book["911"] = "Emergency";
    phone_book["508-678-2811"] = "BCC";
    if (phone_book.find("411") != phone_book.end())
    {
        phone_book.insert(make_pair(string("411"), string("Directory")));
    }
    assert(phone_book.size() == 3);     //Check argument
    //map<string, string>::const_iterator it;
    /*for (it = phone_book.begin(); it != phone_book.end(); ++it)               
    {
        cout << " " << it->first << " " << it->second << endl;
       
    }*/

    // a map is a container that holds unique pairs of keys and values and the elements are always sorted by its keys


  /****Section_Name**** Sort_Algorithm*/
  
    int arr[100];       //create array
    sort(arr, arr + 100);
    //vector v1;
    //sort(v1.begin(), v1.end());           //Sort vector

    //sort the range between two iterators
    //iterators must be random access



  /****Section_Name****Predicate_Algorithm*/
    /* bool less_than_7(int value)                      //a function returning a bool is a predicate
    {
        return value < 7;                               //an object which overloads operator() to return bool is also a predicate
    }

    vector<int> v1;                                     //Create vector v1
    int count_less = std::count_if(v1.begin * (), v1.end(), less_than_7);


    */



    return 0;
}