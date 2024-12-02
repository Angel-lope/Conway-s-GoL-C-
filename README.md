PSEUDOCODE OF OUR CONWAYS GAME OF LIFE

MAIN FUNCTION:
1. Display options to the user:
   - Option 1: Random simulation.
   - Option 2: Glider gun simulation (predefined setup from file).
   - Option 3: Simulation with extended neighbor scan range.
   - Option 4: Custom configuration via mouse input.

2. Read user's choice (option):
   - For options 1, 2, or 4:
     - Set grid size to 50x50, cell size to 15, neighbor range to 1, and standard rules.
   - For option 3:
     - Set grid size to 520x700, cell size to 2, neighbor range to 5, and extended rules.
   - If input is invalid, exit the program.

3. Initialize the game board:
   - For option 1 or 3: Randomly initialize cells (alive or dead).
   - For option 2: Read glider gun pattern from a file.
   - Option 4: Leave board empty for user input.

4. Create a graphical window using SFML with size based on the grid dimensions.

5. Start a separate thread to continuously:
   - Update the game board using the rules of Conway's Game of Life.

6. While the graphical window is open:
   - Check for user events (close window or mouse input for custom configuration).
   - Render the game board in the window.

7. Once the window is closed:
   - Stop the update thread and exit.

---

FUNCTIONS:
- **initializeRandomBoard(board, rows, columns):**
  - Populate the board with random alive (`1`) or dead (`0`) cells.

- **initializeBoardFromFile(board, rows, columns, filename):**
  - Open a file and read predefined cell positions. Mark these cells as alive on the board.

- **handleMouseInput(window, board, rows, columns, cellSize):**
  - Check if the user clicks a cell.
  - Convert mouse coordinates to cell indices and set the clicked cell to alive (`1`).

- **drawBoard(window, board, rows, columns, cellSize):**
  - Iterate over the board:
    - Draw a green rectangle for alive cells and a black rectangle for dead cells.
  - Display the cells on the graphical window.

- **countNeighbors(board, row, col, rows, columns, range):**
  - Count the number of alive neighbors within a specified range around the cell at `(row, col)`.
  - Use modular arithmetic for wrapping edges of the board.

- **applyRules(neighbors, currentState, useExtendedRules):**
  - Apply the standard or extended Game of Life rules to decide the next state of a cell:
    - Standard rules:
      - Alive cells survive with 2 or 3 neighbors.
      - Dead cells come alive with exactly 3 neighbors.
    - Extended rules:
      - Custom thresholds for cell survival or death.

- **updateBoard(board, newBoard, rows, columns, range, useExtendedRules):**
  - For each cell, count neighbors and determine the next state using `applyRules`.
  - Update the board efficiently by swapping with a temporary board.


