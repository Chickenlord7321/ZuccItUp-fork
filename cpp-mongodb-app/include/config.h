#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <cstdlib>

using namespace std;

class Config {
private:
    string mongodb_uri;
    string mongodb_database;
    int mongodb_timeout_ms;
    string app_env;
    string log_level;
    
    // Private helper to get env var with default
    static string getEnv(const string& key, const string& default_value = "") {
        const char* val = getenv(key.c_str());
        return val ? string(val) : default_value;
    }

public:
    Config() {
        mongodb_uri = getEnv("MONGODB_URI", "mongodb+srv://keenan:Mowgli4$@cluster0.oorsnye.mongodb.net/?appName=Cluster0");
        mongodb_database = getEnv("MONGODB_DATABASE", "myapp");
        mongodb_timeout_ms = stoi(getEnv("MONGODB_TIMEOUT_MS", "5000"));
        app_env = getEnv("APP_ENV", "development");
        log_level = getEnv("APP_LOG_LEVEL", "INFO");
    }
    
    // Getters
    const string& getMongodbUri() const { return mongodb_uri; }
    const string& getMongodbDatabase() const { return mongodb_database; }
    int getMongodbTimeoutMs() const { return mongodb_timeout_ms; }
    const string& getAppEnv() const { return app_env; }
    const string& getLogLevel() const { return log_level; }
    
    bool isProduction() const { return app_env == "production"; }
    bool isDevelopment() const { return app_env == "development"; }
    
    void printConfig() const {
        cout << "\n===== Application Configuration =====" << endl;
        cout << "Environment: " << app_env << endl;
        cout << "Log Level: " << log_level << endl;
        cout << "Database: " << mongodb_database << endl;
        cout << "MongoDB Timeout: " << mongodb_timeout_ms << "ms" << endl;
        cout << "Connection: " << (mongodb_uri.find("mongodb+srv") != string::npos ? "Atlas (SRV)" : "Local/Custom") << endl;
        cout << "======================================" << endl;
    }
};

#endif // CONFIG_H
