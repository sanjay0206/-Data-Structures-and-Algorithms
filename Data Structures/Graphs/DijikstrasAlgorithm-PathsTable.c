#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define max 3001
#define INF 99999

int graph[max][max], cost[max][max], dist[max], path[max], V, E, source;
bool visited[max];

void create_graph() {
    scanf("%d%d",&V,&E);
    memset(graph,0,sizeof(graph));
    for(int i=1;i<=V;i++) {
        for(int j=1;j<=V;j++) {
                if(graph[i][j] == 0)
                     cost[i][j] = INF;
        }
    }
	int v1, v2, w;
        for(int i=1;i<=E;i++)
        {
            scanf("%d%d%d",&v1,&v2,&w);
            if(cost[v1][v2] == 0 || cost[v1][v2] > w)
                cost[v1][v2] = cost[v2][v1] = w;
        }
}

int Min_Dist(int V) {
    int min = INF,index;
    for(int v=1;v<=V;v++) {
        if(!visited[v] && dist[v] <= min) {
            min = dist[v];
            index = v;
        }
    }
    return index;
}

void Dijiktras(int source,int V) {
    int no_Visited_Nodes = 0;
    for(int i=1;i<=V;i++) {
        dist[i] = INF;
        visited[i] =  false;
    }
    dist[source] = 0;
    // since we dont want to visit the same node again 
    // it checks for all nodes other than the source
    // So it runs for V-1 times and stops when all are visited
    while(no_Visited_Nodes < V) 
    {
        int u = Min_Dist(V);
        no_Visited_Nodes++;
        visited[u] = true;
        for(int v=1;v<=V;v++)
        {
            if(!visited[v] && cost[u][v] && dist[u] + cost[u][v] < dist[v]) {
                    dist[v] = dist[u] + cost[u][v];
                    path[v] = u; // To store the path not needed  while finding distance covered alone.
            }
        }
    }
}

void display_table(int V,int source) {
	 printf("Vertex\tDistance\tShortest-Path");
  	 for(int i=2;i<=V;i++)
  	 {
    	    if(i != source)
	    {
		  printf("\n%d to %d\t%d\t\t",source,i,dist[i]);
		  printf("%d ",i);
		  int j = i;
		   do {
		       j = path[j];
		       printf("<-%d",j);
		   } while(j != source);
	    }
  	 }
}

int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        create_graph();
        scanf("%d",&source);
        Dijiktras(source,V);
        display_table(V,source);
    }
}
