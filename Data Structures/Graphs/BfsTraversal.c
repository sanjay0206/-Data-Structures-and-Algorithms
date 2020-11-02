#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define max 3005

int adj[max][max], V, E, que[max], front = -1, rear = -1;;
bool visited[max];

void enqueue(int x){
	if(front == -1)
	front++;
	rear++;
	que[rear] = x;
}
int dequeue(){
	int x = que[front];
	front++;
	return x;
}
bool isEmpty() {
   return (front == -1 || front > rear);
}
void addEdge(int v1,int v2) {
    adj[v1][v2] = 1;
}
void create_graph(){
      memset(adj,0, sizeof(adj)); // sets 0  for tall the elements in the visited matrix 
      scanf("%d%d", &V,&E);
   // int maxEdges = V*(V-1)
	int v1, v2, w;
 	for (int i = 1; i <= E; i++) {
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
void bfs(int v){
	int node,w;
	visited[v] = true;;
	enqueue(v);
	while(!isEmpty())
        {
		node = dequeue();
		printf("V%d-",node);
		for(w=1;w<=V;w++) {
			if(adj[node][w] && !visited[w])
			{
				visited[w] = true;
				enqueue(w);
			}
		}
	}
}
int main() {
	create_graph();
	printf("\nGraph Successfully created\n");
	display_graph();
	memset(visited, false, sizeof(visited)); // sets false for tall the elements in the visited matrix 
	printf("\nBFS traversal\n");
	for(int v=1;v<=V;v++) {
	   if(!visited[v])
		bfs(v);
	}
}
