#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main() {
	int arr1[] = {49,56,2,3};
	int i,j;
	for(j=0;j<4;j++){
	for(i=0;i<4;i++){
		if(arr1[i]>arr1[j]){
         int temp = arr1[i];
         arr1[i] = arr1[j];
         arr1[j] = temp;
		}
	}
}
    for(i=0;i<4;i++){
    	printf("%d ",arr1[i]);
    }
	return 0;
}
