#include <stdio.h>
void input(int mat[20][20],int r,int c)
{printf("enter elements of the matrix\n");
   for( int i=0;i<r;i++)
      {for ( int j=0;j<c;j++)
         scanf("%d",&mat[i][j]);
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
display_sparce(s,t,3);
return 0;
}