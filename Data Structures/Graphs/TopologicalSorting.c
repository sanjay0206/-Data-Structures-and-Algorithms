/* step 1 : Calculate the indegree of all vertices and select the vertex with no indegree and insert in a queue
   step 2 : Then we have to remove the edges which are connected to that node so dequeue the first element
   step 3: Check whether the node has an edge if so then remove the adge and reduce the indegree
*/


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define max 3005

int adj[max][max], i, j, v1, v2, w, V, E, q[max], front = -1, rear = -1;

void addEdge(int v1,int v2) {
    adj[v1][v2] = 1;
}

void create_graph(){
	 scanf("%d%d", &V,&E);
	 memset(adj,0,sizeof(adj));  //no edges in graph initially
      for (i = 1; i<=E; i++) {
	        scanf("%d%d", &v1,&v2); //get the vertices for which edges should be connected
  	        addEdge(v1,v2); //add an edge an edge
	    }
}
void display(){
	printf("\nAdj Matrix\n");
	for(i=1;i<=V;i++) {
		printf("\n");
		for(j=1;j<=V;j++)
			printf("%d ",adj[i][j]);
	}
}
int indegree(int node){//if the node has an edge the count how many it has
	int i,c = 0;
	for(i=1;i<=V;i++)
		if(adj[i][node])
			c++;
	return c;
}
void enqueue(int x){
	if(front == -1)
		front++;
	rear++;
	q[rear] = x;
}
int dequeue(){
	int deq = q[front];
	front++;
	return deq;
}
void Toppological_sort(){
	 int j=1; //j=1 since we are starting from index 1 in our graph
	int T[max], indeg[max];
	for(i=1;i<=V;i++)
	{
		indeg[i] = indegree(i); // put all the indegrees in an indegree[]
		printf("\n Indegree[v%d]=%d\n",i,indeg[i]);
		if(!indeg[i]) //if there is no indegree insert it into the queue since we want to delete that node first
			enqueue(i);
	}
	while(front <= rear)
	{
		int node = dequeue();
		T[j++] = node;
		printf("Ts %d \n",T[j-1]);
		for(w=1;w<=V;w++)
		{
			if(adj[node][w])//if the node wich is in  queue has an edge then remove the edge and reduce indegree
			{
				adj[node][w] = 0;
				indeg[w]--;
				if(!indeg[w])
					enqueue(w);
			}
		}
	}
        printf("Nodes after TS\n ");
	for(i=1;i<=V;i++)
		printf("V%d\t",T[i]);
}
int main()
{
	create_graph();
	printf("\nGraph Successfully created\n");
	display();
	Toppological_sort();
}
