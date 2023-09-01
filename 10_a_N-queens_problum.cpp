#include <iostream>

using namespace std;

bool isSafe(int board[], int row, int col, int N) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void printBoard(int board[], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i] == j ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

void solveNQueensUtil(int board[], int row, int N) {
    if (row == N) {
        printBoard(board, N);
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row] = col;
            solveNQueensUtil(board, row + 1, N);
        }
    }
}

void solveNQueens(int N) {
    int board[N];
    solveNQueensUtil(board, 0, N);
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
    solveNQueens(N);
    return 0;
}
