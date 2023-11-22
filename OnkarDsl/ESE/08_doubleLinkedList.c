#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

void printList(struct node *ptr){
    struct node *temp=ptr;
    printf("\n[ ");
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf(" ]\n");
}

void printRev(struct node *ptr){
    struct node *temp=ptr;
    printf("\n[ ");
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->prev;
    }
    printf(" ]\n");
}

struct node *insertAtBegin(struct node *head,struct node **tail, int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL){
        head=newnode;
        *tail=newnode;
        return head;
    }
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
    return head;
}

struct node *insertAtEnd(struct node *head, struct node **tail, int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL){
        head=newnode;
        *tail=newnode;
        return head;
    }
    (*tail)->next=newnode;
    newnode->prev=*tail;
    *tail=newnode;
    return head;
}

struct node *insertAtPosition(struct node *head, struct node **tail, int position, int data){
    if(position<=1){
        head=insertAtBegin(head, tail, data);
        return head;
    }
    int pos=1;
    struct node *temp=head;
    while(pos<position-1 && temp!=NULL){
        temp=temp->next;
        pos++;
    }
    if(temp==NULL){
        printf("\nInsertion not possible!");
        return head;
    }
    
    //insert at end
    if(temp->next==NULL){
        head=insertAtEnd(head, tail, data);
        return head;
    }

    //insert at position
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;

    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next->prev=newnode;
    temp->next=newnode;
    
    return head;
}

struct node *insertAfterElement(struct node *head, struct node **tail, int element, int data){
    struct node *temp=head;
    if(temp->data==data){
        head=insertAtBegin(head, tail, data);
        return head;
    }

    while(temp!=NULL && temp->data!=element){
        temp=temp->next;
    }

    if(temp==NULL){
        printf("\nElement not Found!");
        return head;
    }
    //insert element at end
    if(temp->next==NULL){
        head = insertAtEnd(head, tail, data);
        return head;
    }
    //insert after element
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;

    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next->prev=newnode;
    temp->next=newnode;
    return head;
}

struct node *deleteAtBegin(struct node *head, struct node **tail){
    struct node *temp = head;

    if(temp==NULL){
        printf("\n list is empty!");
        return head;
    }

    //if list has one element
    if(temp->next==NULL){
        head=NULL;
        *tail=NULL;
        return head;
    }
    head=head->next;
    head->prev=NULL;
    free(temp);
    return head;
}

struct node *deleteAtEnd(struct node *head, struct node **tail){
    struct node *temp = *tail;
    
    if(head==NULL){
        printf("\n list is empty!");
        return head;
    }

    //if list has one element
    if(head->next==NULL){
        head=NULL;
        *tail=NULL;
        return head;
    }

    *tail=(*tail)->prev;
    (*tail)->next=NULL;
    free(temp);
    return head;
}

struct node *deleteAtPos(struct node *head, struct node **tail, int position){

    if(position<=1){
        head = deleteAtBegin(head, tail);
        return head;
    }
    struct node *temp=head;
    int pos=1;
    while(temp!=NULL && pos<position){
        temp=temp->next;
        pos++;
    }
    if(temp==NULL){
        printf("\nInvalid Position!");
        return head;
    }

    if(temp->next==NULL){
        head=deleteAtEnd(head, tail);
        return head;
    }
    
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
    return head;
}

struct node *deleteElement(struct node *head, struct node **tail, int element){
    struct node *temp = head;
    if(temp->data==element){
        head=deleteAtBegin(head,tail);
        return head;
    }
    while(temp!=NULL && temp->data!=element){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("\nElement Not Found!");
        return head;
    }
    if(temp->next==NULL){
        head = deleteAtEnd(head,tail);
        return head;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
    return head;
}

void search(struct node *head, int data){
    struct node *temp=head;
    int position=1;
    while(temp!=NULL && temp->data!=data){
        temp=temp->next;
        position++;
    }
    if(temp!=NULL){
        printf("\nElement Found at position: %d", position);
    }
    else{
        printf("\nElement not Found!");
    }
}

struct node *sort(struct node *head, struct node **tail){
    struct node *i,*j;
    for(i=head;i->next->next!=NULL;i=i->next){
        for(j=head;j->next!=NULL;j=j->next){
            if(j->data>j->next->data){
                int temp = j->data;
                j->data=j->next->data;
                j->next->data=temp;
            }
        }
    }
    return head;
}

struct node *reverse(struct node *head, struct node **tail){
    struct node *current=head;
    struct node *prevNode=NULL;
    struct node *nextNode=NULL;
    while(current!=NULL){
        nextNode=current->next;
        current->next=prevNode;
        current->prev=nextNode;
        prevNode=current;
        current=nextNode;
    }
    *tail=head;
    head = prevNode;
    return prevNode;
}

struct node *concatenate(struct node *head1,struct node **tail1,struct node *head2,struct node **tail2){
    
    if (head1 == NULL) {
        // If the first list is empty, simply return the second list
        *tail1 = *tail2 = head2;
        return head2;
    }
    
    if (head2 == NULL) {
        // If the second list is empty, nothing needs to be done
        return head1;
    }

    struct node *ptr1=head1, *ptr2=head2;
    while(ptr1->next!=NULL){
        ptr1=ptr1->next;
    }
    while(ptr2->next!=NULL){
        ptr2=ptr2->next;
    }

    ptr1->next=head2;
    head2->prev=ptr1;

    head2=head1;
    *tail1=*tail2;
    return head1;
}


struct node *unionList(struct node *head1,struct node *head2){
    struct node *p=head1,*q,*head=NULL,*tail=NULL;
    // if either list is null
    if(head1==NULL){
        head=head2;
        return head;
    }
    if(head2==NULL){
        head=head1;
        return head;
    }

    while(p!=NULL){
        q=head2;
        while(q!=NULL){
            if(p->data==q->data){
                break;
            }
            q=q->next;
        }
        if(q==NULL){
            head=insertAtEnd(head, &tail, p->data);
        }
        p=p->next;
    }
    struct node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head2;
    return head;
}

struct node *intersectionList(struct node *head1, struct node *head2){
    struct node *p=head1,*q,*head=NULL,*tail=NULL;
    if(head1==NULL || head2==NULL){
        return head;
    }
    while(p!=NULL){
        q=head2;
        while(q!=NULL){
            if(p->data==q->data){
                head=insertAtEnd(head,&tail,p->data);
                break;
            }
            q=q->next;
        }
        p=p->next;
    }
    return head;
}

int main(){
    struct node *head=NULL,*tail=NULL;
    head=insertAtEnd(head, &tail, 1);
    head=insertAtEnd(head, &tail, 2);
    head=insertAtEnd(head, &tail, 3);
    head=insertAtEnd(head, &tail, 4);
    head=insertAtEnd(head, &tail, 5);
    head=insertAfterElement(head, &tail, 5, 79);
    head=insertAtEnd(head, &tail, 78);
    head=sort(head,&tail);

    struct node *head1=NULL,*tail1=NULL;
    head1=insertAtEnd(head1, &tail1, 10);
    head1=insertAtEnd(head1, &tail1, 11);
    head1=insertAtEnd(head1, &tail1, 3);
    head1=insertAtEnd(head1, &tail1, 4);
    head1=insertAtEnd(head1, &tail1, 24);
    printList(head);
    printList(head1);
    struct node *result = intersectionList(head,head1);
    printList(result);
    return 0;
}