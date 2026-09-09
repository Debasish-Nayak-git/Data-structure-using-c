#include <stdio.h>
#define size 18
int s[size],top=-1;
void Push();
void Pop();
void Display();
void Peek();
void Peep();
void Change();
int Menu();
int isFull();
int isEmpty();
//main function
int main()
{int ch;
while(1)
{ch=Menu();
if(ch!=7){
switch(ch)
{case 1:
   Push();
   break;
case 2:
   Pop();
   break;
case 3:
   Display();
   break;
case 4:
   Peep();
   break;
case 5:
   Peek();
   break;
case 6:
   Change();
   break;
default:
   printf("invalid choice\n");
}}
else
  break;
}
return 0;
}

//push
void Push()
{int item;
printf("Enter the element to be push\n");
scanf("%d",&item);
if(isFull())
printf("stack is full\n");
else
{top=top+1;
 s[top]=item;      
}}

//pop
void Pop()
{int item;
if(isEmpty())
printf("stack is empty\n");
else
{item=s[top];   
 top=top-1;
 printf("Deleted element:%d\n",item);
}}

//display
void Display()
{if(isEmpty())
printf("stack is empty\n");
else
{printf("Elements of stack:\n");
for(int i=top;i>=0;i--)
 printf("%d ",s[i]);
}}

//Peek
void Peek()
{printf("\n peek element=%d\n",s[top]);
}

//peep
void Peep()
{int pos;
printf("Enter the position\n");
scanf("%d",&pos);
if (pos<=0 || top-pos+1<0)
printf("\n operation not possible \n");
else
printf("copied element=%d\n",s[top-pos+1]);
}
//change
void Change()
{int pos,val;
printf("Enter position\n");
scanf("%d",&pos);
printf("Enter value \n");
scanf("%d",&val);
if (pos<=0 || top-pos+1<0)
printf("\n changing operation not possible \n");
else
s[top-pos+1]=val;
printf("Content of stack:\n");
for(int i=top;i>=0;i--)
 printf("%d ",s[i]);
}
int Menu()
{int ch;
printf("\n1.Push\n");
printf("2.Pop\n");
printf("3.Display\n");
printf("4.peep\n");
printf("5.peek\n");
printf("6.change\n");
printf("7.Exit\n");
printf("Enter your choice:\n");
scanf("%d",&ch);
return ch;
}
int isFull()
{return top==size-1;}
int isEmpty()
{return top==-1;}