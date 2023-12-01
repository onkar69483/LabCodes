#include <stdio.h>

#define V 5

void init(int arr[V][V]){
    int i, j;
    for(i=0; i<V; i++){
        for(j=0; j<V; j++){
            arr[i][j] = 0;
        }
    }
}

void addEdge(int arr[V][V]){
    int i, j, w;
    printf("\nEnter vertices of edge: ");
    scanf("%d %d", &i, &j);
    printf("\nEnter the weight: ");
    scanf("%d", &w);
    arr[i-1][j-1] = w;
    arr[j-1][i-1] = w;
}

void printMatrix(int arr[V][V]){
    int i, j;
    
    for(i=0; i<V; i++){
        printf("\n[ ");
        for(j=0; j<V; j++){
            printf("%d ", arr[i][j]);
        }
        printf("]");
    }
    printf("\n");
}

int main(){
    int adj[V][V];
    init(adj);
    int choice = -1;
    while(choice != 0){
        printf("\n1. Add Edge");
        printf("\n2. Print Matrix");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addEdge(adj);
                break;
            case 2:
                printf("\nAdjacency Matrix: ");
                printMatrix(adj);
                break;
            case 0:
                printf("\nExiting the program!");
                break;
            default:
                printf("\nExiting the program!");
                break;
        }
    }
    return 0;
}