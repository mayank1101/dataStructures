#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int info;
	struct node *link;
};
struct node *insert(struct node *,int);
void search(struct node *,int);
void display(struct node *);
int main()
{
	struct node *start=NULL;
	int data,choice,item;
	while(1)
	{
		printf("1. Insert \n");
		printf("2. Search \n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("Enter your choice \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				printf("Enter the data to be Inserted\n");
				scanf("%d",&data);
				start=insert(start,data);
				break;
			}
			
			case 2:
			{
				printf("Enter the item to be searched\n");
				scanf("%d",&item);
				search(start,item);
				break;
			}
			
			case 3:
			{
				display(start);
				break;
			}
			
			case 4:
			{
				exit(1);
			}
			
			default:
			{
				printf("Please Enter Correct Choice\n");
				break;
			}
		}
	}
	return 0;
}

struct node *insert(struct node *start,int data)
{
	struct node *temp,*ptr;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	if(start==NULL || data<start->info)
	{
		temp->link=start;
		start=temp;
		return start;
	}
	else
	{
		ptr=start;
		while(ptr->link!=NULL && ptr->link->info<data) /*add after case*/
        ptr=ptr->link;
           
	    temp->link=ptr->link;
		ptr->link=temp;
		return start;
	}
	
	return start;
}

void display(struct node * start)
{
	struct node *ptr;
	ptr=start;
	printf("\n");
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->info);
		ptr=ptr->link;
	}
	printf("\n");
}

void search(struct node *start,int item)
{
	int pos=1;
	struct node *ptr;
	printf("\n");
	if(start==NULL || item<start->info)
	{
		printf("Item %d not found \n",item);
		return;
	}
	ptr=start;
	while(ptr!=NULL && ptr->info<=item)
	{
		if(ptr->info==item)
		{
			printf("Item %d found at position %d \n",item,pos);
			return;
		}
		ptr=ptr->link;
		pos++;
	}
	printf("\n");
}

		
			 	
