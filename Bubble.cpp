#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

template <typename T> // шаблон для сортировки
void BubbleSort(T arr[], int size) // функция для сортировки типа Bubble
{
    for(int i=0;i<size-1;++i)
    {
        for(int j=0;j<size-i-1;++j)
        {
            if(arr[j]>arr[j+1])
            {
                T temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

template<typename T> // шаблон для вывода массива
void PrintArray(T arr[], int n) // функция для вывода массива
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n\n";
}


int main()
{
    int S;
    cout<<"imput number: "<<endl; //ввод размера массива
    cin >> S;
    int arr [S] = {}; //объявление массива размера S
    for(int i = 0; i < S; i++) //создание массива
        arr[i] = rand(); //запись рандомных чисел в массив по порядку, начиная с 0 позиции.

    int size = sizeof(arr) / sizeof(int);
    cout << "Array Before Sorting: " << endl;
    PrintArray(arr, size); //вывод созданного рандомного массива

    BubbleSort(arr, size); //функция сортировки

    cout << "Array After Sorting: " << endl; //вывод массива после сортировки
    PrintArray(arr, size);
}
