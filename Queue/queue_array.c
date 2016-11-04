#include<stdio.h>
#include<stdlib.h>
#define MAX 20

struct arrayQueue{
    int capacity;
    int front,rear;
    int *array;
};

void enQueue(struct arrayQueue *q,int item);
void dQueue(struct arrayQueue *q);
int isEmpty(struct arrayQueue *q);
int isFull(struct arrayQueue *q);
void display(struct arrayQueue *q);
int fornt(struct arrayQueue *q);

int main()
{
    int choice, data;
    struct arrayQueue *q;
    q=malloc(sizeof(struct arrayQueue));
    if(!q)
        return 0;
    q->capacity=MAX;
    q->front=q->rear=-1;
    q->array=malloc(q->capacity*sizeof(int));
    while(1)
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Front\n");
        printf("5. Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
                printf("Enter the data to be inserted\n");
                scanf("%d",&data);
                enQueue(q,data);
                break;
            }
        case 2:
            {
                dQueue(q);
                break;
            }
        case 3:
            {
                display(q);
                break;
            }
        case 4:
            {
                data=front(q);
                printf("Front element is \n",data);
                break;
            }
        case 5:
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

void enQueue(struct arrayQueue *q, int item)
{
    if(isFull(q))
    {
        printf("Overflow");
        return;
    }
    if(q->front==-1)
        q->front=0;
    q->array[++q->rear]=item;
}

void dQueue(struct arrayQueue *q)
{
    int item;
    if(isEmpty(q))
    {
        printf("Empty Queue");
        return;
    }
    else{
            item = q->array[q->front];
            if(q->front==q->rear)
                q->front=q->rear=-1;
            else{
                q->front=q->front+1;
            }
        return (item);
    }
}

int isFull(struct arrayQueue *q)
{
    return(q->rear==q->capacity-1);
}

int isEmpty(struct arrayQueue *q)
{
    return (q->front==q->rear+1);
}

void display(struct arrayQueue *q)
{
    int i;
    for(i=q->front;i<=q->rear;i++)
    {
        printf("Element %d %d\n",i,q->array[i]);
    }
}

int front(struct arrayQueue *q)
{
    if(!isEmpty(q))
    {
        return q->array[q->front];
    }
    else{
        printf("Empty List\n");
        return 0;
    }
}
