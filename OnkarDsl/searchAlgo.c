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

int main() {
	int arr[10],i,target,num;
	printf("Enter elements of an integer array: ");
	for(i=0;i<10;i++){
		scanf("%d",&arr[i]);
	}
	printf("\nEnter the element to search in the array: ");
	scanf("%d",&target);
	printf("\n1. Linear Search\n2. Binary Search\nPress Key: ");
	scanf("%d",&num);
	switch(num){
		case 1:
	if(binarySearch(arr,target)==-1){
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
    default: 
    printf("Invalid Input!");
}		
	return 0;
}
