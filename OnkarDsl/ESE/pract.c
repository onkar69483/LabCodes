#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *left;
    struct node *right;
    int data;
    };

struct node *createNode(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node *insert(struct node *root,int data){
    struct node *temp=root, *prev=NULL;
    struct node *newnode=createNode(data);
    if(root==NULL){
        root=newnode;
        return root;
    }
    while(temp!=NULL){
        prev=temp;
        if(temp->data==data){
            printf("\nData already present!\n");
            return root;
        }
        else if(data>temp->data){
            temp=temp->right;
        }
        else{
            temp=temp->left;
        }
    }
    if(data>prev->data){//insert right
        prev->right=newnode;
    }
    else{
        prev->left=newnode;
    }
    return root;
}

struct node *delete(struct node *root,int data){
    if(root==NULL){
        return NULL;
    }
    else if(data<root->data){
        root->left=delete(root->left,data);
    }
    else if(data>root->data){
        root->right=delete(root->right,data);
    }
    else{
        //Case1: Node with no child
        if(root->left==NULL && root->right==NULL){
            free(root);
            return root;
        }
        //Case 2: Node with only one child
        else if(root->left==NULL){
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right=NULL){
            struct node *temp=root->left;
            free(root);
            return temp;
        }

        //node with 2 children
        else{
            struct node *temp=root->left;
            while(temp->left!=NULL){
                temp=temp->left;
            }
            root->data=temp->data;
            root->right=delete(root->right, temp->data);
        }
    }
    
}

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}



int main(){
    struct node *root=NULL;
    root = insert(root,5);
    root = insert(root,6);
    root = insert(root, 7);
    root = insert(root, 3);
    root = insert(root, 9);
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 8);
    root = insert(root, 1);
    root = insert(root, 10);
    root = insert(root, 11);
    root = insert(root, 12);
    inorder(root);
    // root = delete(root,6);
    printf("\n");
    inorder(root);
    printTree(root,0);
    return 0;
}