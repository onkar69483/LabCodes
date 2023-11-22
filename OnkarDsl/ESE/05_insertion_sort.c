#include <stdio.h>
//principle sorted sublist|unsorted sublist
// find appropriate position for element in the unsorted sublist to put in the sorted sublist

void insertionSort(int arr[],int size){
    int i,j,temp;
    for(i=1;i<size;i++){
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp){
                arr[j+1]=arr[j];
                j--;
            }
        arr[j+1]=temp;
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
    insertionSort(arr,size);
    printf("\nAfter Sorting: ");
    
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}