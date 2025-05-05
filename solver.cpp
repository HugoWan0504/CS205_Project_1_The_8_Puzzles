#include <bits/stdc++.h>
#include "solver.h"
#include "heuristics.h"
using namespace std;

struct Node {
    vector<vector<int>> state; // 3x3 state
    int g; // g(n), path cost from initial state
    int h; // h(n), heuristic value
    vector<Node*> path; // to redirect the path to current state

    Node(const vector<vector<int>>& s, int g_val, int h_val, const vector<Node*>& p)
        : state(s), g(g_val), h(h_val), path(p) {}
};

// prioritize nodes with lowest f(n) = g(n) + h(n) using min heap
struct CompareNodes {
    bool operator()(const Node* a, const Node* b) const {
        return (a->g + a->h) > (b->g + b->h);
    }
};

// The unified goal state for my 8-puzzle
// 0 stands for blank
const vector<vector<int>> GOAL_STATE = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}
};

// Converts puzzle state to a string for hashing / visited tracking
string serializeState(const vector<vector<int>>& state) {
    stringstream ss;
    for (const auto& row : state) {
        for (int num : row) ss << num;
    }
    return ss.str();
}

// Finds the position of the 0 (blank tile)
pair<int, int> findBlank(const vector<vector<int>>& state) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (state[i][j] == 0)
                return {i, j};
    return {-1, -1}; // should never happen
}

// All four move directions: up, down, left, right
const vector<pair<int, int>> directions = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

// Checks if a position is within bounds
bool isValid(int row, int col) {
    return row >= 0 && row < 3 && col >= 0 && col < 3;
}

// Solver class implementation
Solver::Solver(const Puzzle& puzzle, SearchType type)
    : puzzle(puzzle), strategy(type) {}

void Solver::solve() {
    vector<vector<int>> initial = puzzle.getState();
    priority_queue<Node*, vector<Node*>, CompareNodes> frontier;
    unordered_set<string> visited;

    // Compute initial heuristic value
    int h = 0;
    if (strategy == MISPLACED_TILE)
        h = misplacedTile(initial);
    else if (strategy == MANHATTAN_DISTANCE)
        h = manhattanDistance(initial);
    // UCS => h stays 0

    Node* start = new Node(initial, 0, h, {});
    frontier.push(start);

    int nodesExpanded = 0;
    int maxQueueSize = 1;

    while (!frontier.empty()) {
        Node* current = frontier.top();
        frontier.pop();

        string currKey = serializeState(current->state);
        if (visited.count(currKey)) continue; // skip if already visited

        visited.insert(currKey);
        nodesExpanded++;
        maxQueueSize = max(maxQueueSize, (int)frontier.size());

        // Print current state and cost info
        cout << "Expanding node with g(n) = " << current->g
             << ", h(n) = " << current->h << ", f(n) = "
             << current->g + current->h << ":\n";
        for (const auto& row : current->state) {
            for (int val : row) cout << val << " ";
            cout << "\n";
        }
        cout << "\n";

        // Check goal
        if (current->state == GOAL_STATE) {
            cout << "Goal state reached!\n";
            cout << "Solution depth: " << current->g << "\n";
            cout << "Nodes expanded: " << nodesExpanded << "\n";
            cout << "Max queue size: " << maxQueueSize << "\n";
            return;
        }

        // Locate blank tile
        pair<int, int> blank = findBlank(current->state);

        // Expand all valid moves
        for (const auto& dir : directions) {
            int newRow = blank.first + dir.first;
            int newCol = blank.second + dir.second;

            if (!isValid(newRow, newCol)) continue;

            // Copy current state and perform swap
            vector<vector<int>> newState = current->state;
            swap(newState[blank.first][blank.second], newState[newRow][newCol]);

            string newKey = serializeState(newState);
            if (visited.count(newKey)) continue;

            int new_h = 0;
            if (strategy == MISPLACED_TILE)
                new_h = misplacedTile(newState);
            else if (strategy == MANHATTAN_DISTANCE)
                new_h = manhattanDistance(newState);

            vector<Node*> newPath = current->path;
            newPath.push_back(current);

            Node* child = new Node(newState, current->g + 1, new_h, newPath);
            frontier.push(child);
        }
    }

    cout << "Failure: No solution found.\n";
}

/*
void Solver::printSummary() const {
    // Currently prints nothing extra — logic is inside solve()
    // Could be used to print final path later
}
*/
