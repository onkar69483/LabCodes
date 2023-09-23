#include <stdio.h>
#include <stdlib.h>

//create node
struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;
//print/traverse list
void printlist(){
    struct node *p = head;
    printf("\n[");
    while(p!=NULL){
        printf(" %d",p->data);
        p=p->next;
    }
    printf(" ]\n");
}
struct node *insertnode(struct node *ptr, int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=ptr;
    ptr=newnode;
    return ptr;
}
//insert element at begin
void insertatbegin(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=head;
    head = newnode;
}
//insert element at end
void insertatend(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    struct node *temp = head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}
//insertatpos
void insertatpos(int pos,int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    struct node *temp = head;
    int count =1;
    while(count!=pos-1){
        if(temp->next==NULL){
            printf("\nElement position for insertion not found!");
            return;
        }
        temp=temp->next;
        count++;
    }
    newnode->next = temp->next;
    temp->next=newnode;
}
//insertafterpos 
void insertafterpos(int pos,int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    struct node *temp = head;
    int count =1;
    while(count!=pos){
        if(temp->next==NULL){
            printf("\nElement position for insertion not found!");
            return;
        }
        temp=temp->next;
        count++;
    }
    newnode->next = temp->next;
    temp->next=newnode;
}
//insert after some element
void insertafter(int element,int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    struct node *temp = head;
    while(temp->data!=element){
        if(temp->next==NULL){
            printf("\nElement position for insertion not found!");
            return;
        }
        temp=temp->next;
    }
    newnode->next = temp->next;
    temp->next=newnode;
}
//deleteatbegin
void deleteatbegin(){
    struct node *temp=head;
    head=head->next;
    free(temp);
}
//deleteatend
void deleteatend(){
    struct node *temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    struct node *del=temp->next;
    temp->next=NULL;
    free(del);
}
//void deleteatpos
void deleteatpos(int pos){
    if(pos==1){
        deleteatbegin();
        return;
    }
    int count=1;
    struct node *temp=head;
    while(count!=pos-1){
        temp=temp->next;
        count++;
    }
    struct node *del = temp->next;
    temp->next=temp->next->next;
    free(del);
}
//void delete element
void deleteelement(int data){
    struct node *temp=head;
    if(temp->data==data){
        deleteatbegin();
        return;
    }
    while(temp->next->data!=data){
        temp=temp->next;
    }
    struct node *del = temp->next;
    temp->next=temp->next->next;
    free(del);
}
//reverse
void reverse(){
    struct node *temp=NULL,*temp1;
    while(head!=NULL){
        temp1=head;
        head=head->next;
        temp1->next=temp;
        temp=temp1;
    }
    head=temp1;
}
//search
void search(int data){
    struct node *temp=head;
    int count = 1;
    while(temp->next!=NULL){
        if(temp->data==data && temp!=NULL){
            printf("\nElement found at %d",count);
            return;
        }
        temp=temp->next;
        count++;
    }
    printf("\nElement not found!");
}
//concatenate
void concatenate(struct node *ptr, struct node *ptr1){
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=ptr1;
}
//intersection
struct node *intersection(struct node *ptr1, struct node *ptr2){
    struct node *result=NULL,*p=ptr1;
    //if either of the set is empty
    if(ptr2==NULL || ptr1==NULL){
        return result;
    }

    //code for non empty sets
    while(p!=NULL){
        struct node *q=ptr2;
        while(q!=NULL){
            if(p->data==q->data){
                result=insertnode(result,p->data);
                break;
            }
            q=q->next;
        }
        p=p->next;
    }
    return result;
}
//sort
void sort(struct node *ptr){
    struct node *ptr1=ptr,*ptr2;
    int temp;
    while(ptr1!=NULL){
        ptr2=ptr1->next;
        while(ptr2!=NULL){
            if(ptr1->data>=ptr2->data){
                temp=ptr1->data;
                ptr1->data=ptr2->data;
                ptr2->data=temp;
            }
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
}


void printnew(struct node *ptr){
    struct node *p = ptr;
    printf("\n[");
    while(p!=NULL){
        printf(" %d",p->data);
        p=p->next;
    }
    printf(" ]\n");
}
//union
struct node *Union(struct node *ptr1, struct node *ptr2){
    struct node *result=NULL,*p=ptr1;
    //if either of the set is empty
    if(ptr1==NULL){
        result=ptr2;
        return result;
    }
    if(ptr2==NULL){
        result=ptr1;
        return result;
    }

    //code for non empty sets
    while(p!=NULL){
        struct node *q=ptr2;
        while(q!=NULL){
            if(p->data==q->data){
                break;
            }
            q=q->next;
        }
        if(q==NULL){
            result=insertnode(result,p->data);
        }
        p=p->next;
        
    }
    struct node *temp=result;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=ptr2;
    sort(result);
    return result;  
}
int main(){
    insertatbegin(5);
    insertatbegin(6);
    insertatend(8);
    insertatend(12);
    insertatpos(3,19);
    insertafterpos(3,14);
    insertafter(8,16);
    printlist();
    struct node *head1=NULL;
    head1 = insertnode(head1,24);
    head1 = insertnode(head1,65);
    head1 = insertnode(head1,12);
    head1 = insertnode(head1,45);
    head1 = insertnode(head1,46);
       head1 = insertnode(head1,47);
          head1 = insertnode(head1,8);
    sort(head);
    sort(head1);
    printlist();
    printnew(head1);
    struct node *unionRes = Union(head1,head);
    printnew(unionRes);
    return 0;
}
