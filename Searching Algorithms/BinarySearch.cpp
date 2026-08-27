#include <iostream>

using namespace std;

void Print(const int arr[], int size, int result, int x) {
    if (result != -1) {
        cout << result << endl;
    } else {
        cout << -1 << endl;
    }
}

int BinarySearch(int arr[], int size, int x) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n;
    cin >> n;

    if (n <= 0) {
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    int index = BinarySearch(arr, n, x);
    Print(arr, n, index, x);

    return 0;
}