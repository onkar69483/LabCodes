#include <iostream>
using namespace std;

int LinearSearch(int arr[],int index,  int size, int target){

    if (index == size){
        return -1;
    } else if(target == arr[index]){
        return index;
    } else {
        return LinearSearch(arr, index+1, size, target);
    }
}

int main(){

    int arr[] = {4,5,62,3,4,5,6,7,2,6};

    int target = 7;

    int size = sizeof(arr) / sizeof(arr[0]);

    int index = LinearSearch(arr,0, size, target);

    if(index < 0){
        cout<<"Element not found"<<endl;
    }else {
        cout<<"Element found at index: "<<index<<endl;
    }


    return 0;
}