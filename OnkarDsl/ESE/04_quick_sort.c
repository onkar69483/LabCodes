#include <stdio.h>

int partition(int arr[], int lb,int ub){
    int pivot=arr[lb], start=lb, end=ub;    
    while(start<end){
    while(arr[start]<=pivot){
        start++;
    }
    while(arr[end]>pivot){
        end--;
    }
    if(start<end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
    }
    }
    int temp=arr[end];
    arr[end]=arr[lb];
    arr[lb]=temp;

    return end;
}

void quickSort(int arr[], int lb, int ub){
    int loc;
    if(lb<ub){
        loc=partition(arr, lb, ub);
        quickSort(arr, lb, loc-1);
        quickSort(arr, loc+1, ub);
    }
}

int main(){
    int arr[]={10,9,8,7,6,5,4,3,2,1};
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("\nBefore Sorting: ");
    int i;
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    quickSort(arr, 0, size);
    printf("\nAfter Sorting: ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}