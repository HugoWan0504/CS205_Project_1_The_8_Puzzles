void Solver::solve() {
    vector<vector<int>> initial = puzzle.getState();

    // Priority queue (min-heap) for A*/UCS based on f(n) = g(n) + h(n)
    priority_queue<Node*, vector<Node*>, CompareNodes> frontier;
    unordered_set<string> visited;

    // Calculate initial heuristic based on strategy
    int h = 0;
    if (strategy == MISPLACED_TILE)
        h = misplacedTile(initial);
    else if (strategy == MANHATTAN_DISTANCE)
        h = manhattanDistance(initial);
    // If strategy is UCS, h stays 0

    // Create the root node
    Node* start = new Node(initial, 0, h, {});
    frontier.push(start);

    int nodesExpanded = 0;
    int maxQueueSize = 1;

    while (!frontier.empty()) {
        Node* current = frontier.top();
        frontier.pop();

        string currKey = serializeState(current->state);
        if (visited.count(currKey)) continue; // Skip repeated states

        visited.insert(currKey);
        nodesExpanded++;
        maxQueueSize = max(maxQueueSize, (int)frontier.size());

        // Print each node expansion
        cout << "Expanding node with g(n) = " << current->g
             << ", h(n) = " << current->h
             << ", f(n) = " << current->g + current->h << ":\n";
        for (const auto& row : current->state) {
            for (int val : row) cout << val << " ";
            cout << "\n";
        }
        cout << "\n";

        // Check if reach the goal
        if (current->state == GOAL_STATE) {
            cout << "Goal state reached!\n\n";

            // Combine path (history of nodes) + current node
            vector<Node*> fullPath = current->path;
            fullPath.push_back(current);

            // Traceback: print each step from start to goal
            for (int step = 0; step < fullPath.size(); ++step) {
                Node* node = fullPath[step];
                cout << "Step " << step << ": g(n)=" << node->g
                     << ", h(n)=" << node->h
                     << ", f(n)=" << node->g + node->h << "\n";

                // Current Puzzle State 
                for (const auto& row : node->state) {
                    for (int val : row) cout << val << " ";
                    cout << "\n";
                }
                cout << "\n";
            }

            // Final statistics
            cout << "Solution depth: " << current->g << "\n";
            cout << "Nodes expanded: " << nodesExpanded << "\n";
            cout << "Max queue size: " << maxQueueSize << "\n";
            return;
        }

        // Expand current node in all 4 directions (up, down, left, right)
        pair<int, int> blank = findBlank(current->state);

        for (const auto& dir : directions) {
            int newRow = blank.first + dir.first;
            int newCol = blank.second + dir.second;

            if (!isValid(newRow, newCol)) continue;

            // Generate new state by swapping blank with its neighbors
            vector<vector<int>> newState = current->state;
            swap(newState[blank.first][blank.second], newState[newRow][newCol]);

            string newKey = serializeState(newState);
            if (visited.count(newKey)) continue; // avoid looping forever

            // Compute heuristic if needed
            int new_h = 0;
            if (strategy == MISPLACED_TILE)
                new_h = misplacedTile(newState);
            else if (strategy == MANHATTAN_DISTANCE)
                new_h = manhattanDistance(newState);

            // Build path history
            vector<Node*> newPath = current->path;
            newPath.push_back(current);

            // Create new child node and add to frontier
            Node* child = new Node(newState, current->g + 1, new_h, newPath);
            frontier.push(child);
        }
    }

    // If no solution found, output a failure message
    cout << "Failure: No solution found.\n";
}
