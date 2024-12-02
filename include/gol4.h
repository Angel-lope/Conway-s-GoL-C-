#ifndef GOL4_H
#define GOL4_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

namespace GameOfLife {

    /**
     * @brief Initializes the board with random alive cells.
     *
     * @param board The board represented as a vector of integers.
     * @param rows The number of rows in the board.
     * @param columns The number of columns in the board.
     */
    void initializeRandomBoard(std::vector<int>& board, int rows, int columns);

    /**
     * @brief Initializes the board from a given file.
     *
     * @param board The board represented as a vector of integers.
     * @param rows The number of rows in the board.
     * @param columns The number of columns in the board.
     * @param filename The name of the file containing the initial board state.
     */
    void initializeBoardFromFile(std::vector<int>& board, int rows, int columns, const std::string& filename);

    /**
     * @brief Handles mouse input for setting cells alive.
     *
     * @param window The SFML window instance.
     * @param board The board represented as a vector of integers.
     * @param rows The number of rows in the board.
     * @param columns The number of columns in the board.
     * @param cellSize The size of each cell.
     */
    void handleMouseInput(sf::RenderWindow& window, std::vector<int>& board, int rows, int columns, int cellSize);

    /**
     * @brief Draws the board on the given SFML window.
     *
     * @param window The SFML window instance.
     * @param board The board represented as a vector of integers.
     * @param rows The number of rows in the board.
     * @param columns The number of columns in the board.
     * @param cellSize The size of each cell.
     */
    void drawBoard(sf::RenderWindow& window, const std::vector<int>& board, int rows, int columns, int cellSize);

    /**
     * @brief Counts the number of living neighbors for a cell.
     *
     * @param board The board represented as a vector of integers.
     * @param row The row of the cell.
     * @param col The column of the cell.
     * @param rows The number of rows in the board.
     * @param columns The number of columns in the board.
     * @param range The scan range for neighbors.
     * @return int The number of living neighbors.
     */
    int countNeighbors(const std::vector<int>& board, int row, int col, int rows, int columns, int range);

    /**
     * @brief Applies the rules of Conway's Game of Life.
     *
     * @param neighbors The number of living neighbors.
     * @param currentState The current state of the cell (alive or dead).
     * @param useExtendedRules Flag to determine if extended rules should be applied.
     * @return int The new state of the cell (alive or dead).
     */
    int applyRules(int neighbors, int currentState, bool useExtendedRules);

    /**
     * @brief Updates the board according to the Game of Life rules.
     *
     * @param board The board represented as a vector of integers.
     * @param newBoard A temporary board used to compute the new state.
     * @param rows The number of rows in the board.
     * @param columns The number of columns in the board.
     * @param range The scan range for neighbors.
     * @param useExtendedRules Flag to determine if extended rules should be applied.
     */
    void updateBoard(std::vector<int>& board, std::vector<int>& newBoard, int rows, int columns, int range, bool useExtendedRules);

}

#endif // GOL4_H
