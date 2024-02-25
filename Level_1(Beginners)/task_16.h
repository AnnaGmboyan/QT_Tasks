#ifndef TASK_16_H
#define TASK_16_H

class SortingStrategy
{
	public:

		virtual	void sort(std::vector<int>& obj) = 0;
		virtual	~SortingStrategy() { };

};
class Selection_sort : public SortingStrategy
{
	private:

		bool swapped;
		
	public:
		Selection_sort();
		void sort(std::vector<int>& vec) override;
};
class Bubble_sort : public SortingStrategy
{
		private:
			int min_index;
		public:
			Bubble_sort();
			void sort(std::vector<int>& vec) override;
};
class FileHandler
{		
	private:
			std::vector<int> vec;
			std::ifstream read;
			std::ofstream write;

	public:
		FileHandler(std::string input_file_name, std::string output_file_name);
		~FileHandler();
		std::vector<int>& get_vec();
		void ReadArrayFromFile();
		void SaveArrayToFile();		
};


class SortingApplication
{
	private:
		SortingStrategy* base_ptr;
		FileHandler fh;
	public:
		SortingApplication(const std::string &input_file_name, const std::string &output_file_name);
		~SortingApplication();
		void selection_of_algorithm();
		void execution();
};

#include "task16.hpp"

#endif //TASK_16_H
