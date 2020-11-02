#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#define INF INT_MAX
#define max 3005

int graph[max][max], cost[max], V, E, source;
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
    for (int v = 1; v<= V; v++) 
    {
           if (!visited[v] && cost[v] <= min )
           {
               min = cost[v];
               index = v;
           }
    }
return index;
}
int no_Visited_Edges = 0;
void prims(int V, int node){
    cost[source] = 0;
    visited[node] = true;
    no_Visited_Edges++;
    if (no_Visited_Edges == V)
        return;
    for (int w = 1; w <= V; w++) {
        if (graph[node][w] >= 0 && !visited[w] && (graph[node][w]) < cost[w])
            cost[w] = graph[node][w];
    }
    int source = findMinVertex(V);
    prims(V, source);
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
       cost[i]=INF;
     visited[i]= false;
    } 
    scanf("%d", &source);
    prims(V, source);
    MinCost(V);
}

/*
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#define max 3006

int graph[max][max], cost[max], V, E, v1, v2, w;
bool visited[max];

void create_graph() {
    scanf("%d%d",&V,&E);
    memset(graph,0,sizeof(graph)); //should include string library for using memset
    for(int i=1;i<=E;i++){
        scanf("%d%d%d",&v1,&v2,&w);
        graph[v1][v2] =  graph[v2][v1] = w;
    }
}
int findMinVertex(int n){
    int index, min = INT_MAX;
    for (int v = 1; v<= V; v++) {
           if (!visited[v] && cost[v]<=min ) {
            min = cost[v];
            index = v;
           }
    }
return index;
}
int prims(int source) {
    int sum = 0, visitedEdges = 0;
    cost[source] = 0;
    while(visitedEdges < V) {
        int node = findMinVertex(V);
        visitedEdges++;
        visited[node] = true;
        sum = sum + cost[node];
        for(int i=1;i<=V;i++){
            if (graph[node][i] >= 0 && !visited[i] && (graph[node][i]) <  cost[i])
               cost[i] = graph[node][i];
        }
    }
return sum;
}
int main() {
    create_graph();
     for(int i=1;i<=V;i++){
     cost[i]=INT_MAX;
     visited[i]=false;
    }   
    int source;
    scanf("%d",&source);
    int min_cost = prims(source); 
    printf("%d\n",min_cost);
}
*/
