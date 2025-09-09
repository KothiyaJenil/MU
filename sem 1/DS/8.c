#include<stdio.h>
#define MAX 50
int stack[MAX];
int top=-1;
//push function
void push(int value)
 {
   if(top==MAX-1)
   {
   printf("stack is overflow \n");
   }
   else
   {
   top++;
   stack[top]=value;
   }
 }
int pop()
{
    if(top==-1)
    {
        printf("stack is underflow\n");
        return 1;
    }
    else
    {
        int value=stack[top];
        top--;
        return value;
    }
}
void main()
{
    int n,i;
    int fact=1;
    printf("enter a number.");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        push(i);
    }
    while(top!=-1)
    {
        fact=fact*pop();
    }
        printf("factorial of %d is: %d",n,fact);

}
