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
	int v1, v2;
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
void bfs(int i){
	int node;
	visited[i] = true;;
	enqueue(i);
	while(!isEmpty()) {
		node = dequeue();
		printf("V%d-",node);
		for(int i=1;i<=V;i++) {
			if(adj[node][i] && !visited[i])
			{
				visited[i] = true;
				enqueue(i);
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
	for(int i=1;i<=V;i++) {
	   if(!visited[i])
		bfs(i);
	}
}
