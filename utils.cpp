#include <bits/stdc++.h>
#include "utils.h"
using namespace std;

// Parses a space-separated string into integers for one row
vector<int> parseRow(const string& input) {
    vector<int> row;
    stringstream ss(input);
    int num;

    while (ss >> num) {
        row.push_back(num);
    }

    return row;
}

// Checks if the input contains all digits from 0 to 8 exactly once
bool isUniqueDigitsZeroToEight(const vector<int>& values) {
    if (values.size() != 9) return false;

    unordered_set<int> seen;
    for (int num : values) {
        // invalid number or duplicate
        if (num < 0 || num > 8 || seen.count(num)) {
            return false;
        }
        seen.insert(num);
    }

    return true;
}

// convert the puzzle state to a string
std::string serializeState(const std::vector<std::vector<int>>& state) {
    std::string result;
    for (const auto& row : state)
        for (int val : row)
            result += std::to_string(val);
    return result;
}

