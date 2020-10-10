#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define max 3005

int adj[max][max], V, E, v1, v2, w, source, stack[max],top=-1;
bool visited[max];

void push(int x){
	top++;
	stack[top]=x;
}
int pop(){
	int del=stack[top];
	top--;
	return del;
}
void addEdge(int v1,int v2) {
    adj[v1][v2] = 1;
}
void create_graph(){
    memset(adj, 0, sizeof(adj)); // sets 0  for tall the elements in the visited matrix 
	scanf("%d%d", &V,&E);
	 // int maxEdges = V*(V-1)
    for (int i=1; i<=E; i++)
	{
     	scanf("%d%d", &v1,&v2);
      	addEdge(v1,v2);
    }
}
void display_graph(){
	printf("\nAdj Matrix\n");
	for(int i=1;i<=V;i++)
	{
		printf("\n");
		for(int j=1;j<=V;j++)
			printf("%d ",adj[i][j]);
	}
}
void dfs(int v){
	push(v);
	while(top >= 0)
	{
		int node=pop();
		if(!visited[node])
		{
			printf("V%d-",node);
			visited[node] = true;
		}
		else
		     continue;	
		for(int i=V;i>=1;i--)
			if(adj[node][i] && !visited[i])
	  		   push(i);
	}
}
int main()
{
	create_graph();
	printf("\nGraph Successfully created\n");
	display_graph();
	memset(visited, false, sizeof(visited));  // sets false for tall the elements in the visited matrix 
	printf("\nDFS traversal\n");
	for(int v=1;v<=V;v++)
           if(!visited[v])
		dfs(v);
}
