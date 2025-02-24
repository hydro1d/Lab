#include <iostream>
using namespace std;


int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);  /
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Find partition index

        quickSort(arr, low, pi - 1);  // Recursively sort the left subarray
        quickSort(arr, pi + 1, high);  // Recursively sort the right subarray
    }
}

// Helper function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};  // Example array
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);  // Call quickSort

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}

