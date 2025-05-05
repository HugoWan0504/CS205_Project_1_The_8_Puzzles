#include "puzzle.h"

// 3x3 grid puzzle
Puzzle::Puzzle() {
    state = vector<vector<int>>(3, vector<int>(3, 0));
}

// default puzzle
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
    if (flatInput.size() != 9) return false;

    unordered_set<int> seen;
    for (int num : flatInput) {
        if (num < 0 || num > 8 || seen.count(num)) return false;
        seen.insert(num);
    }
    return true;
}

// Custom puzzle digit inputs setup
bool Puzzle::loadFromInput() {
    cout << "Enter your puzzle row-by-row (use 0 for blank):\n";

    vector<int> flatInput;
    for (int i = 0; i < 3; ++i) {
        cout << "Row " << (i + 1) << ": ";
        string line;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // clear input buffer
        getline(cin, line);
        stringstream ss(line);
        int num;
        while (ss >> num) {
            flatInput.push_back(num);
        }
    }

    if (!isValid(flatInput)) return false;

    state.clear();
    for (int i = 0; i < 3; ++i) {
        vector<int> row(flatInput.begin() + i * 3, flatInput.begin() + (i + 1) * 3);
        state.push_back(row);
    }
    return true;
}

// show puzzle state with values
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

vector<vector<int>> Puzzle::getState() const {
    return state;
}
