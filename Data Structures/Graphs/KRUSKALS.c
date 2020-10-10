#include<stdio.h>
#define INF 99999
#define max 1000
int graph[max][max],visited[max],cost[max],v,v1, v2, w,source,i, V, E, j,noEdges=0;

void create_graph(){
 	 scanf("%d%d", &V,&E);
    for (i= 1; i <= V; i++)
	    for (j = 1; j <= V; j++)
	    {
   	       graph[i][j]= 0;
	        if(graph[i][j]==0)
	       	 cost[i] = INF;
	    }
	    for (i = 1; i<=E; i++) {
	        scanf("%d%d%d", &v1,&v2,&w);
  	       graph[v1][v2] = graph[v2][v1] = w;
	    }
}
int findMinVertex(int V){
    int index, min = INF;
	for (v = 1; v<= V; v++) {
 	   if (!visited[v] && cost[v]<=min ) {
	           min = cost[v];
	        index = v;
	    }
    }
return index;
}
void kruskals(int V){
	int node = findMinVertex(V);
	visited[node] = 1;
	noEdges++;
	if (noEdges == V)
		return;
	for (w = 1; w <= V; w++){
	    if (graph[node][w] && !visited[w] && (graph[node][w]) < cost[w])
	        cost[w] = graph[node][w];
	}
	kruskals(V);
}
void MinCost(int V){
	    long int min_cost = 0;
	    for ( v = 1;  v<= V; v++) {
	        if (cost[v] == INF)
	            cost[v] = 0;
	         min_cost = min_cost+cost[v];
  	    }
	     printf("\n%ld", min_cost);
}
int main(){
	create_graph();
 	kruskals(V);
  	MinCost(V);
}
