#include<stdio.h>

void warshall(int r[10][10],int n)
{
	int i,j,k;
	for(k=0;k<n;k++)
	 for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	   r[i][j]=(r[i][j]|r[i][k]&r[k][j]);
}

int main()
{
	int r[10][10],i,j,n;
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	
	printf("Enter adjacency matrix \n");
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	scanf("%d",&r[i][j]);
	warshall(r,n);
	printf("Transitive closure is:\n");
	for(i=0;i<n;i++)
	{
	  for(j=0;j<n;j++)
		  printf("%d \t",r[i][j]);
	  printf("\n");
	}
	return 0;
}
