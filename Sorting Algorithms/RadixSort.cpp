#include <iostream>
using namespace std;

void PrintArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void SelectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
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
    SelectionSort(arr, size);
    cout << "\nThe sorted array: ";
    PrintArray(arr, size);
    delete[] arr;
    return 0;
}