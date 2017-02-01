#include <string>
#include <sstream>
#include <iostream>
using namespace std;

int main()
{
	int arrayLength = 0; // User-specified size of "integers" array
	int* integers; // The array that will hold the user-specified integers
	string integersInputString; // User input that will contain integers to be put in the array

	// Defining the array size
	cout << "Enter the length of your array. ";
	while (arrayLength <= 0) // Keep taking inputs until user enters a valid integer
	{
		cout << "Must be an integer greater than 0: ";
		cin >> arrayLength;
		cin.clear();
		cin.ignore();
	}

	// Parsing the input integers
	integers = new int[arrayLength]; // Initialize the array "integers" with the size that the user specified.
	cout << "Now enter the " << arrayLength << " numbers in the array, separated by a space, and press enter: ";
	getline(std::cin, integersInputString); // Take in the entire line of integers that the user input as a string
	stringstream stream(integersInputString); // Convert that string into a stream for parsing

	for (int i = 0; i < arrayLength; i++) // Parse the stream while there are valid indexes in "integers"
	{
		int input;
		stream >> input; // Extract the next integer from "stream"
		integers[i] = input; // Put the extracted integer into the next index of "integers"
	}

	// Outputting the array
	cout << "Your array: ";
	for (int i = 0; i < arrayLength; i++)
	{
		cout << integers[i] << " ";
	}
	cout << "... ";

	// Checking Sorting
	bool isSorted = true;
	for (int i = 1; i < arrayLength; i++)
	{
		if (integers[i] < integers[i - 1])
		{
			isSorted = false;
		}
	}
	if (isSorted)
	{
		cout << "Is in increasing order!" << endl;
	}
	else
	{
		cout << "Is NOT in increasing order!" << endl;
	}
	return EXIT_SUCCESS;
}
