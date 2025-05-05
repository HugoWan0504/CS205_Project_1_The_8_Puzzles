#ifndef SOLVER_H
#define SOLVER_H

#include <bits/stdc++.h>
#include "puzzle.h"
using namespace std;

enum SearchType {
    UNIFORM_COST = 1,
    MISPLACED_TILE = 2,
    MANHATTAN_DISTANCE = 3
};

class Solver {
public:
    Solver(const Puzzle& puzzle, SearchType type);
    void solve();
    // void printSummary() const;

private:
    Puzzle puzzle;
    SearchType strategy;
};

#endif
