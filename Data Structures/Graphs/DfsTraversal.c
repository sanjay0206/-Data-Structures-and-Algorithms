#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define max 3005

int adj[max][max], V, E;
bool visited[max];

void addEdge(int v1,int v2) {
    adj[v1][v2] = 1;
}
void create_graph(){
     memset(adj,0,sizeof(adj)); // // sets 0  for tall the elements in the visited matrix 
	 scanf("%d%d", &V,&E);
   // int maxEdges = V*(V-1)
	int v1, v2;
 	for (int i = 1; i <= E; i++) 
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
void dfs(int node) {
	printf("V%d-",node);
	visited[node] = true;
	for(int w=1;w<=V;w++)
	{
		if(adj[node][w] && !visited[w])
	    	    dfs(w);
	}
}
int main()
{
	create_graph();
	printf("\nGraph Successfully created\n");
	display_graph();
	memset(visited,false,sizeof(visited)); // sets false for tall the elements in the visited matrix 
	printf("\nDFS traversal\n");
	for(int v=1;v<=V;v++)
 	   if(!visited[v])
		dfs(v);
}
