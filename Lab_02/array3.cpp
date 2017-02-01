#include <string>
#include <sstream>
#include <iostream>
using namespace std;

int main()
{
	int arrayDimension = 0; // User-specified dimension of square 2D "integers" array
	int** integers; // The array that will hold the user-specified integers

	// Defining the array dimension
	cout << "Enter the dimension of your array. ";
	while (arrayDimension <= 0 || arrayDimension > 10) // Keep taking inputs until user enters a valid integer
	{
		cout << "Must be an integer between 1 and 10: ";
		cin >> arrayDimension;
		cin.clear();
		cin.ignore();
	}

	// Initializing the 2D array
	integers = new int*[arrayDimension]; // Initialize the array "integers" with the dimensions that the user specified.
	for (int i = 0; i < arrayDimension; i++)
	{
		integers[i] = new int[arrayDimension];
	}

	// Inputting and Parsing the array
	for (int i = 0; i < arrayDimension; i++)
	{
		cout << "Now enter the numbers of row " << i << " in the array, separated by a spaces, and press enter: ";
		string integersInputString; // User input string of integers
		getline(std::cin, integersInputString); // Take in the entire line of integers that the user input as a string
		stringstream stream(integersInputString); // Convert that string into a stream for parsing

		for (int j = 0; j < arrayDimension; j++) // Parse the stream while there are valid indexes in "integers"
		{
			int input;
			stream >> input; // Extract the next integer from "stream"
			integers[i][j] = input; // Put the extracted integer into the next index of "integers"
		}
	}

	// Counting negatives in array
	int negativeCount = 0;
	cout << "Your array: " << endl;
	for (int i = 0; i < arrayDimension; i++)
	{
		for (int j = 0; j < arrayDimension; j++)
		{
			cout << integers[i][j] << " ";
			if (integers[i][j] < 0)
			{
				negativeCount++;
			}
		}
		cout << endl;
	}

	// Outputting result of negative count
	if (negativeCount > 0)
	{
		cout << "Has " << negativeCount << " negative integers!" << endl;
	}
	else cout << "Has no negative values!" << endl;

	return EXIT_SUCCESS;
}
