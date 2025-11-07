#include<stdio.h>
void main()
{
    int a[10],sum=0,i=-0;
    float avg;
    printf("enter element of array");
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<10;i++)
    {
        sum=sum+a[i];
    }
    printf("\n sum of array is =%d",sum);
    avg=(float)sum/10;
    printf("\n average is =%d",avg);
}
