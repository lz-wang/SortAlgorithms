# SortAlgorithms
A simple implement for 10+ sort algorithms.



> 注意：以下排序算法均默认为升序排序

## 冒泡排序(Bubble Sort)

**算法思想**：两两比较元素的主键值，如果二者的主键值次序相反，则调换顺序。在序列中遍历直至没有反序的元素为止。
**算法特点**：在每次遍历后，主键值最大的元素会冒泡到顶端对应位置，因而得名。
**算法步骤**：

1. 比较相邻的两个元素，如果第二个比第一个主键值小，交换两者位置;
2. 遍历数组，对每一对相邻的元素执行步骤1的操作，这样在最后的元素就是最大的元素;
3. 除了已经冒泡出来的元素以外，针对所有的元素重复以上步骤;
4. 重复步骤1～3，直到排序完毕。

**CPP代码**：

```cpp
// 冒泡排序（Bubble Sort）
void BubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                Swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void Swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}
```


## 选择排序(Selection Sort)

**算法思想**：不断地选择未排序的元素中的最小者放到已排序元素序列的后面。
**算法特点**：对N个元素而言，此算法需要(N-1)次选择操作完成排序。
**算法步骤**：

1. 序列（数组）的有序部分没有元素，无序部分有N个元素;
2. 从N个元素中选择最小的元素，放到有序序列中;
3. 从剩余无序部分的剩余元素中选择出最小的元素，放到有序序列后面;
4. 重复第3步，直到排序完成。

**CPP代码**：

```cpp
// 选择排序（Selection Sort）
void SelectionSort(int arr[], int size) {
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

void Swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}
```

## 插入排序(Insertion Sort)

**算法思想**：在构建有序序列后，对于未排序的元素，扫描有序序列并插入到对应位置。
**算法特点**：对于一个接近有序的数组而言，速度远比选择排序快。
**算法步骤**：

1. 假定第一个元素已经排序完毕，形成了已排序序列;
2. 取出未排序序列的下一个元素x，在已排序的序列中扫描;
3. 扫描过程中，若已排序元素y大于x，则元素y后移一个位置;
4. 重复步骤3，直到找到已排序元素小于或等于x的位置，在此位置后插入未排序元素x;
5. 重复步骤2~5，直到排序完成。

**CPP代码**：

```cpp
// 插入排序（Insertion Sort）
void InsertSort(int arr[], int size) {
    int preIndex, current;
    for (int i = 1; i < size; ++i) {
        preIndex = i - 1;
        current = arr[i];
        while (preIndex >= 0 && arr[preIndex] > current) {
            arr[preIndex + 1] = arr[preIndex];
            --preIndex;
        }
        arr[preIndex + 1] = current;
        PrintArray(arr, size);
    }
}
```

## 希尔排序(Shell Sort)

**算法思想**：作为插入排序的改进版，希尔排序假设任意间隔`gap`内的元素都是有序的，这样优先插入排序间隔`gap`的若干个元素，然后逐渐减小`gap`值，直至`gap`值为1时便完成排序。
**算法特点**：希尔排序相比插入排序更高效的原因在于其权衡了子数组的规模和有序性。
**算法步骤**：
       1. 初始化`gap=N/2`，则原序列中存在间隔为`gap`的若干组无序元素序列，对这些无序序列分别使用插入排序有序化;
       2. 缩小间隔`gap=gap/2`，将原序列中间隔`gap`的无序序列可以分别使用插入排序有序化;
       3. 重复步骤2，直到`gap=1`时，再次使用插入排序，原序列排序即可完成。

**CPP代码**：

```cpp
// 希尔排序（Shell Sort）
void ShellSort(int arr[], int size) {
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
```

### 归并排序(Merge Sort)

**算法思想**：归并排序是分治法的典型应用。它通过将已有的子序列合并，来得到有序的完整序列。如果是两个有序表合并为一个有序表，称之为2-路归并。

**算法特点**：性能稳定，与选择排序类似，归并排序并不受输入数据的影响，但性能优于前者，其时间复杂度为O(n*logn)，但空间复杂度较高，因为在排序过程中需要额外的内存空间。

**算法步骤**：

1. 将长度为N的序列分成两个长度为N/2的子序列；
2. 对子序列重复进行步骤1的划分，直到不能分割为止；
3. 对以上子序列进行两两归并，直到合并成一个有序的序列。

**CPP代码**：

```c++
// 归并排序（Merge Sort）
void MergeSort(int arr[], int size) {
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

void Merge(int arr[], const int *L, int leftCount, const int *R, int rightCount) {
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
```



### 快速排序(Quick Sort)

TODO

### 堆排序(Heap Sort)

TODO

### 计数排序(Counting Sort)

TODO

### 桶排序(Bucket Sort)

TODO

### 基数排序(Radix Sort)

TODO