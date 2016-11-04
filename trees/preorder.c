/* NON RECURSIVE IMPLEMENTATION
1. Push The root node
2. Pop the root node
3. process the popped node
4. push the rchild of visited node in stack
5. push the lchild of the visited node in the stack
6. Repeat step 2,3,4,5 till stack is not empty
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct tree{
  int info;
  struct tree *lchild;
  struct tree *rchild;
};

struct tree *stack[MAX];
int top=-1;
int capacity=MAX;

struct tree *createTree(struct tree *root,int data);
void non_rec(struct tree *root);

void push(struct tree *root);
struct tree *pop();
int isEmpty();

int main()
{
  struct tree *root=NULL;
  int data,n;
  printf("Enter the elements\n");
  scanf("%d",&n);
  while(n--)
    {
      printf("Enter the data to be inserted\n");
      scanf("%d",&data);
      root=createTree(root,data);
    }
  printf("Use Inorder Non-Recursive Traversal\n");
  non_rec(root);
  return 0;
}

struct tree *createTree(struct tree *root,int data)
{
  if(root==NULL)
    {
      root=(struct tree *)malloc(sizeof(struct tree));
      root->info=data;
      root->lchild=NULL;
      root->rchild=NULL;
    }
  else if(data < root->info)
    root->lchild=createTree(root->lchild,data);
  else if(data > root->info)
    root->rchild=createTree(root->rchild,data);
  else
    printf("Duplicate data");
  return root;
}

void non_rec(struct tree *root)
{
  if(root==NULL)
    {
      printf("Empty tree\n");
      return;
    }
  push(root);
  while(!isEmpty())
    {
      root=pop();
      printf("%d\n",root->info);
      if(root->rchild!=NULL)
	push(root->rchild);
      if(root->lchild!=NULL)
	push(root->lchild);
    }
  printf("\n");
}

void push(struct tree *ptr)
{
  if(top==MAX-1)
    printf("Stack Overflow\n");
   stack[++top]=ptr;
}

struct tree *pop()
{
  if(isEmpty())
    printf("Stack Underflow\n");
    else
    {
        return stack[top--];
    }
}

int isEmpty()
{
  return (top==-1);
}
