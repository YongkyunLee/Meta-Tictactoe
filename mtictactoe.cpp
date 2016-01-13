#include <iostream>
#include "mboard.hpp"
#include "mtictactoe.hpp"

using namespace std;

Game::Game()
{
  turn = 0;
  priority = 0; // 0 for player X, 1 for player O, 2 for temp
}

void Game::run()
{
  /*
  @brief runs the game
  This function runs the game
  */

  /*
  Question: What do I do if I want to use an object from Board class in two
  different functions of Game class.
  */
  Board board;
  Board metaboard;
  int active = 0, coord = 0;
  int xcount = 0, ocount = 0; // count of wins of X and O
  bool ended = false;

  while (!ended)
  {
    if (priority == 0)
    {
      cout << "Meta-board" << endl;
      metaboard.print();
      cout << "Player X has priority." << endl;
      cout << "Choose a board to make active: " ;
      cin >> active;
      metaboard.place(active, 'A'); // 'A' stands for 'active'
      priority = 2;
    }
    else if (priority == 1)
    {
      cout << "Meta-board" << endl;
      metaboard.print();
      cout << "Player O has priority." << endl;
      cout << "Choose a board to make active: ";
      cin >> active;
      metaboard.place(active, 'A');
      priority = 2;
    }
    cout << "Metaboard" << endl;
    metaboard.print();
    cout << endl;
    cout << "Active Board" << endl;
    board.print();

    if (turn % 2 == 0)
    {
      cout << "Player X's turn. Choose a box number: ";
      cin >> coord;
      board.place(coord, 'X');
    }
    else
    {
      cout << "Player O's turn. Choose a box number: ";
      cin >> coord;
      board.place(coord, 'O');
    }

    if (board.boardWin() == 'X') // if X wins the game
    {
      board.print();
      metaboard.place(active, 'X');
      cout << "Player X wins board " << active << "." << endl << endl;
      board.clean();
      priority = 1; // priority goes to the loser
      xcount++;
    }
    else if (board.boardWin() == 'O') // if O wins the game
    {
      board.print();
      metaboard.place(active, 'O');
      cout << "Player O wins board " << active << "." << endl;
      board.clean();
      priority = 0;
      ocount++;
    }
    else if (board.finished() && board.boardWin() == ' ')  // if it is a draw on the active board
    {
      board.print();
      metaboard.place(active, 'D');
      cout << "Board " << active << " is a draw." << endl;
      board.clean();
      if (turn % 2 == 0) // It was X's turn this turn.
      {
        priority = 1;
      }
      else
      {
        priority = 0;
      }
    }

    if (metaboard.boardWin() == 'X')
    {
      cout << "Player X wins the game! Congrats!" << endl;
      ended = true;
    }
    else if (metaboard.boardWin() == 'O')
    {
      cout << "Player O wins the game! Congrats!" << endl;
      ended = true;
    }
    if (metaboard.finished()) // if there is no clear winner
    {
      if (xcount > ocount)
      {
        cout << "Player X wins the game! Congrats!" << endl;
      }
      else if (xcount < ocount)
      {
        cout << "Player O wins the game! Congrats!" << endl;
      }
      else // if number of X == number of Y
      {
        cout << "It is a draw. Play again!" << endl;
      }
    }
    turn ++;
  }
}

int main(int argc, char ** argv)
{
  Board board;
  Board metaboard;
  Game game;
  game.run();
}
