// file main.cpp
// Kendal Anderson   igt22@txstate.edu
// 17.10 PA6 Tic Tac Toe
// CS2308 Spring 2024
// 4/9/24
//Implementation of the GameState member functions

#include <iostream>
#include "GameState.h"

using namespace std;


bool GameState::checkLastPlayerWin() {
    char targetSymbol = getCurrentPlayer() ? 'x' : 'o';
    int sumHorizontal, sumVertical;
    for (int i = 0; i < 3; ++i){
        sumHorizontal = 0;
        sumVertical = 0;
        for (int j = 0; j < 3; ++j){
            sumHorizontal += boardState[i][j] == targetSymbol;
            sumVertical += boardState[j][i] == targetSymbol;
        }
        if (sumHorizontal == 3 || sumVertical == 3)
            return true;
    }
    int sumDiagonal1 = 0, sumDiagonal2 = 0;
    for (int i = 0; i < 3; ++i){
        sumDiagonal1 += boardState[i][i] == targetSymbol;
        sumDiagonal2 += boardState[i][2 - i] == targetSymbol;
    }
    if (sumDiagonal1 == 3 || sumDiagonal2 == 3)
        return true;

    return false;
}

// initializes the board to all underscore characters ('_')
GameState::GameState() {
   
   for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
         boardState[i][j] = '_';
      }
   }
}

// return the player that has to make the next turn. 
// Hint: use the size of the stack to determine who's move it is.
// Extra hint: odd/even.
int GameState::getCurrentPlayer() {

   return moveStack.getSize() % 2 == 0 ? 0 : 1;
}

// Updates the state of the board and stack of the past moves given a move
// of the current player. 
// If the turn is invalid (the target position is not empty). returns -1.
// If all positions are filled. returns 0.
// If the move was successfully done and there are moves available. returns 1.
// Hint: use the size of the stack to determine if all positions are filled.
int GameState::addMove(Move move) {
   
   int x = move.x;
   int y = move.y;
   
   if (boardState[x][y] != '_') {
   
      return -1;
   }
   
   char currentPlayer = getCurrentPlayer() ? 'o' : 'x';
   boardState[x][y] = currentPlayer;
   
   moveStack.push(move);
   
   if (checkLastPlayerWin()) {
      
      return 2;
   }

   if (moveStack.getSize() == 9) {
      
      return 0;
   }
   
   return 1;
   
}

// Undoes the last turn by changing the board state to the previous one and
// removing the last move from the stack. 
// Returns true if the move was removed, false if there are no moves to undo.
bool GameState::undoLast() {
   
   if (moveStack.getSize() == 0) {
      cout << "No moves to undo." << endl;
      return false;
   }
   
   Move lastMove = moveStack.top();
   int x = lastMove.x;
   int y = lastMove.y;
   
   boardState[x][y] = '_';
   
   moveStack.pop();
   
   return true;
}

// prints the board state to the "out" stream
void GameState::displayBoardState(ostream &out) {
   
   for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
         out << boardState[i][j];
      }
      out << endl;
   }
   
}
