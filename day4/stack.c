#include <stdio.h>
#define size 18
int s[size],top=-1;
void Push()
{int item;
printf("Enter the element to be push\n");
scanf("%d",&item);
if(top==size-1)
printf("stack is empty\n");
else
{top=top+1;
 s[top]=item;
 printf("Elements of array:\n");
for(int i=top;i>=0;i--)
 printf("%d ",s[i]);   
}}
void Pop()
{int item;
if(top==-1)
printf("stack is empty\n");
else
{item=s[top];   
 top=top-1;
 printf("Deleted element:%d\n",item);
 printf("Elements of array:\n");
for(int i=top;i>=0;i--)
 printf("%d ",s[i]);
}}
void Display()
{if(top==-1)
printf("stack is empty\n");
else
{printf("Elements of array:\n");
for(int i=top;i>=0;i--)
 printf("%d ",s[i]);
printf("\n");
}}
//main function
int main()
{int ch;
while(1)
{printf("1.Push\n");
printf("2.Pop\n");
printf("3.Display\n");
printf("4.Exit\n");
printf("Enter your choice:\n");
scanf("%d",&ch);
if(ch!=4){
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
default:
   printf("invalid choice\n");
}}
else
  break;
}
return 0;
}
