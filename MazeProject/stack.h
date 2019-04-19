/*******************************************************************************
Author: Lauren Bolin
Name:Stack.h
Des: This is the definitions of the functions used to solve a maze.
These Functions Include:
	1)Struct Coordinate which holds the row, and column for stepping thru the maze
	2)Struct Node to be used in the Push function in the stack.cpp file
	3)A class named stack which holds the constructor, destructor, and 
	functions to implement a Backtrackingsolution. Which is achieved by using a 
	stack implemented as a linked list.

********************************************************************************/
#pragma once

struct coordinate
{
	int row, column;
};

struct Node
{
	coordinate location;
	Node * next;

};

class stack
{
public:
	stack();
	~stack();
	bool push(coordinate);
	coordinate pop();
	bool empty();


private:

	Node * top;

};