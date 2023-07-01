#include "init.h"

int isRowSafe(struct Board *brd, int row, int num) {
    for (int col = 0; col < brd->size; col++) {
        if (brd->field[row][col] == num)
            return 0;
    }
    return 1;
}

int isColSafe(struct Board *brd, int col, int num) {
    for (int row = 0; row < brd->size; row++) {
        if (brd->field[row][col] == num)
            return 0;
    }
    return 1;
}

int isBoxSafe(struct Board *brd, int startRow, int startCol, int num){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (brd->field[i + startRow][j + startCol] == num)
                return 0;
        }
    }
    return 1;
}

int isSafe(struct Board *brd, int row, int col, int num) {
    return isRowSafe(brd, row, num) &&
           isColSafe(brd, col, num) &&
           isBoxSafe(brd, row - (row % 3), col - (col % 3), num);
}

int findUnassignedLocation(struct Board *brd, int *row, int *col) {
    for (*row = 0; *row < brd->size; (*row)++) {
        for (*col = 0; *col < brd->size; (*col)++) {
            if (brd->field[*row][*col] == -1)
                return 1;
        }
    }
    return 0;
}

int backtracking(struct Board *brd) {
    int row, col;

    // Find unassigned field.
    if (!findUnassignedLocation(brd, &row, &col))
        return 1;

    // Check if num is possible candidate and set it.
    for (int num = 1; num <= brd->size; num++) {
        if (isSafe(brd, row, col, num)) {
            brd->field[row][col] = num;

            // Sudoku solved.
            if (backtracking(brd) == 1)
                return 1;

            // Undo field.
            brd->field[row][col] = -1;
        }
    }
    return 0;
}