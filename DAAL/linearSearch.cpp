#include <iostream>

using namespace std;

int linearSearch(int arr[], int size, int target){
    if(size < 0){
        return -1;
    } else if (arr[size-1] == target){
        return size-1;
    } else {
        return linearSearch(arr, size-1, target);
    }
    return -1;
}

int main() {
    int arr[] = {1,2,3,4,5};
    int res = linearSearch(arr, 5, 4);
    cout<<res;
    return 0;
}
