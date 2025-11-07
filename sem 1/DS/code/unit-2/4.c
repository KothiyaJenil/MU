#include<stdio.h>
#include<conio.h>
void hanoi(int n,char from_rodA,char to_rodC,char aux_rodB)
{
if(n==1)
{
printf("\n move disk 1 from rod  %c to rod  %c",from_rodA,to_rodC);
return;
}
hanoi(n-1,from_rodA,aux_rodB,to_rodC);
printf("\n move disk %d from rod  %c to rod %c",n,from_rodA,to_rodC);
hanoi(n-1,aux_rodB,to_rodC,from_rodA);
}
void main()
{
int n;
printf("\n enter number of disks:");
scanf("%d" ,&n);
if(n>0)
hanoi(n,'A','B','C');
getch();
}
