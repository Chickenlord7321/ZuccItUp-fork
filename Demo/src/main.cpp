/**
 * Authors: Caleb Bronn
 * Last update: 22 Feb 2026

 * Main file for user interaction, command-line interface, and Server instance
 */

/* 
TODO: Enter location
TODO: List vendors
TODO: Select Vendor
TODO: Menu
TODO: Loop
	TODO: Add to Cart
	TODO: Evaluate subtotal
TODO: Place order
TODO: Confirm order or decline and try again
*/

#include "../include/server.hpp"
#include <unistd.h>		// for getpass()
#include <ctype.h>		// for toupper() and tolower()
#include <cstdlib>		// for exit()
#include <limits.h>		// for INT_MAX
#include <iostream>
#include <string>
	using namespace std;

// Global Server
Server svr;

/***************************
 * STRING HELPER FUNCTIONS *
 ***************************/

// Convert string to lowercase
string to_lower(string s) {
	for (int i = 0; i < s.length(); i++) {
		s[i] = tolower(s[i]);
	}
	return s;
}

// Convert string to uppercase
string to_upper(string s) {
	for (int i = 0; i < s.length(); i++) {
		s[i] = toupper(s[i]);
	}
	return s;
}

// Get input from user and check if user types "q" to quit the program.
string input_str(const string msg) {
	string input = "";
	cout << msg;
	getline(cin, input);
	if (to_lower(input) == "q") {
		cout << "Goodbye!" << endl;
		exit(0);
	}
	return input;
}

// Get integer input from user
int input_int(const string msg, const int min = INT_MIN, const int max = INT_MAX) {
	int answer;
	string throwaway;

	cout << msg;
	// If the user does not input an integer, prompt them to try again. 
	// If the the user inputs an integer that isn't within the min and max, prompt them to try again.
	while (!(cin >> answer) || answer < min || answer > max) {
		// Clean out cin and the buffer.
		cin.clear();
		getline(cin, throwaway);

		// Quit if user types 'Q'
		if (to_lower(throwaway) == "q") {
			cout << "Goodbye!" << endl;
			exit(0);
		}
		cout << "Sorry, that was not a valid integer. Please try again\n> ";
	}
	// Clean out buffer again. Just in case.
	cin.clear();
	getline(cin, throwaway);
	return answer;
}

// Get password from user
string input_password(const char* msg) {
	return string(getpass(msg));
}


int main() {
	cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⠶⠚⠋⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	<< "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠶⠋⠀⣀⣀⠀⠀⠀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	<< "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⠤⠞⠁⠀⠀⣴⠃⣼⠀⠀⣰⡇⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠐⠒⠒⠒⠤⣀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	<< "⠀⠀⠀⠀⠀⠀⠀⠀⢀⡤⠚⠉⠀⡄⠀⠀⠀⢸⣿⣿⡿⠀⠀⣿⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠲⡄⠀⠀⠀⠀⠀\n"
	<< "⠀⠀⠀⠀⠀⠀⠀⢠⠏⠁⠀⠀⡰⠁⠀⣀⡀⢸⣿⣿⠇⠀⠀⣿⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⣄⠀⠀⠱⡀⠀⠀⠀⠀\n"
	<< "⠀⠀⠀⠀⠀⠀⢀⡟⠀⠀⣀⡀⡀⠀⢾⣯⣭⠟⠉⢋⣀⣀⣀⡨⠍⠁⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⠲⠯⢭⣅⣈⡀⠀⠀⠱⡄⠀⠀⠀\n"
	<< "⠀⠀⠀⠀⠀⢀⡾⠀⠀⠒⢺⢀⡇⠀⠀⠀⠀⠀⠀⠈⠻⠿⠿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⡄⠀⠀⠀⠀⠀⠀⠀⠱⡄⠀⠀\n"
	<< "⠀⠀⠀⠀⣠⠞⠁⠀⠀⠀⠈⡎⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣶⡄⠀⠀⠀⠀⠀⠀⠙⣆⠀\n"
	<< "⠀⠀⢠⡞⠁⠀⢷⣄⠀⣴⣾⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⠃⠙⢶⣤⡀⠀⠀⠀⠀⠘⠀\n"
	<< "⠀⠀⣾⠃⠀⠀⣈⣻⣿⣿⠟⠁⠹⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⠏⠀⠀⠀⢹⡏⢦⠀⠀⠀⠀⠀\n"
	<< "⠀⢠⡏⠀⠀⣰⣿⢠⣾⠟⠀⠀⠀⠘⢷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⡴⠋⠀⠀⠀⠀⠈⠻⣿⡄⠀⠀⠀⠀\n"
	<< "⠀⡼⠀⠀⢰⣿⠿⠛⠁⠀⠀⠀⠀⠀⠈⣿⠷⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⠖⠋⠉⠁⢸⡁⠀⠀⠀⠀⠀⠀⠀⣠⠃⠀⠀⠀⠀\n"
	<< "⢠⡇⠀⠀⠈⢧⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠉⠛⠶⣦⣤⣀⣀⣶⣤⠞⠋⠁⠀⠀⠀⠀⠘⡇⠀⠀⠀⠀⠀⠀⣸⣿⢦⣤⡀⠀⠀\n"
	<< "⢸⣴⠀⣤⢶⣿⠀⠀⠀⠀⠀⠀⠀⠀⢰⠿⡆⠀⠀⠀⠀⠀⠈⣽⡟⠛⣧⡀⠀⠸⡄⠀⠀⠀⢀⡇⠀⠀⠀⠀⠀⠀⠹⣧⣴⠟⢇⢀⣀\n"
	<< "⠘⣯⣜⠁⠘⠿⠀⠀⠀⠀⠀⠀⠀⠀⠸⡄⣿⣄⠀⠀⠀⠀⣠⡿⠀⠀⠘⣷⡄⠀⠹⡆⠀⢀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣾⠟\n"
	<< "⠀⠹⣿⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣟⣿⣧⡄⠀⢰⡿⠁⠀⠀⠀⠘⣷⣀⣠⢷⣽⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠀⠀\n"
	<< "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⡛⠻⣿⣶⣿⠃⠀⠀⠀⠀⠀⠘⣿⣏⢀⣤⣼⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	<< "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣟⡶⣮⣽⡏⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⡶⠟⢱⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	<< "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠿⠛⠛⠙⡄⠀⠀⠀⠀⠀⠀⣰⠿⣟⠉⠀⠈⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	<< "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣧⠀⠀⠀⢀⣵⠀⠀⠀⠀⠀⠀⢿⠀⢸⡀⠀⢸⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	<< "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣏⠀⠀⢠⣼⠏⠀⠀⠀⠀⠀⠀⠈⢿⣄⠃⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	<< "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⣾⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	<< "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣿⣷⣶⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⡛⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	<< "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣼⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⣷⣿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
	cout << "\nWelcome to Zucc It Up!\n\n";

	//* Get credentials for Oracle database
	cout << "First, you will need to enter your Oracle Database credentials.\n";
	cout << "Type 'Q' at any time to quit the program.\n";
	string oracle_username;
	string oracle_password;
	do {
		oracle_username = input_str("Enter Oracle username: ");
		oracle_password = input_password("Enter Oracle password: ");
	} while (!svr.connect(oracle_username, oracle_password));
	cout << "Credentials verified!\n";

	//* Enter location
	int building = input_int("Enter your building number: ", 100, 500);
	int room = input_int("Enter your room number: ", 0, 500);

	//* List vendors

	cout << "Goodbye!\n";
	return 0;
}