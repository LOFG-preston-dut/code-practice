#include <iostream>
using namespace std;

void PrintArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] <<" ";
    }
    cout << endl;
}

void SelectionSort(int arr[], int size){
    for (int i = 0; i < size; i++){
        int MinIndex = i;
        for (int j = i+1; j < size; j++){
            if (arr[j] < arr[MinIndex]){
                MinIndex = j;
            }
        }
        if (MinIndex != i){
            int temp = arr[i];
            arr[i] = arr[MinIndex];
            arr[MinIndex] = temp;
        }
    }
}

int main(){
    int size;
    cout << "Enter the elements n of the array" << endl;
    cin >> size;
    int arr[size];
    cout << "Enter " << size << "elements of the array" << endl;
    for (int i = 0; i < size; i++){
        cout << "arr[" <<i<<"] = " <<endl;
        cin >> arr[i];
    }
    cout << "\n The original array: ";
    PrintArray(arr,size);
    SelectionSort(arr,size);
    cout <<endl;
    cout << "\n The sorted array: ";
    PrintArray(arr,size);
    return 0;
}