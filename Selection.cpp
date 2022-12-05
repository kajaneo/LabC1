#include <iostream>
#include <cstdlib>
#include <vector>
using std::swap;
using namespace std;
template <typename T>
void swap(T* const, T* const);

template <typename T> //шаблон для вывода  массива
void PrintArray(T arr[], int n) // функция для вывода массива
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n\n";
}

template <typename T> //шаблон для сортировки массива
void SelectionSort(T* const arr, const unsigned int size) // функция сортировки типа Selection
{
    for (std::size_t i = 0; i < size - 1; ++i) {
        int smallest = i; // первый индекс от конечного массива

        // цикл для поиска наименьшего элемента
        for (int index = i + 1; index < size; ++index) {
            if (arr[index] < arr[smallest]) smallest = index;
        }

        swap (&arr[i], &arr[smallest]); //
    }
}

//обмен местами element1Ptr и element2Ptr
template <typename T>
void swap(T* const element1Ptr, T* const element2Ptr) {
    T hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
}

int main() {
    int S;
    cout<<"imput number: "<<endl; // ввод размера массива
    cin >> S;
    int arr [S] = {}; // объявление массива размера S
    for(int i = 0; i < S; i++) // создание массива
        arr[i] = rand(); // запись рандомных чисел в массив по порядку, начиная с 0 позиции

    cout << "Array Before Sorting: " << endl; //вывод массива после сортировки
    PrintArray(arr, S); //вывод созданного рандомного массива

    SelectionSort(arr, S);; //функция сортировки

    cout << "Array After Sorting: " << endl; //вывод массива после сортировки
    PrintArray(arr, S);

    return 0;
}
