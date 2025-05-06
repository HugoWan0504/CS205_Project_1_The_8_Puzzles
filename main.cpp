#include <bits/stdc++.h>
#include "puzzle.h"
#include "solver.h"
using namespace std;

// Print welcome screen
void printIntro() {
    cout << "Welcome to the 8-Puzzle Solver!\n";
    cout << "Choose an option:\n";
    cout << "1. Use default puzzle\n";
    cout << "2. Enter your own puzzle\n";
}

// Show algorithm options
void printAlgorithmMenu() {
    cout << "\nChoose a search algorithm:\n";
    cout << "1. Uniform Cost Search (UCS)\n";
    cout << "2. A* with Misplaced Tile heuristic (AMT)\n";
    cout << "3. A* with Manhattan Distance heuristic (AMD)\n";
}

int main() {
    char choice = 'Y';

    while (choice == 'Y' || choice == 'y') {
        Puzzle puzzle;

        // --- Puzzle Selection ---
        printIntro();
        int inputType;
        cout << "Enter 1 or 2: ";
        while (!(cin >> inputType) || (inputType != 1 && inputType != 2)) {
            cout << "Invalid input. Please enter 1 (default) or 2 (custom): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Load puzzle based on user choice
        if (inputType == 1) {
            puzzle.loadDefault();
        } else {
            while (!puzzle.loadFromInput()) {
                cout << "Invalid puzzle. Please try again.\n";
            }
        }

        // Display current puzzle
        puzzle.printState();

        // --- Algorithm Selection ---
        printAlgorithmMenu();
        int algo;
        cout << "Enter 1, 2, or 3: ";
        while (!(cin >> algo) || (algo < 1 || algo > 3)) {
            cout << "Invalid input. Please enter 1, 2, or 3: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Create and run solver
        SearchType type = static_cast<SearchType>(algo);
        Solver solver(puzzle, type);
        solver.solve();

        // --- Replay Option ---
        cout << "\nWould you like to play again? (Y/y = Yes, N/n = No): ";
        cin >> choice;
        cout << "---------------------------------------------\n";
    }

    cout << "Thanks for playing. Exiting now.\n";
    return 0;
}
