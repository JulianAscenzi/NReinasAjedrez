#include <iostream>
#include <vector>

bool isSafe(int board[], int file, int col) {
    for (int i = 0; i < file; i++) {
        // board[i] = col where the queen is the i file
        if (board[i] == col)
            return false; // same col

        if (abs(board[i] - col) == abs(i - file))
            return false; // same diagonal
    }
    return true;
}

