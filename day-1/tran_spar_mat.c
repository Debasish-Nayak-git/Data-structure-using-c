#include <stdio.h>
int main ()
{
int i,j,r,c,mat[20][20],s[20][3],t=0,Tran[20][3],k=0;
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
Tran[0][0]=s[0][1];
Tran[0][1]=s[0][0];
Tran[0][2]=s[0][2];
for( i=0;i<c;i++)
{for(j=0;j<=s[0][2];j++)
if(s[j][1]==i)
{k=k+1;
Tran[k][0]=s[j][1];
Tran[k][1]=s[j][0];
Tran[k][2]=s[j][2];
}
}
printf("Tran of triplet form:\n");
for(i=0;i<t+1;i++)
{for (j=+0;j<3;j++)
printf("%d ",Tran[i][j]);
printf("\n");
}

return 0;
}