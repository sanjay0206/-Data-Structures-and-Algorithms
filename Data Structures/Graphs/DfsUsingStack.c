#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define max 3005

int adj[max][max], V, E, stack[max], top = -1;
bool visited[max];

void push(int x) {
	top++;
	stack[top] = x;
}

int pop() {
	int pop_ele = stack[top];
	top--;
	return pop_ele;
}

void addEdge(int v1,int v2) {
    adj[v1][v2] = 1;
}

void create_graph() {
    memset(adj, 0, sizeof(adj)); // sets 0  for all the elements in the visited matrix 
    scanf("%d%d", &V,&E); 
   // int maxEdges = V*(V-1)
    int v1, v2;
    for (int i=1; i<=E; i++) {
     	scanf("%d%d", &v1,&v2);
      	addEdge(v1,v2);
    }
}

void display_graph() {
	printf("\nAdj Matrix\n");
	for(int i=1;i<=V;i++)
	{
		printf("\n");
		for(int j=1;j<=V;j++)
			printf("%d ",adj[i][j]);
	}
}
void dfs(int node) {
	push(node);
	while(top >= 0)
	{
	   node = pop();
	   if(!visited[node]) {
	      printf("V%d-",node);
	      visited[node] = true;
	   }
	   else
	      continue;	
	   for(int i=V;i>=1;i--)
		if(adj[node][i] && !visited[i])
	  	     push(i);
	}
}

int main() {
	create_graph();
	printf("\nGraph Successfully created\n");
	display_graph();
	memset(visited, false, sizeof(visited));  // sets false for all the elements in the visited matrix 
	printf("\nDFS traversal\n");
	for(int i=1;i<=V;i++)
           if(!visited[i])
		dfs(i);
}
