#include<stdio.h>
#define max 1000
int adj[max][max],visited[max],v,v1,v2,V,E,i,j;
void create(){
	 scanf("%d%d", &V,&E);
    for (i=1; i<=V; i++)
	        for (j=1; j<=V; j++)
   	         adj[i][j]= 0;

    for (i=1; i<=E; i++)
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

void dfs(int node)
{
	int w;
	printf("V%d-",node);
	visited[node]=1;
	for(w=1;w<=V;w++)
	{
		if(adj[node][w] && !visited[w])
		dfs(w);
	}
}
int main()
{
	create();
	printf("\nGraph Successfully created\n");
	display_graph();
	for(v=1;v<=V;v++)
		visited[i]=0;
	printf("\nDFS traversal\n");
	for(v=1;v<=V;v++)
 	 if(!visited[v])
		dfs(v);
}
