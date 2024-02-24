#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

class SortingStrategy
{
	public:

		virtual	void sort(std::vector<int>& obj) = 0;

};

class Selection_sort : public SortingStrategy
{
		void sort(std::vector<int>& vec) override
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
					{
						return;			
					}
            
				}
		}
};

class Bubble_sort : public SortingStrategy
{
			void sort(std::vector<int>& vec) override
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
};

class FileHandler
{		
		private:
			std::vector<int> vec;
			std::string input_file_name;
			std::string output_file_name;
	
		public:
			
		std::vector<int>& get_vec()
		{
				return vec;
		}
		
		void set_input_file_name(std::string name)
		{
				input_file_name = name;
		}
		void set_output_file_name(std::string name)
		{
				output_file_name = name;
		}
		
		void ReadArrayFromFile()
		{
			std::ifstream file(input_file_name);
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
		void SaveArrayToFile()
		{
				std::ofstream result(output_file_name);
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




		
};


class SortingApplication
{
	private:
		SortingStrategy* base_ptr;
		FileHandler fh;

	public:
		void prompting_file_names()
		{
				std::string input_file_name;
				std::cout << "Enter the Input file name: ";
				std::getline(std::cin, input_file_name);
				fh.set_input_file_name(input_file_name);

				std::string output_file_name;
				std::cout << "Enter the Output file name: ";
				std::getline(std::cin, output_file_name);
				fh.set_output_file_name(output_file_name);

		}
		
		void selection_of_algorithm()
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
		void execution()
		{

				fh.ReadArrayFromFile();
				base_ptr -> sort(fh.get_vec());
				fh.SaveArrayToFile();

		}
		~SortingApplication()
		{
		    delete base_ptr; // Deallocate memory
		}

		
};

int main()
{

	SortingApplication sapp;
	sapp.prompting_file_names();
	sapp.selection_of_algorithm();
	sapp.execution();

	
	return 0;
		
}

