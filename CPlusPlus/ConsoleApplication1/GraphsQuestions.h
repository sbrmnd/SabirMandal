#pragma once
#include<iostream>
#include<list>
#include<queue>
#include<stack>

using namespace std;

class GraphsQuestions
{
public:
	void addEdge(vector<int> adj[], int u, int v);
	void DfsUtil(int u, vector<int> adj[], vector<bool>& visited);
	void dfs(vector<int> adj[], int v);
};

class Graph
{
private:
	void DFSUtils(int V, bool visited[]);
public:
	int V;
	list<int>* Adj;

	Graph(int V);
	void AddEdges(int v, int e);
	void DFS();
};

