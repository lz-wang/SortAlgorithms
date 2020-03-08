//
// Created by lzwang on 2019/9/16.
//

#ifndef SORTALGORITHMS_MYSORT_H
#define SORTALGORITHMS_MYSORT_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class MySort {

public:
    void BubbleSort(int arr[], int size);

    void SelectionSort(int arr[], int size);

    void InsertSort(int arr[], int size);

    void ShellSort(int arr[], int size);

    void MergeSort(int arr[], int size);

    void QuickSort(int arr[], int size);

    void HeapSort(int arr[], int size);

    void CountingSort(int arr[], int size);

    void BucketSort(int arr[], int size);

    void RadixSort(int arr[], int size);

private:
    void Swap(int &a, int &b);
    void Merge(int arr[], const int L[], int leftCount, const int R[], int rightCount);
    void QuickSort(int arr[], int low, int high);
    void HeapBuild(int arr[], int root, int length);
    int MaxBit(const int arr[], int size);

    void PrintArray(const int arr[], int size) {
        std::cout << "[ ";
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << "]" << std::endl;
    }
};

#endif //SORTALconst GORITHMS_MYSORT_H
