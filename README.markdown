# Bio-Computer Simulator

## Overview
This C++ console application simulates a bio-computer interface, managing sensory information types (Picture, Sound, Taste, Smell, Kinesthetic feeling) and brain hemisphere information. It features a menu-driven UI with ASCII art visualizations (via `visualization.hpp`), robust input validation, and exception handling.

## Features
- **BioComputer Class**:
  - Stores `InformationType` structs (name, tool, recording type) in a `std::vector`.
  - Manages program state with `isRunning` flag.
  - `run`: Executes the main loop, displaying menus and handling choices.
- **Menu System**:
  - Options: View information types, brain hemisphere info, about program, or exit.
  - `showMainMenu`: Displays menu with ASCII art via `Visualization::drawBanner`.
  - `handleUserChoice`: Processes user input with validation.
- **Information Types**:
  - Lists sensory inputs (e.g., Picture via Eyeballs, Sound via Ears).
  - `showInformationTypes`: Displays details for a selected type.
- **Brain Info**:
  - `showBrainInfo`: Shows hemisphere info (via `Visualization::drawBrainInfo`).
- **About Program**:
  - `showAboutProgram`: Displays program details.
- **Input Validation**:
  - `getValidInput`: Ensures input is within valid range, clears invalid input.

## Requirements
- C++ compiler (e.g., g++, clang++) with C++11 or later
- Standard C++ libraries: `<iostream>`, `<vector>`, `<stdexcept>`
- Custom headers: `config.hpp`, `visualization.hpp` (assumed to provide visualization functions)
- Operating system: Windows (for `system("cls")` and `system("pause")`)

## Setup
1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd <repository-directory>
   ```
2. Ensure `config.hpp` and `visualization.hpp` are in the project directory with required functions (e.g., `Visualization::drawBanner`, `Visualization::drawMenu`).
3. Save the provided code as `bio_computer.cpp`.
4. Compile the program:
   ```bash
   g++ bio_computer.cpp -o bio_computer
   ```
5. Run the program:
   ```bash
   .\bio_computer
   ```

## Usage
1. Compile and run the program using the steps above.
2. **Interface**:
   - Displays a main menu with ASCII art and options:
     1. Information Types
     2. Brain Hemispheres Info
     3. About Program
     4. Exit
3. **Actions**:
   - Enter 1–4 to select an option.
   - For Information Types, choose a sensory type (1–5) to view details.
   - View brain info or program details; press any key to return to menu.
   - Select 4 to exit.
4. **Output**:
   - Example: Selecting "Picture" shows "Name: Picture, Tool: Eyeballs, Recording: Electromagnetic waves" with ASCII art.
   - Invalid inputs prompt for retry.

## File Structure
- `bio_computer.cpp`: Main C++ source file with program logic.
- `config.hpp`: Configuration header (assumed, not provided).
- `visualization.hpp`: Visualization header for ASCII art (assumed, not provided).
- `README.md`: This file, providing project documentation.

## Notes
- Windows-specific due to `system("cls")` and `system("pause")`; adapt for other OS (e.g., `system("clear")` for Unix).
- Requires `config.hpp` and `visualization.hpp` with functions like `drawBanner`, `drawMenu`, `drawResult`, `drawBrainInfo`, `drawAboutProgram`.
- Input validation ensures robust user interaction.
- Extend by adding more information types, persistent storage, or cross-platform support.
- No locale settings; uses English text for output.
- No external dependencies beyond standard C++ libraries and custom headers.

## Contributing
Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make changes and commit (`git commit -m "Add feature"`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact
For questions or feedback, open an issue on GitHub or contact the repository owner.