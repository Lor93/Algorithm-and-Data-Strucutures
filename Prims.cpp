#include<iostream>
using namespace std;

const int V=5;		//NUmber of edge in the graph		
void primMST(int graph[V][V]);
int minKey(int key[], bool mstSet[]);

int main()
{
	int graph[V][V] = { { 0, 2, 0, 6, 0 },
					   { 2, 0, 3, 8, 5 },
					   { 0, 3, 0, 0, 7 },
					   { 6, 8, 0, 0, 9 },
					   { 0, 5, 7, 9, 0 } };

	// Print the solution
	primMST(graph);
	return 0;
}
// Fucntion to find the vertex with the minimum key value
int minKey(int key[], bool mstSet[])
{
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;
	return min_index;
}
void printMST(int parent[], int graph[V][V])
{
	cout << "Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";

}
void primMST(int graph[V][V])
{
	//Array to store the contructed MST
	int parent[V];
	//Key value set of vertices include in MST
	int key[V];
	//Represent set of vetices in the MST
	bool mstSet[V];
	//Initialize all key as INFINITE	
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;
	//Setup to make the first vertex in the MST
	key[0] = 0;
	parent[0] = -1; // Making sure that the first node is always root of MST

	//The MST will always have V vertices
	for (int count = 0; count < V-1; count++)
	{
		//Picking the min key vertex from the set of vertices not yet included
		int u = minKey(key, mstSet);
		mstSet[u] = true;
		//Update the value and parent index of adjaccent
		for (int v = 0; v < V; v++)
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}
	printMST(parent, graph);
}