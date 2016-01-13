class Board {
private:
  char board[10];
  int active;
public:
  Board();
  void act_board(int num); //activate board
  void place(int coord, char piece);
  char boardWin();
  void print();
  void clean();
  bool finished();
};
bool horizontal(char board[10], char piece);
bool vertical(char board[10], char piece);
bool diagonal(char board[10], char piece);
