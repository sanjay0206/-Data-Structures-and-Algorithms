#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define max 3001
#define INF 99999

int graph[max][max], dist[max][max], i, j, k, V, E, w, v1, v2;
bool visited[max];

void create() {
 	scanf("%d%d",&V,&E);
 	memset(graph,0,sizeof(graph));
	for(i=1;i<=V;i++) {
            for(j=1;j<=V;j++) {
                if(graph[i][j] == 0)
                     dist[i][j] = INF;
        }
    }
    for (i=1; i<=E; i++) { 
        scanf("%d%d%d", &v1,&v2,&w);
  	    dist[v1][v2] =  w;
    }
}
int min(int a,int b) {
	return (a < b) ? a : b;
}
void floyds(int V) {
 for(k=1;k<=V;k++)
	for(i=1;i<=V;i++)
  		for(j=1;j<=V;j++)
 		    if(i == j)      //all the diagonal elements will be 0 since there is no loop
    			dist[i][j] = 0;
    		else
    			 dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
void TransitiveClosure() {
    printf("\n Transitive closure:\n");
	for(i=1;i<=V;i++) {
 	    for(j=1;j<=V;j++) {
		printf("%d\t",dist[i][j]);
 		}
	 	printf("\n");
	}
}
void shortestPaths() {
    printf("\n The shortest paths are:\n");
	for(i=1;i<=V;i++) {
 	    for(j=1;j<=V;j++) {
	        if(i != j)//since there is no loop
		       printf("\n <%d,%d> = %d",i,j,dist[i][j]);
		}
	}
}
int main() {
 	create();
	floyds(V);
 	TransitiveClosure();
 	shortestPaths();
}
