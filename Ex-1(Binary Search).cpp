#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

int binarySearchRecursive(const vector<int>& arr, int target, int low, int high) {
    if (low > high) {
        return -1; // Base case: target not found
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {
        return mid; // Base case: target found at index mid
    } else if (arr[mid] < target) {
        return binarySearchRecursive(arr, target, mid + 1, high); // Search right half
    } else {
        return binarySearchRecursive(arr, target, low, mid - 1); // Search left half
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements in sorted order:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target element to search: ";
    cin >> target;

    auto start = high_resolution_clock::now();
    int result = binarySearchRecursive(arr, target, 0, n - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    cout << "Time taken: " << duration.count() << " milliseconds" << endl;

    return 0;
}

