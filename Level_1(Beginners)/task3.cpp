/*
Develop a program that asks the user for a number and then, using if-else statements, checks whether the number is positive, negative, or zero. Extend the program with a switch-case to assign a grade (A, B, C, D, F) based on a number range (e.g., 90-100 for A). Lastly, implement a loop that prints numbers from 1 to 10. This task teaches the fundamental control structures for program flow.
*/
#include <iostream>
int main()
{
		int number;
		std::cout << "Enter a number: ";
		std::cin >> number;
		if (number < 0) {
				std::cout << "Number is negative." << std::endl;
		} else if (number > 0) {
				std::cout << "The number is positive." << std::endl;
		} else {
				std::cout << "The number is equal to zero." << std::endl;
		}

		char grade;
		switch(number)
		{
			case 90 ... 100:
				grade = 'A';
				break;
			case 80 ... 89:
				grade = 'B';
				break;
			case 70 ... 79:
				grade  = 'C';
				break;
			case 60 ... 69:
				grade = 'D';
				break;
			case 50 ... 59:
				grade = 'E';
				break;
			default: 
				grade = 'F';
	
		}
		std::cout << "Grade is: " << grade << std::endl;
		for (int i = 1; i < 11; ++i)
		{
				std::cout << i << " ";
		}
		return 0;

}
