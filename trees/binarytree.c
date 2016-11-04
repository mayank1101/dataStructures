/*Binary Tree*/
#include<stdio.h>
#include<stdlib.h>

struct treeNode{
    int data;
    struct treeNode *left;
    struct treeNode *right;
};

struct treeNode *insert(struct treeNode *root,int data);
void preOrder(struct treeNode *root);
void inorder(struct treeNode *root);
void postOrder(struct treeNode *root);

int main()
{
    struct treeNode *root=NULL;
    int data,choice;
    while(1)
    {
        printf("1. Insert\n");
        printf("2. Pre-Order Traversal\n");
        printf("3. Post-Order Traversal\n");
        printf("4. Inorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
                printf("Enter the data to be inserted\n");
                scanf("%d",&data);
                root=insert(root,data);
                break;
            }
        case 2:
            {
                printf("Pre-Order traversal is \n");
                preOrder(root);
                break;
            }
        case 3:
            {
                postOrder(root);
                break;
            }
        case 4:
            {
                inorder(root);
                break;
            }
        case 5:
            {
                exit(1);
            }
        default:
            {
                printf("Enter the correct choice\n");
                break;
            }
        }
    }
    return 0;
}

struct treeNode *insert(struct treeNode *root, int data)
{
    if(root==NULL)
    {
        root=(struct treeNode *)malloc(sizeof(struct treeNode));
        root->data=data;
        root->left=NULL;
        root->right=NULL;
    }
    else if(data < root->data)
        root->left=insert(root->left,data);
    else if(data > root->data)
        root->right=insert(root->right,data);
    else
        printf("Duplicate Data\n");
    return root;
};

void preOrder(struct treeNode *ptr)
{
    if(ptr)
    {
        printf("%d\n",ptr->data);
        preOrder(ptr->left);
        preOrder(ptr->right);
    }
}

void postOrder(struct treeNode *root)
{
    if(root)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d\n",root->data);
    }
}

void inorder(struct treeNode *root)
{
    if(root)
    {
        inorder(root->left);
        printf("%d\n",root->data);
        inorder(root->right);
    }
}
