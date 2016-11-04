/*Concatenation two Link List i.e adding one list at the end of other*/
#include<stdio.h>
#include<stdlib.h>
struct node1{
	int info;
	struct node1 *link;
};

struct node1 *create1(struct node1 *);
struct node1 *insert1(struct node1 *, int);
void display1(struct node1 *);

struct node1 *create2(struct node1 *);
struct node1 *insert2(struct node1 *, int);
void display2(struct node1 *);

struct node1 *concatinate(struct node1 *,struct node1 *);

int main()
{
	struct node1 *start1=NULL;
	struct node1 *start2=NULL;
    int choice,data;
    while(1)
    {
		printf("1. CREATE LIST 1\n");
		printf("2. INSERT LIST 1\n");
		printf("3. DISPLAY LIST 1\n");
		printf("4. CREATE LIST 2\n");
		printf("5. INSERT LIST 2\n");
		printf("6. DISPLAY LIST 2\n");
		printf("7. CONCATENATION \n");
		printf("8. EXIT\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				start1=create1(start1);
				break;
			}
			case 2:
			{
				printf("Enter the data to be inserted\n");
				scanf("%d",&data);
				start1=insert1(start1,data);
				break;
			}
			case 3:
			{
				display1(start1);
				break;
			}
			case 4:
			{
				start2=create2(start2);
				break;
			}
			case 5:
			{
				printf("Enter the data to be inserted\n");
				scanf("%d",&data);
				start2=insert2(start2,data);
				break;
			}
			case 6:
			{
				display2(start2);
				break;
			}
			case 7:
			{
				start1 = concatinate(start1,start2);
				break;
			}
			case 8:
			{
				exit(1);
			}
			default:
			{
				printf("Please Enter correct choice\n");
				break;
			}
		}
	}
	return 0;
}	

struct node1 *create1(struct node1 *start1)
{
	struct node1 *temp;
	int data;
	printf("LIst is empty\n");
	printf("Enter the data\n");
	scanf("%d",&data);
	temp=(struct node1 *)malloc(sizeof(struct node1));
	temp->info=data;
	temp->link=NULL;
	start1=temp;
	printf("One data added\n");
	printf("%d\n",temp->info);
    return start1;
}


struct node1 *insert1(struct node1 *start1,int data)
{
	struct node1 *temp,*ptr;
	temp=(struct node1 *)malloc(sizeof(struct node1));
	temp->info=data;
	if(start1==NULL||data<start1->info)  /*Insertion at the begining or in the empty list*/
	{
		temp->link=start1;
		start1=temp;
		return start1;
	}
	else
	{
		ptr=start1;
		while(ptr->link!=NULL && ptr->link->info<data)
		ptr=ptr->link;
		temp->link=ptr->link;
		ptr->link=temp;
		return start1;
	}
	return start1;
}

void display1(struct node1 *start1)
{
	struct node1 *ptr;
	printf("\n");
	printf("LIST ONE\n");
	ptr=start1;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->info);
		ptr=ptr->link;
	}
	printf("\n");
}


struct node1 *create2(struct node1 *start2)
{
	struct node1 *temp;
	int data;
	printf("LIst is empty\n");
	printf("Enter the data\n");
	scanf("%d",&data);
	temp=(struct node1 *)malloc(sizeof(struct node1));
	temp->info=data;
	temp->link=NULL;
	start2=temp;
	printf("One data added\n");
	printf("%d\n",temp->info);
    return start2;
}


struct node1 *insert2(struct node1 *start2,int data)
{
	struct node1 *temp,*ptr;
	temp=(struct node1 *)malloc(sizeof(struct node1));
	temp->info=data;
	if(start2==NULL||data<start2->info)  /*Insertion at the begining or in the empty list*/
	{
		temp->link=start2;
		start2=temp;
		return start2;
	}
	else
	{
		ptr=start2;
		while(ptr->link!=NULL && ptr->link->info<data)
		ptr=ptr->link;
		temp->link=ptr->link;
		ptr->link=temp;
		return start2;
	}
	return start2;
}

void display2(struct node1 *start2)
{
	struct node1 *ptr;
	printf("\n");
	printf("LIST TWO\n");
	ptr=start2;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->info);
		ptr=ptr->link;
	}
	printf("\n");
}

struct node1 *concatinate(struct node1 *start1, struct node1 *start2)
{
	struct node1 *ptr;
	if(start1==NULL)
	{
		start1=start2;
		return start1;
	}
	if(start2==NULL)
	{
		return start1;
	}
	ptr=start1;
	while(ptr->link!=NULL)
	ptr=ptr->link;
	ptr->link=start2;
	return start1;
}
