#include <stdio.h>
#include <stdlib.h>

int linearSearch(int arr[],int target){
	int i;
	for(i=0;i<10;i++){
		if(arr[i]==target){
			return i;
		}
	}
	return -1;
}

int recursiveLinSearch(int arr[],int i,int target){
    if (i < 0) {
        return -1; // Target not found in the array
    }
    if (arr[i] == target) {
        return i; // Target found at index i
    } else {
        return recursiveLinearSearch(arr, i - 1, target); // Continue searching with the previous index
    }	
}
int binarySearch(int arr[],int target){
	int left = 0, right = 9,mid;
	while(left<=right){
		mid = (left+right)/2;
		if(arr[mid]==target){
			return mid;
		}
		else if(arr[mid]>target){
			right = mid-1;
		}
		else{
			left = mid+1;
		}
	}
	return -1;
}

int recursiveBinSearch(int arr[],int low,int high,int target){
	int mid;
	if(low<=high){
		mid=(low+high)/2;
		if(arr[mid]==target){
			return mid;
		}
		else if(target>arr[mid]){
			return recursiveBinSearch(arr,mid+1,high,target);
		}
		else{
			return recursiveBinSearch(arr,low,mid-1,target);
		}
	}
	return -1;
}

int main() {
	int arr[10],i,target,num;
	printf("Enter elements of an integer array: ");
	for(i=0;i<10;i++){
		scanf("%d",&arr[i]);
	}
	printf("\nEnter the element to search in the array: ");
	scanf("%d",&target);
	printf("\n1. Linear Search\n2. Binary Search\n3. Recursive Binary Search\n4. Recursive Linear Search\nPress Key: ");
	scanf("%d",&num);
	switch(num){
		case 1:
	if(linearSearch(arr,target)==-1){
		printf("\nTarget not found!");
	}
	else{
		printf("\nTarget found at index: %d",linearSearch(arr,target));
	}
	break;
	case 2: 
	if(binarySearch(arr,target)==-1){
		printf("\nTarget not found!");
	}
	else{
		printf("\nTarget found at index: %d",binarySearch(arr,target));
	}
	break;
	case 3:
	if(recursiveBinSearch(arr,0,9,target)==-1){
		printf("\nTarget not found!");
	}
	else{
		printf("\nTarget found at index: %d",recursiveBinSearch(arr,0,9,target));
	}
	break;	
	case 4:
	if(recursiveLinSearch(arr,0,target)==-1){
		printf("\nTarget not found!");
	}
	else{
		printf("\nTarget found at index: %d",recursiveLinSearch(arr,0,target));
	}
	break;	
    default: 
    printf("Invalid Input!");
}		
	return 0;
}
