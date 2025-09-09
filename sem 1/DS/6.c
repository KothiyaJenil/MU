#include<stdio.h>
void main()
{
    int a[100],i,num,max=0;
    printf("enter size of array");
    scanf("%d",&num);
    printf("enter an element of array A+");
    for(i=0;i<num;i++)
    scanf("%d",&a[i]);
    for(i=0;i<num;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    printf("the largest value is %d",max);
}
