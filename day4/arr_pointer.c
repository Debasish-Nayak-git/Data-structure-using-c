#include <stdio.h>
int main()
{int a[10]={10,20,24,15,45,47,84,79,48,56};
for(int i=0;i<10;i++)
printf("%d ",*(a+i));
    return 0;
}