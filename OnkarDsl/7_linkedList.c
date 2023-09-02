// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

void linkedlisttraversal(struct node * ptr){
    while(ptr!=NULL){
        printf("Element : %d\n",ptr->data);
        ptr = ptr ->next;
    }
}

struct node * insertatbegin(struct node * head,int data){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr -> data = data;
    ptr -> next = head;
    return ptr;
};

struct node * insertatindex(struct node * head , int data , int index){
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    struct node * p = head;
    int i=0;
    while(i!=index-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
};

struct node * insertatend(struct node * head , int data){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    struct node * p = head;
    ptr->data = data;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
};

struct node * afternode(struct node * head , struct node * prevnode ,int data){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = prevnode->next;
    prevnode->next =ptr;
    return head;
};

struct node * deleteatbegin(struct node * head){
   struct node * p = head ;
   head = head->next;
};

struct node * deletenode(struct node * head,int key){
    struct node * temp = head, *prev;
    while(temp != NULL && temp->data !=key){
        prev = temp ;
        temp = temp->next;
    }
    if(temp==NULL) {
        return head;
    }
    prev->next = temp->next;
};

struct node * deleteatend(struct node * head){
    struct node * ptr = head;
    while(ptr->next->next != NULL){
        ptr = ptr->next;
    }
    ptr->next=NULL;
};

struct node * search(struct node * head,int key){
    struct node * ptr = head;
    while(ptr!=NULL){
        if(ptr->data==key){
        printf("Found\n");
        return head;
    }
        ptr = ptr -> next;
    }
      printf("not found\n");
      return head;
};

int main() {
    int ops=0;
    struct node * head;
    struct node * second;
    struct node * third;
    
    head = (struct node * )malloc(sizeof(struct node));
    second = (struct node * )malloc(sizeof(struct node));
    third = (struct node * )malloc(sizeof(struct node));
    
    head -> data = 65;
    head -> next = second;
    
    second -> data =88;
    second -> next = third;
    
    third -> data = 42;
    third -> next = NULL;
    
    printf("Linked list is : \n");
    linkedlisttraversal(head);
    printf("Select the correct option : \n");
    printf("1) Insert at Begin \n2) Insert at index \n3) Insert at end \n4) Insert after node \n5) Delete at begin \n6) Delete node \n7)Delete at end\n8) Search\n");
    scanf("%d",&ops);
    switch(ops){
        case 1:
            head = insertatbegin(head,58);
           break;
        case 2:
            head = insertatindex(head,74,1);
            break;
        case 3:
            head = insertatend(head,25);
            break;
        case 4:
            head = afternode(head,third,96);
            break;
        case 5:
        	head = deleteatbegin(head);
        	break;
        case 6:
            head = deletenode(head,36);
            break;
        case 7:
            head = deleteatend(head);
            break;
        case 8:
            head = search(head,45);
		     
    }
    linkedlisttraversal(head);
    return 0;
}
