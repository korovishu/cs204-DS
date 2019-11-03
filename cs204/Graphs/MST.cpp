#include <bits/stdc++.h>
#define ll long long
#define f(i, a, b) for(ll i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;

int minKey(int key[], bool mstset[], int V)
{
	int min=INT_MAX, min_index;

	for(int v=0; v<V; v++)
	{
		if(mstset[v]==false && key[v]<min)
		{
			min=key[v];min_index=v;
		}
	}
	return min_index;
}

void printMST(int parent[], int** graph, int V)  
{  
	int (*a)[V]=(int(*)[V])graph;
    cout<<"Edge \tWeight\n";  
    for (int i = 1; i < V; i++)  
        cout<<parent[i]<<" - "<<i<<" \t"<<a[i][parent[i]]<<" \n";  
}  

void MST(int **graph, int v)
{
	int (*a)[v]=(int(*)[v])graph;
	int parent[v], key[v];
	bool mstset[v];

	for(int i=0;i<v;i++) 
	{
		mstset[i]=false; key[i]=INT_MAX;
	}
	key[0]=0;
	parent[0]=-1;

	for(int count=0; count<v-1; count++)
	{
		int u = minKey(key, mstset, v);
		mstset[u]=true;

		for(int i=0;i<v;i++)
		{
			if(a[u][i] && mstset[i]==false && a[u][i]<key[i])
			{
				parent[i]=u; key[i]=a[u][i];
			}
		}
	}
	printMST(parent, (int**)a, v);
}

int main()  
{  
	int V=5;
    int graph[V][V] = { { 0, 2, 0, 6, 0 },  
                        { 2, 0, 3, 8, 5 },  
                        { 0, 3, 0, 0, 7 },  
                        { 6, 8, 0, 0, 9 },  
                        { 0, 5, 7, 9, 0 } };  
  
    MST((int**)graph, V);  
  
    return 0;  
}  

























