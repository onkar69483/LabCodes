#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node *insert(struct node *root, int data){
    struct node *newnode = createNode(data);
    if(root==NULL){
        root=newnode;
        return root;
    }
    struct node *prev=NULL,*temp=root;
    while(temp!=NULL){
        prev=temp;
        if(data==temp->data){
            printf("\n%d already present!\n", data);
            return root;
        }
        else if(data>temp->data){
            temp=temp->right;
        }
        else{
            temp=temp->left;
        }
        
    }
    if(data<prev->data){
        prev->left=newnode;
    }
    else{
        prev->right=newnode;
    }
    return root;
}


void preorder(struct node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}



int main(){
    struct node *root=NULL;
    root=insert(root, 6);
    root=insert(root, 2);
    root=insert(root, 12);
    root=insert(root, 36);
    root=insert(root, 41);
    root=insert(root, 7);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    return 0;
}