#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct tree{
    int info;
    struct tree *rchild;
    struct tree *lchild;
};

struct tree *insert_node(struct tree *root,int data);
void non_rec(struct tree *root);
struct tree *stack[MAX];
int top=-1;

void push(struct tree *item);
struct tree *pop();
struct tree *peek();
int isEmpty();

int main()
{
    struct tree *root=NULL;
    int n,data;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    while(n--)
    {
        printf("Enter the node\n");
        scanf("%d",&data);
        root=insert_node(root,data);
    }
    printf("traversing in Post-Order fashion\n");
    non_rec(root);
    return 0;
}

struct tree *insert_node(struct tree *root, int data)
{
    if(root==NULL)
    {
        root=(struct tree *)malloc(sizeof(struct tree));
        root->info=data;
        root->lchild=NULL;
        root->rchild=NULL;
    }
    else if(data < root->info)
        root->lchild=insert_node(root->lchild,data);
    else if(data > root->info)
        root->rchild=insert_node(root->rchild,data);
    else
        printf("Duplicate data\n");
    return root;
}

void non_rec(struct tree *root)
{
    if(!root)
    {
        printf("Empty tree\n");
    }
    push(root);
    struct tree *prev=NULL,*current=NULL;
    while(!isEmpty())
    {
        current=peek();
        if(prev==NULL || prev->lchild == current || prev->rchild == current) /*Traversing down the tree*/
        {
            if(current->lchild)
                push(current->lchild);
            else if(current->rchild)
                push(current->rchild);
            else /*If leaf node*/
            {
                printf("%d\n",current->info);
                pop();
            }
        }
        if(current->lchild == prev) /*Traversing up the tree*/
        {
            if(current->rchild)
                push(current->rchild);
            else
            {
                printf("%d\n",current->info);
                pop();
            }
        }
        if(current->rchild == prev)/*Traversing up from the right child*/
        {
            printf("%d\n",current->info);
            pop();
        }
        prev = current;
    }
}

void push(struct tree *item)
{
    if(top==MAX-1)
        printf("Stack Overflow\n");
    else{
        stack[++top]=item;
    }
}

struct tree *pop()
{
    if(isEmpty())
        printf("Stack Underflow\n");
    else
        return stack[top--];
}

struct tree *peek()
{
    if(isEmpty())
    {
        printf("empty Stack");
        return NULL;
    }
    else
    {
        return stack[top];
    }

}

int isEmpty()
{
    return(top == -1);
}
