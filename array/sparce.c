#include <stdio.h>
void input(int mat[20][20],int r,int c)
{printf("enter elements of the matrix\n");
   for( int i=0;i<r;i++)
      {for ( int j=0;j<c;j++)
         scanf("%d",&mat[i][j]);
      }
}
void tran_trip(int Tran[20][3],int s[20][3],int c)
{int i,j,k=0;
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
    
}
int creat_triplet(int mat[20][20],int r,int c,int s[20][3])
{int i,j,t=0;
 for(i=0;i<r;i++)
   {for (j=0;j<c;j++)
       if(mat[i][j]!=0)
         { t=t+1;
           s[t][0]=i;
           s[t][1]=j;
           s[t][2]=mat[i][j];
         }
    }
  s[0][0]=r;
  s[0][1]=c;
  s[0][2]=t;
return t;
}
void display(int s[20][20],int t,int c)
{int i,j;
    for(i=0;i<t;i++)
        {for (j=0;j<c;j++)
            printf("%d ",s[i][j]);
            printf("\n");
        }
}
void display_sparce(int s[20][3],int t,int c)
{int i,j;
    for(i=0;i<t;i++)
        {for (j=0;j<c;j++)
            printf("%d ",s[i][j]);
            printf("\n");
        }
}
int main ()
{
int i,j,r,c,mat[20][20],s[20][3];
printf("enter row and col of the matrix\n");
scanf("%d%d",&r,&c);
input(mat,r,c);
printf("Sparse matrix:\n");
display(mat,r,c);
int t=creat_triplet(mat,r,c,s);
printf("Triplet of Sparse matrix:\n");
display_sparce(s,t+1,3);
int tran_triplet[20][3];
tran_trip(tran_triplet,s,c);
printf("Transpose Triplet of Sparse matrix:\n");
display_sparce(tran_triplet,t+1,3);
return 0;
}