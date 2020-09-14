#include "GraphsQuestions.h"



Graph::Graph(int V)
{
	this->V = V;
	Adj = new list<int>[V];
}
void Graph::AddEdges(int v, int e)
{
	//Add the edges to V's list.
	Adj[v].push_back(e);
}
void Graph::DFSUtils(int V, bool visited[])
{
	//Make the current node as visited node.
	visited[V] = true;
	cout << V << " ";

	//recur all the vertices adjacent to this vertex.

	list<int>::iterator i;

	for (i = Adj[V].begin(); i != Adj[V].end(); i++)
	{
		if (!visited[*i])
		{
			DFSUtils(V, visited);
		}

	}

}



//Function to do DFS traversal. It uses recursive DFSUtils
void Graph::DFS()
{
	//Mark all the vertices not visited.

	bool* visited = new bool[V];
	memset(visited, 0, V);

	//Call the recursive helper function to print the DFS traversal stating form  all the vertices  one by one. 
	for (int i = 0; i < V; i++)
	{
		DFSUtils(V, visited);
	}
}

void GraphsQuestions::addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void GraphsQuestions::DfsUtil(int u, vector<int> adj[], vector<bool>& visited)
{
	visited[u] = true;
	cout << u << " ";

	for (int i = 0; i < adj[u].size(); i++)
	{
		if (visited[adj[u][i]] == false)
		{
			DfsUtil(adj[u][i], adj, visited);
		}
	}
}

void GraphsQuestions::dfs(vector<int> adj[], int v)
{
	vector<bool> visited(v,false);

	for (int i = 0; i < v; i++)
	{
		if (visited[i] == false)
		{
			DfsUtil(i, adj, visited);
		}
	}

}
