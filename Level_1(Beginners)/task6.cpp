/*
Create a program that declares an integer variable, a pointer variable, and a reference variable. Assign the address of the integer to the pointer and manipulate the data using both the pointer and the reference. Output the results to ensure an understanding of how pointers and references are used to access and modify data.
*/

#include <iostream>
int main()
{
		int x = 10;
		int* ptr = &x;
		int& ref = x;
		std::cout << x << std::endl;
		*ptr += 15;
		std::cout << x << std::endl;
		ref = 12;
		std::cout << x << std::endl;
	return 0;

}
