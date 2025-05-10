#include <iostream>
#include <vector>  // Added missing vector header
#include <stdexcept>
#include "config.hpp"
#include "visualization.hpp"

#define BRAIN_HEMISPHERES 2

struct InformationType {
    std::string name;
    std::string tool;
    std::string recordingType;
};

class BioComputer {
private:
    std::vector<InformationType> infoTypes;  // Properly declare vector member
    bool isRunning;

public:
    BioComputer() : isRunning(true) {
        infoTypes = {
            {"Picture", "Eyeballs", "Electromagnetic waves"},
            {"Sound", "Ears", "Acoustic waves"},
            {"Taste", "Tongue", "Chemical molecules"},
            {"Smell", "Nostrils", "Chemical molecules"},
            {"Kinesthetic feeling", "Whole body", "Receptors"}
        };
    }

    void run() {
        try {
            while(isRunning) {
                showMainMenu();
                handleUserChoice();
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

private:
    void showMainMenu() {
        system("cls");
        Visualization::drawBanner();
        Visualization::drawProgramDescription();
        std::cout << "\nMain Menu:\n";
        std::cout << "1. Information Types\n";
        std::cout << "2. Brain Hemispheres Info\n";
        std::cout << "3. About Program\n";
        std::cout << "4. Exit\n";
    }

    void handleUserChoice() {
        size_t choice = getValidInput(1, 4);
        switch(choice) {
            case 1: showInformationTypes(); break;
            case 2: showBrainInfo(); break;
            case 3: showAboutProgram(); break;
            case 4: isRunning = false; break;
        }
    }

    void showInformationTypes() {
        system("cls");
        Visualization::drawMenu();
        size_t choice = getValidInput(1, infoTypes.size());
        const auto& info = infoTypes[choice - 1];
        Visualization::drawResult(info.name, info.tool, info.recordingType);
        system("pause");
    }

    void showBrainInfo() {
        system("cls");
        Visualization::drawBrainInfo();
        system("pause");
    }

    void showAboutProgram() {
        system("cls");
        Visualization::drawAboutProgram();
        system("pause");
    }

    size_t getValidInput(size_t min, size_t max) {
        size_t choice;
        while (true) {
            std::cout << "\nEnter your choice (" << min << "-" << max << "): ";
            if (std::cin >> choice && choice >= min && choice <= max) {
                return choice;
            }
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Please try again.\n";
        }
    }
};

int main() {
    BioComputer computer;
    computer.run();
    return 0;
}
