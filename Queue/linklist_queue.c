#include<stdio.h>
#include<stdlib.h>

struct linkNode{
    int data;
    struct linkNode *next;
}*front=NULL,*rear=NULL;

struct linkNode *createNode();
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

struct linkNode *createNode()
{
    struct linkNode *newNode;
    newNode = malloc(sizeof(struct linkNode));
    if(!newNode)
        printf("Memory Error!!");
    return newNode;
};

void insert(int data)
{
    struct linkNode *temp;
    temp=createNode();
    temp->data=data;
    temp->next=NULL;
    if(front==NULL)
    {
        front=temp;
    }
    else{
        rear->next=temp;
    }
    rear=temp;
}

int del()
{
    int item;
    struct linkNode *temp;
    if(isEmpty())
    {
        printf("Empty Queue\n");
        return;
    }
    temp=front;
    item=temp->data;
    front=temp->next;
    free(temp);
    return item;
}

int isEmpty()
{
    return(front==NULL);
}

void display()
{
    struct linkNode *ptr;
    if(isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    ptr=front;
    while(ptr!=NULL)
    {
        printf("%d \n",ptr->data);
        ptr=ptr->next;
    }
}
