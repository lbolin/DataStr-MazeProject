/*******************************************************************************************************
Author:Lauren Bolin
Name: maze.cpp
Des: This file used the function definitions from the stack.h file and the implimentation from the stack.cpp
	to solve a maze 
********************************************************************************************************/

#include "stack.h"
#include <vld.h>
#include<iostream>
#include<fstream>

using namespace std;

/******************************************************************************************************
Function Name: AvaliableMove
Des: This function will check to see if the move is avaliable by checking the North,East,South and west
	boundrys. Then it will check to see if the coordinate is 0 or E. If the coordinate is 0 or E it is an
	avaliable move.
*******************************************************************************************************/
bool AvaliableMove(coordinate curPos, char maze[][80],int numRows, int numCol)
{
	bool Avaliable = false;

	if (curPos.row < numRows && curPos.row >= 0) 
		if (curPos.column < numCol && curPos.column >=0)
			{
				if ((maze[curPos.row][curPos.column] == '0' )||( maze[curPos.row][curPos.column] == 'E'))
					{
						Avaliable = true;
					}
			}
	return Avaliable;

}
/*******************************************************************************************************
Function Name: ProcessMaze
Des: This function uses a Do While to process the maze.
	1)Read in the the maze starting point
	2)Check to see if the starting point is at an exit
	3)Set the parameters for North,East,South and West moves in the maze
	4)Check each direction for available move , push coordinate of avaliable on to the too of the stack
	5)Place breadcrum at the coordinate of available move
	6)After breadcrum had been placed pop coordinate off stack, if there is nothing to pop the stack 
	is empty.

********************************************************************************************************/
void ProcessMaze(char maze[][80], int numRows, int numCol, ifstream &fin, coordinate& curPos)
{
	stack moveStack;
	

	//coordinate North, East, South, West;
	coordinate North, East, South, West;

	//Read in the maze starting point 
	fin >> curPos.row >> curPos.column;

	do
	{
		if (maze[curPos.row][curPos.column] == 'E')
		{
			cout << "There is a Exit" << endl;
			break;
		}
		else {

			North.row = curPos.row - 1;
			North.column = curPos.column;
			East.row = curPos.row;
			East.column = curPos.column + 1;
			South.row = curPos.row + 1;
			South.column = curPos.column;
			West.row = curPos.row;
			West.column = curPos.column - 1;

			if (AvaliableMove(North, maze, numRows, numCol))
			{
				if (!moveStack.push(North))
				{
					cout << "Memory error" << endl;
					exit(1);
				}
				else
					moveStack.push(North);
			}

			if (AvaliableMove(East, maze, numRows, numCol))
			{
				if (!moveStack.push(East))
				{
					cout << "Memory error" << endl;
					exit(1);
				}
				else
					moveStack.push(East);
			}

			if (AvaliableMove(South, maze, numRows, numCol))
			{
				if (!moveStack.push(South))
				{
					cout << "Memory error" << endl;
					exit(1);
				}
				else
					moveStack.push(South);
			}

			if (AvaliableMove(West, maze, numRows, numCol))
			{
				if (!moveStack.push(West))
				{
					cout << "Memory error" << endl;
					exit(1);
				}
				else
					moveStack.push(West);
			}
			//bread crum
			maze[curPos.row][curPos.column] = '.';

			if (!moveStack.empty())
			{
				curPos = moveStack.pop();
				cout << "New Current Position in Maze is" << curPos.row << " , " << curPos.column << endl;


			}
			else
			{
				cout << "Stack is Empty" << endl;
			}

		}


	} while (!moveStack.empty());
}


/*****************************************************************************************************
Class Name: Main
Des: The main class opens and reads the file and prints the first maze into the file mazeSoulutions.txt.It will 
	also close the input and output files when all the mazes have been processed. 
*******************************************************************************************************/
int main()
{	
	
	int count = 0;
	coordinate curPos;
	char maze[80][80];
	char returnCharacter;

	ifstream fin;
	//code to read maze dimensions (row and col as seen in code below)
	fin.open("maze.txt");

	ofstream fout;
	fout.open("mazeSolutions.txt");
	fout << "Solutions to A-MAZE-ING Stacks Assignment"<<endl;
	fout << "Lauren Bolin"<<endl<<endl;


	if (!fin)
		{
		cout << "Input File could not be read" << endl;
			exit(1);
	}

	int numRows, numCol;

	
	fin >> numRows >> numCol;

	//read in the maze

	while (numRows != -1 || numCol != -1)
	{
		for (int row = 0; row < numRows; row++)
		{
			for (int col = 0; col < numCol; col++)
			{
				fin >> maze[row][col];
			};
		};
		count++;

		ProcessMaze(maze,numRows,numCol,fin,curPos);
		//Output the Maze
		fout << "MAZE NUMBER " << count << endl<<endl;
		//prints maze to maze.txt

		for (int row = 0; row < numRows; row++)
		{
			for (int col = 0; col < numCol; col++)
			{
				fout << maze[row][col];
			}
			fout << endl;
		}
		//checks if there is a exit
		if (maze[curPos.row][curPos.column] == 'E')
		{
			fout << endl << "There IS a way out!" << endl << endl;
		}
		else
		{
			fout << endl << "There IS NOT a way out!" << endl << endl;
		}

		//Read in next Maze 
		fin >> numRows >> numCol;
	}
	//close input file
	fin.close();

	//close output file
	fout.close();

	
}



