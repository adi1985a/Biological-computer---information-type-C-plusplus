#pragma once
#include <string>
#include <windows.h>

class Visualization {
public:
    static void setColor(int color);
    static void drawBanner();
    static void drawMenu();
    static void drawResult(const std::string& type, const std::string& tool, const std::string& recording);
    static void drawProgramDescription();
    static void drawBrainInfo();
    static void drawAboutProgram();
};
