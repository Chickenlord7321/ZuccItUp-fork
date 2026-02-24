# C++ MongoDB Application

A simple C++ application that demonstrates reading and writing to a MongoDB database using the MongoDB C++ driver.

## Prerequisites

- C++ 17 or later
- CMake 3.16+
- MongoDB server running locally or accessible remotely
- MongoDB C++ Driver

## Installation

### Install MongoDB C++ Driver on Ubuntu/Debian

```bash
# Install dependencies
sudo apt-get update
sudo apt-get install -y \
    build-essential \
    cmake \
    libmongocxx-dev \
    libbsoncxx-dev \
    pkg-config

# On older systems, you may need to install from source:
# Follow: https://mongocxx.org/mongocxx-v3/installation/
```

### On macOS

```bash
# Using Homebrew
brew install mongo-cxx-driver
```

## Building the Application

```bash
cd cpp-mongodb-app
mkdir -p build
cd build
cmake ..
make
```

## Running

Make sure MongoDB is running:

```bash
# If using MongoDB locally
mongod --dbpath ~/.mongodb/data

# Or using Docker
docker run -d -p 27017:27017 mongo:latest
```

Then run the application:

```bash
./mongodb_app
```

## Features

- **Insert**: Add single or multiple documents to MongoDB
- **Read**: Query documents by filters
- **Update**: Modify existing documents
- **Delete**: Remove documents from the database
- **Connection Management**: Automatic connection pooling and error handling

## Usage Example

```cpp
// Create database instance
Database db("mongodb://localhost:27017", "myapp");

// Insert a document
auto doc = make_document(
    kvp("name", "John Doe"),
    kvp("email", "john@example.com")
);
db.insertOne("users", doc.view());

// Find documents
auto filter = make_document(kvp("name", "John Doe"));
auto found = db.findOne("users", filter.view());

// Update a document
auto update = make_document(kvp("$set", make_document(kvp("age", 31))));
db.updateOne("users", filter.view(), update.view());

// Delete a document
db.deleteOne("users", filter.view());
```

## Connection String

The MongoDB connection URI can be customized:

- Local: `mongodb://localhost:27017`
- Atlas Cloud: `mongodb+srv://user:password@cluster.mongodb.net`
- Custom: `mongodb://host:port/database`

## API Reference

### Database Class

- `findOne(collection, filter)` - Find first matching document
- `findMany(collection, filter)` - Find all matching documents
- `insertOne(collection, document)` - Insert single document
- `insertMany(collection, documents)` - Insert multiple documents
- `updateOne(collection, filter, update)` - Update single document
- `deleteOne(collection, filter)` - Delete single document
- `listCollections()` - List all collections in database
- `isConnected()` - Check database connection status

## Error Handling

All database operations throw exceptions on error. Wrap calls in try-catch blocks:

```cpp
try {
    db.insertOne("users", doc.view());
} catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
}
```

## Documentation

- [MongoDB C++ Driver](https://mongocxx.org/)
- [BSON Library](https://mongocxx.org/bsoncxx-v3/)
- [MongoDB Documentation](https://docs.mongodb.com/)

## License

MIT
