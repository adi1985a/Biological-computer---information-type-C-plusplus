// config.hpp
#pragma once
#include <string>
#include <map>
#include <fstream>
#include <sstream>

class Config {
private:
    static Config* instance;
    std::map<std::string, std::string> settings;

    Config() {}

public:
    static Config* getInstance() {
        if (!instance) {
            instance = new Config();
        }
        return instance;
    }

    bool loadConfig(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            return false;
        }
        std::string line;
        while (std::getline(file, line)) {
            if (line.empty() || line[0] == '#') continue;
            std::istringstream iss(line);
            std::string key, value;
            if (std::getline(iss, key, '=') && std::getline(iss, value)) {
                settings[key] = value;
            }
        }
        file.close();
        return true;
    }

    std::string getSetting(const std::string& key) {
        if (settings.count(key)) {
            return settings[key];
        }
        return "";
    }
};

Config* Config::instance = nullptr;
