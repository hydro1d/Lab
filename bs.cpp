#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }


   // sort(arr, arr + n);

    cout << "Enter the value you want to search: ";
    int target;
    cin >> target;

    int result = binarySearch(arr, n, target);

    if (result != -1) {
        cout << "Found at index: " << result << endl;
    } else {
        cout << "Not found" << endl;
    }
}

