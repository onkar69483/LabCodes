#include <iostream>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int lb, int ub){
    int pivot = arr[lb];
    int start = lb;
    int end = ub;

    while (start <= end){
        while (arr[start] <= pivot){
            start++;
        }

        while (arr[end] > pivot){
            end--;
        }

        if(start < end){
            swap(arr[start], arr[end]);
        }
    }

    swap(arr[lb], arr[end]);
    return end;
}

void QuickSort(int arr[], int lb, int ub){
    if(lb < ub){
        int loc = partition(arr, lb, ub);
        QuickSort(arr, lb, loc-1);
        QuickSort(arr, loc+1, ub);
    }
}

int main(){
    int arr[] = {6,7,4,5,3,2,9,8,1,10};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    QuickSort(arr, 0, size-1);

    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}