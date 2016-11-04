/*Circular Linked List*/
#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int info;
	struct node *link;
};
struct node *create(struct node *);
struct node *addatbeg(struct node *,int);
struct node *addatend(struct node *,int);
struct node *addbefor(struct node *,int,int);
struct node *addafter(struct node *,int,int);
struct node *delete(struct node *,int);
void display(struct node *);
int main()
{
	struct node *last=NULL;
	int data,choice,item;
	while(1)
	{
		printf("1. Create a Circular Linklist\n");
		printf("2. ADD at the begining of the Circular List\n");
		printf("3. ADD at the end of the Circular List\n");
		printf("4. ADD After a Particular Node\n");
		printf("5. ADD Before a Particular Node\n");
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
				last=create(last);
				break;
			}
			
			case 2:
			{
				printf("Enter the data to be inserted \n");
				scanf("%d",&data);
				last=addatbeg(last,data);
				break;
			}
			
			case 3:
			{
				printf("Enter the data to be inserted \n");
				scanf("%d",&data);
				last=addatend(last,data);
				break;
			}
			
			case 4:
			{
				printf("Enter the item after which data is to be inserted \n");
				scanf("%d",&item);
				printf("Enter the data to be inserted \n");
				scanf("%d",&data);
				last=addafter(last,data,item);
			    break;
			}
			
			case 5:
			{
				printf("Enter the item before which data is to be inserted \n");
				scanf("%d",&item);
				printf("Enter the data to be inserted \n");
				scanf("%d",&data);
				last=addbefor(last,data,item);
			    break;
			}
			
			case 6:
			{
				printf("Enter the item to be deleted \n");
				scanf("%d",&item);
				last=delete(last,item);
				break;
			}
			
			
			case 7:
			{
				display(last);
				break;
			}
			
			case 10:
			{
				exit(1);
			}
			
            default :
			{
				printf("Please Enter correct choice\n");
				break;
			}
		}
	}
	return 0;
}


struct node *create(struct node *last)
{
	struct node *temp;
	int data;
	printf("List is empty !!! would you like to add a data\n");
	printf("Enter the data to be inserted\n");
	scanf("%d",&data);
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	last=temp;
	last->link=last;
	printf("Data successfully added! \n");
	printf("%d\n",temp->info);
	return last;
}

struct node *addatbeg(struct node *last,int data)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	temp->link=last->link;
	last->link=temp;
	return last;
}

struct node *addatend(struct node *last,int data)
{
	struct node *temp;
	temp=(struct  node *)malloc(sizeof(struct node));
	temp->info=data;
	temp->link=last->link;
	last->link=temp;
	last=temp;
	return last;
}


struct node *addafter(struct node *last,int data,int item)
{
	struct node *temp,*ptr;
	ptr=last->link;
	do
	{
		if(ptr->info==item)
		{
			temp=(struct node *)malloc(sizeof(struct node));
			temp->info=data;
			temp->link=ptr->link;
			ptr->link=temp;
			if(ptr==last)
			last=temp;
			return last;
		}
			ptr=ptr->link;
		}while(ptr!=last->link);
		printf("Item %d not found\n",item);
		return last;
}

struct node *addbefor(struct node *last,int data,int item)
{
	struct node *temp,*ptr;
	if(last==NULL)
	{
		printf("List is empty");
		return last;
	}
	if(last->link->info==item)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->info=data;
		temp->link=last->link;
		last->link=temp;
		return last;
	}
	ptr=last->link;
	do
	{
		if(ptr->link->info==item)
		{
			temp=(struct node *)malloc(sizeof(struct node));
			temp->info=data;
			temp->link=ptr->link;
			ptr->link=temp;
			return last;
		}
		ptr=ptr->link;
		}while(ptr!=last->link);
		printf("Item %d not found\n",item);
		return last;
	}
	
struct node *delete(struct node *last,int item)
{	struct node *temp,*ptr;
	
	if(last==NULL)   /*Empty List*/
	{
		printf("List uis Empty\n");
		return last;
	}
	if(last->link->info==item) /*Deletion of First Node*/
	{
		temp=last->link;
		last->link=temp->link;
		free(temp);
		return last;
	}
	if(last->info==item && last->link==last) /*Deletion of the Only node*/
	{
		temp=last;
		last=NULL;
		return last;
	}
	ptr=last->link;
	do
	{
		if(ptr->link->info==item)
		{
			temp=ptr->link;
			ptr->link=temp->link;
			free(temp);
			return last;
		}
		ptr=ptr->link;
		}while(ptr!=last->link);
		printf("Item %d not found \n",item);
		return last;
}
			

void display(struct node *last)
{
	struct node *ptr;
	printf("\n");
	if(last==NULL)
	printf("List is Empty\n");
	ptr=last->link;
	do
	{
		printf("%d\n",ptr->info);
		ptr=ptr->link;
	}while(ptr!=last->link);
	printf("\n");
}

	
	
