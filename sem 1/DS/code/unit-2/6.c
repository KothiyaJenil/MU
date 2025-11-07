#include<stdio.h>
#include<stdlib.h>
#define size 5
int Queue[size],front=-1,rear=-1;
void insert(int val)
  {
   if((rear+1) % size==front)
   printf("Queue is full");
   else

   {
   if(front==-1)
   front=0;
   rear=(rear+1) % size;
   Queue[rear]=val;
   printf("inserted %d\n",val);
   }
  }
  void delete()
  {
  if(front==-1)
    {
    printf("queue is empty");
    }
    else
    {
    printf("deleted %d\n",Queue[front]);
     }
    if
    (front==rear) front=rear=-1;
    else
    front=(front+1)%size;
    }

   void display()
   {
   if(front==-1)
    {
     printf("queue is empty");
    }
     else
     {
     int i=front;
     printf("queue");
     while(1)
     {
     printf("\n %d",Queue[i]);
     if(i==rear)
     break;
     i=(i+1)%size;
     }
     printf("\n");
   }
  }
  int main()
  {
  int choice,val;
  while(1)
  {
  printf("\n----Circulaer Queue Menu----\n");
  printf("1.Insert\n2. Delete\n 3.Display\n4. Exit\n");
  printf("enter choice");
  scanf("%d",&choice);
  switch(choice)
  {
  case 1:
   printf("enter value:");
   scanf("%d",&val);
   insert(val);
   break;
  case 2:
   delete();
   break;
  case 3:
   display();
   break;
  case 4:
  return 0;
  default:
  printf("invalid choice!\n");
  }
 }
}
