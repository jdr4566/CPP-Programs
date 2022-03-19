/*  Programmer : John-David Rodriguez
    Course: COSC-2436
    Date: 3/15/2022
    IDE: Microsoft Visual Studio
    Description:   Write a (Java or C++) program to calculate the statistical operation performed on a set of data values to 
                   remove values (outlier) that are far from the average.
*/

#include <iostream>
#include <iomanip>
#include <iterator>
#include <numeric>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>


using namespace std;

//variables
string datafile; // for getting file name
string filetxt; //for outputting the text file
float dat; 


int main() {
    ifstream my_file;
    ifstream file("data2.txt");
    vector<float>data;  //create vector to store text data into
    size_t data_size = data.size();
    cout << "\t\tWhat is the name of the data file?" << endl;
    cin >> datafile;
    my_file.open(datafile);
    
    //if statement for checking condition if file name is what user is looking for
    if (!my_file) {
        cout << "*****************************************************************************" << endl;
        cout << "\n\t\tNo file with that name exists!!" << endl;
    }
    else {

        cout << "\n\t\tReading data from file... " << datafile << endl;
        cout << "*****************************************************************************" << endl;
        cout << "\n\t\tThe data is: " << endl;
        ifstream MyReadFile(datafile);  //read the data from text file

        //store data from file into vector
        while (file >> dat)
        {
            data.push_back(dat);
        }
        copy(data.begin(), data.end(), ostream_iterator<float>(cout, "\n"));

        //close the file
        MyReadFile.close();
        cout << "\n\t\tFinished Reading File..." << endl;
        cout << "*****************************************************************************" << endl;

        
        cout << "\n\t\tThe List is originally....: " << endl;
        //print out the contents of the vector
        for (double i : data)
        {
            cout << i << " " << endl;
        }
        //print average from the vector
        float average = accumulate(data.begin(), data.end(), 0.0) / data.size();
        cout << "*****************************************************************************" << endl;
        cout << "\n\t\tThe average is....: " << average << endl;
        
        
        //get standard deviation
        //do some math!
        float sum = accumulate(data.begin(), data.end(), 0.0);  //calculate the sum of vector
        float m = sum / data.size();                            //variable for mean
        float accum = 0.0;
        for_each(begin(data), end(data), [&](const float d) {
            accum += (d - m) * (d - m);
            });
        float stdev = sqrt(accum / (data.size() - 1));
        cout << "\n\t\tThe Standard deviation is ...: " << stdev << endl;

        //remove values outside the range
        //more math
        float lowerlimit = average - 2 * stdev;     //to calculate the lower limit
        float upperlimit = average + 2 * stdev;     //to calculate the upper limit
        cout << "\n\t\tRemoving values outside the range...: " << lowerlimit << " to " << upperlimit << endl;
        cout << "\n\t\tRemoved value...: " ;
        for (auto it = begin(data); it != end(data); ++it) {
            if ((*it > upperlimit) || (*it < lowerlimit)) {
                cout << *it << "";
                data.erase(it--);
            }
        }

        //display updated list
        cout << "\n\t\tThe list is now: ";
        average = 0;
        stdev = 0;
        data_size = data.size();
        for_each(data.begin(), data.end(), [&](float value) {
            cout << value << " ";
            average += value;
            });
        average = average / data_size;
        for_each(data.begin(), data.end(), [&](float value) {
            stdev += pow(value - average, 2);
            });
        stdev = pow(stdev / data_size, 0.5);
        cout << "\n\t\tThe average with extreme values removed is: " << average;
        cout << "\n\t\tThe standard Deviation with extreme values removed is: " << stdev << "\n\n" << endl;
    }
    return 0;
}
