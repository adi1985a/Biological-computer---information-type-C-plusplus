// visualization.cpp
#include "visualization.hpp"
#include <iostream>

// Define color constants
const WORD Visualization::COLOR_RESET   = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;              // White
const WORD Visualization::COLOR_HEADER  = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;       // Cyan
const WORD Visualization::COLOR_PROMPT  = FOREGROUND_GREEN                  | FOREGROUND_INTENSITY;       // Bright Green
const WORD Visualization::COLOR_INPUT   = FOREGROUND_RED   | FOREGROUND_GREEN | FOREGROUND_INTENSITY;       // Bright Yellow
const WORD Visualization::COLOR_ERROR   = FOREGROUND_RED                  | FOREGROUND_INTENSITY;       // Bright Red
const WORD Visualization::COLOR_RESULT  = FOREGROUND_BLUE                 | FOREGROUND_INTENSITY;       // Bright Blue

void Visualization::setColor(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

std::string Visualization::horizontalLine(size_t length) {
    return std::string(length, '=');
}

void Visualization::drawBanner() {
    setColor(COLOR_HEADER);
    std::cout << R"(
  ____  _     ____        _       
 | __ )(_) __| __ )  ___ | |_ ___ 
 |  _ \| |/ _`  _ \ / _ \| __/ _ \
 | |_) | | (_| |_) | (_) | ||  __/
 |____/|_|\__,____/ \___/ \__\___|
                                   
    )" << "\n";
    setColor(COLOR_RESET);
}

void Visualization::drawProgramDescription() {
    setColor(COLOR_PROMPT);
    std::cout << " Bio Data: Human Brain Information Processing\n";
    setColor(COLOR_RESET);
    std::cout << "=======================================================\n";
}

void Visualization::drawMenu() {
    setColor(COLOR_PROMPT);
    std::cout << "\n Specify the type of information received:\n\n";
    std::cout << "   1) Picture\n";
    std::cout << "   2) Sound\n";
    std::cout << "   3) Taste\n";
    std::cout << "   4) Smell\n";
    std::cout << "   5) Kinesthetic feeling\n";
    setColor(COLOR_RESET);
}

void Visualization::drawResult(const std::string& type, const std::string& tool, const std::string& recording) {
    setColor(COLOR_RESULT);
    std::cout << "\n Information Details:\n";
    std::cout << horizontalLine(40) << "\n";
    setColor(COLOR_RESET);
    std::cout << "   Type      : " << type << "\n";
    std::cout << "   Tool      : " << tool << "\n";
    std::cout << "   Recording : " << recording << "\n";
}

void Visualization::drawBrainInfo() {
    setColor(COLOR_RESULT);
    std::cout << "\n Brain Hemispheres Info:\n";
    std::cout << horizontalLine(40) << "\n\n";
    setColor(COLOR_RESET);
    std::cout << " Left Hemisphere:\n";
    std::cout << "   - Logical thinking\n";
    std::cout << "   - Language processing\n";
    std::cout << "   - Mathematical calculations\n";
    std::cout << "   - Sequential processing\n\n";
    std::cout << " Right Hemisphere:\n";
    std::cout << "   - Creative thinking\n";
    std::cout << "   - Spatial awareness\n";
    std::cout << "   - Artistic abilities\n";
    std::cout << "   - Holistic processing\n";
}

void Visualization::drawAboutProgram() {
    setColor(COLOR_RESULT);
    std::cout << "\n About Program:\n";
    std::cout << horizontalLine(40) << "\n\n";
    setColor(COLOR_RESET);
    std::cout << "  Bio Data v1.0\n";
    std::cout << "  Created by: Adrian Lesniak\n";
    std::cout << "  Purpose: Demonstrate human brain info processing\n";
    std::cout << "  Features:\n";
    std::cout << "    - Info type analysis\n";
    std::cout << "    - Hemisphere details\n";
    std::cout << "    - ASCII & color UI\n";
}
