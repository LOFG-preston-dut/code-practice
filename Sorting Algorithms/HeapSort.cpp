#include <iostream>
using namespace std;

void PrintArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if (right < n && arr[largest] < arr[right]){
        largest = right;
    }

    if (largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        Heapify(arr, n, largest);
    }
}

void HeapSort(int arr[], int size){
    for (int i = size/2 - 1; i >= 0; i--){
        Heapify(arr, size, i);
    }

    for (int i = size - 1; i >= 0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        Heapify(arr, i, 0);

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
    int* arr = new int[size];
    
    cout << "Enter " << size << "elements of the array" << endl;
    for (int i = 0; i < size; i++){
        cout << "arr[" <<i<<"] = " <<endl;
        cin >> arr[i];
    }
    cout << "\n The original array: ";
    PrintArray(arr,size);
    HeapSort(arr,size);
    cout <<endl;
    cout << "\n The sorted array: ";
    PrintArray(arr,size);
    return 0;
}
