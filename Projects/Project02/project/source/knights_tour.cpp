#include <iostream>
#include <iomanip>
#include "knights_tour.h"
using namespace std;

KnightsTour::KnightsTour(int board_size) {
  this->board_size = board_size;

  this->board.resize(board_size);
  for (int i = 0; i < board_size; ++i) {
    this->board[i].resize(board_size);
  }
}

void KnightsTour::print() {
  for (int i = 0; i < this->board_size; i++) {
    for (int j = 0; j < this->board_size; j++)
      cout << setw(4) << this->board[i][j] << " ";
    cout << endl;
  }
  cout << endl << endl;
}

// Function: get_moves()
//    Desc: Get the row and column indices of all valid
//          knight moves reachable from position row, col.
//          An invalid move would be one that sends the
//          knight off the edge of the board or
//          to a position that has already been visited.
//          
//    int row         - Current row position of knight.
//    int col         - Current column position of knight.
//    int row_moves[] - Array to store row indices
//                      of all valid new moves reachable from
//                      the current position row, col.
//    int col_moves[] - Array to store column indices
//                      of all valid new moves reachable from
//                      the current position row, col.
//    int num_moves -   Number of valid moves found. Corresponds
//                      to the sizes of row_moves and col_moves.

void KnightsTour::get_moves(
  int row, int col, 
  int row_moves[], int col_moves[], int& num_moves
) {
  if (col + 2 <= 4 && row - 1 >= 0 && board[row - 1][col + 2] == 0){ // Valid move 2 right 1 up
    row_moves[num_moves] = row - 1; // Add the valid row to moves
    col_moves[num_moves] = col + 2; // Add the valid col to moves
    num_moves += 1; // Increment the valid move counter
  }

  if (col + 2 <= 4 && row + 1 <= 4 && board[row + 1][col + 2] == 0){ // Valid move 2 right 1 down
    row_moves[num_moves] = row + 1; // Add the valid row to moves
    col_moves[num_moves] = col + 2; // Add the valid col to moves
    num_moves += 1; // Increment the valid move counter
  }

  if (col + 1 <= 4 && row + 2 <= 4 && board[row + 2][col + 1] == 0){ // Valid move 1 right 2 down
    row_moves[num_moves] = row + 2; // Add the valid row to moves
    col_moves[num_moves] = col + 1; // Add the valid col to moves
    num_moves += 1; // Increment the valid move counter
  }

  if (col - 1 >= 0 && row + 2 <= 4 && board[row + 2][col - 1] == 0){ // Valid move 1 left 2 down
    row_moves[num_moves] = row + 2; // Add the valid row to moves
    col_moves[num_moves] = col - 1; // Add the valid col to moves
    num_moves += 1; // Increment the valid move counter
  }

  if (col - 2 >= 0 && row + 1 <= 4 && board[row + 1][col - 2] == 0){ // Valid move 2 left 1 down
    row_moves[num_moves] = row + 1; // Add the valid row to moves
    col_moves[num_moves] = col - 2; // Add the valid col to moves
    num_moves += 1; // Increment the valid move counter
  }

  if (col - 2 >= 0 && row - 1 >= 0 && board[row - 1][col - 2] == 0){ // Valid move 2 left 1 up
    row_moves[num_moves] = row - 1; // Add the valid row to moves
    col_moves[num_moves] = col - 2; // Add the valid col to moves
    num_moves += 1; // Increment the valid move counter
  }

  if (col - 1 >= 0 && row - 2 >= 0 && board[row - 2][col - 1] == 0){ // Valid move 1 left 2 up
    row_moves[num_moves] = row - 2; // Add the valid row to moves
    col_moves[num_moves] = col - 1; // Add the valid col to moves
    num_moves += 1; // Increment the valid move counter
  }

  if (col + 1 <= 4 && row - 2 >= 0 && board[row - 2][col + 1] == 0){ // Valid move 1 right 2 up
    row_moves[num_moves] = row - 2; // Add the valid row to moves
    col_moves[num_moves] = col + 1; // Add the valid col to moves
    num_moves += 1; // Increment the valid move counter
  }
}

// Function: move() --> Recursive
//     int row        - Current row position of knight.
//     int col        - Current column position of knight.
//     int& m         - Current move id in tour.
//                      Stored in board at position
//                      row, col.
//     int& num_tours - Total number of tours found.

void KnightsTour::move(int row, int col, int& m, int& num_tours) {
}

int KnightsTour::generate(int row, int col) {
  int m = 0;
  int num_tours = 0;
  move(row, col, m, num_tours);

  return num_tours;
}
