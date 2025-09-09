#include<stdio.h>
#include<string.h>
#define max 100
char stack[max];
int top=-1;
void push(char ch)
{
    if(top==max-1)
    {
        printf("stack overflow");
    }
    else
    {
        stack[++top]=ch;
    }
}
char pop()
{
    if(top==-1)
    {
        printf("stack underflow\n");
        return '\0';
    }
    else
    {
        return stack[top--];
    }
}
int main()
{
    char str[max];
    int i;
    printf("enter string\n");
    gets(str);
    for(i=0;i<strlen(str);i++)
    {
        push(str[i]);
    }
    printf("reversed string\n");
    while(top !=-1)
    {
        printf("j %c",pop());
    }
}
