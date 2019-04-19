/******************************************************************************************
Author:Lauren Bolin
Implementation Name: stack.cpp
Des: This file contains the function definitions declared in class stack.
*******************************************************************************************/

#include "stack.h"
#include <iostream>
using namespace std;
/******************************************************************************************
Function Name: stack (constructor)
Des: This constructor will create a Stack object top which is null
*******************************************************************************************/
stack::stack():top(NULL)
{}
/******************************************************************************************
Function Name: ~stack (destructor)
Des: This function will destroy a top object
*******************************************************************************************/
stack::~stack()
{
	Node * temp =top;
	while (top != NULL)
	{
		temp = top->next;
		delete top;
		top = temp;
	}
};

/******************************************************************************************
Function Name: push
Des: This function will create a new node and push it to the top of the stack
*******************************************************************************************/
bool stack::push(coordinate data)
{

	Node *p = new Node;

	if (p == NULL)
		return false;

		p->location = data;
		p->next = NULL;

		if (empty())
		{
			top = p;
		}
		else
		{
		p->next = top;
		top = p;
		}
	
}
/*******************************************************************************************
Function Name:pop
Des:This function will pop the data off the top of the stack
********************************************************************************************/
coordinate stack::pop()
{
	Node * p = top;
	coordinate temp = top->location;
	top = top->next;
	delete p;
		
	return temp;

}
/*******************************************************************************************
Function Name:empty
Des:This function will determine if the stack is empty.
********************************************************************************************/
bool stack::empty() 
{
	return (top == NULL);
};