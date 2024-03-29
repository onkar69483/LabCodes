#include <iostream>
#include <stdlib.h>

using namespace std;

struct node{
	string data;
	struct node *prev;
	struct node *next;
};

struct node *head,*tail=NULL;
struct node *head1,*tail1=NULL;

void insert1(string data){
	struct node *newnode = new node;
	newnode->data=data;
	if(head==NULL){
		head=tail=newnode;
		newnode->next=NULL;
		newnode->prev=NULL;
	}
	else{
		tail->next = newnode;
		newnode->prev=tail;
		tail=newnode;
		tail->next=NULL;
	}
}
void insert2(string data){
	struct node *newnode = new node;
	newnode->data=data;
	if(head1==NULL){
		head1=tail1=newnode;
		newnode->next=NULL;
		newnode->prev=NULL;
	}
	else{
		tail1->next = newnode;
		newnode->prev=tail1;
		tail1=newnode;
		tail1->next=NULL;
	}
}

void printlist(struct node *ptr){
	struct node *temp = ptr;
	cout<<"[ ";
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"]\n";
}

struct node *intersection(struct node *ptr1, struct node *ptr2){
	struct node *result=NULL,*p=ptr1;
        //if either of the set is empty
    if(ptr1==NULL || ptr2==NULL){
        return result;
    }

    //code for non empty sets
	while(p!=NULL){
		struct node *q=ptr2;
		while(q!=NULL){
			if(p->data==q->data){
				struct node *newnode = new node;
                newnode->data=p->data;
	            if(result==NULL){
                    result=newnode;
                    result->prev = NULL;
                    result->next = NULL;
                }
                else{
                    result->prev=newnode;
                    newnode->next = result;
                    newnode->prev = NULL;
                    result = newnode;
                }
			}
			q=q->next;	
		}
		p=p->next;
	}
	return result;	
}

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
			struct node *newnode = new node;
            newnode->data=p->data;
            if(result==NULL){
                result=newnode;
                result->prev = NULL;
                result->next = NULL;
            }
            else{
                result->prev=newnode;
                newnode->next = result;
                newnode->prev==NULL;
                result = newnode;
            }
		}
		p=p->next;
	}
	struct node *temp=result;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=ptr2;
    ptr2->prev=temp;
	return result;	
}

int main() {
	insert1("pr");
	insert1("qp");
	insert1("zx");
	insert2("ol");
	insert2("fi");
	insert2("lx");
	insert2("zx");
	cout<<"List1: ";	
	printlist(head);
	cout<<"List2: ";
	printlist(head1);
	struct node *intersection_result = intersection(head,head1);
	struct node *union_result = Union(head,head1);
	cout<<"Intersection Result: ";
	printlist(intersection_result);
	cout<<"Union Result: ";
	printlist(union_result);
	return 0;
}
