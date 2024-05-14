// file main.cpp
// Kendal Anderson   igt22@txstate.edu
// 17.10 PA6 Tic Tac Toe
// CS2308 Spring 2024
// 4/9/24
//The move stack specification file.  It stores the history of the moves
// currently in effect

// Represents a players move by storing the
// x,y coordinates
// Added constructor functions to this struct to simplify the code

#include <string>
#include <iostream>

using namespace std;

#ifndef MOVE_H
#define MOVE_H
struct Move {
    int x;
    int y;
    Move() { x=0; y=0; }
    Move(int a, int b) { x=a, y=b;}
};
#endif

#ifndef MOVESTACK_H
#define MOVESTACK_H

class MoveStack {
private:
    /* add your member variables here */
   struct MoveNode {
      Move data;
      MoveNode *next;
      //MoveNode(Move m)
   };
   MoveNode *head;
   MoveNode *rear;
   
   bool isEmpty() const;
   
public:
    MoveStack();
    ~MoveStack();
    int getSize();
    Move top();
    void push(Move move);
    void pop();
};

#endif


