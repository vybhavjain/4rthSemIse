#include<stdio.h>
int a,b,u,v,n,i,j,ne=1,source;
int visited[20]={0},min,mincost=0,cost[20][20];
void main()
{
 printf("Enter the number of nodes\n");
 scanf("%d",&n);
 printf("Enter the cost matrix\n");
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  {
   scanf("%d",&cost[i][j]);
   if(cost[i][j]==0)
    cost[i][j]=999;
  }
 printf("Enter the source node\n");
 scanf("%d",&source);
 visited[source]=1;
 while(ne<n)
 {
  for(i=1,min=999;i<=n;i++)
   for(j=1;j<=n;j++)
    if(cost[i][j]<min)
     if(visited[i]!=0)
     {
      min=cost[i][j];
      a=u=i;
      b=v=j;
     }
  if(visited[u]==0 || visited[v]==0)
  {
   printf("Edge %d:(%d->%d) cost:%d\n",ne++,a,b,min);
   mincost+=min;
   visited[b]=1;
  }
  cost[a][b]=cost[b][a]=999;
 }
 printf("Minimun cost=%d\n",mincost);
}
