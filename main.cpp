#include <iostream>
#include "MySort.h"

using namespace std;

int N = 10;
int ARRAY[10] = {119, 27, 3565, 200, 1000, 21, 34, 41, 6, 89};


void PrintArray(const int arr[], int size) {
    cout << "[ ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

void RestoreArray(int arr[], int size) {
    for (int i = 0; i < size; ++i)
        arr[i] = ARRAY[i];
}

int main() {
    int arr[N];
    RestoreArray(arr, N);
    cout << "Original ARRAY: \n\t";
    PrintArray(arr, N);

    MySort ms;
    ms.BubbleSort(arr, N);
    cout << "Bubble Sort: \n\t";
    PrintArray(arr, N);

    RestoreArray(arr, N);
    cout << "Selection Sort: \n\t";
    ms.SelectionSort(arr, N);
    PrintArray(arr, N);

    RestoreArray(arr, N);
    cout << "Insertion Sort: \n\t";
    ms.InsertSort(arr, N);
    PrintArray(arr, N);

    RestoreArray(arr, N);
    cout << "Shell Sort: \n\t";
    ms.ShellSort(arr, N);
    PrintArray(arr, N);

    RestoreArray(arr, N);
    cout << "Merge Sort: \n\t";
    ms.MergeSort(arr, N);
    PrintArray(arr, N);

    RestoreArray(arr, N);
    cout << "Quick Sort: \n\t";
    ms.QuickSort(arr, N);
    PrintArray(arr, N);

    RestoreArray(arr, N);
    cout << "Heap Sort: \n\t";
    ms.HeapSort(arr, N);
    PrintArray(arr, N);

    RestoreArray(arr, N);
    cout << "Counting Sort: \n\t";
    ms.CountingSort(arr, N);
    PrintArray(arr, N);

    RestoreArray(arr, N);
    cout << "Bucket Sort: \n\t";
    ms.BucketSort(arr, N);
    PrintArray(arr, N);

    RestoreArray(arr, N);
    cout << "Radix Sort: \n\t";
    ms.RadixSort(arr, N);
    PrintArray(arr, N);

    return 0;
}