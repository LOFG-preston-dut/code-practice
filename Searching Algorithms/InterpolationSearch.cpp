#include <iostream>

using namespace std;

void Print(const int arr[], int size, int result, int x) {
    cout << "\n The imported array: [ ";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << " ]" << endl;

    if (result != -1) {
        cout << "=> Find the value of " << x << " at the position (index): " << result << endl;
    } else {
        cout << "=> Cannot find the value " << x << " in the array." << endl;
    }
}

int InterpolationSearch(int arr[], int size, int x) {
    int low = 0;
    int high = size - 1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (arr[low] == arr[high]) {
            if (arr[low] == x) return low;
            return -1;
        }

        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]));

        if (arr[pos] == x) {
            return pos;
        }

        if (arr[pos] < x) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }

    return -1;
}

int main() {
    int n;

    cout << "Enter the number of array elements (n > 0): ";
    cin >> n;

    if (n <= 0) {
        cout << "The number of elements n must be greater than 0" << endl;
        return 0;
    }

    int arr[n];

    cout << "Enter" << n << " elements sorted in ascending order.\n";
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    int x;
    cout << "\nEnter which needed to find ";
    cin >> x;
    int index = InterpolationSearch(arr, n, x);
    Print(arr, n, index, x);

    return 0;
}