﻿#include <iostream>
using namespace std;

template <typename T>
static int partition(T arr[], int idx_start, int idx_end)
{
	int idx_pivot = rand()%sizeof(arr)-1+0; // выбор рандомного элемента, по которому будет делиться этот массив
	// rand
	int pivot = arr[idx_start];

	int counter = 0, i = 0, j = 0;

	for (int i = idx_start + 1; i <= idx_end; ++i)
		if (arr[i] <= pivot)
			counter++;

	idx_pivot = counter + idx_start;

	std::swap(arr[idx_pivot], arr[idx_start]);

	i = idx_start;
	j = idx_end;

	while (i < idx_pivot && j > idx_pivot)
	{
		while (arr[i] <= pivot)
			i++;

		while (arr[j] > pivot)
			j--;

		if (i < idx_pivot && j > idx_pivot)
			std::swap(arr[i], arr[j]);
	}
	return idx_pivot;
}

template <typename T>
void quickSort(T arr[], int idx_start, int idx_end)
{
	if (idx_start >= idx_end)
		return;

	int idx_pivot = partition(arr, idx_start, idx_end);

	quickSort(arr, idx_start, idx_pivot - 1);
	quickSort(arr, idx_pivot + 1, idx_end);

}

int main()
{int S;
    cout<<"imput number: "<<endl; //ввод размера массива
    cin >> S;
    int arr [S] = {}; //объявление массива размера S
    for(int i = 0; i < S; i++) //создание массива
        arr[i] = rand(); //запись рандомных чисел в массив по порядку, начиная с 0 позиции.

    int size_arr = sizeof(arr) / sizeof(arr[0]);
	std::cout << "size_arr = " << size_arr << std::endl;

	quickSort(arr, 0, size_arr - 1);


	for (int i = 0; i < size_arr; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	return 0;
}