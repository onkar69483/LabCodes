#include <stdio.h>

int linearSearch(int arr[],int size,int target){
    int i;
    for(i=0;i<size;i++){
        if(target==arr[i]){
            return i;
        }
    }
    return -1;
}

int recursiveLinearSearch(int arr[], int i, int target){
    if(i<0){
        return -1;
    }
    if(target==arr[i]){
        return i;
    }
    else return recursiveLinearSearch(arr,i-1,target);
}

int binarySearch(int arr[],int size,int target){
    int low=0,high=size-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(arr[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}

int recursiveBinarySearch(int arr[], int low, int high, int target){
    if (low <= high) {
        int mid = (low + high) / 2;
        printf("Entered loop! Low: %d, High: %d, Mid: %d\n", low, high, mid); // Print indices and mid
        if (arr[mid] == target) {
            return mid; // Element found at mid
        } else if (arr[mid] > target) {
            return recursiveBinarySearch(arr, low, mid - 1, target); // Search in the left half
        } else {
            return recursiveBinarySearch(arr, mid + 1, high, target); // Search in the right half
        }
    }
    else return -1; // Element not found in the array
}



int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("Size: %d",size);
    int choice=0,result;
    while(choice!=5){
        printf("\nMenu");
        printf("\n1.Linear Search");
        printf("\n2.Recursive Linear Search");
        printf("\n3.Binary Search");
        printf("\n4.Recursive Binary Search");
        printf("\n5.Quit\n");
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            result=linearSearch(arr,size,5);
            if(result!=-1) printf("Element found at %d\n",result);
            else printf("Element not found!\n");
            break;
        case 2:
            result=recursiveLinearSearch(arr,size-1,5);
            if(result!=-1) printf("Element found at %d\n",result);
            else printf("Element not found!\n");
            break;
        case 3:
            result=binarySearch(arr,size,5);
            if(result!=-1) printf("Element found at %d\n",result);
            else printf("Element not found!\n");
            break;
        case 4:
            result=recursiveBinarySearch(arr,0,size-1,5);
            if(result!=-1) printf("Element found at %d\n",result);
            else printf("Element not found!\n");
            break;
        case 5:
            printf("Exiting!\n");
            break;
        default:
            printf("Exiting!\n");
            choice=5;
            break;
        }
    }
    return 0;
}