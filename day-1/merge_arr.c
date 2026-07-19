#include <stdio.h>
int main()
{
int s1,s2,i,j;
printf("enter size of both array\n");
scanf("%d%d",&s1,&s2);
int a[s1],b[s2],mer[s1+s2];
printf("Enter elements of 1st array");
for(i=0;i<s1;i++)
scanf("%d",&a[i]);
printf("Enter elements of 2nd array");
for(i=0;i<s2;i++)
scanf("%d",&b[i]);
for(i=0;i<s1;i++)
mer[i]=a[i];
for(j=0;j<s2;j++,i++)
mer[i]=b[j];
for(i=0;i<s1+s2;i++)
printf("%d  ",mer[i]);

return 0;    
}