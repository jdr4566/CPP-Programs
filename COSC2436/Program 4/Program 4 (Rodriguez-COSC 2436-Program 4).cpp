/*  Programmer : John-David Rodriguez
	Course: COSC-2436
	Date: 4/13/2022
	IDE: Microsoft Visual Studio
	Description:   Write a (Java or C++) program to perform the following:
				   Suppose you have numerical data stored in a two-dimensional array (8X10) randomly.
				   The data in each row and in each column is sorted in increasing order.
				   Use an efficient search algorithm (binary search) for an array of this type.
				   Implement and test your program.
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;


bool binarySearch(int a[][MAX], int n, int m, int k, int x)
// x is the row number
{
	
	int l = 0, r = m - 1, mid;
	while (l <= r)
	{
		mid = (l + r) / 2;

		if (a[x][mid] == k)
		{
			cout << "Found data at (Row - " << x + 1 << ",Coloumn - " << mid + 1 << ")" << endl;
			return true;
		}

		if (a[x][mid] > k)
			r = mid - 1;
		if (a[x][mid] < k)
			l = mid + 1;
	}
	cout << "Data not found" << endl;
}

bool findRow(int a[][MAX], int n, int m, int k)
{

	int l = 0, r = n - 1, mid;

	while (l <= r)
	{
		mid = (l + r) / 2;

		
		if (k == a[mid][0]) // checking leftmost element
		{
			cout << "Found Data at (Row - " << mid + 1 << ",Coloumn - 1)" << endl;
			return true;
		}

		if (k == a[mid][m - 1]) // checking rightmost
								// element
		{
			int t = m - 1;
			cout << "Found Data at (Row - " << mid + 1 << ",Coloumn - " << t + 1 << ")" << endl;
			return true;
		}

		if (k > a[mid][0] && k < a[mid][m - 1])
			// this means the element
			// must be within this row
		{
			binarySearch(a, n, m, k, mid);
			// we'll apply binary
			// search on this row
			return true;
		}

		if (k < a[mid][0])
			r = mid - 1;
		if (k > a[mid][m - 1])
			l = mid + 1;
	}
}

//Driver Code
int main()
{
	const int n = 10; // no. of rows
	const int m = 8; // no. of columns

	cout << "Please Enter sorted 2-D Array( Row wise in array ) : " << endl;

	int arr[n][MAX];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> arr[i][j];
		}
	}
	cout << "Please Enter Element to search : " << endl;
	int k; // element to search
	cin >> k;

	findRow(arr, n, m, k);

	return 0;
}