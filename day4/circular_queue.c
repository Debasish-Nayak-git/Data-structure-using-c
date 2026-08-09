#include <stdio.h>
#define size 5
int cq[size],rear=-1,front=-1;
void Insertion()
{int item;
printf("Enter the element to be insert:\n");
scanf("%d",&item);
if ((front==0 && rear==size-1)|| (front==rear+1))
printf("Queue overflow\n");
else{
    if (front==-1){
    rear=0;
    front=0;
    }
    else
    { if(rear==size-1 && front>0)
    rear=0;
    else 
    rear=rear+1;}
cq[rear]=item;
}}
//deletion
void Deletion()
{int temp;
if (front==-1)
printf("Queue empty\n");
else{
    temp=cq[front];
    printf("Deleted element = %d\n",temp);
    if (front==rear){
        rear=-1;
        front=-1;
    }
    else if (front==size-1)
    front=0;
    else
    front=front+1;

}}
//Display
void Display()
{
if (front==-1)
printf("Queue empty");
else{
    printf("Elements of queue\n");
    if(front<=rear){
        for (int i=front;i<=rear;i++)
            printf("%d ",cq[i]);
        printf("\n");}
    else
     { for (int i=front;i<=size-1;i++)
        printf("%d ",cq[i]);
       for (int i=0;i<=rear;i++)
        printf("%d ",cq[i]);
       printf("\n");}
    }
}
//main function
int main()
{int ch;
while(1)
{printf("\n1.Insertion\n");
printf("2.Deletion\n");
printf("3.Display\n");
printf("4.Exit\n");
printf("Enter your choice:\n");
scanf("%d",&ch);
if(ch!=4){
switch(ch)
{case 1:
   Insertion();
   break;
case 2:
   Deletion();
   break;
case 3:
   Display();
   break;
default:
   printf("invalid choice\n");
}}
else
  break;
}
return 0;
}