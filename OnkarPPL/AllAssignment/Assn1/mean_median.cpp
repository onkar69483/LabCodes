#include <iostream>
using namespace std;

double mean(int arr[],int size){
    double sum=0;
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    return (sum/size);
}


void bubble_sort(int arr[],int size){
    int i,j;
    for(i=0;i<size-1;i++){
        for(j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

double median(int arr[],int size){
    if(size%2==0){
        return (arr[size/2-1]+arr[size/2])/2;
    }
    else return arr[size/2];
}


int main(){
    int arr[5] = {4,8,2,6,9};
    int size=5;
    cout<<mean(arr,size)<<endl;
    bubble_sort(arr,size);
    cout<<median(arr,size);
    return 0;
}