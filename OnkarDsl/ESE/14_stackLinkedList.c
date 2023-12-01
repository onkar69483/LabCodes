#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = top;
    top = newnode;
}

void pop(){
    struct node *temp = top;
    if(top == NULL){
        printf("\nUnderFlow!");
        return;
    }
    printf("\nPop: %d", top->data);
    top = top->next;
    free(temp);
}

void peek(){
    if(top==NULL){
        printf("\nStack is Empty!");
        return;
    }
    else{
        printf("\nTop element: %d",top->data);
    }
}

void display(){
    struct node *temp = top;
    if(top == NULL){
        printf("\nList is Empty!");
        return;
    }
    printf("\n[ ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("]\n");
}

int main(){
    push(5);
    push(6);
    push(34);
    display();
    peek();
    pop();
    display();
    peek();
    return 0;
}