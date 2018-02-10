//Name: John McCrary
#include <iostream>
#include <cctype>
#include <string>
#include "graph1.h"
using namespace std;

// Required functions
string getString(string prompt);
bool validateName(string name);
bool validateAddress(string addr);
bool validateCity(string city);
bool validateState(string state);
bool validateZip(string zip);
string convertToUpper(string input);
void displayLetter(string fn, string ln, string addr, string city,
	string state, string zip, int weight);

// Personal functions
void getAndValidateString(string *const info, string prompt, 
	bool(*valid)(string s));
bool validateWeight(string weight);
void displayCost(int weight);

int main(void)
{
	string fn, ln, addr, city, state, zip, weight_str;
	int weight; 

	// user input
	getAndValidateString(&fn, "Enter First Name: ", validateName);
	getAndValidateString(&ln, "Enter Last Name: ", validateName);
	getAndValidateString(&addr, "Enter Street Address: ", validateAddress);
	getAndValidateString(&city, "Enter City: ", validateCity);
	getAndValidateString(&state, "Enter State: ", validateState);
	getAndValidateString(&zip, "Enter Zip: ", validateZip);
	getAndValidateString(&weight_str, "Enter weight: ", validateWeight);
	weight = stoi(weight_str);

	// begin graphics programming after everything is validated.
	displayGraphics();
	displayLetter(fn, ln, addr, city, state, zip, weight);
	displayCost(weight);

	return 0;
}

string getString(string prompt)
{
	string input;
	cout << prompt;
	getline(cin, input);

	return input;
}

// This is a helper function, created to keep main free from do-while clutter.
// Although it requires the use of function pointers, which we haven't gone over
// in class, I think it's straightforward enough.
void getAndValidateString(string *const info, string prompt, 
	bool(*valid)(string s)) // scary function pointer actually makes sense here.
{
	do {
		*info = getString(prompt);
	} while (!valid(*info));
}

bool validateName(string name)
{
	for (int i = 0; name[i]; ++i) {
		if (!isalpha(name[i])) {
			if (name[i] != ' ')
				return false;
		}
	}
}

bool validateAddress(string addr)
{
	for (int i = 0; addr[i]; ++i) {
		if (!isalnum(addr[i])) {
			if (addr[i] != ' ') {
				return false;
			}
		} 
	}

	return true;
}

bool validateCity(string city)
{
	if (!isupper(city[0])) {
		return false;
	} else {
		for (int i = 1; city[i]; ++i) {
			if (!isalpha(city[i])) {
				return false;
			}
		}

		return true;
	}
}

bool validateState(string state)
{
	if (state.length() != 2) {
		return false;
	} else {
		if (!isalpha(state[0]) || !isalpha(state[1])) {
			return false;
		} else {
			return true;
		}
	}
}

bool validateZip(string zip)
{
	if (zip.length() != 5) {
		return false;
	} else {
		for (int i = 0; zip[i]; ++i) {
			if (!isdigit(zip[i])) {
				return false;
			}
		}

		return true;
	}
}

bool validateWeight(string weight)
{
	if (weight.length() != 1) {
		return false;
	} else {
		if (!isdigit(weight[0])) {
			return false;
		} else {
			return true;
		}
	}
}

string convertToUpper(string input)
{
	for (int i = 0; input[i]; ++i) {
		input[i] = toupper(input[i]);
	}

	return input;
}

// Displays everything on the envelope. DOES NOT display the info 
// rectangle below the envelope. See displayStats()
void displayLetter(string fn, string ln, string addr, string city,
	string state, string zip, int weight)
{
	int stamp_x = 525, stamp_y = 20;
	double cost = (double)weight * 0.47;

	// calculate how big of an array to hold the object id nums for the stamps.
	int *stamp_ids = new int[weight];

	displayBMP("envelope.bmp", 0, 0);
	displayBMP("returnAddress.bmp", 43, 26);

	// position the stamps
	for (int i = 0, x = 525, y = 20; i < weight; ++i) {
		if (i == 3) {
			x = 525;
			y += 79;
		}

		stamp_ids[i] = displayBMP("stamp.bmp", x, y);
		x -= 75;
	}

	gout << setColor(0,0,0) << setPos(315, 210) 
		<< fn << " " << ln << endg;
	gout << setColor(0,0,0) << setPos(315, 225) << addr << endg;
	gout << setColor(0,0,0) << setPos(315, 240) 
		<< city << " " << state << ", " << zip << endg;

	// Free up all dynamic memory
	delete[] stamp_ids;
}

// Displays the rectangle below the envelope with weight, cost, etc.
void displayCost(int weight)
{
	drawRect(200, 385, 290, 85);
	int box = drawRect((200 + 2), (387 + 1), (290 - 4), (85 - 4));
	setColor(box, 0, 0, 0);
	gout << setPos(205, 400) << "Weight: " << weight << " ounces" << endg;
	gout << setPos(205, 415) << "Cost of First Class Stamp: 47 Cents" << endg;
	gout << setPos(205, 430) << "Total Mailing Cost $" << setPrecision(2) 
		 << (double)weight * 0.47 << endg;
}

