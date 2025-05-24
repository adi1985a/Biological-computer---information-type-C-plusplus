# 🧠🖥️ NeuroSim Interface: Bio-Computer Simulator 👁️👂👃👅✋
_A C++ console application simulating a bio-computer interface for managing sensory information types and displaying brain hemisphere information, featuring ASCII art visualizations._

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/Language-C%2B%2B%2011%2B-blue.svg)](https://isocpp.org/)
[![Platform: Windows (Primary)](https://img.shields.io/badge/Platform-Windows%20(Primary)-lightgrey.svg)]()

## 📋 Table of Contents
1.  [Overview](#-overview)
2.  [Key Features](#-key-features)
3.  [Screenshots (Conceptual)](#-screenshots-conceptual)
4.  [System Requirements](#-system-requirements)
5.  [Core Custom Headers (`config.hpp`, `visualization.hpp`)](#-core-custom-headers-confighpp-visualizationhpp)
6.  [Installation and Setup](#️-installation-and-setup)
7.  [Usage Guide](#️-usage-guide)
8.  [File Structure](#-file-structure)
9.  [Technical Notes](#-technical-notes)
10. [Contributing](#-contributing)
11. [License](#-license)
12. [Contact](#-contact)

## 📄 Overview

**NeuroSim Interface: Bio-Computer Simulator**, developed by Adrian Lesniak, is a C++ console application designed to simulate a conceptual bio-computer interface. It focuses on managing and displaying different types of sensory information (Picture, Sound, Taste, Smell, Kinesthetic feeling) and providing illustrative information about brain hemispheres. The program utilizes a menu-driven user interface enhanced with ASCII art visualizations (managed via `visualization.hpp`). It features robust input validation, exception handling for a smooth user experience, and configurations defined in a user-provided `config.hpp`. The application is primarily targeted for Windows due to its use of `system("cls")` and `system("pause")`.

## ✨ Key Features

*   🧬 **BioComputer Class & Logic**:
    *   Manages a collection of `InformationType` structures (each holding name, associated "tool," and "recording type") using a `std::vector`.
    *   Controls the main application loop and program state (`isRunning` flag).
    *   `run()`: Executes the primary loop, handling menu display and user choice processing.
*   🖥️ **Menu System & Navigation**:
    *   `showMainMenu`: Displays the main menu with options to:
        1.  View Information Types
        2.  Brain Hemispheres Info
        3.  About Program
        4.  Exit
    *   Utilizes `Visualization::drawBanner` (from `visualization.hpp`) for an engaging ASCII art menu header.
    *   `handleUserChoice`: Processes validated user input for menu selections.
*   👁️👂👃👅✋ **Sensory Information Types**:
    *   Lists predefined sensory inputs (e.g., "Picture" via "Eyeballs" recording "Electromagnetic waves", "Sound" via "Ears" recording "Air pressure waves").
    *   `showInformationTypes`: Allows the user to select a specific sensory type and displays its detailed information, potentially with dedicated ASCII art via `Visualization::drawResult`.
*   🧠 **Brain Hemisphere Information**:
    *   `showBrainInfo`: Presents information about the brain's hemispheres, likely visualized with ASCII art using `Visualization::drawBrainInfo`.
*   ℹ️ **About Program**:
    *   `showAboutProgram`: Displays details about the application, its purpose, and author, possibly with `Visualization::drawAboutProgram`.
*   ✔️ **Robust Input Validation**:
    *   `getValidInput`: Ensures user input for menu choices is within the valid range (e.g., 1-4 or 1-5 for sub-menus), clearing invalid input and prompting for retry.
*   🎨 **ASCII Art Visualizations**: Leverages functions from `visualization.hpp` to display banners, menus, results, and informational screens with custom ASCII art.

## 🖼️ Screenshots (Conceptual)

**Coming soon!**

_This section would ideally show conceptual mockups or actual screenshots if the ASCII art is elaborate, demonstrating: the main menu with banner, the information types list, details of a selected sensory type, the brain info screen, and the about program screen._

## ⚙️ System Requirements

*   **Operating System**: Windows (primarily, due to `system("cls")` and `system("pause")`). Basic functionality might work on other OSes if `system("clear")` is used as an alternative for screen clearing and standard input methods replace `system("pause")`.
*   **C++ Compiler**: A C++ compiler supporting C++11 or later (e.g., g++, clang++, MSVC).
*   **Standard C++ Libraries**: `<iostream>`, `<vector>`, `<string>`, `<stdexcept>`, `<limits>`, `<iomanip>`.
*   📄 **Custom Header Files (User-Provided)**: This project **critically requires** `config.hpp` and `visualization.hpp`. **These files are not included in the repository and must be created by the user.**
    *   `config.hpp`: For global configurations, settings, or constants.
    *   `visualization.hpp`: For declaring/defining functions that render ASCII art.
    See "Core Custom Headers" and "Installation and Setup" for details.

## 🧩 Core Custom Headers (`config.hpp`, `visualization.hpp`)

These user-provided header files are essential for the program's look and feel:

*   **`config.hpp`**: Defines global configurations or constants.
    *   Example: Could define program title, version, or even color codes if not handled directly in `main.cpp` or a separate utils file.
    ```cpp
    #ifndef CONFIG_HPP
    #define CONFIG_HPP
    #include <string>
    // const std::string PROGRAM_VERSION = "1.0";
    // const int DEFAULT_TEXT_COLOR = 7; // Example if colors managed here
    #endif // CONFIG_HPP
    ```
*   **`visualization.hpp`**: Declares and possibly defines functions for rendering ASCII art.
    *   Example Functions: `Visualization::drawBanner()`, `Visualization::drawMenu(const std::vector<std::string>& items)`, `Visualization::drawResult(const InformationType& info)`, `Visualization::drawBrainInfo()`, `Visualization::drawAboutProgram()`.
    ```cpp
    #ifndef VISUALIZATION_HPP
    #define VISUALIZATION_HPP
    #include <iostream>
    #include <string>
    #include <vector>
    // Assuming InformationType struct is defined elsewhere or passed appropriately
    // struct InformationType { std::string name, tool, recordingType; };

    namespace Visualization {
        void drawBanner(const std::string& title);
        void drawMenu(const std::vector<std::string>& menuOptions);
        // void drawResult(const InformationType& infoType); // Example
        void drawBrainInfo();
        void drawAboutProgram();
        // Add other ASCII art drawing functions
    }
    #endif // VISUALIZATION_HPP
    ```
*Implementations for these visualization functions would typically be in `visualization.cpp` or directly in the header if simple.*

## 🛠️ Installation and Setup

1.  **Clone the Repository**:
    ```bash
    git clone <repository-url>
    cd <repository-directory>
    ```
    (Replace `<repository-url>` and `<repository-directory>` with your specific details)

2.  **Create Custom Header & Implementation Files**:
    *   Create `config.hpp` and `visualization.hpp` in the project directory with the necessary declarations/definitions.
    *   If `visualization.hpp` only contains declarations, create `visualization.cpp` with the implementations.

3.  **Save Main Code**:
    Ensure your main application logic (including the `BioComputer` class and `main()` function) is saved as `bio_computer.cpp` in the project directory.

4.  **Compile the Program**:
    Open a terminal (Command Prompt, PowerShell, Bash, etc.) in the project directory.
    **Example using g++:**
    ```bash
    g++ bio_computer.cpp visualization.cpp -o bio_computer -std=c++11
    ```
    *(This assumes `visualization.cpp` contains implementations for `visualization.hpp`. Adjust if your structure differs. Add `-static-libgcc -static-libstdc++` on Windows with MinGW if desired for standalone executables).*

5.  **Run the Program**:
    *   On Windows: `.\bio_computer.exe` or `bio_computer.exe`
    *   On Linux/macOS: `./bio_computer` (ensure execute permissions: `chmod +x bio_computer`)

## 💡 Usage Guide

1.  Compile and run `bio_computer` as detailed above.
2.  **Interface**:
    *   The program will display a main menu, likely featuring an ASCII art banner (via `Visualization::drawBanner`), with the following options:
        1.  Information Types
        2.  Brain Hemispheres Info
        3.  About Program
        4.  Exit
3.  **Input**:
    *   Select a menu option (1–4) by typing the number and pressing Enter.
    *   **For Information Types (Option 1)**: A sub-menu will likely appear listing the sensory types (1. Picture, 2. Sound, etc.). Select a number to view details for that specific type.
    *   Invalid inputs (e.g., non-numeric, out-of-range choices) will trigger an error message and prompt for re-entry.
4.  **Output**:
    *   **Information Types**: Selecting a type (e.g., "Picture") will display its details, such as "Name: Picture, Tool: Eyeballs, Recording Method: Electromagnetic waves," possibly accompanied by specific ASCII art.
    *   **Brain Hemispheres Info**: Displays textual and/or ASCII art information about the brain.
    *   **About Program**: Shows details about the simulator.
    *   Error messages are displayed directly on the console for invalid inputs.
5.  **Actions**:
    *   After viewing information, you will typically be prompted to press any key (`system("pause")` on Windows or an alternative) to return to the main menu.
    *   Select option `4` from the main menu to exit the application.

## 🗂️ File Structure

*   `bio_computer.cpp`: The main C++ source file containing the `BioComputer` class implementation, `main()` function, and core application logic.
*   `config.hpp`: (User-provided) Header file for global configurations and constants.
*   `visualization.hpp`: (User-provided) Header file declaring/defining functions for rendering ASCII art.
*   `visualization.cpp`: (User-provided, if implementations are separate) Source file for ASCII art rendering functions.
*   `README.md`: This documentation file.

## 📝 Technical Notes

*   **Windows Specifics**: The primary reliance for UI enhancements like screen clearing (`system("cls")`) and pausing (`system("pause")`) is on Windows-specific commands. For cross-platform console behavior, alternatives like `system("clear")` for clearing and standard input methods for pausing would be needed, or a library like ncurses. Console colors, if any beyond default, would also need cross-platform handling (e.g., ANSI codes).
*   **Modularity via Headers**: The use of `config.hpp` and `visualization.hpp` promotes a degree of modularity, separating configuration and visual presentation concerns from the core simulation logic.
*   **Input Validation**: The `getValidInput` function is crucial for ensuring robust user interaction by handling non-numeric input and range checks.
*   **Exception Handling**: The program structure suggests the use of C++ exceptions (`std::runtime_error`, `std::invalid_argument`) for more critical error conditions, providing a more robust error management strategy than just console messages.
*   **Potential Enhancements**: Could be extended by adding more detailed sensory information, interactive simulations, data persistence for user configurations, more sophisticated brain models, or true cross-platform UI libraries.

## 🤝 Contributing

Contributions to **NeuroSim Interface: Bio-Computer Simulator** are welcome! If you have ideas for adding more sensory modalities, refining the brain information, creating more elaborate ASCII visualizations, or improving cross-platform compatibility:

1.  Fork the repository.
2.  Create a new branch for your feature (`git checkout -b feature/YourBioSimIdea`).
3.  Make your changes and commit them (`git commit -m 'Feature: Implement YourBioSimIdea'`).
4.  Push to the branch (`git push origin feature/YourBioSimIdea`).
5.  Open a Pull Request.

Please ensure your code is well-commented and adheres to good C++ practices.

## 📃 License

This project is licensed under the **MIT License**.
(If you have a `LICENSE` file in your repository, refer to it: `See the LICENSE file for details.`)

## 📧 Contact

Created by **Adrian Lesniak**.
For questions, feedback, or issues, please open an issue on the GitHub repository or contact the repository owner.

---
🌌 _Simulating the interface between biology and computation, one character at a time._
