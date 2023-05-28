#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector<int> adj[10];	//  Maintain the adjacent list
int level[10];			// To determine teh level of each node
bool visited[10];	// Mark the node if visited

void BFS(int s);
void addEdge(int v, int w);

int main()
{
	addEdge(0, 1);
	addEdge(0, 2);
	addEdge(1, 2);
	addEdge(2, 0);
	addEdge(2, 1);
	addEdge(2, 3);
		
	cout << "Following is Bredth First Traversal "
		<< "(starting from vertex 2) \n";
	BFS(2);

	return 0;
}
void BFS(int s)
{
	
	//Create a queue for BFS
	list<int> queue;
	//Marked the current node as visited and enqueue it
	visited[s] = true;
	queue.push_back(s);
	list<int>::iterator i;
	while (!queue.empty()) 
	{
		//Dequeue a vortex from the queue and print it
		s = queue.front();
		cout << s << " ";
		queue.pop_front();
		//Get all adjacent vertices of the dequeue vertex s. 
		//If a adjacent has not been visited, then mark it visited and enqueue it 
		for (int i = 0; i != adj[s].size(); i++)
		{
			if (!visited[i])
			{
				//setting the level of each node with an increment in the level of parent node
				visited[i] = true;
				queue.push_back(adj[s][i]);
				
			}
		}
	}
	
}
void addEdge(int v, int w)
{
	adj[v].push_back(w);	// Add w to v list
}