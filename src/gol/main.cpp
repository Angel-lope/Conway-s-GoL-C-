#include "gol4.h" 
#include <iostream> 
#include <SFML/Graphics.hpp> 
#include <vector> 
#include <thread>
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
        GameOfLife::initializeRandomBoard(board, rows, columns);
    } else if (option == 2) {
        GameOfLife::initializeBoardFromFile(board, rows, columns, "gol.txt");
    } else if (option == 3) {
        GameOfLife::initializeRandomBoard(board, rows, columns);
    }

    sf::RenderWindow window(sf::VideoMode(columns * cellSize, rows * cellSize), "Game of Life");
    std::thread updateThread([&]() {
        while (window.isOpen()) {
            GameOfLife::updateBoard(board, newBoard, rows, columns, range, useExtendedRules);
            sf::sleep(sf::milliseconds(100)); // Adjust speed as needed
        }
    });

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (option == 4) {
                GameOfLife::handleMouseInput(window, board, rows, columns, cellSize);
            }
        }
        window.clear(sf::Color::White);
        GameOfLife::drawBoard(window, board, rows, columns, cellSize);
        window.display();
    }

    updateThread.join();

    return 0;
}
