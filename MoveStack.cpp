// file main.cpp
// Kendal Anderson   igt22@txstate.edu
// 17.10 PA6 Tic Tac Toe
// CS2308 Spring 2024
// 4/9/24

//#include <stdio.h>
#include <iostream>
#include <cassert>
using namespace std;

#include "MoveStack.h"

// returns if stack is empty
bool MoveStack::isEmpty() const {
   
   return head == nullptr;
   
}

// initializes the stack
MoveStack::MoveStack() {
   
   head = nullptr;
   rear = nullptr;
   
}

// cleans up the dynamically allocated memory.
MoveStack::~MoveStack() {
   
   while (head != nullptr) {
      MoveNode *temp = head;
      head = head->next;
      delete temp;
   }
   
   rear = nullptr;
}

// Returns stack size (# of moves currently on the stack)
int MoveStack::getSize() {
   
   int size = 0;
   
   MoveNode *p = head;
   while (p != nullptr) {
      size++;
      p = p->next;
   }

   return size;
}

// Returns a move on top of the stack (does not remove it)
Move MoveStack::top() {
   if (head == nullptr) {
   
      return Move();
      
   }
   
   return head->data;
   
}

// adds the move to top of the stack
void MoveStack::push(Move move) {
   
   MoveNode *temp = new MoveNode;
   temp->data = move;
   temp->next = head;
   head = temp;
   
}

// removes a move from the top of the stack (does not return it)
void MoveStack::pop() {
   assert(!isEmpty());
   
   MoveNode *temp = head;
   head = head->next;
   delete temp;
   
}
