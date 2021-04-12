#include "grid.h"

Grid<char> createEmptyBoard() {
    Grid<char> board(3, 3);
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            board[row][col] = ' ';
        }
    }
    return board;
}

int main() {
    createEmptyBoard();
}