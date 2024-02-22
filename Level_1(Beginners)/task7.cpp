#include <iostream>
#include <map>

void bubble_sort(int* arr, int size);
void selection_sort(int* arr, int size);

int main()
{
	int arr[7] = {5, 9, 4, 2, 1, 6, 3};
	std::map<int, void(*)(int*, int)> function_selector {

				{1, bubble_sort},
				{2, selection_sort}
	};
	int selector = 0;
	do {
		std::cout << "Enter 1 to select bubble sort argorith and 2 for selection sort: ";
		std::cin >> selector;
	} while(selector != 1 && selector != 2) ;
	
	function_selector[selector](arr, 7);
	std::cout << "Sorted array is a: ";
	for (int i = 0; i < 7; ++i)
	{
			std::cout << arr[i] << " ";
	}

}

void bubble_sort(int* arr, int size)
{
	bool flag = true;	
	for(int i = 0; i < size - 1; ++i)
		{
				for(int j = i + 1; j < size; ++j)
				{
						if(arr[i] > arr[j])
						{
								std::swap(arr[i], arr[j]);
								flag = false;
						}
				}
				if(flag == true)
				{
						return;
				}
		}
}

void selection_sort(int* arr, int size)
{
		for (int i = 0; i < size - 1; ++i)
		{
			int min_index = i;
				for(int j = i + 1; j < size; ++j)
				{
						if(arr[j] < arr[min_index])
						{
								min_index = j;
						}
				}
				if(min_index != i)
				{
						std::swap(arr[i], arr[min_index]);
				}
		}

}
