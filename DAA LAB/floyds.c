#include<stdio.h>

int min (int a,int b)
{
 if (a<b)
 return a;
 else
 return b;
}

void floyd(int d[50][50],int n)
{
int i,j,k;
for(k=0;k<n;k++)
 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
   d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}

int main()
{
 int d[50][50],i,j,n;
 printf("Enter the number of vertices:\n");
 scanf("%d",&n);
 printf("Enter the cost adjacency matrix:\n");
 for(i=0;i<n;i++)
 for(j=0;j<n;j++)
 scanf("%d",&d[i][j]);
 floyd(d,n);
 printf("The minimum distance matrix is:\n");
 for(i=0;i<n;i++)
	{
  		for(j=0;j<n;j++)
   			printf("%d \t",d[i][j]);
		printf("\n");
	}
	return 0;
}
