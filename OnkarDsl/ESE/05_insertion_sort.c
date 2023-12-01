#include <stdio.h>
//principle sorted sublist|unsorted sublist
// find appropriate position for element in the unsorted sublist to put in the sorted sublist
int passes=0;
void insertionSort(int arr[],int size){
    int i,j,temp;
    for(i=1;i<size;i++){
        temp=arr[i];
        passes++;
        j=i-1;
        while(j>=0 && arr[j]>temp){
                arr[j+1]=arr[j];
                j--;
            }
        arr[j+1]=temp;
        }
        
    }

int main(){
    int arr[]={9,5,10,80,3,2,5};
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

    printf("\nPasses: %d",passes);
    return 0;
}