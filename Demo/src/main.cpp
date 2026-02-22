/**
 * Authors: Caleb Bronn
 * Last update: 22 Feb 2026

 * Main file for user interaction, command-line interface, and Server instance
 */


#include "../include/server.hpp"
#include <unistd.h>		// for getpass()
#include <ctype.h>		// for toupper() and tolower()
#include <cstdlib>		// for exit()
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

	// Get credentials for Oracle database
	cout << "First, you will need to enter your Oracle Database credentials.\n";
	string oracle_username;
	string oracle_password;
	do {
		oracle_username = input_str("Enter Oracle username: ");
		oracle_password = input_password("Enter Oracle password: ");
	} while (!svr.connect(oracle_username, oracle_password));
	cout << "Credentials verified!\n";

	cout << "Goodbye!\n";
}