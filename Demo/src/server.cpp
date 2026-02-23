/**
 * Authors: Caleb Bronn
 * Last update: 22 Feb 2026

 * cpp file for Database Server that connects to and interacts with Oracle
 */

#include "../include/server.hpp"

// Constructor
Server::Server() {
	env = NULL;
	conn = NULL;

	// Set statements to null
		// e.g. create_account_query = nullptr;
	
	// Initialize SQL strings
		// e.g. create_account_sql = "INSERT INTO(....blah blah blah)";
		// ! Important! Do not end SQL strings with ";", as much as your fingers might want to.
		// ! This causes errors because Oracle doesn't need semi-colons when you're using the OCCI library.
}


// Destructor
Server::~Server() {
	// Terminate connection only if it's not null
	// We do this in case the try-catch in connect() fails to establish a connection
	if (conn) {
		// Terminate ALL statements
			// e.g. conn->terminateStatement(create_account_query);
		env->terminateConnection(conn);
	}
	// Same for the environment, terminate only if it's not null
	if (env) {
		Environment::terminateEnvironment(env);
	}
}


// Establish connection with the Oracle server
bool Server::connect(const string username, const string password) {
	env = Environment::createEnvironment();
	try {
		conn = env->createConnection(username, password, DB_ADDRESS);

		// Create statements for each SQL string.
			// e.g. create_account_query = conn->createStatement(create_account_sql);

		return true;	// successful connection
	} catch (SQLException & error) {
		cout << error.what();
		cout << "\nUsername or Password was incorrect, could not connect\n\n";
		return false;	// unsuccessful connection
	}
}