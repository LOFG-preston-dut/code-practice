#include <iostream>
using namespace std;

void PrintArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void QuickSortRecursive(int arr[], int low, int high){
    if (low >= high) return;

    int pivot = arr[(low+high)/2];
    int i = low;
    int j = high;

    while (i <= j){
        while (arr[i] < pivot){
            i++;
        }

        while (arr[j] > pivot){
            j--;
        }

        if (i <= j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (low < j) QuickSortRecursive(arr, low, j);
    if (i < high) QuickSortRecursive(arr, i, high);
}

void QuickSort(int arr[], int size){
    if (size > 1){
        QuickSortRecursive(arr,0,size-1);
    }
}

int main(){
    int size;
    cout << "Enter the elements n of the array" << endl;
    cin >> size;
    if (size <=0){
        cout <<"The size of the array must be greater than 0" <<endl;
        return 0;
    }
    int arr[size];
    cout << "Enter " << size << "elements of the array" << endl;
    for (int i = 0; i < size; i++){
        cout << "arr[" <<i<<"] = " <<endl;
        cin >> arr[i];
    }
    cout << "\n The original array: ";
    PrintArray(arr,size);
    QuickSort(arr,size);
    cout <<endl;
    cout << "\n The sorted array: ";
    PrintArray(arr,size);
    return 0;
}
