#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#define max 3006
#define INF INT_MAX

int graph[max][max], cost[max], V, E;
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
    for (int v = 1; v<= V; v++) {
        if (!visited[v] && cost[v]<=min ) {
               min = cost[v];
            index = v;
        }
    }
return index;
}
int no_Visited_Edges = 0;
void kruskals(int V){
    int node = findMinVertex(V);
    visited[node] = true;
    no_VisitedE_dges++;
    if (no_Visited_Edges== V)
        return;
    for (w = 1; w <= V; w++){
        if (graph[node][w] >= 0 && !visited[w] && (graph[node][w]) < cost[w])
            cost[w] = graph[node][w];
    }
    kruskals(V);
}
void MinCost(int V){
        long int min_cost = 0;
        for (int v = 1;  v<= V; v++) {
            if (cost[v] == INF)
                cost[v] = 0;
             min_cost = min_cost+cost[v];
          }
         printf("%ld\n", min_cost);
}
int main(){
    create_graph();
     for(int i=1;i<=V;i++){
       cost[i] = INF;
     visited[i] = false;
    } 
     kruskals(V);
      MinCost(V);
}
