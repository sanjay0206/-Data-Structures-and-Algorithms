#include<stdio.h>
#define max 1000
int adj[max][max],visited[max],i,j,V,E,v,v1,v2;
int que[max],front=-1,rear=-1;

void create_graph(){
	 scanf("%d%d", &V,&E);
    for (i= 1; i <= V; i++)
	        for (j = 1; j <= V; j++)
   	         adj[i][j]= 0;

 	for (i = 1; i<=E; i++)
	{
       scanf("%d%d", &v1,&v2);
       adj[v1][v2] = 1;
    }
}
void display_graph(){
	printf("\nAdj Matrix\n");
	for(i=1;i<=V;i++)
	{
		printf("\n");
		for(j=1;j<=V;j++)
			printf("%d ",adj[i][j]);
	}
}
void enqueue(int x){
	if(front==-1)
	front++;
	rear++;
	que[rear]=x;
}
int dequeue(){
	int x=que[front];
	front++;
	return x;
}
void bfs(int v){
	int node,w;
	visited[v]=1;
	enqueue(v);
	while(front<=rear)
    {
		node=dequeue();
		printf("V%d-",node);
		for(w=1;w<=V;w++)
		{
			if(adj[node][w] && !visited[w])
			{
				visited[w]=1;
				enqueue(w);
			}
		}
	}
}
int main()
{
	create_graph();
	printf("\nGraph Successfully created\n");
	display_graph();
	for(v=1;v<=V;v++)
 	   visited[v]=0;
	printf("\nBFS traversal\n");
	for(v=1;v<=V;v++)
	{
	if(!visited[v])
		bfs(v);
	}
}
