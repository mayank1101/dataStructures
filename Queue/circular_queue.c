#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int circQueue[MAX];
int rear = -1;
int front = -1;

void insert(int data);
int del();
int isEmpty();
void display();

int main()
{
    int choice,data,item;
    while(1)
    {
      printf("1. Insert\n");
      printf("2. Delete\n");
      printf("3. Display\n");
      printf("4. Exit\n");
      printf("Enter your choice \n");
      scanf("%d",&choice);
      switch(choice)
      {
          case 1:
	  {
	    printf("Enter the data to insert\n");
	    scanf("%d",&data);
	    insert(data);
	    break;
	  }
	case 2:
	  {
	    item=del();
	    printf("Deleted item is %d \n",item);
	    break;
	  }
	case 3:
	  {
	      display();
	      break;
	  }
	case 4:
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

void insert(int data)
{
    if(isFull())
    {
        printf("Queue is Full\n");
        return;
    }
    if(front==-1)
        front = 0;
    if(rear==MAX-1)
        rear = 0;
        else
            rear+=1;
    circQueue[rear]=data;
}

int del()
{
    int item;
    if(isEmpty())
    {
        printf("Empty Queue\n");
        return 0;
    }
    item=circQueue[front];
    if(front==rear)
    {
        front=rear=-1;
    }
    else{
        front+=1;
    }
    return item;
}

int isEmpty()
{
    return(front==-1);
}

int isFull()
{
    if((front==0 && rear==MAX-1) || (front==rear+1))
        return 1;
    else
    return 0;
}

void display()
{
    int i=front;
    if(isEmpty())
    {
        printf("Empty Queue\n");
    }
    else{
        if(front<=rear)
        {
            while(i<=rear)
            {
                printf("%d\n",circQueue[i++]);
            }
        }
        else
        {
            while(i<=MAX-1)
            {
                printf("%d\n",circQueue[i++]);
            }
            i=0;
            while(i<=rear)
            {
                printf("%d\n",circQueue[i++]);
            }
        }
    }
}
