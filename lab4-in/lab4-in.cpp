//Paige Ingram
//Lab 4 in
//Creates a form for inputting/validating information

#include <iostream>
#include <string>
#include <cctype>
#include "graph1.h"

using namespace std;

//Prototypes are below
string getString(string prompt);
bool validateName(string name);
bool validateAddress(string address);
bool validatePhone(string phone);
string convertToUpper(string string);
void displayFields(string name, string address, string phone);


int main()
{
	//Variable Declaration/Initialization
	string name = "";
	string address = "";
	string phone = "";
	string upperName = "";
	bool res = false;


	//Display graphics window
	displayGraphics();

	//Process name info
	do
	{
		//Prompt for the name - 
		name = getString("Enter Name: ");

		//validate the name
		res = validateName(name);

	} while (!res);

	//Process the address info
	do
	{
		//Get the address
		address = getString("Enter Address: ");

		//validate the address
		res = validateAddress(address);

	} while (!res);

	//Process phone info
	do
	{
		//Get the phone
		phone = getString("Enter Phone: ");

		//validate the phone
		res = validatePhone(phone);

	} while (!res);



	//Convert the name to all uppercase
	name = convertToUpper(name);

	//Display the fields
	displayFields(name, address, phone);

	return 0;
}




//Prompts for input based on input parameter prompt
string getString(string prompt)
{

	//Prompt user for name using getline (prompt contains the message displayed to user))
	string input;
	cout << prompt;
	getline(cin, input);

	return input;

}

//Validates characters of name
bool validateName(string name)
{
	//Validate the name – return true if valid, false if not
	int i = 0;

	while (name[i]) {
		if (!isalpha(name[i])) {
			if (name[i] != ' ') {
				return false;
			}
		}

		++i;
	}

	return true;

}

//Validates characters of address
bool validateAddress(string address)
{
	//Validate the address – return true if valid, false if not
	int i = 0;

	while (address[i]) {
		if (!isalnum(address[i])) {
			if (address[i] != ' ') {
				return false;
			}
		}

		++i;
	}

	return true;

}



//Validates characters of phone number
bool validatePhone(string phone)
{
	//Validate the phone – return true if valid, false if not
	if (phone.length != 10) {
		return false;
	}
	else {
		for (int i = 0; i < 10; ++i) {
			if (!isdigit(phone[i]))
				return false;
		}
	}

	return true;

}

//Converts text to uppercase
string convertToUpper(string input)
{
	//Convert input to all uppercase
	for (int i = 0; i < input.length; ++i) {
		input[i] = toupper(input[i]);
	}

	//Return converted input
	return input;
}

//Displays the information in graphics window
void displayFields(string name, string address, string phone)
{
	int dummy_obj = 0;

	//Draw the form (rectangles)
	dummy_obj = drawRect(230, 85, 170, 20); // Name field
	
	drawRect(230, 125, 325, 20);// Address field
	drawRect(230, 165, 125, 20);// Phone field


	//Display the fields
}
