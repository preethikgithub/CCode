#include<stdio.h>
int a[10][10],m,n,n1;
void display()
{
    for(int i=0;i<m;i++)
    { for(int j=0;j<n;j++)
       printf("%d ",a[i][j]);
      printf("\n");
    }
}
void build(int s,int d)
{
    a[s][d]=1;
}
int main()
{   int n1,s,d;
    printf("m and n:");
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++)
     for(int j=0;j<n;j++)
       a[i][j]=0;
    build(0,1);
    build(0,2);
    build(0,3);
    build(1,3);
    build(1,4);
    build(2,3);
    build(3,4);
    display();
}
