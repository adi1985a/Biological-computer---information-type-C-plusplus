#include "visualization.hpp"
#include <iostream>

enum Colors {
    WHITE = 15,
    CYAN = 11,
    GREEN = 10,
    RED = 12
};

void Visualization::setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void Visualization::drawBanner() {
    setColor(CYAN);
    std::cout << "\n=== Biological Computer System ===\n" << std::endl;
    setColor(WHITE);
}

void Visualization::drawMenu() {
    setColor(GREEN);
    std::cout << "Specify the type of information received:\n\n";
    std::cout << "1. Picture\n";
    std::cout << "2. Sound\n";
    std::cout << "3. Taste\n";
    std::cout << "4. Smell\n";
    std::cout << "5. Feeling (e.g. touch)\n";
    setColor(WHITE);
}

void Visualization::drawResult(const std::string& type, const std::string& tool, const std::string& recording) {
    setColor(CYAN);
    std::cout << "\n=== Information Details ===\n";
    setColor(WHITE);
    std::cout << "Type: " << type << "\n";
    std::cout << "Tool: " << tool << "\n";
    std::cout << "Recording: " << recording << "\n";
}

void Visualization::drawProgramDescription() {
    setColor(WHITE);
    std::cout << "\nBiological Computer System - Human Brain Information Processing\n";
    std::cout << "This program simulates how human brain processes different types of information\n";
    std::cout << "through various sensory inputs and neural pathways.\n";
    std::cout << "===============================================================\n";
}

void Visualization::drawBrainInfo() {
    setColor(CYAN);
    std::cout << "\n=== Brain Hemispheres Information ===\n\n";
    setColor(WHITE);
    std::cout << "Left Hemisphere:\n";
    std::cout << "- Logical thinking\n";
    std::cout << "- Language processing\n";
    std::cout << "- Mathematical calculations\n";
    std::cout << "- Sequential processing\n\n";
    
    std::cout << "Right Hemisphere:\n";
    std::cout << "- Creative thinking\n";
    std::cout << "- Spatial awareness\n";
    std::cout << "- Artistic abilities\n";
    std::cout << "- Holistic processing\n";
}

void Visualization::drawAboutProgram() {
    setColor(CYAN);
    std::cout << "\n=== About Program ===\n\n";
    setColor(WHITE);
    std::cout << "Biological Computer System v1.0\n";
    std::cout << "Created by: Adrian Lesniak\n";
    std::cout << "Purpose: Educational demonstration of human brain information processing\n";
    std::cout << "Features:\n";
    std::cout << "- Information type analysis\n";
    std::cout << "- Brain hemisphere information\n";
    std::cout << "- Sensory input simulation\n";
}
