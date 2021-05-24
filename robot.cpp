#include "robot.h"

void printBoard()
{
	//nested loop to print a 2d array
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			cout << board[i][j] << endl;

}

void clear(char a[][10], int size)
{
	Robot* r;
	//use a nested loop to traverse the board and at each cell with a load
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			board[i][j];
			r->pickUp(i, j);
			//dynamically create a Robot object and place at that cell
				//use the robot to pick up the load 
			//Now that the cell is clear, return the memory back to system
		}
			

}

Robot::Robot()
{
	xLocation = 0;
	yLocation = 0;
	cargoBed = false;
	load = '.';
}

Robot::Robot(int lx, int ly, bool cargoBed, char load)
{
	this->cargoBed = cargoBed;
	this->load = load;
	xLocation = lx;
	yLocation = ly;
	board[lx][ly] = 0;

}

int Robot::getLx()
{
	return xLocation;
}
int Robot::getLy()
{
	return yLocation;
}
bool Robot::getCb()
{
	return cargoBed;
}
char Robot::getLoad()
{
	return load;
}
void Robot::setLx(int lx)
{
	if(lx >= 0 && lx <10)
		xLocation = lx;
}
void Robot::setLy(int ly)
{
	if(ly >= 0 && ly < 10)
		yLocation = ly;
}
void Robot::setCb(bool cargoBed)
{
	this->cargoBed = cargoBed;
}
void Robot::setLoad(char load)
{
	this->load = load;
}
bool Robot::moveTo(int lx, int ly)
{
	assert(lx >= 0 && lx < 10);
	assert(ly >= 0 && ly < 10);

	int diffInX = xLocation - lx;
	int diffInY = yLocation - ly;
	int xSteps = abs(diffInX);
	int ySteps = abs(diffInY);
	if (diffInX > 0)
		for (int i = 0; i < xSteps; i++)
		{
			xLocation--;
		}
					
	else
		xLocation++;

	if (diffInY > 0)
		for (int i = 0; i < ySteps; i++)
		{
			yLocation--;
		}
	else
		yLocation++;

	return true;

}

bool Robot::pickUp(int lx, int ly)
{
	assert(lx >= 0 && lx < 10);
	assert(ly >= 0 && ly < 10);
	if (board[lx][ly] != '.')//if board is not empty
	{
		if (cargoBed == false)
		{
			//move robot to the location and place load in cargobed
			//make sure to reset the board to empty and cargobed to true
			return true;
		}
		else
		{
			cout << "Robot has a load already\n";
			return false;
		}
		
	}
	cout << "No load at board location specified\n";
	return false;
}

bool Robot::dropOff(int lx, int ly)
{
	assert(lx >= 0 && lx < 10);
	assert(ly >= 0 && ly < 10);
	if (board[lx][ly] = '.')//board is empty)
	{
		if (load != '.') //Robot has a load)
		{
			//move robot to the location and place load in cargobed
			//make sure to reset the board to full and cargobed to false
			return true;
		}
		else
		{
			cout << "Robot has no load to drop off\n";
			return false;
		}

	}
	cout << "A load is already at board location specified\n";
	return false;
}


