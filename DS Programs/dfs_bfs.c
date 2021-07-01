#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
typedef struct node                      //to represent vertex and edge
{
int data;
int status;
struct node * next, *point;
} node;

typedef struct topsort                   //to represent vertices of topological sort
{
int n;
struct topsort *next;
}topsort;

int d[SIZE],f[SIZE],time;
node * q[10];               		//to maintain queue
int front=0,rear=0;       		//queue handling pointers
node * g=0;             		  //to store graph
topsort *tsort=0;        		 //to store topological sort order


void addvertex(int n)         //function to add a vertex
{
node * t=(node *)malloc(sizeof(node));
t->data=n;
t->point=0;
t->next=g;
g=t;
}


node * find(int n)            //function to find vertex node of a vertex
{
node *t=g;
while(t!=0 && t->data!=n)
t=t->next;
return t;
}

void addedge(int u,int v)  //function to add an edge
{
node *v1,*v2,*t;
v1=find(u);
v2=find(v);
t=(node *)(malloc(sizeof(node)));
t->next=v1->point;
v1->point=t;
t->point=v2;
return;
}


void printgraph()                 //function to print a graph
{
node *t1,*t2,*t3;
printf("\nVertex\tEdge List\n");
t1=g;
while(t1!=0)
{
printf("\n%d...\t",t1->data);
t2=t1->point;
while(t2!=0)
{
t3=t2->point;
printf("%d, ",t3->data);
t2=t2->next;
}
t1=t1->next;	
}
}


void topsortin(int n)                           //inserting nodes in topological order list at begining
{
topsort *z=(topsort *)malloc(sizeof(topsort));
z->n=n;
z->next=tsort;
tsort=z;
}

 
void topsortout()                     //printing topological order list
{
while(tsort!=0)
{
printf("%d, ",tsort->n);
tsort=tsort->next;
}
}


void dfs_visit(node * u)         //DFS-VISIT
{
node *t, *t1;
u->status=1;   //visit vertex
printf("%d,",u->data);
++time;
d[u->data]=time;    //store discovery time
t=u->point;
while(t!=0)
{
t1=t->point;
if(t1->status == 0)  //if not visited
dfs_visit(t1);
t=t->next;
}
++time;
f[u->data]=time;   //store finish time
topsortin(u->data);  //store the node topological sort list
return;
}


void dfs(node *g1)      //DFS search
{
node *t=g;
while(t!=0)
{
t->status=0;    //set as not visited
t=t->next;
}
t=g1;
while(t!=0)
{
if(t->status==0)   //if not visited invoke dfs_visit
dfs_visit(t);
t=t->next;
}
}


void enque(node *s)       //enqueue operation
{
int r1=rear;
r1=(r1+1) % SIZE;
if(front==r1)
{
printf("Q full");
exit(1);
}
rear=r1;
q[rear]=s;
}


int emptyq()            //emptyq - to test queue is not empty or not
{
if(front==rear)
return 1;
else
return 0;
}


node * deque()         //dequeue operation
{
if(emptyq())
{
printf("empty q");
exit(2);
}
front=(front+1)%SIZE;
return q[front];
}


void bfs(node *s)
{
node *t=g,*t1,*u;
while(t!=0)
{
t->status=0;       //set all vertices as not visited
t=t->next;
		}
s->status=1;             //visit start vertex
printf("%d,",s->data);
enque(s);
while(!emptyq())
{
u=deque();
t=u->point;
while(t!=0)
{
t1=t->point;
if(t1->status==0)
{
printf("%d, ",t1->data);
t1->status=1;
enque(t1);
}
t=t->next;
}
}
}



void main()         //main function to demonstrate graph searchs and topological sort
{
addvertex(1);
addvertex(2);
addvertex(3);
addvertex(4);
addvertex(5);
addedge(1,2);
addedge(1,4);
addedge(2,3);
addedge(2,4);
addedge(4,3);
addedge(4,5);
printf("The graph is :\n");
printgraph(g);
printf("\n DFS traverse : ");
dfs(find(1));
printf("\n BFS traverse : ");
bfs(find(1));
printf("\nTopological sort order is : ");
topsortout();
}
