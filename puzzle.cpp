#include "puzzle.h"

// 8-puzzle is a 3x3 grid puzzle
Puzzle::Puzzle() {
    state = vector<vector<int>>(3, vector<int>(3, 0));
}

// my default puzzle
void Puzzle::loadDefault() {
    state = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 5, 8}
    };
    cout << "Default puzzle loaded.\n";
}

// making sure the custom puzzle numbers are valid
bool Puzzle::isValid(const vector<int>& flatInput) const {
    // 9 digits, 1 to 8, including 0 as the blank block
    if (flatInput.size() != 9) return false;

    unordered_set<int> seen;
    for (int num : flatInput) {
        // return invalid if found a number is 
        // lower than 0 or more than 8 or is duplicated
        if (num < 0 || num > 8 || seen.count(num)) return false;
        seen.insert(num);
    }
    return true;
}

// Custom puzzle digit inputs setup
bool Puzzle::loadFromInput() {
    cout << "Enter your puzzle row-by-row (use 0 for blank):\n";

    // log user's inputs of the rows
    vector<int> flatInput;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // clear input buffer
    for (int i = 0; i < 3; ++i) {
        cout << "Row " << (i + 1) << ": ";
        string line;
        getline(cin, line);
        stringstream ss(line);
        int num;
        while (ss >> num) {
            flatInput.push_back(num);
        }
    }

    if (!isValid(flatInput)) return false;

    // converts the flat inputs into a 3x3 grid
    state.clear();
    for (int i = 0; i < 3; ++i) {
        vector<int> row(flatInput.begin() + i * 3, flatInput.begin() + (i + 1) * 3);
        state.push_back(row);
    }
    return true;
}

// log puzzle block states with input in the terminal
void Puzzle::printState() const {
    cout << "\nPuzzle state:\n";
    for (const auto& row : state) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
    cout << endl;
}

// vectorize getting a state
vector<vector<int>> Puzzle::getState() const {
    return state;
}
