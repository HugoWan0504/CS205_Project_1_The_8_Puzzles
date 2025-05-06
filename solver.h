#ifndef SOLVER_H
#define SOLVER_H

#include <bits/stdc++.h>
#include "puzzle.h"
using namespace std;

// Enumeration to select which algorithm to use
enum SearchType {
    UNIFORM_COST = 1,
    MISPLACED_TILE = 2,
    MANHATTAN_DISTANCE = 3
};

// Node struct: represents a puzzle state and path info
struct Node {
    vector<vector<int>> state;     // 3x3 puzzle board
    int g;                         // g(n): cost from start node
    int h;                         // h(n): heuristic cost to goal
    vector<Node*> path;            // backtrack path to this node

    Node(const vector<vector<int>>& s, int g_val, int h_val, const vector<Node*>& p)
        : state(s), g(g_val), h(h_val), path(p) {}
};

// priority queue (min-heap by f(n) = g(n) + h(n))
struct CompareNodes {
    bool operator()(const Node* a, const Node* b) const {
        return (a->g + a->h) > (b->g + b->h); // lower f(n) = higher priority
    }
};

// Solver class: 
// A Puzzle + A Search Strategy
// Then, solves it
class Solver {
public:
    Solver(const Puzzle& puzzle, SearchType type);
    void solve();

private:
    Puzzle puzzle;
    SearchType strategy;
};

#endif
