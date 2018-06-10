#include<stdio.h>

void main()
{ 
  int n,i,j,min,ne=1,min_cost=0,cost[n][n],a,u,b,v,source,visited[20];
  printf("number of vertices : \n ");
  scanf("%d",&n);
  printf("enter the cost matrix \n");
  for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
   scanf("%d",&cost[i][j]);
  for(i=1;i<=n;i++)
  visited[i]=0;
  printf("enter source \n ");
  scanf("%d",&source);
  visited[source]=1;
  while(ne<n)
  { 
    min=111;
    for(i=1;i<=n;i++)
     for(j=1;j<=n;j++)
     {
       if(cost[i][j]<min)
         if(visited[i]==0)
 	 continue;
	 else
	 {
	   min=cost[i][j];
	   a=u=i;
	   b=v=j;
	 }
     }
   if(visited[u]==0||visited[v]==0)
   { 
     printf(" \n edge %d \t %d -> %d =%d \n",ne++,a,b,min);
     min_cost+=min;
     visited[b]=1;
   }   
   cost[a][b]=cost[b][a]=999;
  }
   printf("min cost is %d \n ",min_cost);
}

