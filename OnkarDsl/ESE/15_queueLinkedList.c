#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if(front == NULL && rear == NULL){
        front = rear = newnode;
        return;
    }
    rear->next = newnode;
    rear = newnode;
}

void dequeue(){
    if(front == NULL && rear == NULL){
        printf("\nUnderflow!");
        return;
    }
    printf("\nDequeue Element: %d",front->data);
    struct node *temp=front;
    front = front->next;
    free(temp);
}

void peak(){
    if(front == NULL && rear == NULL){
        printf("\nEmpty Queue!");
        return;
    }
    printf("\nPeak Element: %d", front->data);
}

void display(){
    if(front == NULL && rear == NULL){
        printf("\nEmpty Queue!");
        return;
    }
    struct node *temp = front;
    printf("\n[ ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("]\n");
}

int main(){
    enqueue(9);
    enqueue(80);
    enqueue(45);
    display();
    peak();
    dequeue();
    display();
    peak();
    return 0;
}