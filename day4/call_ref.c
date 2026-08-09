#include <stdio.h>
void call(int *p ,int *q);
void call(int *a,int *b)
{
int temp=*a;
*a=*b;
*b=temp;

}
int main()
{int a=10,b=20;
int *p=&a,*q=&b;
printf("Before swaping a=%d ,b=%d\n",*p,*q);
call(p,q);
printf("After swaping a=%d,b=%d\n",*p,*q);
    return 0;
}