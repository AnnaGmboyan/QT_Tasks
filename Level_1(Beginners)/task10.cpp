/*
   Write a program that creates a text file and writes a list of names into it. Then, open the same file for reading and print its contents to the console. This task aims to teach basic file input 
   and output operations, including opening, reading, writing, and closing files.
*/   

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ofstream write("Writing_file_task_10.txt");
	if(!write.is_open())
	{
			std::cout << "The file you want to write in, isn't open. " << std::endl;
			exit(0);
	}
	std::string name;
	int x = 5;
	std::cout << "Enter " << x << " names: ";
	while(x)
	{
			std::getline(std::cin, name);
			write << name << "\n";
			--x;
	}
	write.close();
	std::ifstream read("Writing_file.txt");
	if(!read.is_open())
	{
			std::cout << "The file you want to read from, isn't open. " <<std::endl;
			exit(0);
	}
	std::cout << std::endl;
	std::cout << "Entered names are: ";
	while(!read.eof())
	{
			std::getline(read, name);
			std::cout << name << std::endl;
	}
	read.close();
return 0;

}
