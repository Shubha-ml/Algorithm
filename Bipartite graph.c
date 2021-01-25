/* Check Whether a graph is Bipartite or not using BFS */
/* Shubha Chakraborty */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100
int v,d[20],v1[20],v2[20],flag=0;
int queue[MAX],front=-1,rear=-1;
const int WHITE=0;
const int GRAY=1;
const int BLACK=2;
typedef struct Graph{
	int adj[20][20];
	int color[20]; 
	int dist[20]; 
	int pred[20];	
}graph; 
void insert_queue(int vertex)
{
	if(rear==MAX-1)
		printf("Queue is Overflow\n");
	else
	{
		if(front==-1) 
			front=0;
		rear=rear+1;
		queue[rear]=vertex ;
	}
}
int Empty_queue()
{
	if(front==-1||front>rear)
		return 1;
	else
		return 0;
}
int delete_queue()
{
	int delete_item;
	if(front==-1||front>rear)
	{
		printf("Queue is Underflow\n");
		exit(1);
	}
	delete_item=queue[front];
	front=front+1;
	return delete_item;
}
int BFS(graph g,int s)
{
	int u=s,i;
	for(i=0;i<v;i++)
		g.color[i]=WHITE;
	g.pred[s]=-1;
	insert_queue(s);
    g.dist[s]=0;
    printf("\nImplementing Breadth First Search Traversal :\n\n");
    while (!Empty_queue())
	{   
        u=delete_queue();
        printf("Vertex %d -> ",u); 
        for (i=0;i<v;i++) 
		{
            if ((g.adj[u][i]==1)&&(g.color[i]==WHITE)) 
			{ 
                insert_queue(i);
                g.color[i]=GRAY; 
                g.dist[i]=g.dist[u]+1;
                g.pred[i]=u;
			}   		
        }
        g.color[u] = BLACK; 
    };
    printf("\n\n");
    printf("Distance and Predecessor of vertex by the order of BFS :-");
    for (i = 0; i < v; i++) 
    {
    	printf("\nDistance is %d\tPredecessor is %d\n",g.dist[i],g.pred[i]);
    	d[i]=g.dist[i];
	}
}
bool check_bipartite(graph g,int D[])
{
	int i,j;
	for(i=0;i<v;i++)
	{
		for(j=1;j<v;j++)
			if(d[i]==d[j])
			{
				if(g.adj[i][j]==1)
					flag=1;	
			}
	}
}
int bipartite_set(int D[])
{
	int i,j=0,k=0;
	for(i=0;i<v;i++)
	{
		if(d[i]%2==0)
		{
			v1[j]=i;
			j++;
		}			
		else
		{
			v2[k]=i;
			k++;
		}	
	}
	printf("Set 1 : \n");
	for(i=0;i<j;i++)
		printf("%d ",v1[i]);
	printf("\nSet 2 : \n");	
	for(i=0;i<k;i++)
		printf("%d ",v2[i]);	
}
int main() 
{
	graph g;
	int i,s,j;
    printf("Number of Vertex :");
    scanf("%d",&v);
    printf("The Adjacency matrix of a Graph : \n");
    for(i=0;i<v;i++)
        for(j=0;j<v;j++)
        	scanf("%d",&g.adj[i][j]);
    printf("The Starting vertex :\n");
    scanf("%d",&s);
    BFS(g,s);
    check_bipartite(g,d);
    if(flag==1)
    	printf("\nIt is not Bipartite Graph");
	else
	{
		printf("\nIt is Bipartite Graph");
		printf("\nThe Bipartite Sets are : \n");
		bipartite_set(d);
	}
    getch();
    return 0;
}
