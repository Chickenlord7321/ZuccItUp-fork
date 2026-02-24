cmake_minimum_required(VERSION 3.16)
project(MongoDBApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Release build optimizations
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra")

# Find pkg-config
find_package(PkgConfig REQUIRED)

# Find OpenSSL
find_package(OpenSSL REQUIRED)

# Find MongoDB C++ driver using pkg-config
pkg_check_modules(MONGOCXX REQUIRED libmongocxx)
pkg_check_modules(BSONCXX REQUIRED libbsoncxx)

# Include directories
include_directories(include)
include_directories(${MONGOCXX_INCLUDE_DIRS})
include_directories(${BSONCXX_INCLUDE_DIRS})

# Source files
set(SOURCES
    src/main.cpp
    src/database.cpp
)

# Create executable
add_executable(mongodb_app ${SOURCES})

# Link libraries
target_link_libraries(mongodb_app PRIVATE 
    ${MONGOCXX_LIBRARIES}
    ${BSONCXX_LIBRARIES}
    OpenSSL::SSL
    OpenSSL::Crypto
)

# Add compile flags from pkg-config
target_compile_options(mongodb_app PRIVATE ${MONGOCXX_CFLAGS_OTHER})
target_link_directories(mongodb_app PRIVATE ${MONGOCXX_LIBRARY_DIRS})

# Strip binary in release mode
if(CMAKE_BUILD_TYPE STREQUAL Release)
    add_custom_command(TARGET mongodb_app POST_BUILD
        COMMAND ${CMAKE_STRIP} mongodb_app
        COMMENT "Stripping binary for production"
    )
endif()

