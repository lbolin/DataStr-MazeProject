#include "stack.h"
#include<iostream>
#include<fstream>

using namespace std;

bool AvaliableMove(coordinate curPos, char maze[][80], int numRows, int numCol)
{
	if (curPos.row < numRows && curPos.column < numCol)
	{
		if ((maze[curPos.row][curPos.column] == '0') || (maze[curPos.row][curPos.column] == 'E'))
		{
			return true;
		}

		return false;

	}

}

int main()
{

	int count = 0;

	//coordinate North, East, South, West;
	coordinate North, East, South, West;


	char maze[80][80];
	char returnCharacter;
	int row, col, rIndex, cIndex;

	ifstream fin;
	//code to read maze dimensions (row and col as seen in code below)
	fin.open("maze.txt");

	ofstream fout;
	fout.open("mazeSolutions.txt");
	fout << "Solutions to A-MAZE-ING Stacks Assignment" << endl;
	fout << "Lauren Bolin" << endl;


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

		stack moveStack;
		coordinate curPos;

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
			//ProcessMaze(curPos,moveStack);
		} while (!moveStack.empty());

		//Output the Maze
		fout << "MAZE NUMBER" << count << endl;
		//prints maze to maze.txt

		for (int row = 0; row < numRows; row++)
		{
			for (int col = 0; col < numCol; col++)
			{
				fout << maze[row][col];
			}
			fout << endl;
		}

		if (maze[curPos.row][curPos.column] == 'E')
		{
			fout << endl << "There IS a way out!" << endl << endl;
		}
		else
		{
			fout << endl << "There IS NOT a way out!" << endl << endl;
		}

		fin >> numRows >> numCol;
	}
	//close input file
	fin.close();

	//close output file
	fout.close();


}