#include<stdio.h>
int ne=1,min_cost=0;

void main()
{ 
  int n,i,j,min,cost[20][20],a,u,b,v,parent[20];
  printf("Number of vertices : \n ");
  scanf("%d",&n);
  printf("Enter the cost matrix \n");
  for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
   scanf("%d",&cost[i][j]);
  for(i=1;i<=n;i++)
  parent[i]=0;
  printf("The edges of spanning tree are: \n ");
  while(ne<n)
  { 
    min=111;
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
      {
       if(cost[i][j]<min)
        {
	   min=cost[i][j];
	   a=u=i;
	   b=v=j;
	}
      }
  while(parent[u])
  u=parent[u];
  while(parent[v])
  v=parent[v]; 
  if(u!=v)
   { 
     printf(" \n Edge %d \t %d -> %d =%d \n",ne++,a,b,min);
     min_cost+=min;
     parent[v]=u;
   }   
  printf("Testing \n "); 
  cost[a][b]=cost[b][a]=111;
  }
   printf("Min cost is %d \n ",min_cost);
}
