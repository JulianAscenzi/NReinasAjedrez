#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int file, int col, vector<int>& board) {
    for (int i = 0; i < file; i++) {
        // board[i] = col where the queen is the i file
        if (board[i] == col)
            return false; // same col

        if (abs(board[i] - col) == abs(i - file))
            return false; // same diagonal
    }
    return true;
}

void solve(int n, int file, vector<int>& board) {
    if (file == n)
    {
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (j == board[i]){
                    cout << 'Q' << ' ';
                } else cout << '.' << ' ';
            }
            cout << '\n';
        }
        cout << "\n";
        return;
    }
    
    for (int col = 0; col < n; col++){
        // if isSafe put the queen
        if (isSafe(file, col, board)){
            board[file] = col;
            solve(n,file + 1,board);
            board[file] = -1;
        }
    }
}

int main(){
    int n;
    cin >> n;
    if (n < 1){
        return 0;
    }
    vector<int> board(n, -1);
    solve(n, 0, board);
}