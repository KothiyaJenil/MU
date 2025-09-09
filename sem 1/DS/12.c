#include<stdio.h>
#include<conio.h>
void hanoi(int n,char from_rodA,char to_rodC,char aux_rodB)
{
if(n==1)
{
printf("\n move disk 1 from rod  %c to rod  %c",from_rodA,to_rodC);
return;
}
hanoi(n-1,from_rodA,aux_rodB,to_rodC); //Move top 2 disks from A → B (using C).
printf("\n move disk %d from rod  %c to rod %c",n,from_rodA,to_rodC); //Move the biggest disk (3) from A → C.
hanoi(n-1,aux_rodB,to_rodC,from_rodA); //Move the 2 disks from B → C (using A).
}
void main()
{
int n;//number of disks
printf("\n enter number of disks:");
scanf("%d" ,&n);
if(n>0)
hanoi(n,'A','B','C');
getch();
}
