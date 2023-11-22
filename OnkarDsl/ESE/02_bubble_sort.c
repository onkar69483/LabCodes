#include <stdio.h>

void bubbleSort(int arr[],int size){
    int i,j,FLAG=0;
    for(i=0;i<size-1;i++){
        for(j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                FLAG=1;
            }
        }
        if(FLAG==0){
            return;
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
    bubbleSort(arr,size);
    printf("\nAfter Sorting: ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}