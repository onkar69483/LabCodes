#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *next;
};

struct node *createNode(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void printList(struct node *head){
    if(head==NULL){
        printf("\nList is Empty!");
        return;
    }
    struct node *current=head;
    printf("\n[ ");
    do{
        printf("%d-> ", current->data);
        current=current->next;
    }while(current!=head);
    printf(" ]\n");
}

struct node *insertAtBegin(struct node *head, int data){
    struct node *newnode = createNode(data);
    if(head==NULL){
        newnode->next=newnode;
        head = newnode;
        return head;
    }
    struct node *last=head;
    while(last->next!=head){
        last=last->next;
    }
    newnode->next=head;
    last->next=newnode;
    head=newnode;
    return head;
}

struct node *insertAtEnd(struct node *head, int data){
    struct node *newnode = createNode(data);
    if(head==NULL){
        newnode->next=newnode;
        head=newnode;
        return head;
    }
    struct node *last=head;
    while(last->next!=head){
        last=last->next;
    }
    newnode->next=head;
    last->next=newnode;
    return head;
}

struct node *insertAtPosition(struct node *head, int position, int data){
    if(position<=1 || head==NULL){
        head=insertAtBegin(head, data);
        return head;  
    }
    int pos=1;
    struct node *newnode = createNode(data);
    struct node *temp=head;
    while(temp->next!=head && pos<position-1){
        temp=temp->next;
        pos++;
    }

    if(temp->next==head && position!=position-1){
        printf("\nInsertion Not Possible!");
        return head;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}

struct node *insertAfterElement(struct node *head, int element, int data){
    struct node *newnode = createNode(data);
    struct node *temp=head;
    if(head==NULL){
        head=insertAtBegin(head,data);
        return head;
    }
    while(temp->next!=head && temp->data!=element){
        temp=temp->next;
    }
    if(temp->next==head && temp->data!=element){
        printf("\nElement not Found!");
        return head;
    }
    if(temp->next==head && temp->data==element){
        head = insertAtEnd(head,data);
        return head;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}

struct node *deleteAtBegin(struct node *head){
    if(head==NULL){
        return NULL;
    }

    if(head->next==head){
        free(head);
        return NULL;
    }

    struct node *last=head;
    while(last->next!=head){
        last=last->next;
    }

    struct node *temp=head;
    head=head->next;
    last->next=head;
    free(temp);
    return head;
}

struct node *deleteAtEnd(struct node *head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==head){
        free(head);
        return NULL;
    }

    struct node *last=head;
    while(last->next->next!=head){
        last=last->next;
    }
    struct node *temp=last->next;
    last->next=head;
    free(temp);
    return head;
}

struct node *deleteAtPos(struct node *head, int position){
    if(position<=1){
        head=deleteAtBegin(head);
        return head;
    }
    int pos=1;
    struct node *temp=head;
    while(temp->next!=head && pos<position-1){
        temp=temp->next;
        pos++;
    }
    if(temp->next==head){
        printf("\nInvalid Position");
        return head;
    }
    struct node *clear=temp->next;
    temp->next=temp->next->next;
    free(clear);
    return head;
}

struct node *deleteElement(struct node *head, int element){
    if(head->data==element){
        head=deleteAtBegin(head);
        return head;
    }
    struct node *temp=head;
    while(temp->next->next!=head && temp->next->data!=element){
        temp=temp->next;
    }
    if(temp->next->next==head && temp->next->data!=element){
        printf("\nElement not found!");
        return head;
    }
    if(temp->next->next==head && temp->next->data!=element){
        head = deleteAtEnd(head);
        return head;
    }
    
    struct node *clear = temp->next;
    temp->next=temp->next->next;
    free(clear);
    return head;
}

int main(){
    struct node *head=NULL;
    head = insertAtBegin(head, 1);
    head = insertAtBegin(head, 2);
    head = insertAtBegin(head, 3);
    head = insertAtBegin(head, 4);
    head = insertAtEnd(head, 5);
    head = insertAtEnd(head, 6);
    head = insertAfterElement(head, 5, 43);
    head = insertAtEnd(head, 63);
    printList(head);
    head = deleteElement(head, 63);
    printList(head);
    return 0;
}