# CS205_Project_1_The_8_Puzzles

### Content
* PDF report: (link, add in later)
* Cover page: 1st page 
* Summary Report page(s): ? page
* Coding page(s): ? page
* Traceback page(s): ? page


### How to play? (1st Draft)
* Open terminal and compile the code using the following command: g++ -o eight_puzzle main.cpp
* Run the program with: ./eight_puzzle
* The interface will show up for users to choose where they want to play a default eight-puzzle or a custom eight-puzzle.
* Default eight-puzzle is easy and coded for the functionalities of the game. A custom eight-puzzle allows the users to enter numbers from 0 to 8, three numbers in each row (3 total rows) of their created puzzles.
* The puzzle can only start if the numbers were vaild (All numbers are presented on the puzzle). 
* If the numbers on the puzzle is invalid, it will output the invalid game message and restart the game. The game is invalid if there are more than one of each number from 0 to 8 presented on the puzzle, means that all number can only appears once in each game.
* After choosing the puzzle to play, the users will then see an interface that asks the users which algorithms they want to use to solve their chosen puzzles. 
* The choices are:  1. Uniform Cost Search  2. A* with the Misplaced Tile heuristic  3. A* with the Manhattan Distance heuristic
* Then, the terminal will output each step with the corresponding algorithm and evenutally get the solved puzzle of the eight-puzzle. Also, they will get the depth of the solution, the numbers of the modes expanded, and the max queue size of each game.
* Finally, when the game ends, it will ask the users in the terminal whether they want to start another game or end program. Enter "Y/y" to restart game; enter "N/n" to end the program.