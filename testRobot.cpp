#include "robot.h"



int main()
{
	Robot robotlist[3] = { Robot() , Robot(1, 2, true, 'A'), Robot(2, 5, false, '.') };
	robotlist[0].print2D(board, 5);
	robotlist[1].printRobot();
	robotlist[2].printRobot();
	cout << "=================MOVE TO & print =====================\n";
	robotlist[0].moveTo(1, 1);
	robotlist[0].printRobot();
	cout << " \n";
	robotlist[1].moveTo(4, 7);
	robotlist[1].printRobot();
	cout << " \n";
	robotlist[2].moveTo(3, 6);
	robotlist[2].printRobot();
	cout << " \n";
}