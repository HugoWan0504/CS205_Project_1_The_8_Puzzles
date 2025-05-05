#include <bits/stdc++.h>
#include "puzzle.h"
#include "solver.h"
using namespace std;

void printIntro() {
    cout << "Welcome to the 8-Puzzle Solver!\n";
    cout << "Choose an option:\n";
    cout << "1. Use default puzzle\n";
    cout << "2. Enter your own puzzle\n";
}

void printAlgorithmMenu() {
    cout << "\nChoose a search algorithm:\n";
    cout << "1. Uniform Cost Search\n";
    cout << "2. A* with Misplaced Tile heuristic\n";
    cout << "3. A* with Manhattan Distance heuristic\n";
}

int main() {
    char choice = 'Y';

    while (choice == 'Y' || choice == 'y') {
        Puzzle puzzle;

        // Ask the user to choose a puzzle type
        printIntro();

        int inputType;
        cin >> inputType;

        // Default puzzle
        if (inputType == 1) {
            puzzle.loadDefault();
        } else { // Custom Puzzle
            // Check if the custom puzzle is valid
            while (!puzzle.loadFromInput()) { 
                // return invalid puzzle message if not
                cout << "Invalid puzzle. Please try again.\n";
            }
        }

        // Print the Initial / Current Puzzle State
        puzzle.printState();

        // Ask the user to choose a search algorithm
        printAlgorithmMenu();

        int algo;
        cin >> algo;
        SearchType type = static_cast<SearchType>(algo);

        Solver solver(puzzle, type);
        solver.solve();
        // solver.printSummary();

        cout << "\nWould you like to play again? (Y/y = Yes, N/n = No): ";
        cin >> choice;
        cout << "---------------------------------------------\n";
    }

    cout << "Thanks for playing. Exiting now.\n";
    return 0;
}
