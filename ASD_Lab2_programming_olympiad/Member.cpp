#include <iostream>

#include "Member.h"

int Member::count_id = 1;

Member::Member(int _solvedTasks, int _timeSpent, int _points, int _failedAttempts)
{
	ID = count_id++;
	solved_tasks = _solvedTasks;
	time_spent = _timeSpent;
	points = _points;
	failed_attempts = _failedAttempts;
}


bool Member::operator < (const Member& otherObject) const
{
	if (points != otherObject.points) return points > otherObject.points;
	if (solved_tasks != otherObject.solved_tasks) return solved_tasks > otherObject.solved_tasks;

	if (time_spent != otherObject.time_spent) return time_spent < otherObject.time_spent; 
	if (failed_attempts != otherObject.failed_attempts) return failed_attempts < otherObject.failed_attempts;

	return ID < otherObject.ID;
}

bool Member::operator > (const Member& otherObject) const
{
	if (points != otherObject.points) return points < otherObject.points;
	if (solved_tasks != otherObject.solved_tasks) return solved_tasks < otherObject.solved_tasks;

	if (time_spent != otherObject.time_spent) return time_spent > otherObject.time_spent;
	if (failed_attempts != otherObject.failed_attempts) return failed_attempts > otherObject.failed_attempts;

	return ID > otherObject.ID;
}