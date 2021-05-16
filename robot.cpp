#include "robot.h"

Robot::Robot(int lx, int ly, bool cb, char ld)
{
	cargoBed = cb;
	load = ld;
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
	xLocation = lx;
}
void Robot::setLy(int ly)
{
	yLocation = ly;
}
void Robot::setCb(bool cb)
{
	cargoBed = cb;
}
void Robot::setLoad(char ld)
{
	load = ld;
}
bool Robot::moveTo(int lx, int ly)
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			board[i][j];
			if (board[lx][ly] != board[i][j])
				return false;

		}
	return true;

}

bool Robot::pickUp(int lx, int ly)
{
	load;
	board[lx][ly];
	cargoBed;
}