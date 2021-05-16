#ifndef ROBOT_H
#define ROBOT_H
#include <iomanip>
#include <string>

using namespace std;

int board[10][10];

class Robot
{

public:
	Robot(int lx, int ly, bool cb, char ld);
	int getLx();
	int getLy();
	bool getCb();
	char getLoad();
	void setLx(int lx);
	void setLy(int ly);
	void setCb(bool cb);
	void setLoad(char ld);
	bool moveTo(int lx, int ly);
	bool pickUp(int lx, int ly);


private:
	int xLocation;
	int yLocation;
	bool cargoBed;
	char load;

};


#endif

