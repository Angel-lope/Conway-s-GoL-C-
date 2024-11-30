#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <thread>
#include <vector>

// Initialize a board with random alive cells
void initializeRandomBoard(std::vector<int>& board, int rows, int columns) {
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < rows * columns; ++i) {
        board[i] = rand() % 2; // 0 for dead, 1 for alive
    }
}

// Reads from a file and places the cells in each correct place
void initializeBoardFromFile(std::vector<int>& board, int rows, int columns, const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }
    int row, col;
    while (file >> row >> col) {
        if (row >= 0 && row < rows && col >= 0 && col < columns) {
            board[row * columns + col] = 1;
        }
    }
}

// Allows the user to mouse input the cells
void handleMouseInput(sf::RenderWindow& window, std::vector<int>& board, int rows, int columns, int cellSize) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        int col = mousePos.x / cellSize;
        int row = mousePos.y / cellSize;
        if (col >= 0 && col < columns && row >= 0 && row < rows) {
            board[row * columns + col] = 1;
        }
    }
}

// SFML board
void drawBoard(sf::RenderWindow& window, const std::vector<int>& board, int rows, int columns, int cellSize) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
            cell.setPosition(j * cellSize, i * cellSize);
            if (board[i * columns + j] == 1) {
                cell.setFillColor(sf::Color::Green); // Alive cell
            } else {
                cell.setFillColor(sf::Color::Black); // Dead cell
            }
            window.draw(cell);
        }
    }
}

// Counts the alive neighbours a cell has
int countNeighbors(const std::vector<int>& board, int row, int col, int rows, int columns, int range) {
    int livingNeighbors = 0;
    for (int i = -range; i <= range; ++i) {
        for (int j = -range; j <= range; ++j) {
            if (i == 0 && j == 0) continue; // Skips the cell itself
            int neighborRow = (row + i + rows) % rows;
            int neighborCol = (col + j + columns) % columns;
            livingNeighbors += board[neighborRow * columns + neighborCol];
        }
    }
    return livingNeighbors;
}

// Apply the rules of Conways Game of Life
int applyRules(int neighbors, int currentState, bool useExtendedRules) {
    if (useExtendedRules) {
        if (neighbors >= 0 && neighbors <= 33) {
            return 0;
        } else if (neighbors >= 34 && neighbors <= 45) {
            return 1;
        } else if (neighbors >= 58 && neighbors <= 121) {
            return 0;
        }
    } else {
        if (currentState == 1) { // Alive cell
            return (neighbors == 2 || neighbors == 3) ? 1 : 0;
        } else { // Dead cell
            return (neighbors == 3) ? 1 : 0;
        }
    }
    return currentState; // Keeps the same state if no rule applies
}

// Updates the board following the CGoL rules
void updateBoard(std::vector<int>& board, std::vector<int>& newBoard, int rows, int columns, int range, bool useExtendedRules) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            int neighbors = countNeighbors(board, i, j, rows, columns, range);
            newBoard[i * columns + j] = applyRules(neighbors, board[i * columns + j], useExtendedRules);
        }
    }
    board.swap(newBoard); // Efficiently updates the board
}

int main() {
    int option;
    int rows, columns, cellSize, range;
    bool useExtendedRules;

    std::cout << "What would you like to see? \n";
    std::cout << "For random simulation press 1\n";
    std::cout << "For glider gun simulation press 2\n";
    std::cout << "For simulation with extended cell scan range press 3\n";
    std::cout << "For custom configuration press 4\n";
    std::cin >> option;

    if (option == 1 || option == 2 || option == 4) {
        rows = 50;
        columns = 50;
        cellSize = 15;
        range = 1;
        useExtendedRules = false;
    } 
    // I decided to create a bigger grid for the extended range option because its easier to see how
    // the game changes just by changing the scan range
    else if (option == 3) {  
        rows = 520;
        columns = 700;
        cellSize = 2;
        range = 5;
        useExtendedRules = true;
    } else {
        std::cout << "Invalid option. Exiting program.\n";
        return 0;
    }

    std::vector<int> board(rows * columns, 0);
    std::vector<int> newBoard(rows * columns, 0);

    if (option == 1) {
        initializeRandomBoard(board, rows, columns);
    } else if (option == 2) {
        initializeBoardFromFile(board, rows, columns, "gol.txt");
    } else if (option == 3) {
        initializeRandomBoard(board, rows, columns);
    }

    sf::RenderWindow window(sf::VideoMode(columns * cellSize, rows * cellSize), "Game of Life");
    std::thread updateThread([&]() {
        while (window.isOpen()) {
            updateBoard(board, newBoard, rows, columns, range, useExtendedRules);
            sf::sleep(sf::milliseconds(100)); // Adjust speed as needed
        }
    });

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (option == 4) {
                handleMouseInput(window, board, rows, columns, cellSize);
            }
        }
        window.clear(sf::Color::White);
        drawBoard(window, board, rows, columns, cellSize);
        window.display();
    }

    updateThread.join();

    return 0;
}
