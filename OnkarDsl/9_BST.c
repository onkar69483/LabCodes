/*
OUTPUT:
78 75 65 79 
65 75 78 79
65 75 79 78

After Deletion

78 65 79
65 78 79
65 79 78
*/

#include <stdio.h>
#include <stdlib.h>

struct tree{
    int data;
    struct tree *left,*right;
};

struct tree *root=NULL;

void insert(int data){
    struct  tree *newnode = (struct tree*)malloc(sizeof(struct tree));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root == NULL){
        root=newnode;
    }
    else{
        struct tree *temp=root;
        while(temp!=NULL){
            if(data<temp->data){
                if(temp->left==NULL){
                    temp->left=newnode;
                    return;
                }
                else temp=temp->left;
            }
            if(data>temp->data){
                if(temp->right==NULL){
                    temp->right=newnode;
                    return;
                }
                else temp=temp->right;
            }
        }
    }   
}

void createTree(int data){
    if(root == NULL){
        struct  tree *newnode = (struct tree*)malloc(sizeof(struct tree));
        newnode->data=data;
        newnode->left=NULL;
        newnode->right=NULL;
        root=newnode;
    }
    else insert(data);
}

void preorder(struct tree *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct tree *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void postorder(struct tree *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

struct tree *findMin(struct tree *root){
    struct tree *temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

struct tree *delete(struct tree *root,int key){
    if(root==NULL){
        return root;
    }
    else{
        if(key<root->data){
            root->left=delete(root->left,key);
        }
        else if(key>root->data){
            root->right=delete(root->right,key);
        }
        else{
            if(root->left==NULL && root->right==NULL){
                free(root);
                return NULL;
            }
            else if(root->left==NULL){
                struct tree *temp=root->right;
                free(root);
                return temp;
            }
            else if(root->right==NULL){
                struct tree *temp=root->left;
                free(root);
                return temp;
            }
            else{
                struct tree *temp = findMin(root->right);
                root->data = temp->data;
                root->right = delete(root->right,temp->data);
            }
        }
    }
}

int main(){
    createTree(78);
    createTree(75);
    insert(65);
    insert(79);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    root = delete(root,75);
    printf("\n\nAfter Deletion\n");
    printf("\n");
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    return 0;
}
