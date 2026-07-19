#include <stdio.h>
int main()
{
int  i,plc,size;
printf("Enter the place for deletion");
scanf("%d",&plc);
printf("Enter the number of element of array");
scanf("%d",&size);
int arr[size];
printf("Enter the array element");
for(i=0;i<size;i++)
scanf("%d",&arr[i]);

for(i=plc-1;i<size;i++)
arr[i]=arr[i+1];
for(i=0;i<size-1;i++)
printf("%d  ",arr[i]);


return 0;
}