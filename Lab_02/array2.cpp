#include <string>
#include <sstream>
#include <iostream>
using namespace std;

int main()
{
	string inputString; // The user-input string that will be reversed;
	string reversedString; // The string that the user input, after being reversed;

	cout << "Enter the string to reverse: "; // Prompt for user input
	getline(cin, inputString); // Take in a string from user
	for (int i = inputString.length() - 1; i >= 0; i--) // Iterate backwards through "inputString"
	{
		reversedString.push_back(inputString[i]); // Put the current index of "inputString" into "reversedString"
	}
	cout << "The reverse of your string is: " << reversedString; // Output the reversed string
	return EXIT_SUCCESS;
}