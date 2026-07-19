#include <stdio.h>
int main ()
{
int i,j,r,c,mat[20][20],s[20][3],t=0;
printf("enter row and col of the matrix\n");
scanf("%d%d",&r,&c);
printf("enter elements of the matrix\n");
for(i=0;i<r;i++)
{for (j=+0;j<c;j++)
scanf("%d",&mat[i][j]);
}
for(i=0;i<r;i++)
{for (j=+0;j<c;j++)
if(mat[i][j]!=0)
{t=t+1;
s[t][0]=i;
s[t][1]=j;
s[t][2]=mat[i][j];
}
}
s[0][0]=r;
s[0][1]=c;
s[0][2]=t;
printf("Triplet of Sparce matrix:\n");
for(i=0;i<t+1;i++)
{for (j=+0;j<3;j++)
printf("%d ",s[i][j]);
printf("\n");
}

return 0;
}