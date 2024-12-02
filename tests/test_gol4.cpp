#include <gtest/gtest.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <thread>
#include <vector>
#include "gol4.h"  // Include your header file for function declarations

using namespace GameOfLife;  // Use the correct namespace

TEST(InitializeBoard, RandomBoard) {
    int rows = 10;
    int columns = 10;
    std::vector<int> board(rows * columns, 0);

    initializeRandomBoard(board, rows, columns);

    int aliveCells = 0;
    for (int cell : board) {
        aliveCells += cell;
    }

    EXPECT_GE(aliveCells, 0);
    EXPECT_LE(aliveCells, rows * columns);
}

TEST(InitializeBoard, BoardFromFile) {
    int rows = 10;
    int columns = 10;
    std::vector<int> board(rows * columns, 0);
    std::ofstream outfile("gol4.txt");
    outfile << "5 1\n5 2\n6 1\n6 2\n5 11\n6 11\n7 11\n4 12\n8 12\n3 13\n9 13\n3 14\n9 14\n6 15\n4 16\n8 16\n5 17\n6 17\n7 17\n6 18\n3 21\n4 21\n5 21\n3 22\n4 22\n5 22\n2 23\n6 23\n1 25\n2 25\n6 25\n7 25\n3 35\n4 35\n3 36\n4 36\n";
    outfile.close();

    initializeBoardFromFile(board, rows, columns, "gol4.txt");

    EXPECT_EQ(board[5 * columns + 1], 1);
    EXPECT_EQ(board[5 * columns + 2], 1);
    EXPECT_EQ(board[6 * columns + 1], 1);
    EXPECT_EQ(board[6 * columns + 2], 1);

    // Clean up the test file
    std::remove("gol4.txt");
}
