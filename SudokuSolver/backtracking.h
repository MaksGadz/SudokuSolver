//
// Created by maksi on 30.06.23.
//

#ifndef UNTITLED_BACKTRACKING_H
#define UNTITLED_BACKTRACKING_H

int isRowSafe(struct Board *brd, int row, int num);
int isColSafe(struct Board *brd, int col, int num);
int isBoxSafe(struct Board *brd, int startRow, int startCol, int num);
int isSafe(struct Board *brd, int row, int col, int num);
int findUnassignedLocation(struct Board *brd, int *row, int *col);
int backtracking(struct Board *brd);

#endif //UNTITLED_BACKTRACKING_H
