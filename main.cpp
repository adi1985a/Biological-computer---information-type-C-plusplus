// main.cpp
#include <iostream>
#include <vector>
#include <stdexcept>
#include <windows.h>
#include <limits>
#include <conio.h>
#include "config.hpp"
#include "visualization.hpp"

using namespace std;

struct InformationType {
    string name;
    string tool;
    string recordingType;
};

class BioComputer {
private:
    vector<InformationType> infoTypes;
    bool isRunning;

public:
    BioComputer() : isRunning(true) {
        infoTypes = {
            {"Picture", "Eyes", "Electromagnetic waves"},
            {"Sound", "Ears", "Acoustic waves"},
            {"Taste", "Tongue", "Chemical molecules"},
            {"Smell", "Nose", "Chemical molecules"},
            {"Kinesthetic feeling", "Body receptors", "Mechanical stimuli"}
        };
    }

    void run() {
        try {
            while (isRunning) {
                showMainMenu();
                handleUserChoice();
            }
        }
        catch (const exception& e) {
            Visualization::setColor(Visualization::COLOR_ERROR);
            cerr << "[Error] " << e.what() << "\n";
            Visualization::setColor(Visualization::COLOR_RESET);
        }
    }

private:
    void showMainMenu() {
        system("cls");
        Visualization::drawBanner();
        Visualization::drawProgramDescription();
        cout << "\n" << Visualization::horizontalLine(60) << "\n";
        Visualization::setColor(Visualization::COLOR_PROMPT);
        cout << " Main Menu:\n";
        cout << "   1) Information Types\n";
        cout << "   2) Brain Hemispheres Info\n";
        cout << "   3) About Program\n";
        cout << "   4) Exit\n";
        Visualization::setColor(Visualization::COLOR_RESET);
        cout << "\n" << Visualization::horizontalLine(60) << "\n";
    }

    void handleUserChoice() {
        size_t choice = getValidInput(1, 4);
        switch (choice) {
            case 1: showInformationTypes(); break;
            case 2: showBrainInfo();       break;
            case 3: showAboutProgram();    break;
            case 4: isRunning = false;     break;
        }
    }

    void showInformationTypes() {
        system("cls");
        Visualization::drawBanner();
        cout << "\n" << Visualization::horizontalLine(50) << "\n";
        Visualization::drawMenu();
        cout << "\n" << Visualization::horizontalLine(50) << "\n";

        size_t choice = getValidInput(1, infoTypes.size());
        const auto& info = infoTypes[choice - 1];
        system("cls");
        Visualization::drawBanner();
        Visualization::drawResult(info.name, info.tool, info.recordingType);
        cout << "\n" << Visualization::horizontalLine(50) << "\n";
        Visualization::setColor(Visualization::COLOR_PROMPT);
        cout << " Press any key to return to main menu...";
        Visualization::setColor(Visualization::COLOR_RESET);
        _getch();
    }

    void showBrainInfo() {
        system("cls");
        Visualization::drawBanner();
        Visualization::drawBrainInfo();
        cout << "\n" << Visualization::horizontalLine(50) << "\n";
        Visualization::setColor(Visualization::COLOR_PROMPT);
        cout << " Press any key to return to main menu...";
        Visualization::setColor(Visualization::COLOR_RESET);
        _getch();
    }

    void showAboutProgram() {
        system("cls");
        Visualization::drawBanner();
        Visualization::drawAboutProgram();
        cout << "\n" << Visualization::horizontalLine(50) << "\n";
        Visualization::setColor(Visualization::COLOR_PROMPT);
        cout << " Press any key to return to main menu...";
        Visualization::setColor(Visualization::COLOR_RESET);
        _getch();
    }

    size_t getValidInput(size_t min, size_t max) {
        size_t choice;
        while (true) {
            Visualization::setColor(Visualization::COLOR_INPUT);
            cout << "\n Enter your choice (" << min << "-" << max << "): ";
            if (cin >> choice && choice >= min && choice <= max) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            Visualization::setColor(Visualization::COLOR_ERROR);
            cout << " Invalid input. Please try again.\n";
            Visualization::setColor(Visualization::COLOR_RESET);
        }
        Visualization::setColor(Visualization::COLOR_RESET);
        return choice;
    }
};

int main() {
    // Optionally load configuration
    Config::getInstance()->loadConfig("settings.cfg");

    BioComputer computer;
    computer.run();

    return 0;
}
