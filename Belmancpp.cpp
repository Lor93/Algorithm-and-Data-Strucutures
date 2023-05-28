#include<iostream>
#include<vector>
using namespace std;
void bellman(int graph[][3], int V, int E, int src);

int main()
{
	int V = 5;
	int E = 8;
	int graph[][3] = { { 0, 1, -1 }, { 0, 2, 4 },
					   { 1, 2, 3 }, { 1, 3, 2 },
					   { 1, 4, 2 }, { 3, 2, 5 },
					   { 3, 1, 1 }, { 4, 3, -3 } };
	bellman(graph, V, E, 0);
	return 0; 
}
void bellman(int graph[][3], int V, int E, int src)
{
	//Initiallize distance of all vertices as infinite. 
	int* dist = new int [V];
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	//Initialize the distance of source as 0
	dist[src] = 0;

	//Relax all edges |V|-1 times.
	for (int i = 0; i < V - 1; i++)
	{
		for (int j = 0; j < E; j++)
		{
			if (dist[graph[j][0]] != INT_MAX && dist[graph[j][0]] + graph[j][2] <
				dist[graph[j][1]])
				dist[graph[j][1]] = dist[graph[j][0]] + graph[j][2];
		}
	}
	//Check for negative weight cycle
	for (int i = 0; i < E; i++)
	{
		int x = graph[i][0];
		int y = graph[i][0];
		int weight = graph[i][2];
		if (dist[x] != INT_MAX && dist[x] + weight < dist[y])
			cout << "Graph contain negative weight cycle" << endl;
	}
	cout << "Vertex Distance from Source" << endl;
	for (int i = 0; i < V; i++)
	{
		cout << i << "\t\t" << dist[i] << endl;
	}
	delete[] dist;
}