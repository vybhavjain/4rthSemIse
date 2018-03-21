#include<stdio.h>

int max (int a,int b)
{
 if (a>b)
 return a;
 else
 return b;
}

void knapsack(int m,int n,int w[],int p[])
{
int v[100][200],x[10],i,j,sum=0;
for(i=0;i<=n;i++)
v[i][0]=0;
for(j=0;j<=m;j++)
v[0][j]=0;
for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
if(j>=w[i])
v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
else
v[i][j]=v[i-1][j];
for(i=1;i<=n;i++)
x[i]=0;
i=n;
j=m;
while(i>0 && j>0)
{
if(v[i][j]!=v[i-1][j])
{
x[i]=1;
j=j-w[i];
}
i--;
}
printf("\n the optional set of items are :\n");
for(i=1;i<=n;i++)
{
if(x[i]==1)
{
printf("%d \t ",i);
sum=sum+p[i];
}
}
printf("\n total profit is %d",sum);
}

void main()
{
int w[10],p[10],m,n,j,i;
printf("enter the number of items");
scanf("%d",&n);
printf("enter the weights of the items \n ");
for(i=1;i<=n;i++)
scanf("%d",&w[i]);
printf("enter profit of items \n");
for(i=1;i<=n;i++)
scanf("%d",&p[i]);
printf("enter capacity \n");
scanf("%d",&m);
knapsack(m,n,w,p);
}
