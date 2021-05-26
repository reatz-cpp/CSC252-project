#include "robot.h"

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

	else if (diffInX < 0)
	{
		for(int i = 0; i <xSteps; i++)
			xLocation++;
	}
		

	if (diffInY > 0)
	{
		for (int i = 0; i < ySteps; i++)
			yLocation--;
	}

	else if (diffInY < 0)
	{
		for (int i = 0; i < ySteps; i++)
			xLocation++;
	}
		
	return true;

}

bool Robot::pickUp(int lx, int ly)
{
	assert(lx >= 0 && lx < 10);
	assert(ly >= 0 && ly < 10);
	
	if (!this->moveTo(lx, ly))
		return false;
		
	if(cargoBed)
	{
		cout << "Robot has a load already\n";
		return false;
	}

	if (board[lx][ly] == '.')
	{
		cout << "No load at board location specified\n";
		return false;
	}
		

	load = board[lx][ly];
	board[lx][ly] = '.';
	cargoBed = true;
	return true;

}

/*bool Robot::dropOff(int lx, int ly)
{
	assert(lx >= 0 && lx < 10);
	assert(ly >= 0 && ly < 10);
	if (board[lx][ly] == '.')//board is empty)
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
}*/


ostream& operator<<(ostream& out, const Robot& r)
{
	
	out << r.xLocation << r.yLocation << r.load << endl;
	return out;
}

