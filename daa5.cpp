
#include <bits/stdc++.h>
using namespace std;

// Common Partition Function
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];

    int i = low;
    int j = high;

    while (i < j) {

        while (i < high && arr[i] <= pivot)
            i++;

        while (j > low && arr[j] > pivot)
            j--;

        if (i < j)
            swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);

    return j;
}

// Deterministic Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Randomized Partition
int randomizedPartition(vector<int>& arr, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);

    swap(arr[low], arr[randomIndex]);

    return partition(arr, low, high);
}

// Randomized Quick Sort
void randomizedQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high);

        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

int main() {

    vector<int> arr1 = {8, 3, 1, 7, 0, 10, 2};
    vector<int> arr2 = arr1;

    // Deterministic Quick Sort
    quickSort(arr1, 0, arr1.size() - 1);

    cout << "Deterministic Quick Sort: ";
    for (int x : arr1)
        cout << x << " ";

    cout << endl;

    // Randomized Quick Sort
    randomizedQuickSort(arr2, 0, arr2.size() - 1);

    cout << "Randomized Quick Sort: ";
    for (int x : arr2)
        cout << x << " ";

    cout << endl;

    return 0;
}
