#include<stdio.h>
struct arrayStack {
       int top;
       int capacity;
       int *array;
};

struct arrayStack *create();
int isEmpty(struct arrayStack *s);
int isFull(struct arrayStack *s);
void push(struct arrayStack *s, int data);
int pop(struct arrayStack *s);
void deleteStack(struct arrayStack *s);
void display(struct arrayStack *s);

int main()
{
  int choice,element;
  struct arrayStack *S;
  while(1)
  {
    printf("1. Create Stack\n");
    printf("2. Push\n");
    printf("3. Pop\n");
    printf("4. Delete\n");
    printf("5. Display\n");
    printf("6. Exit\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            {
                S=create();
                break;
            }
        case 2:
            {
                printf("Enter the element \n");
                scanf("%d",&element);
                push(S,element);
                break;
            }
        case 3:
            {
                element = pop(S);
                printf("Element is %d \n",element);
                break;
            }
        case 4:
            {
                delete(S);
                break;
            }
        case 5:
            {
                display(S);
                break;
            }
        case 6:
            {
                exit(1);
            }
        default:
            {
                printf("Enter the correct choice\n");
                break;
            }
    }
  }
  return 0;
}

struct arrayStack *create()
{
    struct arrayStack *s;
    s=malloc(sizeof(struct arrayStack));
    if(!s)
    {
        return NULL;
    }
    s->top = -1;
    s->capacity = 5;
    s->array=malloc(s->capacity * sizeof(int));
    if(!s->array)
    {
        return NULL;
    }
    printf("Stack Successfully created \n");
    printf("Capacity : %d\n",s->capacity);
    return s;
}

int isEmpty(struct arrayStack *s)
{
    return (s->top == -1);
}

int isFull(struct arrayStack *s)
{
    return (s->top == s->capacity-1);
}

void push(struct arrayStack *s, int data)
{
    if(isFull(s))
    {
        printf("Stack Overflow");
    }
    else{
        s->array[++s->top]=data;
        /*printf("top value %d\n",s->top);*/
    }
}

int pop(struct arrayStack *s)
{
    if(isEmpty(s))
    {
        printf("Stack Underflow");
        return 0;
    }
    else{
        return (s->array[s->top--]);
    }
}

void delete(struct arrayStack *s)
{
    if(s)
    {
        if(s->array)
        {
            free(s->array);
            free(s);
        }
    }
}

void display(struct arrayStack *s)
{
    int i;
    if(isEmpty(s))
    {
        printf("Empty Stack");
    }
    else{
        for(i=s->top;i>=0;i--)
        {
            printf("%d \n",s->array[i]);
        }
    }
}
