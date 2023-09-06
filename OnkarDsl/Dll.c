#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head,*tail=NULL;

void create(){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data: ");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL){
        head=tail=newnode;
        head->prev=NULL;
        tail->next=NULL;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
        tail->next=NULL;
    }
}
void display(){
    struct node *temp = head;
    if(head==NULL){
        printf("\nList is empty!");
    }
    printf("\n[ ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf(" ]\n");
}
void insertatbegin(){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data: ");
    scanf("%d",&newnode->data);
    if(head==NULL){
        head=tail=newnode;
        head->prev=NULL;
        tail->next=NULL;
    }
    else{
        head->prev=newnode;
        newnode->next=head;
        newnode->prev=NULL;
        head=newnode;
    }
}
void insertatend(){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=tail;
    tail->next=newnode;
    tail=newnode;
}
void insertatpos(){
    int pos,i=1;
    printf("Enter position: ");
    scanf("%d",&pos);
    if(pos<1){
        printf("Invalid position!");
        return;
    }
    else if(pos==1){
        insertatbegin();
    }
    else{
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter data: ");
        scanf("%d",&newnode->data);      
        struct node *temp=head;
        while(pos-1!=i){
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next->prev=newnode;
        temp->next=newnode;
        newnode->prev=temp;

    }
}
void insertafterpos(){
    int pos,i=1;
    printf("Enter position: ");
    scanf("%d",&pos);
    if(pos<1){
        printf("Invalid position!");
        return;
    }
    else if(pos==1){
        insertatbegin();
    }
    else{
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter data: ");
        scanf("%d",&newnode->data);      
        struct node *temp=head;
        while(pos!=i){
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next->prev=newnode;
        temp->next=newnode;
        newnode->prev=temp;

    }   
}
void deleteatbegin(){
    struct node *temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);
}
void deleteatend(){
    struct node *temp=tail;
    tail=tail->prev;
    tail->next=NULL;
    free(temp);
}
void deleteatpos(){
    int pos,i=1;
    printf("Enter position: ");
    scanf("%d",&pos);
    if(pos<1){
        printf("Invalid position!");
        return;
    }
    else if(pos==1){
        deleteatbegin();
    }
    else{     
        struct node *temp=head;
        while(pos!=i){
            temp=temp->next;
            i++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
}
void deleteafterpos(){
    int pos,i=1;
    printf("Enter position: ");
    scanf("%d",&pos);
    if(pos<1){
        printf("Invalid position!");
        return;
    }
    else if(pos==1){
        deleteatbegin();
    }
    else{     
        struct node *temp=head;
        while(pos+1!=i){
            temp=temp->next;
            i++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
}
void search(){
    int data;
    printf("Enter data: ");
    scanf("%d",&data);
    struct node *temp=head;
    int count=0; //starting counting from 0
     while(temp!=NULL){
        temp=temp->next;
        count++;
        if(temp!=NULL && temp->data==data){
            printf("\nElement found at %d position",count);
            return;
        }
    }
    printf("\nElement not found!\n");   
}
void sort(){
    struct node *p=head,*q=NULL;
    while(p->next!=NULL){
        q=p->next;
        while(q!=NULL){
            if(p->data > q->data){
                int temp = p->data;
                p->data=q->data;
                q->data=temp;
            }
            q=q->next;
        }
        p=p->next;
    }
}
void main(){
    int ops;
    while(ops!=7){
    printf("\n1) Create linked List \n2) Display List \n3) insert at begin \n4) Insert at end \n5) insert at postion \n6) insert after postion \n7) Exit \n");
    printf("8) deleteatbegin\n9) deleteatend\n10) deleteatpos\n11) deleteafterpos\n12) search\n13) Sort\n");
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
        case 8:
            deleteatbegin();
            break;
        case 9:
            deleteatend();
            break;
        case 10:
            deleteatpos();
            break;
        case 11:
            deleteafterpos();
            break;
        case 12:
            search();
            break;
        case 13:
            sort();
            break;
        default:
           printf("Invalid option");
        }    
    }
}
