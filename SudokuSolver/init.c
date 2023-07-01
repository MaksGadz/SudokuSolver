#include "init.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct Board initBoard(int size){
  struct Board brd;
  brd.size = size;
  
  brd.field = malloc(size * sizeof(int *));
  for (size_t i = 0; i < size; i++)   
    brd.field[i] = malloc(size * sizeof(int));

  return brd;
}

void printBoard(struct Board brd){
  for (int i = 0; i < brd.size; i++) {
      for (int j = 0; j < brd.size; j++) {
          printf(" %d ", brd.field[i][j]);
          if ((j+1) % 3 == 0 && j+1 != brd.size)
              printf(" ");
      }
      if ((i+1) % 3 == 0){
          printf("\n");
      }
      printf("\n");
  }
}

void fillBoard(struct Board *brd, char *s) {

    char *outerToken;
    char *innerToken;
    char *outerContext = NULL;
    char *innerContext = NULL;

    outerToken = strtok_r(s, ";", &outerContext);
    int row = 0;
    while (outerToken) {
        int col = 0;
        innerToken = strtok_r(outerToken, " ", &innerContext);
        while (innerToken) {
            if (strcmp(innerToken, "-") == 0)
                brd->field[row][col] = -1;
            else
                brd->field[row][col] = atoi(innerToken);
            col++;
            innerToken = strtok_r(NULL, " ", &innerContext);
        }
        row++;
        outerToken = strtok_r(NULL, ";", &outerContext);
    }
}
