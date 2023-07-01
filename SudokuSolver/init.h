
struct Board {
  int size;
  int **field;
};

struct Board initBoard(int size);
void fillBoard(struct Board *brd, char *s);
void printBoard(struct Board brd);

