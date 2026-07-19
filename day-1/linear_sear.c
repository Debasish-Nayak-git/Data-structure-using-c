#include <stdio.h>
int main()
{
int  i,target,size,freq=0;
printf("Enter the searching element:");
scanf("%d",&target);
printf("Enter the size of array");
scanf("%d",&size);
int arr[size];
printf("Enter the array element");
for(i=0;i<=size-1;i++)
scanf("%d",&arr[i]);
for(i=0;i<size;i++)
{if (target==arr[i])
{freq=freq+1;
printf("%d found at %d th position\n",target,i+1);
}}
if(freq>0)
printf("%d found  %d times",target,freq);
else
printf("%d not found",target);

return 0;
}