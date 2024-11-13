#include <iostream>

using namespace std;

int BinarySearch(int arr[], int low, int high, int target){
    if(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] > target) return BinarySearch(arr, low, mid-1, target);
        else return BinarySearch(arr, mid+1, high, target);
    }

    return -1;
}

int main(){

    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    int index = BinarySearch(arr, 0, size-1, target);
    
    if(index < 0) cout<<"Element not found";
    else cout<<"Element found at index: "<<index;

    return 0;
}