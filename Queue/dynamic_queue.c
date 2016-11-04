#include<stdio.h>
#include<stdlib.h>

struct dynamicQueue{
  int capacity;
  int front,rear;
  int *array;
};

int size=0;
void enQueue(struct dynamicQueue *q,int data);
int deQueue(struct dynamicQueue *q);
int isEmpty(struct dynamicQueue *q);
int isFull(struct dynamicQueue *q);
int front(struct dynamicQueue *q);
void reSize(struct dynamicQueue *q);
void display(struct dynamicQueue *q);

int main()
{
  int choice,data,item=0;
  printf("Enter the size of Queue\n");;
  scanf("%d",&size);
  struct dynamicQueue *q;
  q=malloc(sizeof(struct dynamicQueue));
  if(!q)
  {
      printf("Queue Unable to create\n");
      return 0;
  }
  q->capacity=size;
  q->front=q->rear=-1;
  q->array=malloc(q->capacity*sizeof(int));
  while(1)
    {
      printf("1. Insert\n");
      printf("2. Delete\n");
      printf("3. Front Element\n");
      printf("4. Display\n");
      printf("5. Exit\n");
      printf("Enter your choice \n");
      scanf("%d",&choice);
      switch(choice)
	{
	case 1:
	  {
	    printf("Enter the data to insert\n");
	    scanf("%d",&data);
	    enQueue(q,data);
	    break;
	  }
	case 2:
	  {
	    item=deQueue(q);
	    printf("Deleted Item is %d\n",item);
	    break;
	  }
	case 3:
	  {
	    data=front(q);
	    printf("Front element is %d\n",data);
	    break;
	  }
	case 4:
	  {
	    display(q);
	    break;
	  }
	case 5:
	  {
	    exit(1);
	  }
	default:
	  printf("Wrong Choice\n");
	  break;
	}
    }
  return 0;
}

void enQueue(struct dynamicQueue *q,int data)
{
  if(isFull(q))
    {
        printf("Queue is FUll\n");
        printf("Calling resize function\n");
        printf("Please enter the element again\n");
        reSize(q);
        return;
    }
  if(q->front==-1)
  {
      q->front=0;
  }
  q->array[++q->rear]=data;
}

int deQueue(struct dynamicQueue *q)
{
    int data=0;
    if(isEmpty(q))
    {
        printf("Empty Queue\n");
        return 0;
    }
    else{
            data = q->array[q->front];
            if(q->front==q->rear)
                q->front=q->rear=-1;
            else{
                q->front=q->front+1;
            }
        return data;
    }
}


int isEmpty(struct dynamicQueue *q)
{
  return (q->front==-1);
}

int isFull(struct dynamicQueue *q)
{
  return(q->rear==q->capacity-1);
}

void reSize(struct dynamicQueue *q)
{
  int i;
  size=q->capacity;
  q->capacity=q->capacity*2;
  q->array=realloc(q->array,q->capacity);
  if(!q->array)
    {
      printf("Memory Error!\n");
      return;
    }
  if(q->front > q->rear)
    {
      for(i=0;i < q->front;i++)
      {
          q->array[i+size]=q->array[i];
      }
      q->rear=q->rear+size;
    }
}

void display(struct dynamicQueue *q)
{
  int i;
  printf("Queue Elements are:\n");
  for(i=q->front;i<=q->rear;i++)
    {
      printf("%d\n",q->array[i]);
    }
}


int front(struct dynamicQueue *q)
{
    if(!isEmpty(q))
        return (q->array[q->front]);
    else{
        printf("Empty Queue\n");
        return 0;
    }
}
