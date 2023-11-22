#include <stdio.h>

void selectionSort(int arr[],int size){
    int i,j,min;
    for(i=0;i<size-1;i++){
        min=i;
        for(j=i+1;j<size;j++){
            if(arr[j]<arr[min]){if(arr[j])
                min=j;
            }
        }
    if(min!=i){
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
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
    selectionSort(arr,size);
    printf("\nAfter Sorting: ");
    
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}