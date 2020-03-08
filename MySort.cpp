//
// Created by lzwang on 2019/9/16.
//

#include "MySort.h"


// 冒泡排序（Bubble Sort）
void MySort::BubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                Swap(arr[j], arr[j + 1]);
            }
        }
    }
}


// 选择排序（Selection Sort）
void MySort::SelectionSort(int arr[], int size) {
    int minIndex;
    for (int i = 0; i < size - 1; ++i) {
        minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        Swap(arr[i], arr[minIndex]);
    }
}


// 插入排序（Insertion Sort）
void MySort::InsertSort(int arr[], int size) {
    int preIndex, current;
    for (int i = 1; i < size; ++i) {
        preIndex = i - 1;
        current = arr[i];
        while (preIndex >= 0 && arr[preIndex] > current) {
            arr[preIndex + 1] = arr[preIndex];
            --preIndex;
        }
        arr[preIndex + 1] = current;
    }
}


// 希尔排序（Shell Sort）
void MySort::ShellSort(int arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; ++i) {
            int j = i;
            int current = arr[i];
            while (j - gap >= 0 && current < arr[j - gap]) {
                arr[j] = arr[j - gap];
                j = j - gap;
            }
            arr[j] = current;
        }
    }
}


// 归并排序（Merge Sort）
void MySort::MergeSort(int arr[], int size) {
    if (size < 2)
        return;

    int mid = size / 2;
    int *L = new int[mid];
    int *R = new int[size - mid];

    for (int i = 0; i < mid; ++i)
        L[i] = arr[i];
    for (int j = mid; j < size; ++j)
        R[j - mid] = arr[j];

    MergeSort(L, mid);
    MergeSort(R, size - mid);
    Merge(arr, L, mid, R, size - mid);

    delete[]R;
    delete[]L;
}

void MySort::Merge(int arr[], const int *L, int leftCount, const int *R, int rightCount) {
    int i = 0, j = 0, k = 0;

    while (i < leftCount && j < rightCount) {
        if (L[i] < R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < leftCount)
        arr[k++] = L[i++];

    while (j < rightCount)
        arr[k++] = R[j++];
}


// 快速排序（Quick Sort）
void MySort::QuickSort(int arr[], int size) {
    QuickSort(arr, 0, size - 1);
}

void MySort::QuickSort(int *arr, int low, int high) {
    if (low < high) {
        int mid;
        // make partition
        {
            int i = low - 1;
            for (int j = low; j < high; ++j) {
                if (arr[j] < arr[high]) {
                    ++i;
                    Swap(arr[i], arr[j]);
                }
            }
            Swap(arr[i + 1], arr[high]);
            mid = i + 1;
        }
        QuickSort(arr, low, mid - 1);
        QuickSort(arr, mid + 1, high);
    }
}


// 堆排序（Heap Sort）
void MySort::HeapSort(int arr[], int size) {
    for (int i = size / 2; i >= 0; --i) {
        HeapBuild(arr, i, size);
    }

    for (int j = size - 1; j > 0; --j) {
        Swap(arr[0], arr[j]);
        HeapBuild(arr, 0, j);
    }
}

void MySort::HeapBuild(int arr[], int root, int length) {
    int left = root * 2 + 1;
    if (left < length) {
        int maxIndex = left;
        int right = left + 1;
        if (right < length && arr[right] > arr[maxIndex]) {
            maxIndex = right;
        }

        if (arr[root] < arr[maxIndex]) {
            Swap(arr[root], arr[maxIndex]);
            HeapBuild(arr, maxIndex, length);
        }
    }
}


// 计数排序（Counting Sort）
void MySort::CountingSort(int arr[], int size) {
    // 找出源数组的最大值
    int maxValue = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }

    int counterSize = maxValue + 1;
    int *counter = new int[counterSize];
    int sortedIndex = 0;

    // 初始化计数的数组
    for (int i = 0; i < counterSize; ++i) {
        counter[i] = 0;
    }

    // 统计每个元素的出现次数
    for (int j = 0; j < size; ++j) {
        counter[arr[j]]++;
    }

    // 对源数组重新赋值
    for (int k = 0; k < counterSize; ++k) {
        while (counter[k] > 0) {
            arr[sortedIndex++] = k;
            counter[k]--;
        }
    }

    delete[]counter;
}

// 桶排序（Bucket Sort）
void MySort::BucketSort(int arr[], int size) {
    if (size == 0) {
        return;
    }

    const int DEFAULT_BUCKET_SIZE = 5;
    int minValue = arr[0];
    int maxValue = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minValue) {
            minValue = arr[i];
        } else if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }

    int bucketCount = (maxValue - minValue) / DEFAULT_BUCKET_SIZE + 1;
    std::vector<std::vector<int>> buckets;
    for (int i = 0; i < bucketCount; ++i) {
        std::vector<int> tmp;
        buckets.push_back(tmp);
    }

    for (int i = 0; i < size; ++i) {
        buckets[(arr[i] - minValue) / DEFAULT_BUCKET_SIZE].push_back(arr[i]);
    }

    int arrIndex = 0;
    for (auto currentBucket : buckets) {
        std::sort(currentBucket.begin(), currentBucket.end());
        for (int value : currentBucket) {
            arr[arrIndex++] = value;
        }
    }
}

// 基数排序（Radix Sort）
void MySort::RadixSort(int arr[], int size) {
    int maxDigit = MaxBit(arr, size); // 求出最大位数
    int mod = 10;
    int dev = 1;

    // 构建用于存放当前位数上 0~9 的vector容器
    std::vector<std::vector<int>> counter;
    for (int i = 0; i < mod; i++) {
        std::vector<int> tmp;
        counter.push_back(tmp);
    }

    for (int i = 0; i < maxDigit; ++i, dev *= 10, mod *= 10) {
        // 求出当前位数下的余数（值），并放入对应vector中
        for (int j = 0; j < size; ++j) {
            int bucket = (arr[j] % mod) / dev;
            counter[bucket].push_back(arr[j]);
        }

        // 对当前位数下的值进行排序
        int pos = 0;
        for (auto & values : counter) {
            while (!values.empty()) {
                arr[pos++] = values[0];
                values.erase(values.begin());
            }
        }
    }
}

int MySort::MaxBit(const int arr[], int size) {
    int maxDigit = 1;
    for (int i = 0; i < size; ++i) {
        int currentDigit = 1;
        int currentValue = arr[i];
        while (currentValue / 10) {
            currentValue /= 10;
            ++currentDigit;
        }
        if (currentDigit > maxDigit)
            maxDigit = currentDigit;
    }
    return maxDigit;
}


// =============================================== //
void MySort::Swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

