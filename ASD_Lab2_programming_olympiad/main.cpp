#include <iostream>
#include <fstream>
#include <ctime>

#include "Member.h"
#include "Sort.h"


// Programming Olympiad with using class Sort (ASD_Lab1)

int main() {
	const int NUMBER_MEMBERS = 100000;

	std::vector<Member*> students;

	std::srand(std::time(0));

	// Fill info about members
	for (int i = 0; i < NUMBER_MEMBERS; i++) {
		
		int failed_attempts = std::rand() % 21; // 0 - 20
		
		int solved_tasks = (failed_attempts == 20) ? 0 : (std::rand() % 6); // 0 - 5

		int points = 0;
		// rand 1-5 points for each task
		for (int i = 0; i < solved_tasks; points += std::rand() % 5 + 1, i++);
		// 1 - 20 (if solved task > 0) or 0 (solved task = 0)

		int time_spent = 60 + std::rand() % 241; // 60 - 300
		
		students.push_back(new Member(solved_tasks, time_spent, points, failed_attempts));
	}

	int choice_user = 0;
	std::cout << "Select sorting method 1 - Shell, 2 - Heap : ";
	std::cin >> choice_user;

	int number_comparisons = 0;

	switch (choice_user)
	{
	case 1:

		std::cout << "\n=== === === === === === === === === === === === === === === === === ===" << std::endl;
		std::cout << "\t\t\t Shell Sort" << std::endl;
		std::cout << "=== === === === === === === === === === === === === === === === === ===" << std::endl;

		number_comparisons = Sort<Member>::shell_sort(students);
		std::cout << "Check sort : " << Sort<Member>::check_sorting(students) << "\n";
		std::cout << "Number of comparisons : " << number_comparisons << std::endl;

		break;

	case 2:

		std::cout << "\n=== === === === === === === === === === === === === === === === === ===" << std::endl;
		std::cout << "\t\t\t Heap Sort" << std::endl;
		std::cout << "=== === === === === === === === === === === === === === === === === ===" << std::endl;

		number_comparisons = Sort<Member>::heap_sort(students);
		std::cout << "Check sort : " << Sort<Member>::check_sorting(students) << "\n";
		std::cout << "Number of comparisons : " << number_comparisons << std::endl;

		break;

	default:
		break;
	}

	std::ofstream outFile("results.txt");
	outFile << "ID    Points SolvedTasks TimeSpent FailedAttempts Rank" << std::endl;

	for (int i = 0; i < NUMBER_MEMBERS; i++) {
		students[i]->write_to_file(outFile, i);
	}
	outFile.close();

	for (Member* student : students) delete student;

	return 0;
}