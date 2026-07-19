#include <stdio.h>
int main()
{
int  i,target,size;
printf("Enter the number to be search");
scanf("%d",&target);
printf("Enter the size of array");
scanf("%d",&size);
int arr[size];
printf("Enter the array element");
for(i=0;i<size;i++)
{
scanf("%d",&arr[i]);
}
int mid,beg=0,end=size-1;
for(i=0;i<size;i++)
{mid =(beg+end)/2;
if(arr[mid]==target) 
{ printf("%d found at %dth position",target,mid+1);
return 0;
}
else if (arr[mid]<target)
beg=mid+1;
else
 end=mid-1;
}
return 0;
}