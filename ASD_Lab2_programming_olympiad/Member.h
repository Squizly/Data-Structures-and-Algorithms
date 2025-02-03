#pragma once

class Member
{
public:
	Member();
	~Member();


	static int count; // for ID
private:
	int ID;
	int solved_tasks = 0;
	int time_spent = 0;
	int points = 0;
	int failed_attempts = 0;
};