#include<stdio.h>
void swap(int *x,int *y)
{
    int t=*x;
    *x=*y;
    *y=t;
}
void heapify(int a[],int n,int i)
{
    int large=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && a[l]>a[large])
      large=l;
    if(r<n&& a[r]>a[large])
      large=r;
    if(large!=i)
    {
        swap(&a[i],&a[large]);
        heapify(a,n,large);
    }
}
void heapsort(int a[],int n)
{
    for(int i=n/2-1;i>=0;i--)
        heapify(a,n,i);
    for(int i=n-1;i>=0;i--)
      {
          swap(&a[0],&a[i]);
          heapify(a,i,0);
      }
}
void print(int a[],int n)
{
    for(int i=0;i<n;i++)
      printf("%d",a[i]);
}
int main()
{
    int a[]={6,1,9,3,2,5,8};
    int n=sizeof(a)/sizeof(a[0]);
    heapsort(a,n);
    print(a,n);
}
