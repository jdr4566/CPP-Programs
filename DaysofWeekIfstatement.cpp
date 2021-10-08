/*  John-David Rodriguez, C++ Builder
Purpose of program :    Create a C++ program to accept input from the user between the number values of 1 - 7 . Output to the user, using “IF”, "ELSE-IF", and/or "ELSE" statements what the entered value's day of the week i.e. (1 ouputs "It's Sunday") Account for invalid output in the default clause.
*/


#include <iostream>
#include <string>
using namespace std;




int main(){

	int id;
	cout<<"Enter a value between 1-7 ( 1= Sunday- 7 = Saturday, etc..)"<<endl;
	cin>>id;





if ( id == 1 )
{
	cout << "Sunday" << endl;
}
else
{

	if ( id == 2 )
    {
        cout << "Monday" <<endl;
    }
    else
    {
		if ( id == 3 )
        {
            cout << "Tuesday" << endl;
        }
		else
			if (id == 4)
		{
			cout << "Wednesday" << endl;
		}
	   else
				if (id == 5)
				{
                    cout<<"Thursday"<<endl;
				}
				else
					if (id == 6)
					{
						cout<<"Friday"<<endl;
                    }
                   else
						if(id == 7)
						{
							cout<<"Saturday"<<endl;
                        }
							else
							{
                                cout<<"Please Enter a valid number between 1-7"<<endl;
							}
                  }   }
	system("pause");
}
