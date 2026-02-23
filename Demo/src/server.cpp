/**
 * Authors: Caleb Bronn
 * Last update: 22 Feb 2026

 * cpp file for Database Server that connects to and interacts with Oracle
 */

#include "../include/server.hpp"
#include <iomanip>

// Constructor
Server::Server() {
	env = NULL;
	conn = NULL;

	// Set statements to null
		// e.g. create_account_query = nullptr;

	insert_order_query = nullptr;
	insert_menu_query  = nullptr;

	// Initialize SQL strings
		// e.g. create_account_sql = "INSERT INTO(....blah blah blah)";
		// ! Important! Do not end SQL strings with ";", as much as your fingers might want to.
		// ! This causes errors because Oracle doesn't need semi-colons when you're using the OCCI library.

	insert_order_sql =
    	"INSERT INTO orders (custName, items, destination, total) "
    	"VALUES (:1, SYSDATE, :2, :3, :4)";

	insert_menu_sql =
		"INSERT INTO menu (name, description, price) "
		"VALUES (:1, :2, :3)";
}


// Destructor
Server::~Server() {
	// Terminate connection only if it's not null
	// We do this in case the try-catch in connect() fails to establish a connection
	if (conn) {
		// Terminate ALL statements
			// e.g. conn->terminateStatement(create_account_query);
		conn->terminateStatement(insert_order_query);
		conn->terminateStatement(insert_menu_query);
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

		insert_order_query = conn->createStatement(insert_order_sql);
		insert_menu_query = conn->createStatement(insert_menu_sql);


		return true;	// successful connection
	} catch (SQLException & error) {
		cout << error.what();
		cout << "\nUsername or Password was incorrect, could not connect\n\n";
		return false;	// unsuccessful connection
	}
}

void Server::createTable(const string& table_name) {
	try {
		string sql;

		if (table_name == "orders") {
			sql =
				"CREATE TABLE orders ("
				"custName    VARCHAR(20),"
				"items       VARCHAR(100),"
				"destination VARCHAR(10),"
				"total       NUMBER(5,2)"
				")";
		} else if (table_name == "menu") {
			sql =
				"CREATE TABLE menu ("
				"name        VARCHAR(20),"
				"description VARCHAR(100),"
				"price       NUMBER(5,2)"
				")";
		} else {
			throw ServerException("createTable()", "Unknown table name: " + table_name);
		}

		Statement* stmt = conn->createStatement(sql);
		stmt->executeUpdate();
		conn->terminateStatement(stmt);
		conn->commit();
		cout << "Table '" << table_name << "' created.\n";

	} catch (SQLException& e) {
		throw ServerException("createTable()", e.getMessage());
	}
}
	

//drops table specifed by table_name
void Server::dropTable(const string& table_name){
	try{
		string sql = "DROP TABLE " + table_name;

		Statement* stmt = conn->createStatement(sql);
        stmt->executeUpdate();
        conn->terminateStatement(stmt);
        conn->commit();
        cout << "Table '" << table_name << "' dropped.\n";

    } catch (SQLException& e) {
        throw ServerException("dropTable()", e.getMessage());
    }	
}



void Server::insertMenu(const string& name, const string& description, double price) {
    try {
        insert_menu_query->setString(1, name);
        insert_menu_query->setString(2, description);
        insert_menu_query->setDouble(3, price);

        insert_menu_query->executeUpdate();
        conn->commit();
        cout << "Menu item inserted: " << name << "\n";
    } catch (SQLException& e) {
        throw ServerException("insertMenu()", e.getMessage());
    }
}

void Server::populateMenu() {
    insertMenu("Coffee", "Freshly brewed coffee", 2.50);
    insertMenu("Muffin", "Fresh baked blueberry muffin", 3.00);
    insertMenu("Tea", "Early grey tea", 2.50);
    cout << "Menu populated.\n";
}

void Server::displayTable(const string& table_name) {
    try {
        string sql = "SELECT * FROM " + table_name;

        Statement* stmt = conn->createStatement(sql);
        ResultSet* rs = stmt->executeQuery();

        if (table_name == "orders") {
            cout << "\n"
                 << left
                 << setw(20) << "Customer"
                 << setw(30) << "Items"
                 << setw(15) << "Destination"
                 << setw(10) << "Total" << "\n"
                 << string(90, '-') << "\n";

            while (rs->next()) {
                cout << left
                     << setw(20) << rs->getString(1)
                     << setw(15) << rs->getString(2)
                     << setw(30) << rs->getString(3)
                     << setw(15) << rs->getString(4)
                     << setw(10) << fixed << setprecision(2) << rs->getDouble(5)
                     << "\n";
            }

        } else if (table_name == "menu") {
            cout << "\n"
                 << left
                 << setw(20) << "Name"
                 << setw(40) << "Description"
                 << setw(10) << "Price" << "\n"
                 << string(70, '-') << "\n";

            while (rs->next()) {
                cout << left
                     << setw(20) << rs->getString(1)
                     << setw(40) << rs->getString(2)
                     << "$" << fixed << setprecision(2) << rs->getDouble(3)
                     << "\n";
            }

        } else {
            stmt->closeResultSet(rs);
            conn->terminateStatement(stmt);
            throw ServerException("displayTable()", "Unknown table name: " + table_name);
        }

        cout << "\n";
        stmt->closeResultSet(rs);
        conn->terminateStatement(stmt);

    } catch (SQLException& e) {
        throw ServerException("displayTable()", e.getMessage());
    }
}

void Server::insertOrder(const string& custName, const string& items,
                         const string& destination, double total) {
    try {
        insert_order_query->setString(1, custName);
        insert_order_query->setString(2, items);
        insert_order_query->setString(3, destination);
        insert_order_query->setDouble(4, total);

        insert_order_query->executeUpdate();
        conn->commit();
        cout << "Order placed for: " << custName << "\n";
    } catch (SQLException& e) {
        throw ServerException("insertOrder()", e.getMessage());
    }
}