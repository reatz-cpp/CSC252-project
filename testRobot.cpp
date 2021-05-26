#include "robot.h"

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