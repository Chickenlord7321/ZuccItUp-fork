#include "database.h"
#include <iostream>
#include <mongocxx/instance.hpp>

using namespace std;

// Static instance for mongocxx
static mongocxx::instance inst{};

Database::Database(const string& uri, const string& dbName) {
    try {
        client = mongocxx::client(mongocxx::uri(uri));
        db = client[dbName];
        
        // Verify connection
        auto admin = client["admin"];
        auto ping_cmd = bsoncxx::builder::basic::make_document(
            bsoncxx::builder::basic::kvp("ping", 1)
        );
        admin.run_command(ping_cmd.view());
        
        cout << "✓ Connected to MongoDB successfully" << endl;
    } catch (const exception& e) {
        cerr << "✗ Failed to connect to MongoDB: " << e.what() << endl;
        throw;
    }
}

bsoncxx::document::value Database::findOne(const string& collection,
                                          const bsoncxx::document::view& filter) {
    try {
        auto coll = db[collection];
        auto result = coll.find_one(filter);
        
        if (result) {
            return bsoncxx::document::value(result->view());
        }
        // Return an empty document
        auto empty_doc = bsoncxx::builder::basic::make_document();
        return empty_doc;
    } catch (const exception& e) {
        cerr << "✗ Error finding document: " << e.what() << endl;
        throw;
    }
}

vector<bsoncxx::document::value> Database::findMany(const string& collection,
                                                         const bsoncxx::document::view& filter) {
    vector<bsoncxx::document::value> results;
    try {
        auto coll = db[collection];
        auto cursor = coll.find(filter);
        
        for (auto&& doc : cursor) {
            results.push_back(bsoncxx::document::value(doc));
        }
    } catch (const exception& e) {
        cerr << "✗ Error finding documents: " << e.what() << endl;
        throw;
    }
    return results;
}

bsoncxx::stdx::optional<mongocxx::result::insert_one> Database::insertOne(
    const string& collection,
    const bsoncxx::document::view& document) {
    try {
        auto coll = db[collection];
        return coll.insert_one(document);
    } catch (const exception& e) {
        cerr << "✗ Error inserting document: " << e.what() << endl;
        throw;
    }
}

bsoncxx::stdx::optional<mongocxx::result::insert_many> Database::insertMany(
    const string& collection,
    const vector<bsoncxx::document::view>& documents) {
    try {
        auto coll = db[collection];
        return coll.insert_many(documents);
    } catch (const exception& e) {
        cerr << "✗ Error inserting documents: " << e.what() << endl;
        throw;
    }
}

bsoncxx::stdx::optional<mongocxx::result::update> Database::updateOne(
    const string& collection,
    const bsoncxx::document::view& filter,
    const bsoncxx::document::view& update) {
    try {
        auto coll = db[collection];
        return coll.update_one(filter, update);
    } catch (const exception& e) {
        cerr << "✗ Error updating document: " << e.what() << endl;
        throw;
    }
}

bsoncxx::stdx::optional<mongocxx::result::delete_result> Database::deleteOne(
    const string& collection,
    const bsoncxx::document::view& filter) {
    try {
        auto coll = db[collection];
        return coll.delete_one(filter);
    } catch (const exception& e) {
        cerr << "✗ Error deleting document: " << e.what() << endl;
        throw;
    }
}

void Database::listCollections() {
    try {
        auto collections = db.list_collections();
        cout << "Collections in database:" << endl;
        for (auto&& collection : collections) {
            cout << "  - " << collection["name"].get_string().value << endl;
        }
    } catch (const exception& e) {
        cerr << "✗ Error listing collections: " << e.what() << endl;
    }
}

bool Database::isConnected() {
    try {
        auto admin = client["admin"];
        auto ping_cmd = bsoncxx::builder::basic::make_document(
            bsoncxx::builder::basic::kvp("ping", 1)
        );
        admin.run_command(ping_cmd.view());
        return true;
    } catch (...) {
        return false;
    }
}
