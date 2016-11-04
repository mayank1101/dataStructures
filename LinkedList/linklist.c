#include<stdio.h>
#include<stdlib.h>
struct node {
	int info;
	struct node *link;
};
struct node *create_list(struct node *);
struct node *addatend(struct node *,int);
struct node *addatbeg(struct node *,int);
struct node *addafter(struct node *,int,int);
struct node *addbefore(struct node *,int,int);
struct node *delete(struct node *, int);
struct node *reverse(struct node *);
struct node *count(struct node *);
void display(struct node *);
int main()
{
	struct node *start=NULL;
	int choice,data,item;
	while(1)
	{	
	printf("1. CREATE LIST \n");
	printf("2. ADD at End \n");
	printf("3. ADD at Beginning \n");
	printf("4. ADD after a node \n");
	printf("5. ADD before a node\n");
	printf("6. DELETE a node\n");
	printf("7. Display \n");
	printf("8. REVERSE list\n");
	printf("9. COUNT Elements in the List\n");
	printf("10.EXIT \n");
	printf("Enter your choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1 :
		{
			start=create_list(start);
			break;
		}
		case 2 :
		{
			printf("Enter the data you want to add at the end \n");
			scanf("%d",&data);
			start=addatend(start,data);
		    break;
		}
		
		case 3 :
		{
			printf("Enter the data you want to add at the beginning \n");
			scanf("%d",&data);
			start=addatbeg(start,data);
			break;
		}
		
		case 4:
		{
			printf("Enter the data to be inserted : \n");
			scanf("%d",&data);
			printf("Enter the item after which data is to be inserted : \n");
			scanf("%d",&item);
			start=addafter(start,data,item);
			break;
		}
		
		case 5:
		{
			printf("Enter the data to be inserted : \n");
			scanf("%d",&data);
			printf("Enter the item before which data is to be inserted : \n");
			scanf("%d",&item);
			start=addbefore(start,data,item);
			break;
		}
		
		
		case 6:
		{
		printf("Enter the data to be deleted : \n");
			scanf("%d",&item);
			start=delete(start,item);
			break;
		}
		
		case 7 :
		{
			display(start);
			break;
		}
		
		case 8:
		{
			start=reverse(start);
			break;
		}
		
		case 9:
		
		{
			start=count(start);
			break;
		}
		
		case 10 :
		{
			exit(1);
		
		}
		
		default :
		{
			printf("Please enter correct choice !!!");
		}
	}
}
	return 0;
}

struct node *create_list(struct node *start)
{
	struct node *p1;
	int data;
	printf("List is Empty !!");
	printf("Enter the data :\n");
	scanf("%d",&data);
	p1=(struct node *)malloc(sizeof(struct node));
	p1->link=start;
	p1->info=data;
	start=p1;
	printf("One node added !!! \n");
	printf("%d \n",p1->info);
	return start;
}

struct node *addatend(struct node *start, int data)
{
	struct node *p2,*ptr;
	p2=(struct node *)malloc(sizeof(struct node));
	ptr=start;
	p2->info=data;
	while(ptr->link!=NULL)
	{
		ptr=ptr->link;
	}
	ptr->link=p2;
	p2->link=NULL;
	return start;
}


struct node *addatbeg(struct node *start,int data)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	temp->link=start;
	start  =temp;
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
			temp->link=ptr->link;
			ptr->link=temp;
			return start;
		}
		ptr=ptr->link;
	}
	printf("%d is not present in the List\n",item);
	return start;
}


struct node *addbefore(struct node *start,int data,int item)
{
	struct node *temp,*ptr;
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
	}
	else if(item==start->info)  /*data is to be inserted before 1st node*/
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->info=data;
		temp
		
		->link=NULL;
		start=temp;
		return start;
	}
	 
	 ptr=start;
	 while(ptr->link!=NULL)
	 {
		 if(ptr->link->info==item)
		 {
			temp=(struct node *)malloc(sizeof(struct node));
			temp->info=data;
			temp->link=ptr->link;
			ptr->link=temp;
			return start;
		 }
		 ptr=ptr->link;
	 }
	 printf("%d is not present in the List\n",item);
	 return start;
 }
		struct node *delete(struct node *start,int item)
		{
			struct node *temp,*ptr;
			if(start==NULL)
			{
				printf("List is empty \n");
				return start;
			}
			if(item==start->info)
			{
				temp=(struct node *)malloc(sizeof(struct node));
				temp=start;
				start=start->link;
				free(temp);
				return start;
			}
			ptr=start;
			while(ptr->link!=NULL)
			{
				if(ptr->link->info==item)
				{
					temp=(struct node *)malloc(sizeof(struct node));
					temp=ptr->link;
					ptr->link=temp->link;
					free(temp);
					return start;
				}
				ptr=ptr->link;
			}
		printf("%d is not present in the List\n",item);
	    return start;
}
			
	
void display(struct node *start)
{
	struct node *ptr;
	if(start==NULL)
	{
		printf("List is Empty!!");
		return;
	}
	ptr=start;
	printf("List is :\n");
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->info);
		ptr=ptr->link;
	}
}



struct node *count(struct node *start)
{
	int count=0;
	struct node *ptr;
	if(start==NULL)
	{
		printf("List is Empty \n");
		return start;
	}
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->info);
		count++;
		ptr=ptr->link;
	}
	return start;
}

struct node *reverse(struct node *start)
{
	struct node *ptr,*prev,*next;
	ptr=start;
	prev=NULL;
	while(ptr!=NULL)
	{
		next=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=next;
	}
	start=prev;
	return start;
}

	
