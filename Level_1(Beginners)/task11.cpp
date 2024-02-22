#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>

void write_into_file(std::vector<int>&);
void print_vec(std::vector<int>&);
void filling_the_vec(std::string, std::vector<int>&);
void bubble_sort(std::vector<int>&);
void selection_sort(std::vector<int>&);

enum SortingStrategy {

	BUBBLE_SORT = 1, 
	SELECTION_SORT
};

struct SortingOption
{
	SortingStrategy obj;
	void (*fptr)(std::vector<int>&);
};

int main()
{
		std::string file_name;
	    std::cout << "Enter the name of the input file containing unsorted integers: ";
		std::cin >> file_name;
		
		std::vector<int> vec;

		filling_the_vec(file_name, vec);
	
		SortingOption so[2];
		so[0].fptr = &bubble_sort;
		so[1].fptr = &selection_sort;

		int choice;
		std::cout << "Option 1: Bubble_sort." << std::endl;
		std::cout << "Option 2: Selection_sort." << std::endl;

		do {
			std::cout << "Select the option which algorithm you want for sorting tha array." << std::endl;
			std::cout << "Option is: ";
			std::cin >> choice;
		} while(choice < 0 || choice > SELECTION_SORT);

		switch(choice)
		{
				case BUBBLE_SORT:
					std::cout << "Sorting the array with Bubble_sort." << std::endl;
					so[0].fptr(vec);
					break;
				case SELECTION_SORT:
					std::cout << "Sorting the array with Selection_sort." << std::endl;
					so[1].fptr(vec);
		}
		write_into_file(vec);

}
void write_into_file(std::vector<int>& vec)
{
	std::ofstream result("Sorted_arra_task_11.txt");
	if(!result.is_open())
	{
			std::cout << "The file ypu want to write in, is not open.";
			exit(0);
	}
	result << "Already sorted array: "; 
	for(int i = 0; i < vec.size(); ++i)
	{
			result << vec[i] << " ";
	}
	result.close();
}
void filling_the_vec(std::string file_name, std::vector<int>& vec)
{
		std::ifstream file(file_name);
		if(!file.is_open())
		{
			std::cout << "Couldn't open the input file.";
			exit(0);
		}
		std::string line;
		int value;
		while(!file.eof())
		{
				std::getline(file, line);
				std::stringstream ss(line);
				std::string token;
				while(ss >> token)
				{
						try {							
							 value = std::stoi(token);								
						} catch  (const std::invalid_argument& e) {
						    std::cout << "Invalid argument: " << std::endl;
							exit(0);
					    } catch (const std::out_of_range& e) {
							std::cout << "Out of range: " << std::endl;
							exit(0);
					    }
						vec.push_back(value);
				}
		}

		file.close();
		
}

void bubble_sort(std::vector<int>& vec)
{
    bool swapped;
    for (int i = 0; i < vec.size() - 1; ++i)
	{
		swapped = false;
        for (int j = 0; j < vec.size() - i - 1; ++j) 
		{      
			if (vec[j] > vec[j + 1]) 
			{
                std::swap(vec[j], vec[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            return;
    }
}
void selection_sort(std::vector<int>& vec)
{
		for (int i = 0; i < vec.size() - 1; ++i)
		{
			int min_index = i;
				for(int j = i + 1; j < vec.size(); ++j)
				{
						if(vec[j] < vec[min_index])
						{
								min_index = j;
						}
				}
				if(min_index != i)
				{
						std::swap(vec[i], vec[min_index]);
				}
		}

}
