#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node * prev;
  struct node * next;
};

struct node * head,*tail;

void create(){
    struct node * newnode = (struct node * )malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&newnode->data);
    newnode->prev = 0;
    newnode->next = 0;
    if(head==0){
        head = tail = newnode;
    }
    else{
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void insertatbegin(){
    int data;
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&newnode->data);
    newnode->prev = 0;
    newnode->next = 0;
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}

void insertatend(){
    int data;
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&newnode->data);
    newnode->prev = 0;
    newnode->next = 0;
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

void insertatpos(){
    int pos,i=1;
    printf("Enter postion : ");
    scanf("%d",&pos);
    if(pos<1){
        printf("invalid postion");
    }
    else if(pos==1){
        insertatbegin();
    }
    else{
        struct node * newnode = (struct node * )malloc(sizeof(struct node));
        struct node * temp = head;
        printf("Enter data : ");
        scanf("%d",&newnode->data);
        while(i < pos - 1){
            temp = temp -> next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->prev = newnode;  // my way
        
    }
}

void insertafterpos(){
    int pos,i=1;
    printf("Enter postion : ");
    scanf("%d",&pos);
    if(pos<1){
        printf("invalid postion");
    }
    else{
        struct node * newnode = (struct node * )malloc(sizeof(struct node));
        struct node * temp = head;
        printf("Enter data : ");
        scanf("%d",&newnode->data);
        while(i < pos ){
            temp = temp -> next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->prev = newnode;  // my way
        
    }
}

void display(){
    struct node * temp;
    temp = head;
    while(temp!=NULL){
        printf("Element : %d\n",temp->data);
        temp = temp->next;
    }
}

int main(){
    int ops;
    while(ops!=7){
    printf("1) Create linked List \n2) Display List \n3) insert at begin \n4) Insert at end \n5) insert at postion \n6) insert after postion \n7) Exit \n");
    printf("Enter the choice ");
    scanf("%d",&ops);
    switch(ops){
        case 1: 
           create();
           break;
        case 2:
           display();
           break;
        case 3:
           insertatbegin();
           break;
        case 4:
           insertatend();
           break;
        case 5:
           insertatpos();
           break;
        case 6:
           insertafterpos();
           break;
        case 7:
           break;
        default:
           printf("Invalid option");
        }    
    }
}
