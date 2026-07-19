#include <stdio.h>
int main()
{
int  i,size;
printf("Enter the size of array");
scanf("%d",&size);
int arr[size],temp;
printf("Enter the array element");
for(i=0;i<size;i++)
scanf("%d",&arr[i]);
for(int j=0;j<size-1;j++)
{for (i=j+1;i<size;i++)
{   if(arr[j]>arr[i])
    {temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
    }
}}
for(i=0;i<size;i++)
printf("%d ",arr[i]);

return 0;
}