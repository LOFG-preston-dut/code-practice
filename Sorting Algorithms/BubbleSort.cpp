#include <iostream>
using namespace std;

void PrintArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] <<" ";
    }
    cout << endl;
}

void BubbleSort(int arr[], int size){
    for (int i = 0; i < size - 1; i++){
        bool swapped = false;

        for (int j = 0; j < size - i - 1; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }

        if (!swapped){
            break;
        }
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
    BubbleSort(arr,size);
    cout <<endl;
    cout << "\n The sorted array: ";
    PrintArray(arr,size);
    return 0;
}
