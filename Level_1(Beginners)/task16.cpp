#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "task_16.h"

int main()
{

	
	std::string input_file_name;
	std::cout << "Enter the Input file name: ";
	std::getline(std::cin, input_file_name);
				
	std::string output_file_name;
	std::cout << "Enter the Output file name: ";
	std::getline(std::cin, output_file_name);
	
	SortingApplication sapp(input_file_name, output_file_name);
	sapp.selection_of_algorithm();
	sapp.execution();

	return 0;

		
}

