//Binary Search Tree
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node * left;
   struct Node * right;
}Node;
Node *createNode(int data){
    Node *nn=(Node *)malloc(sizeof(Node));
    nn->data=data;
    nn->left=nn->right=NULL;
}
Node *insertNode(Node * root,int data){
    if(root==NULL){
return createNode(data);
    }
 else{
        if(data <root-> data){
root->left=insertNode(root->left,data);//recrsion
        }
        else{
root->right=insertNode(root->right,data);
        }
    }
    return root ;
}
void printInOrder(Node * root){
    if(root==NULL){
        return ;
    }
    else{
        printInOrder(root->left);
        printf("%d ",root->data);
        printInOrder(root->right);
    }
}
void printPreOrder(Node * root){
    if(root==NULL) return ;
    else{
        printf("%d ",root->data);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}
void printPostOrder(Node * root){
    if(root==NULL) return ;
    else{
       
        printPostOrder(root->left);
        printPostOrder(root->right);
        printf("%d ",root->data);
    }
}
//For only in the BST not in the binary tree 
int getMin(Node *root){
    if(root==NULL) return -99999;
    else {
        if(root->left==NULL){
            return root->data;
         }
         else{
            return getMin(root->left);
         }
}
}
int getMax(Node *root){
    if(root==NULL) return -99999;
    else {
        if(root->right==NULL){
            return root->data;
         }
         else{
            return getMax(root->right);
         }
}
}
Node * deleteNode(Node * root, int data){
    if(root==NULL)
    {
        return NULL;
    }
    else if(data<root->data){
        root->left=deleteNode(root->left,data);
    }
    else if(data>root->data){
        root->right=deleteNode(root->right,data);
    }
    else{
        if(root->left==NULL && root->right==NULL){ //leafnode
            return NULL;
        }
        else if(root->left==NULL){ //1child (child address to parent)
          return root->right;
        }
        else if(root->right==NULL){
            return root->left;
        }
        //2child case
        else{
            int sucessor=getMax(root->left);
            root->data=sucessor;
            root->left=deleteNode(root->left,sucessor);
        }
    }
}
int main(){
    Node * root=NULL;
    int val,choice;
    do{
        printf("\n1. Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Minimum\n6.Maximum\n7.Delete\n");
        printf("Enter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d",&val);
            root=insertNode(root,val);
            break;
            case 2:
            printf("\nInorder\n");
            printInOrder(root);
            break;
            case 3:
            printf("\nPreorder\n");
            printPreOrder(root);
            break;
            case 4:
            printf("\nPostorder\n");
            printPostOrder(root);
            break;
            case 5:
            if(getMin(root)!=-99999)
            printf("The minimum value is: %d\n",getMin(root));
            break;
            case 6:
            if(getMax(root)!=-99999)
            printf("The maximum value is: %d\n",getMax(root));
            case 7:
            printf("Enter the data to be deleted: ");
            scanf("%d",&val);
            root=deleteNode(root,val);
            break;
           

        }
    }while(choice>=1 && choice<=7);
    return 0;
}
//30 15 60 18 7 40 70 3 10 25 35 65 80

