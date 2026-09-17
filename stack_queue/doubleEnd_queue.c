//Double ended Queue implementation using array
#include <stdio.h>
#define MAX 5
int Qu[MAX];
int front = -1, rear = -1;
int menu();
int isEmpty();
int isFull();
void Enqueue();
void Dequeue();
void Display();
void Enqueue_front();
void Dequeue_rear();

int main()
{int ch;
    while(1)
        {
        ch=menu();
        if(ch!=6)
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
        case 4:
            Enqueue_front();
            break;
        case 5:
            Dequeue_rear();
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
    return front == -1;
}
int isFull(){
    return (rear + 1) % MAX == front;
}
void Enqueue()
{
    int item;
    printf("\nEnter the element to insert: \n");
    scanf("%d", &item);

    if (isFull())
        printf("\nQueue overflow\n");
    else {
        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % MAX;
        Qu[rear] = item;
    }
}
void Dequeue()
{
    if (isEmpty())
        printf("\nQueue empty\n");
    else {
        printf("\nDeleted element = %d\n", Qu[front]);
        if (rear == front)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
    }
}
void Display()
{
    if (isEmpty())
        printf("\nQueue empty\n");
    else {
        int i = front;
        printf("\nElements of queue:\n");
        while (i != rear) {
            printf("%d ", Qu[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", Qu[rear]);
    }
}
int menu()
{int ch;
printf("\n1.Insertion\n");
printf("2.Deletion\n");
printf("3.Display\n");
printf("4.Insertion from front\n");
printf("5.Deletion from rear\n");
printf("6.Exit\n");
printf("Enter your choice:\n");
scanf("%d",&ch);
return ch;
}
void Enqueue_front()
{
    int item;
    printf("\nEnter the element to insert: \n");
    scanf("%d", &item);

    if (isFull())
        printf("\nQueue overflow\n");
    else {
        if (isEmpty())
            front = rear = 0;
        else
            front = (front-1 + MAX) % MAX;
        Qu[front] = item;
    }
}
void Dequeue_rear()
{
    if (isEmpty())
        printf("\nQueue empty\n");
    else {
        printf("\nDeleted element = %d\n", Qu[rear]);
        if (rear == front)
            front = rear = -1;
        else
            rear = (rear - 1 + MAX) % MAX;
    }
}