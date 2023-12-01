/*
OUTPUT:-
[0]->4->1
[1]->4->3->2->0
[2]->3->1
[3]->4->2->1
[4]->3->1->0
*/

#include <stdio.h>
#include <stdlib.h>

//Creating Linked List to store adjacency list
struct node{
    int data;
    struct node *next;
};

//Creating an array of linked list
struct list{
    struct node *head;
};

//Creating graph which has vertices and array of adjacency lists
//Size of array will be V number of vertices in graph
struct Graph{
    int V;
    struct list *array;
};

//Creating node of adjacency linked list
struct node *createNode(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

//Creating graph with vertices V and array of linked list of size V
//Initializing all heads to NULL
struct Graph *createGraph(int V){
    struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct list*)malloc(sizeof(struct list)*V);
    
    int i;
    for(i=0; i<V; i++){
        graph->array[i].head = NULL;
    }

    return graph;
}

//Adding edges in graph, 2sided
void addEdge(struct Graph *graph, int src, int des){
    struct node *temp = createNode(des);
    temp->next = graph->array[src].head;
    graph->array[src].head = temp;

    struct node *ntemp = createNode(src);
    ntemp->next = graph->array[des].head;
    graph->array[des].head = ntemp;
}


//Printing Graph using adjacency lists
void printGraph(struct Graph *graph){
    int v;
    for(v=0; v<graph->V; v++){
        struct node *temp = graph->array[v].head;
        printf("[%d]",v);
        while(temp != NULL){
            printf("->%d", temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

int main(){
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
 
    // print the adjacency list representation of the above graph
    printGraph(graph);
    return 0;
}