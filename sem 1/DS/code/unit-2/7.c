#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int queue[MAX];
int front=-1;
int rear=-1;
void insert(int element)
{
   if((front == 0 && rear==MAX-1) || (rear==(front-1)%(MAX-1)))
   {
     printf("\n Queue is full, Insertion not possible");
     return;
   }
  else if(front==-1)
   {
     front=rear=0;
     queue[rear]=element;
   }
  else if(rear==MAX-1 && front!=0)
   {
   rear=0;
   queue[rear]=element;
   }
   else
   {
   rear++;
   queue[rear]=element;
   }
   printf("\n Inserted->%d\n",element);
  }

void deletee()
  {
   if(front==-1)
  {
  printf("\n Nothing to display ,queue is empty");
  return;
  }
   printf("\n Deleted->%d\n",queue[front]);
  if(front==rear)
  {
   front=rear=-1;
  }
  else if (front==MAX-1)
    front=0;
   else
   front++;
}


   void display()
   {
   int i;
   if(front==-1)
   {
   printf("\nQueue is empty\n");
   return;
   }
   printf("queue elements are\n");
   if(rear>=front)
   {
    for(i=front;i<=rear;i++)
    printf(" %d",queue[i]);
   }
    else
    {
    for(i=front;i<MAX;i++)
    printf(" %d",queue[i]);
    for(i=0;i<=rear;i++)
    printf(" %d",queue[i]);
    }
    printf("\n");
  }
  int main()
  {
  int choice ,value;
  while(1)
  {
  printf("\n Circuler Queue\n");
  printf("1. INSERT\n2. DELETE\n3. DISPLAY\n4. EXIT\n");
  printf("Enter your choice:");
  scanf(" %d",&choice);
  switch(choice)
  {
  case 1:
    printf("enter the value to insert:");
    scanf("%d",&value);
    insert(value);
    break;
    case 2 :
    deletee();
    break;
    case 3:
    display();
    break;
    case 4:
    exit(0);
    default:
    printf("\n Invalid choice");
    }
    }
    return 0;
 }
