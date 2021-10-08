/*  John-David Rodriguez , C++ Builder
Purpose of program :   Using a Bubble Sort Algorithm,  sort the contents of the following array in descending order.

*/

#include <iostream>
#include <string>
using namespace std;



int main(){

  double numbers[7] = {23.6, 46.7, 12.7, 35.1,54.88,78.7,100.5};

  int i, j;

  for(i=0; i<=6;i++){
	cout<<"Starting Bubble Sort in Descending Order!!!";

  }

  for (i=0;i<=5;i++)
  {

      for (j=i+1;j<=6;j++)
      {
          int temp;

		  if(numbers[i] < numbers[j])   // Changing the " > or < " sign decides ASC or DSC
            {
				temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
            }
      }
  }

  for(i=0;i<=6;i++)
  { cout<<endl<< numbers[i]<<endl;
  }

  system("pause");
}
