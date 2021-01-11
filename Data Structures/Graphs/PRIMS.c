#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#define INF INT_MAX
#define max 3005

int graph[max][max], cost[max], V, E, src;
bool visited[max];
void create_graph() {
    scanf("%d%d",&V,&E);
    memset(graph,-1,sizeof(graph)); //should include string library for using memset
    int v1, v2, w;
    for(int i=1;i<=E;i++){
        scanf("%d%d%d",&v1,&v2,&w);
        graph[v1][v2] =  graph[v2][v1] = w;
    }
}

int findMinVertex(int V){
    int index, min = INF;
    for (int i = 1; i<= V; i++)  {
        if (!visited[i] && cost[i] <= min) {
               min = cost[i];
               index = i;
        }
    }
return index;
}

int visitedEdges = 0;
void prims(int V, int node){
    visited[node] = true;
    visitedEdges++;
    if (visitedEdges == V)
        return;
    for (int i = 1; i <= V; i++) {
        if (graph[node][i] >= 0 && !visited[i] && (graph[node][i]) < cost[i])
            cost[i] = graph[node][i];
    }
    int next = findMinVertex(V);
    prims(V, next);
}

void MinCost(int V){
    long int min_cost = 0;
    for (int i = 1;  i<= V; i++) {
        if (cost[i] == INF)
            cost[i] = 0;
        min_cost = min_cost + cost[i];
    }
    printf("%ld\n", min_cost);
}

int main(){
    create_graph();
    for(int i=1;i<=V;i++){
       cost[i] = INF;
       visited[i] = false;
    } 
    scanf("%d", &src);
    cost[src] = 0;
    prims(V, src);
    MinCost(V);
}

