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

void KnightsTour::get_moves(int row, int col, int row_moves[], int col_moves[], int& num_moves) {
  num_moves = 0;

  if ((row - 1 > -1) && (col + 2 < 5) && board[row - 1][col + 2] == 0){ // Move on Board
    row_moves[num_moves] = row - 1; // Add the valid row to moves
    col_moves[num_moves] = col + 2; // Add the valid col to moves
    num_moves++; // Increment the valid move counter 
  }

  if ((row + 1 < 5) && (col + 2 < 5) && (board[row + 1][col + 2] == 0)){ // Move on Board
    row_moves[num_moves] = row + 1; // Add the valid row to moves
    col_moves[num_moves] = col + 2; // Add the valid col to moves
    num_moves++; // Increment the valid move counter 
  }  

  if ((row + 2 < 5) && (col + 1 < 5) && (board[row + 2][col + 1] == 0)){ // Move on Board
    row_moves[num_moves] = row + 2; // Add the valid row to moves
    col_moves[num_moves] = col + 1; // Add the valid col to moves
    num_moves++; // Increment the valid move counter 
  }

  if ((row + 2 < 5) && (col - 1 > -1) && (board[row + 2][col - 1] == 0)){ // Move on Board
    row_moves[num_moves] = row + 2; // Add the valid row to moves
    col_moves[num_moves] = col - 1; // Add the valid col to moves
    num_moves++; // Increment the valid move counter 

  }

  if ((row + 1 < 5) && (col - 2 > -1) && (board[row + 1][col - 2] == 0)){ // Move on Board

    row_moves[num_moves] = row + 1; // Add the valid row to moves
    col_moves[num_moves] = col - 2; // Add the valid col to moves
    num_moves++; // Increment the valid move counter 
  }

  if ((row - 1 > -1) && (col - 2 > -1) && (board[row - 1][col - 2] == 0)){ // Move on Board
    row_moves[num_moves] = row - 1; // Add the valid row to moves
    col_moves[num_moves] = col - 2; // Add the valid col to moves
    num_moves++; // Increment the valid move counter 
  }

  if ((row - 2 > -1) && (col - 1 > -1) && (board[row - 2][col - 1] == 0)){ // Move on Board
    row_moves[num_moves] = row - 2; // Add the valid row to moves
    col_moves[num_moves] = col - 1; // Add the valid col to moves
    num_moves++; // Increment the valid move counter 
  }

  if ((row - 2 > -1) && (col + 1 < 5) && (board[row - 2][col + 1] == 0)){ // Move on Board
    row_moves[num_moves] = row - 2; // Add the valid row to moves
    col_moves[num_moves] = col + 1; // Add the valid col to moves
    num_moves++; // Increment the valid move counter 
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
  m++; // Increment m
  board[row][col] = m; // update board

  if (m == board_size*board_size){ // Completion
  print();
  num_tours++;
  }

  int row_moves[8], col_moves[8];
  int num_moves = 0;

  get_moves(row, col, row_moves, col_moves, num_moves);

  for (int i = 0; i < num_moves; i++){
    move(row_moves[i], col_moves[i], m, num_tours); 
  }

  // Backtracking Required
  m--;
  board[row][col] = 0;
}

int KnightsTour::generate(int row, int col) {
  int m = 0;
  int num_tours = 0;
  move(row, col, m, num_tours);

  return num_tours;
}
