//print n numbers using recursion
#include <stdio.h>
void display(int n)
{if (n==0)
    return;
else 
{display(n-1);
printf("%d ",n);
}
}
//print n numbers in reverse order using recursion
void rev_display(int n)
{
if (n==0)
    return;
else
{printf("%d ",n);
rev_display(n-1);
}
}
int main()
{ 
    int n;
    printf("Enter a number\n");
    scanf("%d",&n);
    display(n);
    printf("\n");
    rev_display(n);

    return 0;
}