#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define max 3001
#define INF 99999

int graph[max][max],cost[max][max],dist[max], V, E, v1, v2, w;
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
        for(int i=1;i<=E;i++) {
            scanf("%d%d%d",&v1,&v2,&w);
            if(cost[v1][v2] == 0 || cost[v1][v2] > w)
                cost[v1][v2]=cost[v2][v1]=w;
        }
}
int Min_Dist(int V) {
    int min= INF,index;
    for(int v=1;v<=V;v++) {
        if(!visited[v] && dist[v] <= min) {
            min = dist[v];
            index = v;
        }
    }
    return index;
}
void Dijiktras(int source,int V) {
    int noVisitedNodes=  0;
    for(int i=1;i<=V;i++) {
        dist[i] = INF;
        visited[i] =  false;
    }
    dist[source] = 0;
    // since we dont want to visit the same node again 
    // it checks for all nodes other than the source
    // So it runs for V-1 times and stops when all are visited
    while(noVisitedNodes < V) 
    {
        int u = Min_Dist(V);
        noVisitedNodes++;
        visited[u] = true;
        for(int v=1;v<=V;v++)
        {
            if(!visited[v] && cost[u][v] && dist[u] + cost[u][v] < dist[v])
                    dist[v]=dist[u]+cost[u][v];
        }
    }
 }
int main() {
    int test,source;
    scanf("%d",&test);
    while(test--) {
        create_graph();
        scanf("%d",&source);
        Dijiktras(source,V);
        for(int i=1;i<=V;i++) {
          if(i == source) 
                continue;
          if(dist[i] < 0 || dist[i] == INF)
              printf("-1 ");
          else
              printf("%d ",dist[i]);
        }
     printf("\n");
    }
}

#include <stdio.h>
#define INF 99999
#define max 3001
int graph[max][max],cost[max][max],dist[max],visited[max],path[max],i,j,v1,v2,V,E,w;

void create(){
	scanf("%d%d",&V,&E);
	for(i=1;i<=V;i++)
		for(j=1;j<=V;j++)
		{
			graph[i][j]=0;
			if(graph[i][j]==0)
				cost[i][j]=INF;
			else
				cost[i][j]=graph[i][j];
		}
		for(i=1;i<=E;i++)
		{
			scanf("%d%d%d",&v1,&v2,&w);
			if(cost[v1][v2]==0 || cost[v1][v2]>w)
				cost[v1][v2]=cost[v2][v1]=w;
		}
}
int Min_Dist(int V){
	int min= INF,index,v;
	for(v=1;v<=V;v++)
	{
		if(!visited[v] && dist[v]<=min)
		{
            min=dist[v];
            index=v;
		}
	}
	return index;
}
void Dijiktras(int source,int V)
{
	int u,v,noVisitedNodes=0;
	for(i=1;i<=V;i++)
	{
		dist[i]= INF;
		visited[i]=0;
	}
	dist[source]=0;
	while(noVisitedNodes < V)
	 {
		u=Min_Dist(V);
		noVisitedNodes++;
		visited[u]=1;
		for(v=1;v<=V;v++)
		{
			if(!visited[v] && cost[u][v])
			{
				if(dist[u]+cost[u][v]<dist[v])
				{
					dist[v]=dist[u]+cost[u][v];
					path[v]=u;
				}

			}
		}
	}
	/* for(i=1;i<=V;i++)
	 {
	 	if(i==source)//since we dont want to visit the source node again
          continue;
	 printf("Source %d to Destination %d is %d\n",source,i,dist[i]);
	 }*/
 }
void display_table(int V,int source) {
	 printf("Vertex\tDistance\tShortest-Path");
  	 for(i=2;i<=V;i++)
    	if(i!=source )
	 	{
		  printf("\n%d to %d\t%d\t\t",source,i,dist[i]);
		  printf("%d ",i);
		   j=i;
		   do{
		   j=path[j];
		   printf("<-%d",j);
		   }while(j!=source);
	   }
  }

int main()
{
	int test,source;
	scanf("%d",&test);
	while(test--)
	{
		create();
		scanf("%d",&source);
		Dijiktras(source,V);
		/*for(i=1;i<=V;i++)
		{
		if(i==source)
			continue;
			if(dist[i]<0 || dist[i]== INF)
				printf("-1 ");
			else
			printf("%d ",dist[i]);
		}*/
		display_table(V,source);
	printf("\n");
	}
}
