#include<stdio.h>
void input(int a[2][4],int r,int c)
{int i,j;
printf("\n enter elements of matrix:\n");
for(i=0;i<r;i++){
for(j=0;j<c;j++){
scanf("%d",&a[i][j]);
}}
}
void display(int m[2][4],int r,int c){
int i,j;
for(i=0;i<r;i++){
for(j=0;j<c;j++)
printf("%d ",m[i][j]);
printf("\n");
}
}
int main()
{
int mat[4][4];
input(mat,4,4);
display(mat,4,4);
return 0;
}