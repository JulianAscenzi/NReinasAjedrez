#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<int>& board) {
    for (int i = 0; i < row; i++) {
        // board[i] = col where the queen is in row i
        if (board[i] == col) {
            return false; // same col
        }
        if (abs(board[i] - col) == abs(i - row)) {
            return false; // same diagonal
        }
    }
    return true;
}

void solve(int n, int row, vector<int>& board, int& count) {
    if (row == n) {
        count++;
        cout << "Solution " << count << ":\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == board[i]) {
                    cout << 'Q' << ' ';
                } else {
                    cout << '.' << ' ';
                }
            }
            cout << '\n';
        }
        cout << "\n";
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, board)) {
            board[row] = col;
            solve(n, row + 1, board, count);
            board[row] = -1;
        }
    }
}

int main() {
    int n = 0;
    while (n < 1 || n > 12) {
        cout << "Enter the number of queens (1-12): ";
        cin >> n;
        if (n < 1) {
            cout << "Error: the number of queens must be greater than 0.\n";
        } else if (n > 12) {
            cout << "Error: please enter a value <= 12 to avoid excessive output.\n";
        }
    }

    vector<int> board(n, -1);
    int count = 0;
    solve(n, 0, board, count);

    cout << "Total solutions for N=" << n << ": " << count << "\n";
}