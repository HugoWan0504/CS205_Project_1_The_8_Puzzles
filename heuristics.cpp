#include <bits/stdc++.h>
#include "heuristics.h"
using namespace std;

// Goal state
const vector<vector<int>> GOAL = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}
};

// returns a tile's (row, col) in the goal state
pair<int, int> findGoalPosition(int tile) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (GOAL[i][j] == tile)
                return {i, j};
    return {-1, -1}; // error breakpoint
}

// A* + Misplaced Tiles
int misplacedTile(const vector<vector<int>>& state) {
    int count = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (state[i][j] != 0 && state[i][j] != GOAL[i][j])
                count++; // h(n) += 1 in AMT
    return count; // h(n)
}

// A* + Manhattan Distances
int manhattanDistance(const vector<vector<int>>& state) {
    int total = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int val = state[i][j];
            if (val != 0) {
                pair<int, int> goalPos = findGoalPosition(val);
                // sum of the h(n) in AMD
                total += abs(i - goalPos.first) + abs(j - goalPos.second);
            }
        }
    }
    return total; // h(n)
}
