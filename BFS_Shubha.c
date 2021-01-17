/* BFS Algorithm */
/* Shubha Chakraborty */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100
int v;
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
void BFS(graph g,int s)
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
    printf("\n");
    printf("\nDistance and Predecessor of vertex by the order of BFS : \n");
    for (i = 0; i < v; i++) 
    	printf("\nDistance is : %d\tPredecessor is : %d\n",g.dist[i],g.pred[i]);
}
int main() 
{
	graph g;
	int i,s,j;
    printf("Enter the number of Vertex :");
    	scanf("%d",&v);
    printf("Enter the Adjacency matrix : \n");
	for(i=0;i<v;i++) 
        for(j=0;j<v;j++)
        	scanf("%d",&g.adj[i][j]);
    printf("Enter the Starting vertex : ");
    scanf("%d",&s);
    BFS(g,s);
    getch();
    return 0;
}
