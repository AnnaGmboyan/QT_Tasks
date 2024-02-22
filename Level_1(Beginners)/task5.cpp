/*
Implement a program where you define an array of integers and populate it with some values. Write functions to find the maximum, minimum, and average values in the array. Additionally, create a
string variable and demonstrate basic string operations like concatenation and length calculation. This task focuses on data collection management using arrays and strings.
*/
#include <limits.h>
#include <iostream>
#include <string>

double average(int* arr, int size);
int max(int* arr, int size);
int min(int* arr, int size);

int main()
{

		const int size = 7;
		int arr[size];
		std::cout << "Enter " << size << " elements:";
		for (int i = 0; i < size; ++i)
		{
				std::cin >> arr[i];
		}
		std::cout << "Maximum value of the array is: " << max(arr, size) << std::endl;
		std::cout << "Manimum value of the array is: " << min(arr, size) << std::endl;
		std::cout << "Average value of the array is: " << average(arr, size) << std::endl;

		return 0;

}

double average(int* arr, int size)
{
		double avg = 0;
		for(int i = 0; i < size; ++i)
		{
				avg += arr[i];
		}
		avg /= size;
		return avg;
}

int max(int* arr, int size)
{
	int max = INT_MIN;
		for(int i = 0; i < size; ++i)
		{
				if(max < arr[i])
				{
						max = arr[i];
				}
		}
		return max;
}
int min(int* arr, int size)
{
		int min_elem = INT_MAX;
		for(int i = 0; i < size; ++i)
		{
				if(min_elem > arr[i])
				{
						min_elem = arr[i];
				}
		}
		return min_elem;
}
