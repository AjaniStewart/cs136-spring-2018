
#include <cstdlib>
#include "bot.h"
#include <iostream>

using namespace std;

const int MAX_ROBOT_NUM = 50;

int NUM;          // to remember number or robots
int ROWS, COLS;   // map dimensions

enum Status {
	collecting, fixing, unassigned, broken
};

Loc targetLocations[50];
Status robotStatus[50];
int collector[50][50];
//int fixObligation[50];

//Find the closest debris
//look in a circle(square) around the robot
//increment
void setNearestDebris(Loc &robotLocation, Area &area, int id, ostream &log)
{
	// int count = 1;
	// bool up = true, down = true, left = true, right = true,
	// 	topLeft = true, topRight = true, botLeft = true, botRight = true;

	int row = robotLocation.r;
	int col = robotLocation.c;

	for (int mdist = 1; mdist < 500; mdist++){
		for (int offset = 0; offset <= mdist; offset++){
			int vmov = mdist - offset;
			int hmov = offset;
			if (area.inspect(row-vmov, col+hmov) == DEBRIS){
				targetLocations[id] = Loc{ row - vmov, col + hmov };
				robotStatus[id] = collecting;
				log << "the closest is at {" << row-vmov << "," << col+hmov << "} for robot" << id << '\n';
				return;
			}
			else if (area.inspect(row+vmov, col + hmov) == DEBRIS){
				targetLocations[id] = Loc{row + vmov, col + hmov};
				robotStatus[id] = collecting;
				log << "the closest is at {" << row+vmov << "," << col+hmov << "} for robot" << id << '\n';
				return;
			}
			else if (area.inspect(row - vmov, col - hmov) == DEBRIS){
				targetLocations[id] = Loc{row - vmov, col - hmov};
				robotStatus[id] = collecting;
				log << "the closest is at {" << row-vmov << "," << col-hmov << "} for robot" << id << '\n';
				return;
			} 
			else if (area.inspect(row+vmov, col-hmov) == DEBRIS){
				targetLocations[id] = Loc{row + vmov, col - hmov};
				robotStatus[id] = collecting;
				log << "the closest is at {" << row+vmov << "," << col-hmov << "} for robot" << id << '\n';
				return;
			}
		}
	}

	/*while (count < COLS && count < ROWS)
	{
		if (row-count < 0)
			up = false;
		else if (up && area.inspect(row-count,col) == DEBRIS)
		{
			log << "count: " << count << '\n';
			return Loc{row-count,col};
		}
			

		if (row+count > ROWS)
			down = false;
		else if (down && area.inspect(row + count, col) == DEBRIS)
		{
			log << "count: " << count << '\n';
			return Loc{row+count,col};
		}

		if (col+count > COLS)
			right = false;
		else if (right && area.inspect(row, col + count) == DEBRIS)
		{
			log << "count: " << count << '\n';
			return Loc{row, col + count};
		}

		if (col-count < 0)
			left = false;
		else if (left && area.inspect(row,col-count) == DEBRIS)
		{
			log << "count: " << count << '\n';
			return Loc{row,col-count};
		}

		if (row-count < 0 || col+count > COLS)
			topRight = false;
		else if (topRight && area.inspect(row-count,col+count) == DEBRIS)
		{
			log << "count: " << count << '\n';
			return Loc{row-count,col+count};
		}

		if (row+count < ROWS || col+count < COLS)
			botRight = false;
		else if (botRight && area.inspect(row+count,col+count) == DEBRIS)
		{
			log << "count: " << count << '\n';
			return Loc{row+count, col+count};
		}
	
		if (row-count < 0 || col-count < 0)
			topLeft = false;
		else if (topLeft && area.inspect(row-count,col-count) == DEBRIS)
		{
			log << "count: " << count << '\n';
			return Loc{row-count,col-count};
		}

		if (row+count > ROWS || col-count < 0)
			botLeft = false;
		else if (botLeft && area.inspect(row+count,col-count) == DEBRIS)
		{
			log << "count: " << count << '\n';
			return Loc{row + count, col - count};
		}

		++count;
	}*/

	//return Loc{row+1,col+1};
}

/* Initialization procedure, called when the game starts: */
void onStart(int num, int rows, int cols, double mpr,
             Area &area, ostream &log)
{
	NUM = num;   // save the number of robots and the map dimensions
	ROWS = rows;
	COLS = cols;
	for (int i = 0; i<50; i++){
		targetLocations[i] = Loc{-1,-1};
		robotStatus[i] = unassigned;
		//fixObligation[i] = -1;
		for (int j=0; j<50; j++){
			collector[i][j] = -1; // no collector
		}
	}
	log << "Start!" << endl;
}

/* Deciding robot's next move */
Action onRobotAction(int id, Loc loc, Area &area, ostream &log) {
	// current row and column
	int row = loc.r; 
	int col = loc.c;
	/*if (robotStatus[id] == fixing){
		if (targetLocations[id].r > row)
		{
			return DOWN;
		}
		else if (targetLocations[id].r < row)
		{
			return UP;
		}
		else
		{
			if (targetLocations[id].c > col)
			{
				return RIGHT;
			}
			else if (targetLocations[id].c < col)
			{
				return LEFT;
			}
	}*/
	if (area.inspect(row, col) == DEBRIS)
	{
		log << "Collecting: Robot " << id << "\n";
		collector[row][col] = id;
		return COLLECT;
	}
	if (robotStatus[id] == broken)
	{
		targetLocations[id] = loc;
		return COLLECT;
	}
	//find initial closest
	if (robotStatus[id] == unassigned){
		setNearestDebris(loc,area,id,log);
	}
	if (robotStatus[id] == collecting )
	{
		if (targetLocations[id].r > row){
			return DOWN;
		}
		else if (targetLocations[id].r < row)
		{
			return UP;
		}
		else {
			if (targetLocations[id].c > col)
			{
				return RIGHT;
			}
			else if (targetLocations[id].c < col)
			{
				return LEFT;
			}
			else if (area.inspect(row, col) == DEBRIS)
			{
				log << "Collecting 2: Robot " << id << "\n";
				collector[row][col] = id;
				return COLLECT;
			}
			else {
				robotStatus[id] = unassigned;
				targetLocations[id].r = -1;
				targetLocations[id].c = -1;
				return UP;
			}
		}
	}
	else {
		switch (rand() % 4)
		{
		case 0:
			return LEFT;
		case 1:
			return RIGHT;
		case 2:
			return UP;
		default:
			return DOWN;
		}
	}

	//log << "the closest is at {" << closestDebris.r << "," << closestDebris.c << "} for robot" << id << '\n'; 

	/*if (area.inspect(row, col) == DEBRIS)
	{
		//find next closest
		closestDebris = setNearestDebris(loc,area,id,log);
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
	}*/
}

void onRobotMalfunction(int id, Loc loc, Area &area, ostream &log) {
	log << "Robot " << id << " is damaged." << endl;
	robotStatus[id] = broken;
	
}

void onClockTick(int time, ostream &log) {
	if (time % 100 == 0) log << time << " ";
}


