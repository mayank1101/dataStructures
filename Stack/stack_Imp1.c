/* Parentheses matching using stack */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

struct arrayStack{
int top;
int capacity;
char *exp;
};

int check(struct arrayStack *s, char exp[]);
void push(struct arrayStack *s, char c);
char pop(struct arrayStack *s);
int match(char c1, char c2);

int main()
{
    struct arrayStack *s;
    s=malloc(sizeof(struct arrayStack));
    if(!s)
    {
        printf("Memory Error\n");
        return 0;
    }
    else{
        s->capacity =MAX;
        s->top=-1;
    }
    s->exp=malloc(s->capacity*sizeof(char));
    int valid;
    char exp[20];
    printf("Enter the expression\n");
    scanf("%s",s->exp);
    valid = check(s,s->exp);
    if(!valid)
    {
        printf("Invalid expression\n");
    }
    else{
        printf("Valid expression\n");
    }
    return 0;
}

int check(struct arrayStack *s,char exp[])
{
    int i;
    char temp='\0';
    for(i=0;i<strlen(exp);i++)
    {
        if((exp[i]=='[') || (exp[i]=='{') || (exp[i]=='('))
                {
                    push(s,exp[i]);
                }
        if((exp[i]==']') || (exp[i]=='}') || (exp[i]==')'))
        {
            if(s->top==-1)
            {
                printf("right parentheses are more\n");
                return 0;
            }
            else{
                temp = pop(s);
                if(!match(temp,exp[i]))
                {
                    printf("Mismatch parentheses are : %c %c \n",temp,exp[i]);
                    return 0;
                }
            }
        }
    }
    if(s->top==-1)
    {
        printf("Parentheses are balanced\n");
        return 1;
    }
    else{
        printf("Left parentheses are more\n");
        return 0;
    }
}

int match(char c1, char c2)
{
    if((c1=='{' && c2=='}') ||(c1=='[' && c2==']') || (c1=='(' && c2==')'))
        return 1;
    else
        return 0;
}

void push(struct arrayStack *s, char c)
{
    if(s->top==s->capacity-1)
    {
        printf("stack Overflow");
        return;
    }
    else{
        s->exp[++s->top]=c;
    }
}

char pop(struct arrayStack *s)
{
    if(s->top==-1)
    {
        printf("Stack Underflow");
    }
    else{
        return s->exp[s->top--];
    }
}
