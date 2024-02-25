#pragma once
 Selection_sort::Selection_sort()
{
	swapped = false;		
}
void Selection_sort::sort(std::vector<int>& vec) 
{
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
		{
			return;			
		}

	}
}
Bubble_sort::Bubble_sort()
{
	min_index = 0;			
}
void Bubble_sort::sort(std::vector<int>& vec) 
{
		for (int i = 0; i < vec.size() - 1; ++i)
		{
			 min_index = i;
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
FileHandler::FileHandler(std::string input_file_name, std::string output_file_name)
{
	read.open(input_file_name);
	if(!read.is_open())
	{
		std::cout << "Couldn't open the input file." << std::endl;
		exit(0);
	}
	write.open(output_file_name);
	if(!write.is_open())
	{
		std::cout << "The file you want to write in, is not open.";
		exit(0);
	}
	
}
FileHandler::~FileHandler()
{
		read.close();
		write.close();
}
std::vector<int>& FileHandler::get_vec()
{
		return vec;
}
		
void FileHandler::ReadArrayFromFile()
{
	std::string line;
	int value;
	while(!read.eof())
	{	
			std::getline(read, line);
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
}
void FileHandler::SaveArrayToFile()
{
		write << "Already sorted array: ";
		for(int i = 0; i < vec.size(); ++i)
		{
			write << vec[i] << " ";
		}
}
SortingApplication::SortingApplication(const std::string &input_file_name, const std::string &output_file_name)
						   : fh(input_file_name, output_file_name), base_ptr(nullptr) 
{

}
SortingApplication::~SortingApplication()
{
		delete base_ptr;
}
void SortingApplication::selection_of_algorithm()
{
		int choice;
		std::cout << "Enter 1 to choose Bubble sort." << std::endl;
		std::cout << "Enter 2 to choose Selector sort." << std::endl;

		do {
			std::cout << "Enter your choise: ";
			std::cin >> choice;
		} while(choice != 1 && choice != 2);

		if(choice == 1) {
			base_ptr = new Bubble_sort();
		} else {
			base_ptr = new Selection_sort();
		}

}
void SortingApplication::execution()
{

		fh.ReadArrayFromFile();
		base_ptr -> sort(fh.get_vec());
		fh.SaveArrayToFile();

}























