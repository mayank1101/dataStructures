/*Implementing  stack for converting infix expression to postfix expression*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BLANK ' '
#define TAB '\t'
#define MAX 50

struct arrayStack{
int top;
int capacity;
char *array;
};
char postfix[MAX],infix[MAX];

void infix_postfix(struct arrayStack *s,char infix[]);
void push(struct arrayStack *s,char symbol);
long pop(struct arrayStack *s);
int isEmpty(struct arrayStack *s);
int isFull(struct arrayStack *s);
int priority(char symbol);
int white_space(char symbol);

int main()
{
    struct arrayStack *s;
    s=malloc(sizeof(struct arrayStack));
    if(!s)
    {
        printf("Memory Error");
        return 0;
    }
    else{
        s->capacity=MAX;
        s->top=-1;
    }
    s->array=malloc(s->capacity*sizeof(char));
    printf("Enter the Arithmetic expression \n");
    scanf("%s",infix);
    infix_postfix(s,infix);
    printf("POSTFIX : %s",postfix);
    return 0;
}

void infix_postfix(struct arrayStack *s,char infix[])
{
    unsigned int i,p=0;
    char symbol='\0';
    char next;
    for(i=0;i<strlen(infix);i++)
    {
        symbol = infix[i];
        if(!white_space(symbol))
        switch(symbol)
        {
        case '(':
            {
                push(s,symbol);
            }
        case ')':
            {
                while((next=pop(s))!='(')
                        postfix[p++]=next;
                break;
            }
        case '+':
        case '-':
        case '*':
        case '%':
        case '/':
            while(!isEmpty(s) && priority(s->array[s->top]>=priority(symbol)))
                postfix[p++]=pop(s);
            push(s,symbol);
            break;
        default:
            {
                printf("Enter proper expression");
            }
        }
    }
    while(!isEmpty(s))
        postfix[p++]=symbol;
    postfix[p]=='\0';
}

priority(char symbol)
{
    switch(symbol)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '/':
    case '*':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

int isEmpty(struct arrayStack *s)
{
    return (s->top == -1);
}

int isFull(struct arrayStack *s)
{
    return (s->top == s->capacity-1);
}

void push(struct arrayStack *s, char symbol)
{
    if(isFull(s))
    {
        printf("Stack Overflow");
        return;
    }
    else{
        s->array[++s->top]=symbol;
    }
}

long int pop(struct arrayStack *s)
{
    if(isEmpty(s))
    {
        printf("Stack Underflow");
        return 0;
    }
    return (s->array[s->top--]);
}

int white_space(char symbol)
{
    if(symbol==BLANK || symbol==TAB)
        return 1;
    else
        return 0;
}
