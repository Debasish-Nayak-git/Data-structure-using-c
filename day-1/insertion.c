#include <stdio.h>
int main()
{
int  i,n,plc,size;
printf("Enter the number and place to insert");
scanf("%d%d",&n,&plc);
printf("Enter the number of element of array");
scanf("%d",&size);
int arr[size];
printf("Enter the array element");
for(i=0;i<size-1;i++)
scanf("%d",&arr[i]);

for(i=size-2;i>=plc-1;i--)
arr[i+1]=arr[i];
arr[plc-1]=n;
for(i=0;i<size;i++)
printf("%d  ",arr[i]);


return 0;
}