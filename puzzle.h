#ifndef PUZZLE_H
#define PUZZLE_H

#include <bits/stdc++.h>
using namespace std;

class Puzzle {
public:
    Puzzle();
    void loadDefault();
    bool loadFromInput();
    void printState() const;
    vector<vector<int>> getState() const;

private:
    vector<vector<int>> state; // 3x3 grid
    bool isValid(const vector<int>& flatInput) const;
};

#endif
