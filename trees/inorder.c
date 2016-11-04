/* NON RECURSIVE IMPLEMENTATION
1. Push the root node in the stack.
2. push the lchild of the node to the stack untill lchild!=NULL.
3. pop the node and then process it.
4. Visit the rchild of the current node.
5. repeat the steps 1,2,3,4 until stack is not Empty.
*/
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
    printf("traversing in Inorder fashion\n");
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
};

void non_rec(struct tree *root)
{
    if(root==NULL)
    {
        printf("Empty tree\n");
        return;
    }
    while(1)
    {
        while(root)
        {
            push(root);
            root= root->lchild;
        }
        if(isEmpty())
            break;
        root=pop();
        printf("%d\n",root->info);
        root=root->rchild;
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

int isEmpty()
{
    return(top==-1);
}
