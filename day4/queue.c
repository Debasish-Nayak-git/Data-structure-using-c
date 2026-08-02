#include <stdio.h>
#define size 20
int q[size],rear=-1,front=-1;
void Insertion()
{int item;
printf("Enter the element to be insert:\n");
scanf("%d",&item);
if (rear==size-1)
printf("Queue overflow");
else{
    if (front==-1){
    rear=0;
    front=0;
    }
    else 
    rear=rear+1;
q[rear]=item;
}}
//deletion
void Deletion()
{int temp;
if (front==-1)
printf("Queue empty");
else{
    temp=q[front];
    printf("Deleted element = %d\n",temp);
    if (rear==front){
        rear=-1;
        front=-1;
    }
    else
    front=front+1;

}}
//Display
void Display()
{
if (front==-1)
printf("Queue empty");
else{
    printf("Elements of queue");
    for (int i=front;i<=rear;i++)
    printf("%d ",q[i]);
printf("\n");
}}
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