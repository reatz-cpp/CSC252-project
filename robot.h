#ifndef ROBOT_H
#define ROBOT_H
#include <iomanip>
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <assert.h>

using namespace std;

char board[10][10];

class Robot
{

public:
	Robot();
	Robot(int lx, int ly, bool cargoBed, char load);
	int getLx();
	int getLy();
	bool getCb();
	char getLoad();
	void setLx(int lx);
	void setLy(int ly);
	void setCb(bool cargoBed);
	void setLoad(char load);
	bool moveTo(int lx, int ly);
	bool pickUp(int lx, int ly);
	bool dropOff(int lx, int ly);

private:
	int xLocation;
	int yLocation;
	bool cargoBed;
	char load;

};


#endif

