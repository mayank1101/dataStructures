/*Implementing stack using link list*/
#include<stdio.h>
#include<stdlib.h>

struct llStack{
    int data;
    struct llStack *next;
}*top=NULL;

void push(int data);
void deleteStack(struct llStack *top);
int pop(struct llStack *top);
int isEmpty(struct llStack *top);
int topElement(struct llStack *top);
void display(struct llStack *top);

int main()
{
    int choice, data;
    while(1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Delete Stack\n");
        printf("4. Get Top Element\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
                printf("Enter the data to be inserted\n");
                scanf("%d",&data);
                push(data);
                break;
            }
        case 2:
            {
                data=pop(top);
                printf("Element is %d\n",data);
                break;
            }
        case 3:
            {
                deleteStack(top);
                break;
            }
        case 4:
            {
                data=topElement(top);
                printf("Top element is %d\n",data);
                break;
            }
        case 5:
            {
                display(top);
                break;
            }
        case 6:
            {
                exit(1);
            }
        default:
            {
                printf("Enter proper choice\n");
                break;
            }
        }
    }
    return 0;
}

void push(int data)
{
    struct llStack *temp;
    temp = malloc(sizeof(struct llStack));
    if(!temp)
        return NULL;
    temp->data=data;
    temp->next=top;
    top=temp;
}

int pop(struct llStack *top)
{
    if(isEmpty(top))
    {
        printf("Stack Underflow");
        return NULL;
    }
    else{
        return top->data;
    }
}

int isEmpty(struct llStack *top)
{
    return (top==NULL);
}

int topElement(struct llStack*top)
{
    if(isEmpty(top))
        printf("List is empty");
    else{
        return (top->data);
    }
}

void display(struct llStack *top)
{
    struct llStack *ptr;
    ptr=top;
    while(ptr!=NULL)
    {
        printf("%d \n",ptr->data);
        ptr=ptr->next;
    }
}

void deleteStack(struct llStack *top)
{
    struct llStack *temp;
    if(isEmpty(top))
        printf("Stack Underflow");
    else{
        temp=top;
        top=top->next;
        free(temp);
    }
}
