/*Doubly Link List*/
#include<stdio.h>
#include<stdlib.h>
struct node {
	struct node *prev;
	struct node *next;
	int info;
};

struct node *create(struct node *);
struct node *addatbeg(struct node *,int);
struct node *addbefor(struct node *, int,int);
struct node *addafter(struct node *,int,int);
struct node *addatend(struct node *,int);
struct node *delete(struct node *,int);
void display(struct node *);
struct node *reverse(struct node *);
int main()
{
	struct node *start=NULL; 
	int choice,data,item;
	while(1)
	{
		printf("1. Create a Doubly Linklist\n");
		printf("2. ADD at the begining of the Doubly List\n");
		printf("3. ADD at the end of the Doubly List\n");
		printf("4. ADD Before a Particular Node\n");
		printf("5. ADD After a Particular Node\n");
		printf("6. DELETE\n");
		printf("7. Display Doubly Linklist\n");
		printf("8. REVERSE\n");
		printf("10. Exit\n");
		printf("\n");
		printf("Enter your Choice \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				start=create(start);
				break;
			}
			
			case 2:
			{
				printf("Enter the data to be inserted \n");
				scanf("%d",&data);
				start=addatbeg(start,data);
				break;
			}
			
			case 3:
			{
				printf("Enter the data to be inserted \n");
				scanf("%d",&data);
				start=addatend(start,data);
				break;
			}
			
			case 4:
			{
				printf("Enter the Node item before which data is to be inserted\n");
				scanf("%d",&item);
				printf("Enter the data to be inserted \n");
				scanf("%d",&data);
				start=addbefor(start,data,item);
				break;
			}
			
			case 5:
			{
				printf("Enter the Node item after which data is to be inserted\n");
				scanf("%d",&item);
				printf("Enter the data to be inserted \n");
				scanf("%d",&data);
				start=addafter(start,data,item);
				break;
			}
			
			case 6:
			{
				printf("Enter the Node item to be deleted\n");
				scanf("%d",&item);
				start=delete(start,item);
				break;
			}
			
			case 7:
			{
				display(start);
				break;
			}
			
			case 8:
			{
				start=reverse(start);
				break;
			}
			
			case 10:
			{
				exit(1);
			}
			
			default :
			{
				printf("Please Enter correct choice\n");
			}
		}
	}
	return 0;
}

struct node *create(struct node *start)
{
	struct node *temp;
	int data;
	printf("Node is Empty, Enter the Item !!!\n");
	scanf("%d",&data);
	temp=(struct node *)malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->next=NULL;
	temp->info=data;
	start=temp;
	printf("One item added !!! \n");
	printf("%d\n",temp->info);
	printf("\n");
	return start;
}

struct node *addatbeg(struct node *start,int data)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	temp->prev=NULL;
	temp->next=start;
	start->prev=temp;
	start=temp;
	return start;
}

struct node *addatend(struct node *start, int data)
{
	struct node *ptr,*temp;
	ptr=start;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
		temp=(struct node *)malloc(sizeof(struct node));
		temp->info=data;
		temp->next=NULL;
		ptr->next=temp;
		temp->prev=ptr;
		return start;
	}
	

struct node *addbefor(struct node *start,int data,int item)
{
	struct node *ptr,*temp;
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
	}
	if(start->info==item)
	{
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	temp->prev=NULL;
	temp->next=start;
	start->prev=temp;
	start=temp;
	return start;
}
	ptr=start;
	while(ptr!=NULL)
	{
		if(ptr->info==item)
		{
			temp=(struct node *)malloc(sizeof(struct node));
			temp->info=data;
			temp->next=ptr;
			temp->prev=ptr->prev;
		    ptr->prev->next=temp;
		    ptr->prev=temp;
		    return start;
		}
		ptr=ptr->next;
	}
	printf("Item  %d not found in the list\n",item);
	return start;
}

struct node *addafter(struct node *start,int data,int item)
{
	struct node *ptr,*temp;
	ptr=start;
	while(ptr!=NULL)
	{
		if(ptr->info==item)
		{
			temp=(struct node *)malloc(sizeof(struct node));
		    temp->info=data;
		    temp->next=ptr->next;
		    temp->prev=ptr;
		    if(ptr->next!=NULL)
			ptr->next->prev=temp;
		    ptr->next=temp;
		    return start;
		}
		ptr=ptr->next;
	}
	  printf("Item %d not found \n",item);
	  return start;
 }
		
struct node *delete(struct node *start,int item)
{
	struct node *ptr;
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
	}
	if(start->info==item) /*Deletion of the first node*/
	{
		ptr=start;
		start=start->next;
		start->prev=NULL;
		free(ptr);
	}
	ptr=start->next; /*Deletion between the nodes*/
	while(ptr->next!=NULL)
	{
		if(ptr->info==item)
		{
			ptr->prev->next=ptr->next;
		    ptr->next->prev=ptr->prev;
		    free(ptr);
		    return start;
		}
	     ptr=ptr->next;
   }
   printf("Item %d not found\n",item);
   if(ptr->info==item) /*Deletion of the Last node*/
   {
	   ptr->prev->next=NULL;
	   free(ptr);
       return start;
   }
   return start;
}
   
void display(struct node *start)
{	
struct node *ptr;
if(start==NULL)
{
	printf("List is empty\n");
}
printf("\n");
ptr=start;
while(ptr!=NULL)
{
	printf("%d\n",ptr->info);
	ptr=ptr->next;
}
printf("\n");
}

struct node *reverse(struct node *start)
{
	struct node *p1,*p2;
	p1=start;
	p2=p1->next;
	p1->next=NULL;
	p1->prev=p2;
	while(p2!=NULL)
	{
		p2->prev=p2->next;
		p2->next=p1;
		p1=p2;
		p2=p2->prev;
	}
    start=p1;
printf("List reversed\n");
return start;
}

	
