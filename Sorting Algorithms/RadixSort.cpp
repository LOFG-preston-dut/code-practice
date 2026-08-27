#include <iostream>
using namespace std;

void PrintArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int GetMax(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    return maxVal;
}

void CountSort(int arr[], int size, int exp) {
    int* output = new int[size];
    int count[10] = {0};

    for (int i = 0; i < size; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }

    delete[] output;
}

void RadixSort(int arr[], int size) {
    int maxVal = GetMax(arr, size);
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        CountSort(arr, size, exp);
    }
}

int main() {
    int size;
    cout << "Enter the elements n of the array: ";
    cin >> size;

    if (size <= 0) {
        cout << "The size of the array must be greater than 0" << endl;
        return 0;
    }

    int* arr = new int[size];

    cout << "Enter " << size << " elements of the array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    cout << "\nThe original array: ";
    PrintArray(arr, size);

    RadixSort(arr, size);

    cout << "\nThe sorted array: ";
    PrintArray(arr, size);

    delete[] arr;
    return 0;
}