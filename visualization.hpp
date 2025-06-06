// visualization.hpp
#pragma once
#include <windows.h>
#include <string>

class Visualization {
public:
    // Color constants
    static const WORD COLOR_RESET;
    static const WORD COLOR_HEADER;
    static const WORD COLOR_PROMPT;
    static const WORD COLOR_INPUT;
    static const WORD COLOR_ERROR;
    static const WORD COLOR_RESULT;

    static void setColor(WORD color);
    static void drawBanner();
    static void drawProgramDescription();
    static void drawMenu();
    static void drawResult(const std::string& type, const std::string& tool, const std::string& recording);
    static void drawBrainInfo();
    static void drawAboutProgram();
    static std::string horizontalLine(size_t length);
};
