#include <iostream>
using namespace std;

//using global sudoku to make it easier to code
int sudoku[9][9] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

int* getCandidates(int r, int c, int &size) {
    bool used[9] = {false}; 

    // Row and column check
    for(int i = 0; i < 9; i++) {
        if(sudoku[r][i] != 0) 
            used[sudoku[r][i] - 1] = true;
        if(sudoku[i][c] != 0) 
            used[sudoku[i][c] - 1] = true;
    }

    //sub array check
    int subArrRow = (r/3) * 3;
    int subArrCol = (c/3) * 3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            int val = sudoku[subArrRow+i][subArrCol+j];
            if(val != 0) 
                used[val - 1] = true;
        }
    }

    
    int count = 0;
    for(int i = 0; i < 9; i++) {
        if(used[i] == false) 
            count++;
    }


    int* result = new int[count];
    int idx = 0;
    for(int i = 0; i < 9; i++) {
        if(used[i] == false) 
            result[idx++] = i+1;  //stores 1–9
    }

    size = count;
    return result;
}

bool sudokuSolver(int r, int c) {
    if(r == 9)  
        return true;  


    int nextR = (c == 8) ? r + 1 : r;
    int nextC = (c == 8) ? 0 : c + 1;

    if(sudoku[r][c] != 0) {
        return sudokuSolver(nextR, nextC);
    } 
    else 
    {
        //rough algo
        //for any empty place find all the possible elements that can be placed
        //start placing elements from the sol set into the empty cell
        //go onto the next zero cell and do the same
        //if anywhere no candidate is found it means that the solution that has to
        //go at that place has already been placed before
        //start backtracking
        int sizeCandidateList;
        int* candidateList = getCandidates(r, c, sizeCandidateList);

        for(int i = 0; i < sizeCandidateList; i++) {
            sudoku[r][c] = candidateList[i];   

            if(sudokuSolver(nextR, nextC)) {   
                delete[] candidateList;
                return true;  
            }

            sudoku[r][c] = 0; 
        
        }

        delete[] candidateList;
        return false;  
    }
}


void printSudoku() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    if(sudokuSolver(0,0)) {
        cout << "Solved Sudoku:" << endl;
        printSudoku();
    } 
    else 
    {
        cout << "No solution exists." << endl;
    }
    return 0;
}
