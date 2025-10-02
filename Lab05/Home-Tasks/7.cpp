#include <iostream>
using namespace std;

//global board max 12 for demonstration, can change
int board[12][12] = {0};
int N = 8; //default size


bool isSafe(int r, int c) {
    //column
    for(int i = 0; i < r; i++) {
        if(board[i][c] == 1)
            return false;
    }

    //topleft diagonal
    for(int i = r-1, j = c-1; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 1)
            return false;
    }

    //top right diagonal
    for(int i = r-1, j = c+1; i >= 0 && j < N; i--, j++) {
        if(board[i][j] == 1)
            return false;
    }

    return true;
}

void nQueenSolver(int row, int &solCount) {
    if(row == N) {

        solCount++;
        cout << "solution " << solCount << ":" << endl;
      
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for(int col = 0; col < N; col++) {
        if(isSafe(row, col)) {
            board[row][col] = 1; 
            nQueenSolver(row + 1, solCount); 
            board[row][col] = 0; 
        }
    }
}

int main() {
    cout << "give N for N-Queens (like 4, 8, etc):" << endl;
    cin >> N;
    if(N <= 0 || N > 12) {
        cout << "N invalid(should be 1-12)" << endl;
        return 0;
    }
    int solCount = 0;
    nQueenSolver(0, solCount);
    if(solCount == 0) {
        cout << "no way to place queens for this N" << endl;
    } else {
        cout << "total solutions: " << solCount << endl;
    }
    return 0;
}
