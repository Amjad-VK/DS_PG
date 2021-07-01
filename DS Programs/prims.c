#include<stdio.h>
//to implement prims algorithm -MST

void main()
{
int i,j,u,v,n,ne=1;
int min,mincost=0,cost[10][10],visited[10]={0};
printf("\nEnter the number of nodes:");
scanf("%d",&n);
printf("\nEnter the cost adjacency matrix:\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{
scanf("%d",&cost[i][j]);
if(cost[i][j]==0)
cost[i][j]=999;    //if no edge its weight is infinite
}
visited[1]=1;
printf("\n");
while(ne<n)
{
min=999;
for(i=1;i<=n;i++)  //find the minimum cost edge
for(j=1;j<=n;j++)
if(cost[i][j]<min)
if(visited[i]!=0 && visited[j]==0)
{
min=cost[i][j];
u=i;
v=j;
}

printf("\nEdge %d:(%d,%d) cost:%d\n",ne++,u,v,min);
mincost+=min;
visited[v]=1;
cost[u][v]=cost[v][u]=999;

}
printf("Minimum cost = %d",mincost);
}