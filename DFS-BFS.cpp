#include<iostream>
#include<vector>
using namespace std;

vector <int> adj[10];
bool visited[10];
void DFS_Util(int s);
void addEdge(int x, int y);
void DFS();

int main()
{
	addEdge(0, 1);
	addEdge(0, 9);
	addEdge(1, 2);
	addEdge(2, 0);
	addEdge(2, 3);
	addEdge(9, 3);
	cout << "Following is Depth First Traversal (where the vertex is at 0) \n";
	DFS_Util(0);
	return 0;
}

void DFS_Util(int s)
{
	visited[s] = true;
	cout << s << " ";
	for (int i = 0; i < adj[s].size(); i++) {
		if (visited[adj[s][i]] == false)
			DFS_Util(adj[s][i]);
	}
}
void DFS()
{
	for (int i = 0; i < 10; i++)
		visited[i] = false;
}
void addEdge(int x, int y)
{
	adj[x].push_back(y);
	adj[y].push_back(x);
}