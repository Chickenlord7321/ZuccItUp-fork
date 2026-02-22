#ifndef DATABASE_H
#define DATABASE_H

#include <mongocxx/client.hpp>
#include <mongocxx/uri.hpp>
#include <bsoncxx/document/view.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <string>
#include <vector>

using namespace std;

class Database {
private:
    mongocxx::client client;
    mongocxx::database db;

public:
    // Constructor - connects to MongoDB
    Database(const string& uri = "mongodb+srv://keenan:Mowgli4$@cluster0.oorsnye.mongodb.net/?appName=Cluster0", 
             const string& dbName = "myapp");
    
    // Read operations
    bsoncxx::document::value findOne(const string& collection, 
                                     const bsoncxx::document::view& filter);
    
    vector<bsoncxx::document::value> findMany(const string& collection, 
                                                   const bsoncxx::document::view& filter = {});
    
    // Write operations
    bsoncxx::stdx::optional<mongocxx::result::insert_one> insertOne(
        const string& collection, 
        const bsoncxx::document::view& document);
    
    bsoncxx::stdx::optional<mongocxx::result::insert_many> insertMany(
        const string& collection, 
        const vector<bsoncxx::document::view>& documents);
    
    // Update operations
    bsoncxx::stdx::optional<mongocxx::result::update> updateOne(
        const string& collection,
        const bsoncxx::document::view& filter,
        const bsoncxx::document::view& update);
    
    // Delete operations
    bsoncxx::stdx::optional<mongocxx::result::delete_result> deleteOne(
        const string& collection,
        const bsoncxx::document::view& filter);
    
    // Utility
    void listCollections();
    bool isConnected();
};

#endif // DATABASE_H
