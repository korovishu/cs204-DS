#include <bits/stdc++.h>
#define ll long long
#define f(i, a, b) for(ll i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;

class Graph{
private:
	int N;
	list<int> *adj;
	void DFSUtil(int v, bool visited[]);
public:
	Graph(int N);
	void addEdge(int v, int w);
	void BFS(int v);
	void DFS(int v);
};

Graph::Graph(int N)
{
	this->N=N;
	adj = new list<int>[N];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[])
{
	visited[v]=true;
	cout<<v<<" ";

	for(auto it:adj[v])
	{
		if(!visited[it]) DFSUtil(it, visited);
	}
}

void Graph::DFS(int v)
{
	bool *visited = new bool[N];
	f(i,0,N) visited[i]=false;
	DFSUtil(v,visited);
}

void Graph::BFS(int v)
{
	bool *visited = new bool[N];
	f(i,0,N) visited[i]=false;

	list<int> queue;
	visited[v]=true;
	queue.push_back(v);
	while(!queue.empty())
	{
		int s=queue.front();
		cout<<s<<" ";
		queue.pop_front();
		for(auto i:adj[s])
		{
			if(!visited[i])
			{
				visited[i]=true;
				queue.push_back(i);
			}
		}
	}
}

int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "BFS: \n";
    g.BFS(2); 
  	cout<<endl;
  	cout<<"DFS: \n";
  	g.DFS(2);
  	cout<<endl;
    return 0; 
} 