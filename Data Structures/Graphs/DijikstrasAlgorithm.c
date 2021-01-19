#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define max 3001
#define INF 99999

int graph[max][max], cost[max][max], dist[max], path[max], V, E, src;
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
    int min = INF, index;
    for(int i=1;i<=V;i++) {
        if(!visited[i] && dist[i] <= min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}
void Dijiktras(int src, int V) {
    int visitedEdges = 0;
    for(int i=1;i<=V;i++) {
        dist[i] = INF;
        visited[i] =  false;
    }
    dist[src] = 0;
    /* since we dont want to visit the same node again it checks for all nodes other than the source
     So it runs for V-1 times and stops when all nodes are visited */
	while(visitedEdges < V) {
        int u = Min_Dist(V);
        visitedEdges++;
        visited[u] = true;
        for(int v=1;v<=V;v++) {
            if(!visited[v] && cost[u][v] && dist[u] + cost[u][v] < dist[v]) 
                    dist[v] = dist[u] + cost[u][v];
        }
    }
 }
 
int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        create_graph();
        scanf("%d",&src);
        Dijiktras(src,V);
        for(int i=1;i<=V;i++) {
          if(i == src) 
                continue;
          if(dist[i] < 0 || dist[i] == INF)
              printf("-1 ");
          else
              printf("%d ",dist[i]);
        }
    printf("\n");
    }
}
