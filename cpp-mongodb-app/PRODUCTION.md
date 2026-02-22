# C++ MongoDB Product Management System - Production Ready

A high-performance, production-ready C++ application for managing products and orders with MongoDB integration.

## Features

✓ **Input Validation** - All user inputs are validated
✓ **Configuration Management** - Environment-based configuration
✓ **Docker Support** - Full containerization with docker-compose
✓ **Error Handling** - Comprehensive error handling
✓ **MongoDB Integration** - Works with both local and MongoDB Atlas
✓ **Interactive CLI** - User-friendly terminal interface

## Quick Start

### Local Development (with Docker Compose)

```bash
cd cpp-mongodb-app
docker-compose up --build
```

The app will start and connect to MongoDB automatically.

### Manual Build

```bash
mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

### Run Locally

```bash
# With default local MongoDB
./build/mongodb_app

# With custom MongoDB URI
export MONGODB_URI="mongodb+srv://user:pass@cluster.mongodb.net/?appName=App"
export APP_ENV=production
./build/mongodb_app
```

## Configuration

Create a `.env` file based on `.env.example`:

```env
MONGODB_URI=mongodb://localhost:27017
MONGODB_DATABASE=myapp
MONGODB_TIMEOUT_MS=5000
APP_ENV=production
APP_LOG_LEVEL=INFO
```

Or set environment variables:
```bash
export MONGODB_URI="mongodb+srv://keenan:Mowgli4$@cluster0.oorsnye.mongodb.net/?appName=Cluster0"
export APP_ENV=production
./build/mongodb_app
```

## Database Schema

### Products Collection
```json
{
  "_id": "ObjectId",
  "name": "Coffee",
  "description": "Fresh brewed coffee from beans",
  "price": 2.5,
  "available": true,
  "category": "Drink",
  "options": [
    { "name": "Small", "price_modifier": -2 },
    { "name": "Medium", "price_modifier": 0 },
    { "name": "Large", "price_modifier": 3 }
  ]
}
```

### Orders Collection
```json
{
  "_id": "ObjectId",
  "customerName": "Bob",
  "item": "Coffee",
  "qty": 2
}
```

## Menu Options

1. **Insert Product** - Add new menu items with options
2. **Find Product** - Search for products by name
3. **List Products** - Display all available products
4. **Update Price** - Modify product pricing
5. **Delete Product** - Remove items from menu
6. **Place Order** - Create new customer orders
7. **View Orders** - Display all orders
8. **Exit** - Close application

## Input Validation

- **Names**: Max 100 chars, alphanumeric + space/hyphen/apostrophe
- **Prices**: 0.00 - 10,000.00
- **Quantities**: 1 - 1,000 items
- **Descriptions**: Max 500 characters

## Docker Deployment

### Build Docker Image

```bash
cd cpp-mongodb-app
docker build -t mongodb-app:latest .
```

### Run with Docker Compose

```bash
docker-compose up -d
```

This will:
- Start MongoDB on port 27017 (with auth)
- Start the app on port 8080
- Automatically handle database initialization
- Create persistent MongoDB volumes

# Start everything
docker-compose up

# Stop everything
docker-compose down

# View logs
docker-compose logs

# Rebuild image
docker-compose up --build

### Environment Variables in Docker

```yaml
environment:
  MONGODB_URI: mongodb://user:pass@mongodb:27017/myapp?authSource=admin
  MONGODB_DATABASE: myapp
  APP_ENV: production
```

## Production Checklist

- [x] Input validation
- [x] Configuration management
- [x] Docker containerization
- [x] Release build optimizations (-O3)
- [x] Binary stripping in production
- [x] Error handling and logging
- [x] Connection pooling (via MongoDB driver)
- [x] Health checks (docker-compose)
- [x] Restart policies
- [x] Volume persistence

## Supported MongoDB Deployments

1. **Local MongoDB** (default)
   ```
   mongodb://localhost:27017
   ```

2. **MongoDB Atlas** (Cloud)
   ```
   mongodb+srv://user:password@cluster.mongodb.net/?appName=App
   ```

3. **Custom Server**
   ```
   mongodb://host:port/database
   ```

## Performance Optimizations

- Release build with `-O3` optimizations
- Binary stripping to reduce size
- Connection pooling via MongoDB driver
- Efficient BSON serialization
- Input validation to prevent invalid operations

## Troubleshooting

### Connection Failed
```bash
# Check MongoDB is running
docker-compose logs mongodb

# Check app logs
docker-compose logs app

# Verify connection string
echo $MONGODB_URI
```

### MongoDB Not Responding
```bash
# Restart services
docker-compose restart

# Full reset
docker-compose down -v
docker-compose up --build
```

## Dependencies

- C++17 or later
- MongoDB C++ Driver 4.2+
- OpenSSL 1.1+
- CMake 3.16+

## License

MIT - See LICENSE file

## Support

For issues or questions:
1. Check configuration in `.env`
2. Verify MongoDB is running
3. Review application logs
4. Test MongoDB connection separately

---

**Ready for Production** ✓
