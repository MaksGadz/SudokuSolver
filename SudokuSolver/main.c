#include "init.h"
#include "backtracking.h"

int main() {

    struct Board brd = initBoard(9);
    char s[] = "- - - - - - - 1 2;"
               "- - - - 3 5 - - -;"
               "- - - 6 - - - 7 -;"
               "7 - - - - - 3 - -;"
               "- - - 4 - - 8 - -;"
               "1 - - - - - - - -;"
               "- - - 1 2 - - - -;"
               "- 8 - - - - - 4 -;"
               "- 5 - - - - 6 - -;";

    fillBoard(&brd, s);
    backtracking(&brd);
    printBoard(brd);
  return 0;
}
