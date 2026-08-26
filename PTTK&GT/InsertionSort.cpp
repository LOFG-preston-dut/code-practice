#include <iostream>

void InsertionSort(int arr[], int n){
    for (int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}
void PrintArray(int arr[], int size){
    for (int i = 0; i<size; i++){
        std::cout <<arr[i]<<" ";
    }
    std::cout << std::endl;
}

int main(){
    int n;
    std::cout <<"Enter the number of elements n";
    std::cin >> n;
    if (n <= 0){
        std::cout <<"The number of elements n must be greater than 0"<< std::endl;
        return 0;
    }

    int* arr = new int[n];
    std::cout << "Enter " << n << " elements of the array";
    for (int i = 0; i < n; i++){
        std::cin >>arr[i];
    }
    std::cout << "\nOriginal Array: ";
    PrintArray(arr,n);

    InsertionSort(arr,n);

    std::cout << "\nThe Sorted Array: "; 
    PrintArray(arr, n);
    delete[] arr;
    return 0;
}