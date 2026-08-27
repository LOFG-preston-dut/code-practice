#include <iostream>
using namespace std;

void PrintArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void ShellSort(int arr[], int size){
    for (int gap = size/2; gap > 0; gap = gap/2){

        for (int i = gap; i < size; i++){
            int temp = arr[i];
            int j = i;
        
            while (j >= gap && arr[j-gap] > temp){
                arr[j] = arr[j-gap];
                j = j - gap;
            }

            arr[j] = temp;
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
    int* arr = new int[size];
    cout << "Enter " << size << "elements of the array" << endl;
    for (int i = 0; i < size; i++){
        cout << "arr[" <<i<<"] = " <<endl;
        cin >> arr[i];
    }
    cout << "\n The original array: ";
    PrintArray(arr,size);
    ShellSort(arr,size);
    cout <<endl;
    cout << "\n The sorted array: ";
    PrintArray(arr,size);

    delete[] arr;
    return 0;
}
