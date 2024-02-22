#include <iostream>
void bubble_sort(int*, int);
void selection_sort(int*, int);

enum SortingStrategy {

	BUBBLE_SORT = 1, 
	SELECTION_SORT
};

struct SortingOption
{
	SortingStrategy obj;
	void (*fptr)(int*, int);
};

int main()
{
		const int size = 7;
		int arr[size];
		std::cout << "Enter "<< size << " elements to sort them: ";
		for(int i = 0;  i < size; ++i)
		{
				std::cin >> arr[i];
		}
		SortingOption so[2];
		so[0].fptr = &bubble_sort;
		so[1].fptr = &selection_sort;

		int choice;
		std::cout << "Option 1: Bubble_sort." << std::endl;
		std::cout << "Option 2: Selection_sort." << std::endl;
		std::cout << "Select the option which algorithm you want for sorting tha array." << std::endl;
		std::cout << "Option is: ";
		std::cin >> choice;

		switch(choice)
		{
				case BUBBLE_SORT:
					std::cout << "Sorting the array with Bubble_sort." << std::endl;
					so[0].fptr(arr, size);
					break;
				case SELECTION_SORT:
					std::cout << "Sorting the array with Selection_sort." << std::endl;
					so[1].fptr(arr, size);
		}

		std::cout << "Array after sorting: ";
		for(int i = 0; i < size; ++i)
		{
				std::cout << arr[i] << " ";
		}
		return 0;
}

void bubble_sort(int* arr, int size)
{
    bool swapped;
    for (int i = 0; i < size - 1; ++i)
	{
		swapped = false;
        for (int j = 0; j < size - i - 1; ++j) 
		{      
			if (arr[j] > arr[j + 1]) 
			{
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            return;
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
