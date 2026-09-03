#include <stdio.h>
void add_triplet(int [][3],int [][3],int[][3]);
void tran_trip(int [][3],int [][3],int );
int creat_triplet(int [20][20],int ,int ,int [20][3]);
void display(int [20][20],int ,int );
void display_sparce(int [20][3],int ,int );
void input(int [20][20],int ,int );
void tran_trip(int [20][3],int [20][3],int );

//main function
int main ()
{
int i,j,r=4,c=4,s[20][3],s1[20][3],s2[20][3],s3[20][3],mat3[20][20];
int mat2[20][20]={ {0,0,3,0},
                   {0,0,5,0},
                   {0,0,0,0},
                   {0,0,6,0}};
int mat[20][20]={{0,0,0,0},
                 {0,1,0,0},
                 {0,0,2,0},
                 {0,0,5,0}};

printf("enter row and col of the matrix\n");
scanf("%d%d",&r,&c);
input(mat3,r,c);
printf("Sparse matrix:\n");
display(mat3,r,c);
int t3=creat_triplet(mat2,r,c,s);
int tran_triplet[20][3];
tran_trip(tran_triplet,s,c);
printf("Transpose Triplet of Sparse matrix:\n");
display_sparce(tran_triplet,t3+1,3);
printf("Triplet of Sparse matrix1:\n");
display_sparce(s,t3+1,3);
printf("Sparse matrix1:\n");
display(mat,r,c);
printf("Sparse matrix2:\n");
display(mat2,r,c);
int t=creat_triplet(mat,r,c,s1);
int t2=creat_triplet(mat2,r,c,s2);
printf("Triplet of Sparse matrix1:\n");
display_sparce(s1,t+1,3);
printf("Triplet of Sparse matrix2:\n");
display_sparce(s2,t2+1,3);
add_triplet(s1,s2,s3);
printf("Addition of two Sparse matrix:\n");
display_sparce(s3,s3[0][2]+1,3);

return 0;
}

//addition of triplet form
void add_triplet(int s1[20][3],int s2[20][3],int s3[20][3])
{int i=1,j=1,k=1;
  if (s1[0][0]!=s2[0][0] || s1[0][1]!=s2[0][1])
  {printf("Addition not possible");
    return;
  }
  s3[0][0]=s1[0][0];
  s3[0][1]=s1[0][1];
    while(i<=s1[0][2] && j<=s2[0][2])
    {if(s1[i][0]<s2[j][0])
        {s3[k][0]=s1[i][0];
         s3[k][1]=s1[i][1];
         s3[k][2]=s1[i][2];
         i++;
         k++;
        }
     else if(s1[i][0]>s2[j][0])
        {s3[k][0]=s2[j][0];
         s3[k][1]=s2[j][1];
         s3[k][2]=s2[j][2];
         j++;
         k++;
        }
     else
        {if(s1[i][1]<s2[j][1])
            {s3[k][0]=s1[i][0];
             s3[k][1]=s1[i][1];
             s3[k][2]=s1[i][2];
             i++;
             k++;
            }
         else if(s1[i][1]>s2[j][1])
            {s3[k][0]=s2[j][0];
             s3[k][1]=s2[j][1];
             s3[k][2]=s2[j][2];
             j++;
             k++;
            }
         else
            {s3[k][0]=s1[i][0];
             s3[k][1]=s1[i][1];
             s3[k++][2]=s1[i++][2]+s2[j++][2];
            }
        }
    }
   while(i<=s1[0][2])
   {s3[k][0]=s1[i][0];
    s3[k][1]=s1[i][1];
    s3[k++][2]=s1[i++][2];
   }
   while(j<=s2[0][2])
   {s3[k][0]=s2[j][0];
    s3[k][1]=s2[j][1];
    s3[k++][2]=s2[j++][2];
   }
    s3[0][2]=k-1;
}

//Transpose of triplet form
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

//Triplet form creation from matrix
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

//Display of matrix 
void display(int m[20][20],int t,int c)
{int i,j;
    for(i=0;i<t;i++)
        {for (j=0;j<c;j++)
            printf("%d ",m[i][j]);
            printf("\n");
        }
}

//Display of triplet form
void display_sparce(int s[20][3],int t,int c)
{int i,j;
    for(i=0;i<t;i++)
        {for (j=0;j<c;j++)
            printf("%d ",s[i][j]);
            printf("\n");
        }
}

//input of matrix
void input(int mat[20][20],int r,int c)
{printf("enter elements of the matrix\n");
   for( int i=0;i<r;i++)
      {for ( int j=0;j<c;j++)
         scanf("%d",&mat[i][j]);
      }
}