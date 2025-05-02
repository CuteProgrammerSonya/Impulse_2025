#include <iostream>
#include <ctime>
#include <algorithm>

#define SIZE 5

void fill_arr_random_numbers(int arr[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			arr[i][j] = rand() % 90 + 10;
		}
	}
}

void print_arr(const int arr[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void change_first_max_elements(int arr[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		int *maximum = std::max_element(&arr[i][0], &arr[i][SIZE]);
		int position = maximum - &arr[i][0];
		std::swap(arr[i][0], arr[i][position]);
	}
}

int main()
{
	int arr[SIZE][SIZE] = {};

	srand(time(0));
	fill_arr_random_numbers(arr);
	print_arr(arr);
	change_first_max_elements(arr);
	std::cout << std::endl;
	print_arr(arr);
	return 0;
}