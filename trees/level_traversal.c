/*Level Order Binary tree Trversal*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct tree{
  int data;
  struct tree *lchild;
  struct tree *rchild;
};

int rear=-1,front=-1;
struct tree *queue[MAX];

struct tree *insert(struct tree *root, int data);
void level_traverse(struct tree *root);

struct queue *createQueue();
void insert_queue(struct tree *item);
struct tree *delete_queue();
void deleteQueue();
int isEmpty();
int isFull();

int main()
{
  struct tree *root=NULL;
  int n,data;
  printf("Enter the number of nodes in the tree\n");
  scanf("%d",&n);
  while(n--)
    {
      printf("Enter the node value\n");
      scanf("%d",&data);
     root = insert(root,data);
    }
  printf("traversing tree using level Order traversal\n");
  level_traverse(root);
  return 0;
}

struct tree *insert(struct tree *root, int data)
{
  if(!root)
    {
      root=(struct tree *)malloc(sizeof(struct tree));
      root->data=data;
      root->lchild=NULL;
      root->rchild=NULL;
    }
  else if(data < root->data)
    root->lchild=insert(root->lchild,data);
  else if(data > root->data)
    root->rchild=insert(root->rchild,data);
  else
    printf("Duplicate element\n");
  return root;
}

void level_traverse(struct tree *root)
{
  struct tree *ptr=root;
  if(ptr==NULL)
    printf("Empty tree\n");
  insert_queue(ptr);
  while(!isEmpty())
    {
      ptr=delete_queue();
      //process the current node
      printf("%d\n",ptr->data);
      if(ptr->lchild!=NULL)
        insert_queue(ptr->lchild);
      if(ptr->rchild!=NULL)
        insert_queue(ptr->rchild);
    }
  deleteQueue();
}

void insert_queue(struct tree *item)
{
    if(isFull())
        printf("Queue is Full\n");
    if(front==-1)
        front=0;
    queue[++rear]=item;
}

struct tree *delete_queue()
{
    struct tree *item;
    if(isEmpty())
        printf("Queue is Empty\n");
    else{
            item = queue[front];
            if(front==rear)
                front=rear=-1;
            else{
                front=front+1;
            }
        return (item);
    }
}

int isEmpty()
{
  if(front==rear+1 || front==-1)
    return 1;
  else
    return 0;
}

int isFull()
{
  return(rear==MAX-1);
}

void deleteQueue()
{
  if(*queue)
  {
      free(*queue);
  }
}
