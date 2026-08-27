#include <iostream>

using namespace std;

void Print(const int arr[], int size, int result, int x) {
    cout << "\nEntered array: [ ";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << " ]" << endl;

    if (result != -1) {
        cout << "=> Found value " << x << " at index: " << result << endl;
    } else {
        cout << "=> Value " << x << " not found in the array." << endl;
    }
}

int sequentialSearch(int arr[], int size, int x) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int n;
    cout << "Enter the number of elements (n > 0): ";
    cin >> n;
    if (n <= 0) {
        cout << "Invalid number of elements!" << endl;
        return 0;
    }
    int arr[n];
    cout << "Enter " << n << " elements (in any order):\n";
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
    int x;
    cout << "\nEnter the value x to search for: ";
    cin >> x;
    int index = sequentialSearch(arr, n, x);
    Print(arr, n, index, x);
    return 0;
}