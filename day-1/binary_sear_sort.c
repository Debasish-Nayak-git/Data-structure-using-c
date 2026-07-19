#include <stdio.h>
int main()
{
int  i,target,size,temp;
printf("Enter the size of array");
scanf("%d",&size);
int arr[size];
//array initialization
printf("Enter the array element");
for(i=0;i<=size;i++)
scanf("%d",&arr[i]);
//target
printf("Enter the number to be search");
scanf("%d",&target);
//sorting
for(int j=0;j<size;j++)
{for (i=0;i<size;i++)
{   if(arr[j]<arr[i])
    {temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
    }
}}
//print shorted array
for(i=0;i<size;i++)
printf("%d ",arr[i]);
printf("\n");
int mid,beg=0,end=size-1;
//searching
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