#pragma once

class Member
{
public:
	Member(int _solvedTasks, int _timeSpent, int _points, int _failedAttempts);
	~Member() = default;

	bool operator < (const Member& otherObject) const;
	bool operator > (const Member& otherObject) const;
private:
	int ID;
	int solved_tasks = 0; // 0 - 5
	int time_spent = 0; // 60 - 300 min
	int points = 0; // 0 - 25
	int failed_attempts = 0; // 0 - 20

	static int count_id; // for ID
};