// file main.cpp
// Kendal Anderson   igt22@txstate.edu
// 17.10 PA6 Tic Tac Toe
// CS2308 Spring 2024
// 4/9/24

#include <iostream>
using namespace std;

#include "GameState.h"
#include "MoveStack.h"

int main() {
   
   GameState game;

   game.displayBoardState(cout);
   
   while (true) {
      
      int currentPlayer = game.getCurrentPlayer();
      cout << "Player " << currentPlayer << " make a turn." << endl;
      
      string input;
      cin >> input;
      
      int x, y;
      x = -1;
      y = -1;
      
      bool validMove = false;
      
      while (!validMove) {
         if (input == "move") {

            cin >> x >> y;
            Move move(x, y);
            int result = game.addMove(move);
            

            if (result == 2){
               
               
               game.displayBoardState(cout);
               cout << "Player " << currentPlayer << " won!" << endl;
               return 0;
            }
            
            else if (result == 0) {
               
               
               
               game.displayBoardState(cout);
               cout << "It's a draw!" << endl;
               return 0;
            }
            
            else if (result == -1) {
               cout << "Incorrect move. Please try again." << endl;
               
               break;
            }

            else {
               validMove = true;
               game.displayBoardState(cout);
               
            }
         }
         
         else if (input == "undo") {
            
            if (!game.undoLast()) {
               
            }
            else {
               game.displayBoardState(cout);
            }
            break;
         }
      }
      

   }

   return 0;
}
