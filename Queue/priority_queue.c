/*Efficient to implement through linked list*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct node{
    int data;
    int priority;
    struct node *link;
}*head=NULL;

void insert(int data,int priority);
int del();
int isEmpty();
void display();

int main()
{
    int choice,data,item,priority;
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
	    printf("Enter the data and the priority of the data to insert\n");
	    scanf("%d%d",&data,&priority);
	    insert(data,priority);
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

void insert(int data,int priority)
{
    struct node *temp,*ptr;
    temp=malloc(sizeof(struct node));
    if(!temp)
        printf("Memory Error\n");
    temp->data=data;
    temp->priority=priority;

        if(head==NULL || temp->priority < head->priority)
        {
            temp->link=head;
            head=temp;
        }
        else
        {
            ptr=head;
            while(ptr->link!=NULL && ptr->priority <= temp->priority)
            ptr=ptr->link;
            temp->link=ptr->link;
            ptr->link=temp;
        }
}

int del()
{
    int item;
    struct node *temp;
    if(isEmpty())
        printf("Queue is empty\n");
    temp=head;
    item=temp->data;
    head=temp->link;
    free(temp);
    return item;
}

int isEmpty()
{
    return(head==NULL);
}

void display()
{
    struct node *p;
    if(isEmpty())
        printf("Empty Queue\n");
    p=head;
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p = p->link;
    }
    printf("\n");
}
