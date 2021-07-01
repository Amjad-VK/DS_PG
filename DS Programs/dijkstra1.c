//Dijkstras single source shortest path algorithm
#include<stdio.h>
#define INFINITY 9999
#define SIZE 10
int main()
{
int cost[SIZE][SIZE],distance[SIZE],pred[SIZE];
int visited[SIZE],count,mindist,nextnode,i,j;
int startnode,n;
//pred[] stores the predecessor of each node
//count gives the number of nodes seen so far
printf("Enter no. of vertices:");
scanf("%d",&n);
printf("\nEnter the adjacency matrix:\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{
scanf("%d",&cost[i][j]);
if(cost[i][j]==0)
cost[i][j]=INFINITY;
}
printf("\nEnter the starting node:");
scanf("%d",&startnode);
//initialize pred[],distance[] and visited[]
for(i=1;i<=n;i++)
{
distance[i]=cost[startnode][i];
pred[i]=startnode;
visited[i]=0;
}
distance[startnode]=0;
visited[startnode]=1;
count=1;
while(count<n-1)
{
mindist=INFINITY;
//nextnode gives the node at minimum distance
for(i=1;i<=n;i++)
if(distance[i]<mindist&&!visited[i])
{
mindist=distance[i];
nextnode=i;
}
//check if a better path exists through nextnode
visited[nextnode]=1;
for(i=1;i<=n;i++)
if(!visited[i])
if(mindist+cost[nextnode][i]<distance[i])
{
distance[i]=mindist+cost[nextnode][i];
pred[i]=nextnode;
}
count++;
}
//print the path and distance of each node
for(i=1;i<=n;i++)
if(i!=startnode)
{
printf("\nDistance of node %d = %d",i,distance[i]);
printf("\nPath = %d",i);
j=i;
do
{
j=pred[j];
printf("<-%d",j);
}
while(j!=startnode);
}
}



/*Output:
Enter no. of vertices:6

Enter the adjacency matrix:
0 4 0 0 8 0
4 0 8 0 11 0
0 8 0 5 2 4
0 0 5 0 1 10
8 11 2 1 0 0
0 0 4 10 0 0

Enter the starting node:1

Distance of node 2 = 4
Path = 2<-1
Distance of node 3 = 10
Path = 3<-5<-1
Distance of node 4 = 9
Path = 4<-5<-1
Distance of node 5 = 8
Path = 5<-1
Distance of node 6 = 14
Path = 6<-3<-5<-1
*/