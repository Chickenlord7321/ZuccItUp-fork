#include <iostream>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/json.hpp>
#include <cstdlib>
#include <regex>
#include "database.h"
#include "config.h"

using namespace std;
using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_document;

// Input validation functions
bool isValidName(const string& name) {
    if (name.empty() || name.length() > 100) return false;
    regex valid_pattern("^[a-zA-Z0-9\\s\\-']+$");
    return regex_match(name, valid_pattern);
}

bool isValidPrice(double price) {
    return price >= 0 && price <= 10000;
}

bool isValidQuantity(int qty) {
    return qty > 0 && qty <= 1000;
}

void displayMenu() {
    cout << "\n====== MongoDB Product Management ======" << endl;
    cout << "1. Insert a new product" << endl;
    cout << "2. Find product by name" << endl;
    cout << "3. List all products" << endl;
    cout << "4. Update product price" << endl;
    cout << "5. Delete product" << endl;
    cout << "6. Place an order" << endl;
    cout << "7. View orders" << endl;
    cout << "8. Exit" << endl;
    cout << "========================================" << endl;
    cout << "Enter choice (1-8): ";
}

auto createSampleProduct() {
    return make_document(
        kvp("name", "Coffee"),
        kvp("description", "Fresh brewed coffee from beans of coffee"),
        kvp("price", 2.5),
        kvp("available", true),
        kvp("category", "Drink"),
        kvp("options", make_document(
            kvp("0", make_document(
                kvp("name", "Small"),
                kvp("price_modifier", -2)
            )),
            kvp("1", make_document(
                kvp("name", "Medium"),
                kvp("price_modifier", 0)
            )),
            kvp("2", make_document(
                kvp("name", "Large"),
                kvp("price_modifier", 3)
            ))
        ))
    );
}

int main() {
    try {
        // Load configuration
        Config config;
        config.printConfig();
        
        // Initialize database connection
        string uri = config.getMongodbUri();
        string db_name = config.getMongodbDatabase();
        
        Database db(uri, db_name);
        
        int choice;
        bool running = true;

        cout << "\n===== MongoDB C++ Application =====" << endl;
        cout << "✓ Connected to MongoDB successfully\n" << endl;
        
        while (running) {
            displayMenu();
            cin >> choice;
            cin.ignore(); // Clear newline from input buffer

            switch (choice) {
                case 1: {
                    // Insert a new product
                    cout << "\n--- Insert New Product ---" << endl;
                    string name, description, category;
                    double price;
                    int available;

                    cout << "Product name: ";
                    getline(cin, name);
                    if (!isValidName(name)) {
                        cout << "✗ Invalid name (max 100 chars, alphanumeric only)" << endl;
                        break;
                    }
                    
                    cout << "Description: ";
                    getline(cin, description);
                    if (description.empty() || description.length() > 500) {
                        cout << "✗ Invalid description (max 500 chars)" << endl;
                        break;
                    }
                    
                    cout << "Price: ";
                    cin >> price;
                    if (!isValidPrice(price)) {
                        cout << "✗ Invalid price (0-10000)" << endl;
                        break;
                    }
                    
                    cout << "Available (1=yes, 0=no): ";
                    cin >> available;
                    if (available != 0 && available != 1) {
                        cout << "✗ Invalid input" << endl;
                        cin.ignore();
                        break;
                    }
                    cin.ignore();
                    
                    cout << "Category: ";
                    getline(cin, category);
                    if (!isValidName(category)) {
                        cout << "✗ Invalid category" << endl;
                        break;
                    }

                    auto product = make_document(
                        kvp("name", name),
                        kvp("description", description),
                        kvp("price", price),
                        kvp("available", available == 1),
                        kvp("category", category),
                        kvp("options", make_document(
                            kvp("0", make_document(
                                kvp("name", "Small"),
                                kvp("price_modifier", -2)
                            )),
                            kvp("1", make_document(
                                kvp("name", "Medium"),
                                kvp("price_modifier", 0)
                            )),
                            kvp("2", make_document(
                                kvp("name", "Large"),
                                kvp("price_modifier", 3)
                            ))
                        ))
                    );

                    auto result = db.insertOne("products", product.view());
                    if (result) {
                        cout << "✓ Product inserted successfully!" << endl;
                    }
                    break;
                }

                case 2: {
                    // Find product by name
                    cout << "\n--- Find Product ---" << endl;
                    string name;
                    cout << "Enter product name: ";
                    getline(cin, name);

                    auto filter = make_document(kvp("name", name));
                    auto found = db.findOne("products", filter.view());
                    
                    if (!found.view().empty()) {
                        cout << "✓ Found: " << bsoncxx::to_json(found.view()) << endl;
                    } else {
                        cout << "✗ Product not found" << endl;
                    }
                    break;
                }

                case 3: {
                    // List all products
                    cout << "\n--- All Products ---" << endl;
                    auto all = db.findMany("products");
                    
                    if (all.empty()) {
                        cout << "No products found" << endl;
                    } else {
                        cout << "✓ Found " << all.size() << " products:\n" << endl;
                        for (size_t i = 0; i < all.size(); ++i) {
                            cout << "[" << (i + 1) << "] " << bsoncxx::to_json(all[i].view()) << "\n" << endl;
                        }
                    }
                    break;
                }

                case 4: {
                    // Update product price
                    cout << "\n--- Update Product Price ---" << endl;
                    string name;
                    double new_price;

                    cout << "Enter product name: ";
                    getline(cin, name);
                    if (!isValidName(name)) {
                        cout << "✗ Invalid name" << endl;
                        break;
                    }
                    
                    cout << "Enter new price: ";
                    cin >> new_price;
                    if (!isValidPrice(new_price)) {
                        cout << "✗ Invalid price (0-10000)" << endl;
                        break;
                    }

                    auto filter = make_document(kvp("name", name));
                    auto update = make_document(
                        kvp("$set", make_document(kvp("price", new_price)))
                    );

                    auto result = db.updateOne("products", filter.view(), update.view());
                    if (result && result->modified_count() > 0) {
                        cout << "✓ Product price updated!" << endl;
                    } else {
                        cout << "✗ Product not found or not modified" << endl;
                    }
                    break;
                }

                case 5: {
                    // Delete product
                    cout << "\n--- Delete Product ---" << endl;
                    string name;
                    cout << "Enter product name: ";
                    getline(cin, name);

                    auto filter = make_document(kvp("name", name));
                    auto result = db.deleteOne("products", filter.view());
                    
                    if (result && result->deleted_count() > 0) {
                        cout << "✓ Product deleted!" << endl;
                    } else {
                        cout << "✗ Product not found" << endl;
                    }
                    break;
                }

                case 6: {
                    // Place an order
                    cout << "\n--- Place Order ---" << endl;
                    string customerName, itemName;
                    int qty;

                    cout << "Enter customer name: ";
                    getline(cin, customerName);
                    if (!isValidName(customerName)) {
                        cout << "✗ Invalid customer name" << endl;
                        break;
                    }
                    
                    cout << "Enter item name: ";
                    getline(cin, itemName);
                    if (!isValidName(itemName)) {
                        cout << "✗ Invalid item name" << endl;
                        break;
                    }
                    
                    cout << "Enter quantity: ";
                    cin >> qty;
                    if (!isValidQuantity(qty)) {
                        cout << "✗ Invalid quantity (1-1000)" << endl;
                        break;
                    }

                    // Create order document
                    auto order = make_document(
                        kvp("customerName", customerName),
                        kvp("item", itemName),
                        kvp("qty", qty)
                    );

                    auto result = db.insertOne("order", order.view());
                    if (result) {
                        cout << "✓ Order placed successfully!" << endl;
                        cout << "  Customer: " << customerName << endl;
                        cout << "  Item: " << itemName << endl;
                        cout << "  Quantity: " << qty << endl;
                    }
                    break;
                }

                case 7: {
                    // View orders
                    cout << "\n--- All Orders ---" << endl;
                    auto all_orders = db.findMany("order");
                    
                    if (all_orders.empty()) {
                        cout << "No orders found" << endl;
                    } else {
                        cout << "✓ Found " << all_orders.size() << " orders:\n" << endl;
                        for (size_t i = 0; i < all_orders.size(); ++i) {
                            cout << "[" << (i + 1) << "] " << bsoncxx::to_json(all_orders[i].view()) << "\n" << endl;
                        }
                    }
                    break;
                }

                case 8: {
                    running = false;
                    cout << "\n===== Goodbye! =====" << endl;
                    break;
                }

                default:
                    cout << "✗ Invalid choice. Please try again." << endl;
            }
        }

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
