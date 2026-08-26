/*array operations 
1)insertion from begin or at index or at end
2)Deletion from begin or at index or at end
3)traverse*/
#include <stdio.h>
#define size 5
int curr_index=0;
//Declaration of User_defined function
void menu(void);
void insert_end(int[]);
void Delete_end(int[]);
void Delete_index(int[],int);
void insert_index(int[],int);
void Display(int[]);
void linear_search(int [],int);
void binary_search(int [],int);
//main function
int main ()
{int arr[size]={0};
while(1)
{int ch,i;
menu();
scanf("%d",&ch);
if (ch!=10)
{switch (ch)
{case 1:insert_end(arr);
    break;
case 2:printf("\nEnter index to input:");
        scanf("%d",&i);
        insert_index(arr,i);
    break;
case 3:Display(arr);
    break;
case 4:Delete_end(arr);
    break;
case 5:
    printf("\nEnter index to Delete:");
    scanf("%d",&i);
    Delete_index(arr,i);
        break;
case 6:insert_index(arr,0);
    break;
case 7:Delete_index(arr,0);
    break;
case 8: printf("Enter the number to be search");
    scanf("%d",&i);
    linear_search(arr,i);
    break;
case 9:
    printf("Enter the number to be search");
    scanf("%d",&i);
    binary_search(arr,i);
    break;
default:
printf("\n Wrong choice");
}   
}
else
break; 
}
    return 0;
}
//insert
void insert_end(int a[]){
    int val;
    printf("\nEnter Value to input: ");
    scanf("%d",&val);
    if (curr_index<size)
    a[curr_index++]=val;
    else
    printf("\nArray Overloading ");
}
//insert_index
void insert_index(int a[],int ind){
    int val;
    printf("\nEnter Value to input: ");
    scanf("%d",&val);
    if(curr_index>=size || ind>size && ind<0)
    printf("\n Array Overflow");
    else
    for (int i=curr_index;i>=ind;i--)
    {a[i+1]=a[i];
    }a[ind]=val;
    curr_index++;
}
//display
void Display(int a[]){
    if (curr_index==0)
    printf("\nArray Empty");
    else{printf("\nElement of array:");
    for (int i=0;i<curr_index;i++)
    printf("%d ",a[i]);}
}
//Deletion
void Delete_end(int a[]){
    if (curr_index==0)
    printf("\nArray Empty\n ");
    else{printf("\nDeleted Element:%d\n",a[curr_index-1]);
    curr_index--;}
    Display(a);
}
//Deletion_index
void Delete_index(int a[],int ind){
    
    if (ind>=curr_index || ind<=0)
    printf("\n Not possible");
    else
    {printf("\nDeleted Element:%d",a[ind]);
        for (int i=ind;i<curr_index;i++)
            a[i]=a[i+1];
     curr_index-=1;}
    Display(a);
}
//menu
void menu(){
printf("\n1.insert_end ");
printf("\n2.insert_index ");
printf("\n3.Display ");
printf("\n4.Delete_end ");
printf("\n5.Delete_index ");
printf("\n6.insert_begin ");
printf("\n7.Deletion_begin ");
printf("\n8.Linear Search");
printf("\n9.Binary Search ");
printf("\n10.Exit");
printf("\nEnter your choice ");
}
//linear search
void linear_search(int a[],int value)
{for(int i=0;i<curr_index;i++)
    {if (value==a[i])
    printf("\n %d found at %d index",value,i);}
}
//binary search
void binary_search(int arr[],int target)
{for(int j=0;j<curr_index;j++)
{for (int i=0;i<curr_index;i++)
{   if(arr[j]<arr[i])
    {int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp; }
}}
Display(arr);
int mid,beg=0,end=curr_index-1;
//searching
for(;beg<=end;)
{mid =(beg+end)/2;
if(arr[mid]==target) 
{ printf("\n%d found at %dth position",target,mid+1);
    break;}
else if (arr[mid]<target)
beg=mid+1;
else
 end=mid-1;
}
}