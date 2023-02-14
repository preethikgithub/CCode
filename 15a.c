#include<stdio.h>
#include<stdlib.h>
int n;
struct node
{
    int data;
    struct node* nxt;
}*newnode,*temp,*a[10];
struct node *tail=NULL;
void create(struct node *v,int x)
{
    newnode=(struct node*)malloc(sizeof(struct node*));
    newnode->data=x;
    newnode->nxt=NULL;
    if(v->nxt==NULL)
     { v->nxt=newnode;
       tail=newnode;
     }
    else
    {   tail->nxt=newnode;
        tail=newnode;
    }
      
}
void build()
{   
    int val,n1,val1;
    printf("\n ENTER THE NO.OF VERTICES IN A GRAPH:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
       a[i]=(struct node*)malloc(sizeof(struct node*));
    for(int i=0;i<n;i++)
    {   printf("vertex:");
        scanf("%d",&val);
        a[i]->data=val;
        a[i]->nxt=NULL;
        printf("\n enter no.of neighbours:");
        scanf("%d",&n1);
        for(int j=0;j<n1;j++)
        {   printf("\nneighbour:");
            scanf("%d",&val1);
            create(a[i],val1);
        }
        //tail=NULL;
    }
}
void display()
{   
    for(int i=0;i<n;i++)
    {  temp=a[i];
       while(temp!=NULL)
       {
           printf("%d-> ",temp->data);
           temp=temp->nxt;
       }
       printf("\n");
    }
}
void outdegree()
{
    for(int i=0;i<n;i++)
    {   int c=-1;
        temp=a[i];
        while(temp!=NULL)
        {
         c++;
         temp=temp->nxt;
        }
        printf("\n outdegree of%d is:%d",a[i]->data,c);
    }
}
void indegree()
{   
    for(int i=0;i<n;i++)
    {
        int c=0;
        for(int j=0;j<n;j++)
        {
            temp=a[j];
            while(temp->nxt!=NULL)
            {   temp=temp->nxt;
                if(temp->data==a[i]->data)
                 c++;
                 
            }
        }
        printf("indegree of %d is %d\n",a[i]->data,c);
    }
}
int main()
{
    build();
    display();
    //outdegree();
    indegree();
}
