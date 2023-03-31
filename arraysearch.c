#include <stdio.h>
int arraysearch(){
	int i,n,a[100],num;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	printf("Enter the elements of the array: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Enter the element to be searched: ");
	scanf("%d",&num);
	for(i=0;i<n;i++){
		if(a[i]==num){
			printf("Element found!");
			return 0;
		}
	}
	printf("Element not found!");
	return 0;
}
