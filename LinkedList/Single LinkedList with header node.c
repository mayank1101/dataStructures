/*Single linked List with header node*/
#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int info;
	struct node *link;
};
struct node *create(struct node *);
struct node *addatend(struct node *,int);
struct node *addbefor(struct node *,int,int);
struct node *addafter(struct node *,int,int);
struct node *delete(struct node *,int);
struct node *reverse(struct node *);
void display(struct node *);
int main()
{
	int choice,data,item;
	struct node *head;
	head=(struct node *)malloc(sizeof(struct node));
	head->info=0;
	head->link=NULL;
	while(1)
	{
		printf("1. Create list\n");
		printf("2. ADD at the end of the List\n");
		printf("3. ADD Before a Particular Node\n");
		printf("4. ADD After a Particular Node\n");
		printf("5. DELETE\n");
		printf("6. Displaylist\n");
		printf("7. REVERSE\n");
		printf("8. Exit\n");
		printf("\n");
		printf("Enter your Choice \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				head=create(head);
				break;
			}
			
			
			case 2:
			{
				printf("Enter the data to be Inserted\n");
				scanf("%d",&data);
				head=addatend(head,data);
				break;
			}
			
			case 3:
			{
				printf("Enter the data to be Inserted\n");
				scanf("%d",&data);
				printf("Enter the item before which data is to be inserted\n");
				scanf("%d",&item);
				head=addbefor(head,data,item);
				break;
			}
			
			
			case 4:
			{
				printf("Enter the data to be Inserted\n");
				scanf("%d",&data);
				printf("Enter the item after which data is to be inserted\n");
				scanf("%d",&item);
				head=addafter(head,data,item);
				break;
			}
			
			case 5:
			{
				printf("Enter the Item to be deleted\n");
				scanf("%d",&item);
				head=delete(head,item);
				break;
			}
					
			case 6:
			{
				display(head);
				break;
			}
			
			case 7:
			{
				head=reverse(head);
				break;
			}
			
			case 8:
			{
				exit(1);
			}
			
			default:
			{
				printf("Enter correct choice \n");
				break;
			}
		}
	}
	return 0;
}

struct node *create(struct node *head)
{
	struct node *temp;
	int data;
	printf("List is Empty!!!");
	printf("Please Enter the data to be Inserted\n");
	scanf("%d",&data);
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	temp->link=NULL;
	head->link=temp;
	printf("One node added!!\n");
	printf("%d\n",temp->info);
	printf("\n");
	return head;
}

struct node *addatend(struct node *head,int data)
{
	struct node *temp,*ptr;
	ptr=head->link;
	temp=(struct node *)malloc(sizeof(struct node));
	while(ptr->link!=NULL)
	ptr=ptr->link;

	temp->info=data;
	ptr->link=temp;
	temp->link=NULL;
	return head;
}

struct node *addbefor(struct node *head,int data,int item)
{
	struct node *temp,*ptr;
	if(head->link->info==item)  /*Befor first node*/
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->info=data;
		temp->link=head->link;
		head->link=temp;
		return head;
	}
	ptr=head->link;
	while(ptr->link!=NULL)
	{
		if(ptr->link->info==item)
		{
			temp=(struct node *)malloc(sizeof(struct node));
			temp->info=data;
			temp->link=ptr->link;
			ptr->link=temp;
			return head;
		}
		ptr=ptr->link;
	}
	printf("Item %d not found\n",item);
	return head;
}

struct node *addafter(struct node *head,int data,int item)
{
	struct node *temp,*ptr;
	ptr=head->link;
	while(ptr->link!=NULL)
	{
		if(ptr->info==item)
		{
			temp=(struct node *)malloc(sizeof(struct node));
			temp->info=data;
			temp->link=ptr->link;
			ptr->link=temp;
			return head;
		}
		ptr=ptr->link;
	}
	printf("Item %d not found\n",item);
	return head;
}

struct node *delete(struct node *head,int item)
{
	struct node *temp,*ptr;
	if(head->link->info==item)  /*Deletion of first node*/
	{
		temp=head->link;
		head->link=temp->link;
		free(temp);
		return head;
	}
	
	ptr=head->link;
	while(ptr->link!=NULL)
	{
		if(ptr->link->info==item)
		{
			temp=ptr->link;
			ptr->link=temp->link;
			free(temp);
			return head;
		}
		ptr=ptr->link;
	}
	printf("Item %d not found\n",item);
	return head;
}

struct node *reverse(struct node *head)
{
	struct node *ptr,*prev,*next;
	ptr=head->link;
	prev=NULL;
	while(ptr!=NULL)
	{
		next=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=next;
	}
	head->link=prev;
	return head;
}			


void display(struct node *head)
{
	struct node *ptr;
	ptr=head->link;
	printf("\n");
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->info);
		ptr=ptr->link;
	}
	printf("\n");
}	
	
