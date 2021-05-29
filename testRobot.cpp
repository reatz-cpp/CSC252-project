#include <iomanip>
#include <iostream>
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
	friend ostream& operator<<(ostream& out, const Robot& r);

private:
	int xLocation;
	int yLocation;
	bool cargoBed;
	char load;

};
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
	if (lx >= 0 && lx < 10)
		xLocation = lx;
}
void Robot::setLy(int ly)
{
	if (ly >= 0 && ly < 10)
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
		for (int i = 0; i < xSteps; i++)
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

	if (cargoBed)
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



void print2D(char a[][10])
{
	cout << "The grid is : ";
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << a[i][j] << " ";
		}
			
		cout << endl;
	}
	
	

}

/*void clear(char a[][10], int size)
{
	Robot* r;
	//use a nested loop to traverse the board and at each cell with a load
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			a[i][j];
			//r->pickUp(i, j);
			//dynamically create a Robot object and place at that cell
				//use the robot to pick up the load 
			//Now that the cell is clear, return the memory back to system
		}


}*/


int main()
{
	
	

	board[3][8] = 'B';
	board[2][6] = 'C';

	print2D(board);
	
	int x1 = rand() % 10;
	int x2 = rand() % 10;
	int y1 = rand() % 10;
	int y2 = rand() % 10;

	Robot R1(x1, y1, false, '.');
	Robot R2(x2, y2, false, '.');

	cout << "Robot R1 " << R1 << "\n";
	cout << "Robot R2: " << R2 << endl;



			


}