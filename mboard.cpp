#include <iostream>
#include "mboard.hpp"

using namespace std;

Board::Board()
{
  /*
  @brief Constructor
  initializes the 9 boards
  */
  for (int i = 0; i < 9; i++)
  {
    board[i] = ' ';
  }
  active = 0; //active board
}

void Board::act_board(int num)
{
  /*
  @brief activates a board
  @param num the board number to be activated
  */
  active = num;
}

void Board::place(int coord, char piece)
{
  /*
  @brief places the piece at the right box
  This function places the given piece at the given coordinate of the
  active board.
  @param board the active board
  @param piece either 'X' or 'O'
  @return none
  */
  board[coord-1] = piece;
}

void Board::clean()
{
  /*
  @brief cleans the board
  This function empties the board to make a new active board
  */
  for (int i = 0; i < 9; i++)
  {
    board[i] = ' ';
  }
}

bool Board::finished()
{

  //@brief tells whether the game is finished
  //This function tells whether the game is finished
  //return true if finished, false if not

  int count = 0;
  for (int i = 0; i < 9; i++) // check if there is an empty box
  {
    if (board[i] == ' ')
    {
      count ++;
    }
  }
  if (count == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool horizontal(char board[10], char piece)
{
  /*
  @brief Checks if there is a same piece put in any horizontal rows
  This function checks if whether X or O took over any horizontal lines
  of the board.

  @param board the board to be looked at (3x3 board assumed)
  @param piece the piece to be checked (1 for X, 2 for O)

  @return True if there is horizontal alignment False if there is none
  */
  for (int i = 0; i < 3; i++) // repeat for 3 rows
  {
    if (board[3 * i] == piece) // check first column
    {
      if (board[3 * i + 1] == piece) // check second column
      {
        if (board[3 * i + 2] == piece) // check third column
        {
          return true;
        }
      }
    }
  }
  return false;
}

bool vertical(char board[10], char piece)
{
  /*
  @brief Checks if there is a same piece put in any vertical columns
  This function checks if whether X or O took over any vertical lines
  of the board.

  @param board the board to be looked at (3x3 board assumed)
  @param piece the piece to be checked (1 for X, 2 for O)

  @return True if there is vertical alignment False if there is none
  */
  for (int i = 0; i < 3; i++) // repeat for 3 columns
  {
    if (board[i] == piece) // check first row
    {
      if (board[i + 3] == piece) // check second row
      {
        if (board[i + 6] == piece) // check third row
        {
          return true;
        }
      }
    }
  }
  return false;
}

bool diagonal(char board[10], char piece)
{
  /*
  @brief Checks if there is a same piece put in a diagonal line
  This function checks if whether X or O took over any diagonal lines
  of the board.

  @param board the board to be looked at (3x3 board assumed)
  @param piece the piece to be checked (1 for X, 2 for O)

  @return True if there is a diagonal alignment False if there is none
  */
  /* First diagonal line: line towards right bottom */
  if (board[0] == piece)
  {
    if (board[4] == piece)
    {
      if (board[8] == piece)
      {
        return true;
      }
    }
  }
  else if (board[2] == piece)
  {
    if (board[4] == piece)
    {
      if (board[6] == piece)
      {
        return true;
      }
    }
  }
  return false;
}

char Board::boardWin()
{
  /*
  @brief checks which player wins in the active board
  This function checks which player wins and returns the winner
  @param board the active board we are looking at
  @return X or O, the player who wins
   */
   if (horizontal(board, 'X'))
   {
     return 'X';
   }
   else if (horizontal(board, 'O'))
   {
     return 'O';
   }
   /* vertical check */
   if (vertical(board, 'X'))
   {
     return 'X';
   }
   else if (vertical(board, 'O'))
   {
     return 'O';
   }
   /* diagonal check */
   if (diagonal(board, 'X'))
   {
     return 'X';
   }
   else if (diagonal(board, 'O'))
   {
     return 'O';
   }
   return ' ';
}

void Board::print()
{
  /*
  @brief prints the board
  This function prints the active board.
  */
  cout << "   |   |   " << endl;
  int j = 0;
  for (int i = 0; i < 5; i++)
  {
    if (i % 2 == 0)
    {
      cout << " " << board[3*j] << " | " << board[3*j + 1] << " | ";
      cout << board[3*j + 2] << " " << endl;
      j++;
    }
    else
    {
      cout << "---|---|---" << endl;
    }
  }
  cout << "   |   |   " << endl;
}
