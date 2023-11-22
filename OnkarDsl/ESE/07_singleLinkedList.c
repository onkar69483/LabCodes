//single linked list
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void printList(struct node *ptr){
    struct node *temp=ptr;
    printf("\n[ ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("]\n");
}

struct node *insertAtBegin(struct node *head, int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        return head;
    }
    newnode->next=head;
    head=newnode;
    return head;
}

struct node *insertAtEnd(struct node *head, int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        return head;
    }
    struct node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;      
    return head;
}


struct node *insertAtPosition(struct node *head, int position, int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    struct node *temp=head;
    int pos=1;
    if(head==NULL || position==1){
        head=insertAtBegin(head,data);
        return head;
    }
    while(pos!=position-1 && temp!=NULL){    
        temp=temp->next;
        pos++;
    }

    if(temp==NULL){
        printf("\nInsertion Not Possible!");
        return head;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}

struct node *deleteAtBegin(struct node *head){
    if(head==NULL){
        printf("\nCannot Delete as List is Empty!");
        return head;
    }
    struct node *temp=head;
    head=head->next;
    free(temp);
    return head;
}

struct node *deleteAtEnd(struct node *head){
    if(head==NULL){
        printf("\nCannot Delete as List is Empty!");
        return head;
    }
    struct node *temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    struct node *clear=temp->next;
    temp->next=NULL;
    free(clear);
    return head;
}

struct node *deleteAtPos(struct node *head, int position){
    if(head==NULL){
        printf("\nCannot Delete as List is Empty!");
        return head;
    }
    if(position==1){
        head=deleteAtBegin(head);
        return head;
    }
    struct node *temp=head;
    int pos=1;
    while(pos<position-1 && temp->next!=NULL){
        temp=temp->next;
        pos++;
        
    }
    
    if(temp->next==NULL){
        printf("\nCannot Delete, Out of list range!");
        return head;
    }
    struct node *clear=temp->next;
    temp->next=temp->next->next;
    free(clear);
    return head;
}

struct node *deleteElement(struct node *head, int data){
    if(head==NULL){
        printf("\nCannot Delete as List is Empty!");
        return head;
    }
    struct node *temp=head;
    if(temp->data==data){
        head=deleteAtBegin(head);
        return head;
    }
    while(temp->next!=NULL && temp->next->data!=data){//order of statements matter
        temp=temp->next;
    }
    if(temp->next==NULL){
        printf("\nElement not found!");
        return head;
    }
    struct node*clear = temp->next;
    temp->next=temp->next->next;
    free(clear);
    return head;
}

int search(struct node *head, int data){
    struct node *temp=head;
    int count=1;
    while(temp!=NULL){
        if(temp->data==data){
            return count;
        }
        temp=temp->next;
        count++;
    }
    return -1;
}

struct node* sort(struct node *head){
    struct node *i,*j;
    for(i=head;i->next->next!=NULL;i=i->next){
        for(j=head;j->next!=NULL;j=j->next){
            if(j->data>j->next->data){
                int temp=j->data;
                j->data=j->next->data;
                j->next->data=temp;
            }
        }
    }
    return head;
}

struct node *reverse(struct node *head){
    struct node *current=head,*nextnode=NULL,*prev=NULL;
    while(current!=NULL){
        nextnode=current->next;
        current->next=prev;
        prev=current;
        current=nextnode;
    }
    return prev;
}

struct node *concatenate(struct node *ptr1, struct node *ptr2){
    struct node *temp=ptr1;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=ptr2;
    return temp;
}

struct node *store(struct node *result, int data){
    struct node *newnode= (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(result==NULL){
        result=newnode;
        return result;
    }
    struct node *temp=result;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    return result;
}

struct node *unionList(struct node *ptr1, struct node *ptr2){
    struct node *result=NULL,*p=ptr1, *q;
    //check if either set is empty
    if(ptr1==NULL){
        result=ptr2;
        return result;
    }
    if(ptr2==NULL){
        result=ptr1;
        return result;
    }
    
    //check if both set are non empty
    while(p!=NULL){
        q=ptr2;
        while(q!=NULL){
            if(p->data==q->data){
                break;
            }
            q=q->next;
        }
        if(q==NULL){
            result=store(result,p->data);
        }
        p=p->next;
    }

    struct node *temp=result;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=ptr2;
    result=sort(result);
    return result;  
}

struct node *intersectionList(struct node *ptr1, struct node *ptr2){
    struct node *p=ptr1, *q, *result=NULL;

    //check if either list is null
    if(ptr1==NULL || ptr2==NULL){
        return result;
    }

    //check for non empty set
    while(p!=NULL){
        q=ptr2;
        while(q!=NULL){
            if(p->data==q->data){
                result=store(result,p->data);
                break;
            }
            q=q->next;
        }
        p=p->next;
    }

    return result;
}

int main(){
    struct node *head=NULL,*head1=NULL;
    head=insertAtEnd(head,1);
    head=insertAtEnd(head,2);
    head=insertAtEnd(head,3);
    head=insertAtEnd(head,4);
    head=insertAtEnd(head,5);
    head=insertAtEnd(head,6);
    head=insertAtEnd(head,7);
    head=insertAtEnd(head,8);
    head=insertAtEnd(head,9);
    head=insertAtEnd(head,10);
    
    head1=insertAtEnd(head1,1);
    head1=insertAtEnd(head1,1);
    head1=insertAtEnd(head1,3);
    head1=insertAtEnd(head1,4);
    head1=insertAtEnd(head1,5);
    head1=insertAtEnd(head1,16);
    head1=insertAtEnd(head1,17);
    head1=insertAtEnd(head1,18);
    head1=insertAtEnd(head1,19);
    head1=insertAtEnd(head1,20);
    printList(head);
    printList(head1);
    struct node *result = intersectionList(head,head1);
    printList(result);
    return 0;
}