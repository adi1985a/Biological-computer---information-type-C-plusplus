#pragma once
#include <string>
#include <map>
#include <fstream>

class Config {
private:
    static Config* instance;
    std::map<std::string, std::string> settings;
    
    Config() {} // Private constructor for singleton

public:
    static Config* getInstance();
    bool loadConfig(const std::string& filename);
    std::string getSetting(const std::string& key);
};
