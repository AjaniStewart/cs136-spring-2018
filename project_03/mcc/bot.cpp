
#include <cstdlib>
#include "bot.h"
#include <iostream>

using namespace std;

const int MAX_ROBOT_NUM = 50;

int NUM;          // to remember number or robots
int ROWS, COLS;   // map dimensions

//Find the closest debris
//look in a circle(square) around the robot
//increment
Loc findNearestDebris(Loc &robotLocation, Area &area, int id)
{
	int count = 1;
	bool up = true, down = true, left = true, right = true,
		topLeft = true, topRight = true, botLeft = true, botRight = true;

	int row = robotLocation.r;
	int col = robotLocation.c;
	while (count < COLS && count < ROWS)
	{
		if (row-count < 0)
			up = false;
		else if (up && area.inspect(row-count,col) == DEBRIS)
			return Loc{row-count,col};

		if (row+count > ROWS)
			down = false;
		else if (down && area.inspect(row + count, col) == DEBRIS)
			return Loc{row+count,col};

		if (col+count > COLS)
			right = false;
		else if (right && area.inspect(row, col + count) == DEBRIS)
			return Loc{row, col + count};

		if (col-count < 0)
			left = false;
		else if (left && area.inspect(row,col-count) == DEBRIS)
			return Loc{row,col-count};

		if (row-count < 0 || col+count > COLS)
			topRight = false;
		else if (topRight && area.inspect(row-count,col+count) == DEBRIS)
			return Loc{row-count,col+count};

		if (row+count < ROWS || col+count < COLS)
			botRight = false;
		else if (botRight && area.inspect(row+count,col+count) == DEBRIS)
			return Loc{row+count, col+count};
	
		if (row-count < 0 || col-count < 0)
			topLeft = false;
		else if (topLeft && area.inspect(row-count,col-count) == DEBRIS)
			return Loc{row-count,col-count};

		if (row+count > ROWS || col-count < 0)
			botLeft = false;
		else if (botLeft && area.inspect(row+count,col-count) == DEBRIS)
			return Loc{row + count, col - count};
		++count;
	}
	//return Loc{row+1,col+1};
}

/* Initialization procedure, called when the game starts: */
void onStart(int num, int rows, int cols, double mpr,
             Area &area, ostream &log)
{
	NUM = num;   // save the number of robots and the map dimensions
	ROWS = rows;
	COLS = cols;

	log << "Start!" << endl;
}

/* Deciding robot's next move */
Action onRobotAction(int id, Loc loc, Area &area, ostream &log) {
	// current row and column
	int row = loc.r; 
	int col = loc.c;
	//find initial closest
	static Loc closestDebris = findNearestDebris(loc,area,id);
	log << "the closest is at {" <<closestDebris.r<<","<<closestDebris.c<<"} for robot" <<id <<'\n'; 

	if (area.inspect(row, col) == DEBRIS)
	{
		//find next closest
		closestDebris = findNearestDebris(loc,area,id);
		return COLLECT;
	}
	else {
		// if not at a debris field make movements to the closet:
		//Move towards the same column as the target, then towards the same row
		
		if (closestDebris.c > col)
		{
			log << " right ";
			return RIGHT;
		}
		 if (closestDebris.c < col)
		{
			log << "left ";
			return LEFT;
		}
		 if (closestDebris.r < row)
		{
			log << "up ";
			return UP;
		}
		else 
		{
			return DOWN;
		}
		//switch (rand() % 4)
		// {
		// case 0:
		// 	return LEFT;
		// case 1:
		// 	return RIGHT;
		// case 2:
		// 	return UP;
		// default:
		// 	return DOWN;
		// }
	}
}

void onRobotMalfunction(int id, Loc loc, Area &area, ostream &log) {
	log << "Robot " << id << " is damaged." << endl;
}

void onClockTick(int time, ostream &log) {
	if (time % 100 == 0) log << time << " ";
}


