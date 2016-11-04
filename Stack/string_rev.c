#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 6

char stack[MAX];
int top = -1;

void push(char c);
char pop();
int isEmpty();
int isFull();

int main()
{
  unsigned int i;
  char str[MAX];
  printf("Enter the String\n");
  scanf("%s",str);
  for(i=0;i<strlen(str);i++)
    push(str[i]);
  for(i=0;i<strlen(str);i++)
    str[i]=pop();
  printf("Reversed String is \n");
  printf("%s",str);
  return 0;
}

void push(char c)
{
  if(isFull())
    printf("Stack is Full\n");
  else
    {
      stack[++top]=c;
    }
}

char pop()
{
  if(isEmpty())
    {
      printf("Stack is Empty\n");
      return '\0';
    }
  else
    {
      return stack[top--];
    }
}

int isEmpty()
{
  return (top==-1);
}

int isFull()
{
  return (top==MAX-1);
}
      
