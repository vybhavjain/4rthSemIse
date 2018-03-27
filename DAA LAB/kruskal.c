#include<stdio.h>
int ne=1,min_cost=0;

void main()
{ 
  int n,i,j,min,cost[20][20],a,u,b,v,parent[20];
  printf("number of vertices : \n ");
  scanf("%d",&n);
  printf("enter the cost matrix \n");
  for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
   scanf("%d",&cost[i][j]);
  for(i=1;i<=n;i++)
  parent[i]=0;
  printf("the edges of spanning tree are: \n ");
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
     printf(" \n edge %d \t %d -> %d =%d \n",ne++,a,b,min);
     min_cost+=min;
     parent[v]=u;
   }   
  printf("testing \n "); 
  cost[a][b]=cost[b][a]=111;
  }
   printf("min cost is %d \n ",min_cost);
}

