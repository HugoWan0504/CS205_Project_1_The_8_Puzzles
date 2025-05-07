# CS205 Project 1 The 8 Puzzles by Hugo Wan, 862180666, twan012

### Content
* PDF report: (link, add in later)
* Current github link: https://github.com/HugoWan0504/CS205_Project_1_The_8_Puzzles

### How to play?

# 1. Getting Started
* Open terminal and compile the code using the following command: make
* Run the program with: ./eight_puzzle

# 2. Interface - Choosing a Puzzle
* After running the program, the terminal will prompt users to select between these two puzzle methods:
* 1. Default 8-puzzle, coded for simple testings and demostration.
* 2. Custom 8-puzzle, allow users to create their own puzzles by manually entering the numbers in each row. 
* For the custom puzzle, the user must input three rows with three numbers each, using the digits 0 to 8, where 0 represents the blank tile.

# 3. Rules for Valid Puzzle Input
* Puzzle is only valid under these conditions:
* 1. The puzzle must include all numbers from 0 to 8 exactly once.
* 2. When entering the numbers, each row should have exactly three values, and the number inputs must be separated by spaces.
* A valid puzzle should look like this:
  - Enter the first row: 1 2 3
  - Enter the second row: 4 0 5
  - Enter the third row: 6 7 8
* If the input does NOT meet these requirements, it will be considered invalid, which the program will print an "Invalid Puzzle" message and restart the setup process.
* Here are the example of invalid puzzles:
 - Missing a number: no 0
 - Duplicated numbers: two 3's
 - Fewer or more than 9 total digits (< 0 or > 8)

# 4. Interface - Choosing a Search Algorithm
* After creating a valid puzzle, the program will prompt users to select a search strategy in the terminal:
* 1. Uniform Cose Search (UCS)
* 2. A* with the Misplaced Tile heuristic (AMT)
* 3. A* with the Manhattan Distance heuristic (AMD)
* Each algorithm will attempt to find the optimal path from the initial puzzle state to the goal state


# 5. Output Format and Game Result
* During execution, the program will display:
* 1. The best puzzle state chosen to expand at each step
* 2. The corresponding values of g(n), h(n), and f(n) for A*-based searches
* 3. The final goal state, which is unified and look like this:
  - The first row: 1 2 3
  - The second row: 4 5 6
  - The third row: 7 8 0
* At the end of the game, users will see a summary including:
* 1. Solution depth (number of moves from initial to goal)
* 2. Total number of nodes expanded
* 3. Maximum queue size during the search process

# 6. Restart or Exit
* After solving the puzzle, the terminal will prompt:
 - "Would you like to play again? (Y/y = Yes, N/n = No): "
 - Asking the user to enter 'Y' or 'y' to restart, 'N' or 'n' to exit the program.