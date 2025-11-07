#include<stdio.h>

void main()
{
    int a[10],i=0,flag=0,j;
    printf("enter 10 element \n");
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("\n the element of array are:\n");
    for(i=0;i<10;i++)
    {
        printf("\n%d",a[i]);
    }
    printf("\n the element of search=");
    scanf("%d",&j);
    for(i=0;i<10;i++)
    {
        if(a[i]==j)
            {
                flag=1;
                break;
            }
    }
        if(flag==1)
        {
            printf("searched element is found at index %d",i);
        }
        else
        {
            printf("searched element is not found");
