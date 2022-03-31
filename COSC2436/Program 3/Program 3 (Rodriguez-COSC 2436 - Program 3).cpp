/*  Programmer : John-David Rodriguez
    Course: COSC-2436
    Date: 3/20/2022
    IDE: Microsoft Visual Studio
    Description:   Write a (Java or C++) program to calculate the time performance of selection, insertion, and shell sort. 
                   Students need to create 10,000 random numbers for the data and measure the time performance from three sorting methods.
*/

#include <iostream>
#include <Bits.h>
#include <stdlib.h>
#include <chrono>
using namespace std;
using namespace std::chrono;



//create swap function
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//create insetionSort Function
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

//create selectionSort function
void selectionSort(int array[], int n)
{
    int i, j, mini_ind;

    for (i = 0; i < n - 1; i++)
    {

        mini_ind = i;
        for (j = i + 1; j < n; j++)
            if (array[j] < array[mini_ind])
                mini_ind = j;

        swap(array[mini_ind], array[i]);
    }
}

//create shell sort function
int shellSort(int arr[], int n)
{
    // begin with big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];

            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}



int main() {

    int arr1[10000];    //create the array
    cout << "Create 10000 random numbers from 0 to 100000\n";
    while (1)
    {
        for (int i = 0; i < 10000; i++)
        {
            arr1[i] = rand() % 100001;
        }
        string s;
        cout << "What is the method you want to sort (Selection, Insertion, Shell, Quit) ?\n";
        cin >> s;
        if (s == "Selection" || s=="selection") //option for the menu
        {
            auto st = high_resolution_clock::now();
            selectionSort(arr1, 10000);
            auto ed = high_resolution_clock::now();

            auto dr = duration_cast<microseconds>(ed - st);
            cout << "The time performance of selection sort is " << (double)dr.count() / 1000000 << "\n";
        }
        else if (s == "Insertion" || s=="insertion")
        {
            auto st = high_resolution_clock::now();
            insertionSort(arr1, 10000);
            auto ed = high_resolution_clock::now();

            auto dr = duration_cast<microseconds>(ed - st);
            cout << "The time performance of insertion sort is " << (double)dr.count() / 1000000 << "\n";
        }
        else if (s == "Shell" || s=="shell")
        {
            auto st = high_resolution_clock::now();
            shellSort(arr1, 10000);
            auto ed = high_resolution_clock::now();

            auto dr = duration_cast<microseconds>(ed - st);
            cout << "The time performance of shell sort is " << (double)dr.count() / 1000000 << "\n";
        }
        else if (s == "Quit" || s=="quit")
        {
            break;
        }
    }

    return 0;
}
