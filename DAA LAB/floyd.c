#include<stdio.h>
//#include<conio.h>

int min(int,int);

void floyd(int d[50][50],int n)
{
int i,j,k;
for(k=1;k<=n;k++)
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
   d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}

int min (int a,int b)
{
if (a<b)
return a;
else
return b;
}

void main()
{
int d[50][50],i,j,n;
printf("enter the number of vertices\n");
scanf("%d",&n);
printf("enter the adjacency matrix \n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
scanf("%d",&d[i][j]);
floyd(d,n);
printf("The transitive closure is : \n");
for(i=1;i<=n;i++)
{
  for(j=1;j<=n;j++)
   printf("%d \t",d[i][j]);
   printf("\n");
}
}
