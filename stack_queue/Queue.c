#include <stdio.h>
#define max 5
int Qu[max];
int front=-1,rear=-1;
int menu();
int isEmpty();
int isFull();
void Enqueue();
void Dequeue();
void Display();

int main()
{int ch;
    while(1)
        {
        ch=menu();
        if(ch!=4)
        {
        switch(ch)
        {
        case 1:
            Enqueue();
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            Display();
            break;
        default:
            printf("invalid choice\n");
        }
        }
        else
            break;
        }
return 0;
}
int isEmpty(){
    if (front==-1) return 1;
    else return 0;
}
int isFull(){
    if (rear==max-1) return 1;
    else return 0;
}
void Enqueue()
{int item;
printf("\nEnter the element to be insert:\n");
scanf("%d",&item);
if (isFull())
    printf("\nQueue overflow\n");
else{
    if (isEmpty())
        rear=front=0;
    else 
        rear=rear+1;
    Qu[rear]=item;
    }
}
void Dequeue()
{
    if (isEmpty())
        printf("\nQueue empty\n");
    else{
        printf("\nDeleted element = %d\n",Qu[front]);
        if (rear==front)
            rear=front=-1;
        else
            front=front+1;
        }
}
void Display()
{
if (isEmpty())
    printf("\nQueue empty\n");
else{
    printf("\nElements of queue:\n");
    for (int i=front;i<=rear;i++)
        printf("%d ",Qu[i]);
printf("\n");
}}
int menu()
{int ch;
printf("\n1.Insertion\n");
printf("2.Deletion\n");
printf("3.Display\n");
printf("4.Exit\n");
printf("Enter your choice:\n");
scanf("%d",&ch);
return ch;
}