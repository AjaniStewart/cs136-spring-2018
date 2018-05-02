
#include <cstdlib>
#include "bot.h"
#include <iostream>
#include <cmath>

using namespace std;

const int MAX_ROBOT_NUM = 50;

int NUM;          // to remember number or robots
int ROWS, COLS;   // map dimensions

enum Status { COLLECTING, FIXING, UNASSIGNED, BROKEN };
//Where the robots are headed
Loc targetLocations[MAX_ROBOT_NUM];
//current status of the robots
Status robotStatus[MAX_ROBOT_NUM];
//a map of what robots go to what debris
int collector[MAX_ROBOT_NUM][MAX_ROBOT_NUM];

//Find closest debris in an L Shape kind of
//make a robot target that debris
void setNearestDebris(Loc &robotLocation, Area &area, int id, ostream &log)
{
	int row = robotLocation.r;
	int col = robotLocation.c;

	for (int mdist = 1; mdist < 500; mdist++)
	{
		for (int offset = 0; offset <= mdist; offset++)
		{
			int vmov = mdist - offset;
			int hmov = offset;
			if (area.inspect(row-vmov, col+hmov) == DEBRIS && collector[row-vmov][col+hmov] == -1)
			{
				targetLocations[id] = Loc{ row - vmov, col + hmov };
				robotStatus[id] = COLLECTING;
				collector[row-vmov][col+hmov] = id;
				log << "the closest is at {" << row-vmov << "," << col+hmov << "} for robot" << id << '\n';
				return;
			}
			if (area.inspect(row+vmov, col + hmov) == DEBRIS && collector[row+vmov][col+hmov] == -1)
			{
				targetLocations[id] = Loc{row + vmov, col + hmov};
				robotStatus[id] = COLLECTING;
				collector[row+vmov][col+hmov] = id;
				log << "the closest is at {" << row+vmov << "," << col+hmov << "} for robot" << id << '\n';
				return;
			}
			if (area.inspect(row - vmov, col - hmov) == DEBRIS && collector[row-vmov][col-hmov] == -1)
			{
				targetLocations[id] = Loc{row - vmov, col - hmov};
				robotStatus[id] = COLLECTING;
				collector[row-vmov][col-hmov] = id;
				log << "the closest is at {" << row-vmov << "," << col-hmov << "} for robot" << id << '\n';
				return;
			} 
			if (area.inspect(row+vmov, col-hmov) == DEBRIS && collector[row+vmov][col-hmov] == -1)
			{
				targetLocations[id] = Loc{row + vmov, col - hmov};
				robotStatus[id] = COLLECTING;
				collector[row+vmov][col-hmov] = id;
				log << "the closest is at {" << row+vmov << "," << col-hmov << "} for robot" << id << '\n';
				return;
			}
		}
	}
}

Action moveRandom()
{
	switch (rand() % 4)
	{
	case 0: return LEFT;
	case 1: return RIGHT;
	case 2: return UP;
	default: return DOWN;
	}
}

// Action moveTowardsTarget (Loc target, Loc currentPosition)
// {
// 	int cRow = currentPosition.r;
// 	int cCol = currentPosition.c;
// 	int tRow = target.r;
// 	int tCol = target.c;

// 	if (tRow > cRow) { return DOWN; }
// 	if (tRow < cRow) { return UP; }
// 	if (tCol > cCol) { return RIGHT; }
// 	if (tCol < cCol) { return LEFT; }
// }
/* Initialization procedure, called when the game starts: */
void onStart(int num, int rows, int cols, double mpr,
             Area &area, ostream &log)
{
	NUM = num;   // save the number of robots and the map dimensions
	ROWS = rows;
	COLS = cols;
	for (int i = 0; i<MAX_ROBOT_NUM; i++)
	{
		targetLocations[i] = Loc{-1,-1};
		robotStatus[i] = UNASSIGNED;
		for (int j=0; j<MAX_ROBOT_NUM; j++)
		{
			collector[i][j] = -1; // no robot going to that location
		}
	}
	log << "Start!" << endl;
}

/* Deciding robot's next move */
//
Action onRobotAction(int id, Loc loc, Area &area, ostream &log) 
{
	// current row and column
	int row = loc.r; 
	int col = loc.c;

	if ( area.inspect(row, col) == DEBRIS)
	{
		//collect if you are on debris
		log << "COLLECTING: Robot " << id << "\n";
		collector[row][col] = id;
		return COLLECT;
	}
	
	//make sure they do not stick to each other
	for (int i = 0; i < NUM; ++i)
	{
		if (i == id) continue;
		//if there are one away from another 
		if ((area.locate(i).c == col && abs(area.locate(i).r - row) == 1) || 
		(area.locate(i).r == row && abs(area.locate(i).c - col) == 1) )
		{
			//there is a broken robot nearby, fix it
			if (robotStatus[i] == BROKEN)
			{
				robotStatus[id] = UNASSIGNED;
				robotStatus[i] = UNASSIGNED;
				if (area.locate(i).c == loc.c - 1)
					return REPAIR_LEFT;
				if (area.locate(i).c - 1 == loc.c)
					return REPAIR_RIGHT;
				if (area.locate(i).r == loc.r - 1)
					return REPAIR_UP;
				if (area.locate(i).r - 1 == loc.r)
					return REPAIR_DOWN;
			}
			return moveRandom();
		}
			

		if (robotStatus[i] == BROKEN)
		{
			robotStatus[id] = FIXING;
			targetLocations[id] = Loc{area.locate(i).r-1,area.locate(i).c};
		}
	}
	//stays in place
	//hopefully
	if (robotStatus[id] == BROKEN)
	{
		return DOWN;
	}
	//find initial closest
	if (robotStatus[id] == UNASSIGNED)
	{
		setNearestDebris(loc,area,id,log);
	}
	//go to where the debris is or where a broken robot is 
	if (robotStatus[id] == COLLECTING || robotStatus[id] == FIXING)
	{
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
			 if (area.inspect(row, col) == DEBRIS)
			{
				log << "COLLECTING 2: Robot " << id << "\n";
				collector[row][col] = id;
				return COLLECT;
			}
			else
			{
				robotStatus[id] = UNASSIGNED;
				targetLocations[id] = Loc{-1,-1};
				return moveRandom();
			}
		}
	}
	else 
	{
		return moveRandom();
	}
}

void onRobotMalfunction(int id, Loc loc, Area &area, ostream &log) 
{
	log << "Robot " << id << " is damaged." << endl;
	robotStatus[id] = BROKEN;
}

void onClockTick(int time, ostream &log)
 {
	if (time % 100 == 0) log << time << " ";
}


