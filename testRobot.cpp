#include <iomanip>
#include <iostream>
#include <assert.h>

using namespace std;

char grid[10][10];

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


//function - move robot to location given as parameter
bool Robot::moveTo(int lx, int ly)
{

	//verifies location is in grid
	if (lx < 0 || ly < 0 || lx >= 10 || ly >= 10)
	{
		return false;
	}

	//determines horizontal direction
	if (this->xLocation < lx)
	{

		//move right on x-axis
		while (lx != this->xLocation)
		{
			this->xLocation++;
		}

	}

	//determines horizontal direction
	if (this->xLocation > lx)

	{

		//move left on x-axis
		while (lx != this->xLocation)

		{
			this->xLocation--;
		}

	}

	//determines vertical direction
	if (this->yLocation < ly)

	{

		//move up on x-axis
		while (ly != this->yLocation)

		{
			this->yLocation++;
		}

	}

	//determines vertical direction
	if (this->yLocation > ly)

	{

		//move down on y-axis
		while (ly != this->yLocation)

		{
			this->yLocation--;
		}

	}

	return true;

}




//function - pickup load and bool cargobed
bool Robot::pickUp(int lx, int ly)
{

	//verify robot at pickup loaction, moves if not    
	if (this->xLocation != lx || this->yLocation != ly)
	{
		moveTo(lx, ly);
	}


	//verify a char is at pickup location
	if (grid[xLocation][yLocation] == '.')
	{
		return false;
	}

	//if cargobed is full (true), can't pickup another char
	if (cargoBed)
	{
		return false;
	}


	//fill cargo bed (true)
	cargoBed = true;

	//update load with char
	load = grid[xLocation][yLocation];

	//reset grid location to empty(.)
	grid[xLocation][yLocation] = '.';



	return true;

}

//function - dropoff char in load at a spot on grid
bool Robot::dropOff(int lx, int ly)
{

	//verify robot at dropoff loaction, moves if not     
	if (this->xLocation != lx || this->yLocation != ly)
	{
		moveTo(lx, ly);
	}


	//Can't drop load, char already at grid location
	if (grid[xLocation][yLocation] != '.')
	{
		return false;
	}

	//set grid loaction to dropped load
	grid[xLocation][yLocation] = load;

	//set load on robot to empty (.)
	load = '.';

	//reset cargobed to empty (false)
	cargoBed = false;

	return true;

}



ostream& operator<<(ostream& out, const Robot& r)
{

	out << " at (" <<r.xLocation << ", " << r.yLocation << ") with load: " << r.load << endl;
	return out;
}



void print2D(char a[][10])
{
	cout << "The grid is : " << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << a[i][j] << " ";
		}
			
		cout << endl;
	}
	
	

}

//function - reset grid
void clear(char grid[10][10])
{

	for (int i = 0; i < 10; i++)
	{

		for (int j = 0; j < 10; j++)
		{

			if (grid[i][j] != '.')
			{

				Robot* temporary = new Robot(i, j, false, '.');

				temporary->pickUp(i, j);

				delete temporary;

			}

		}

	}

}





int main()
{
	
	
	//initializing 2d array

	for (int i = 0; i < 10; i++)

	{

		for (int j = 0; j < 10; j++)

		{

			grid[i][j] = '.';

		}

	}


	grid[3][8] = 'B';
	grid[2][6] = 'C';

	print2D(grid);
	
	int x1 = rand() % 10;
	int x2 = rand() % 10;
	int y1 = rand() % 10;
	int y2 = rand() % 10;

	Robot R1(x1, y1, false, '.');
	Robot R2(x2, y2, false, '.');

	cout << "Robot R1 " << R1 << endl;
	cout << "Robot R2: " << R2 << endl;

	R1.moveTo(9, 2);
	R2.moveTo(3, 4);

	cout << "Robot R1: " << R1 << endl;
	cout << "Robot R2: " << R2 << endl;
	print2D(grid);

	R1.pickUp(3, 8);
	R1.dropOff(9, 9);

	cout << "Robot R1: " << R1 << endl;
	print2D(grid);

	R2.pickUp(2, 6);
	R2.dropOff(0, 0);

	cout << "Robot R2: " << R2 << endl;
	print2D(grid);

	clear(grid);
	print2D(grid);

	return 0;

	

}
