#include <bits/stdc++.h>
#define ll long long
#define f(i, a, b) for(ll i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
#define INF 99999
void AllPairShPath(int **graph, int V)
{
	int dist[V][V];
	int (*a)[V] = (int(*)[V])graph;
	f(i,0,V)
	{
		f(j,0,V)
		{
			dist[i][j]=a[i][j];
		}
	}
	f(k,0,V)
	{
		f(i,0,V)
		{
			f(j,0,V)
			{
				if(dist[i][k]+dist[k][j]<dist[i][j])
					dist[i][j]=dist[i][k]+dist[k][j];
			}
		}
	}
	f(i,0,V)
	{
		f(j,0,V)
		{
			if(dist[i][j]==INF)
				cout<<"INF"<<"		";
			else
				cout<<dist[i][j]<<"		";
		}
		cout<<endl;
	}
}

int main()
{
	int V=4;
	int graph[V][V] = { {0, 5, INF, 10},  
                        {INF, 0, 3, INF},  
                        {INF, INF, 0, 1},  
                        {INF, INF, INF, 0}  
                    };  
  
    
    AllPairShPath((int**)graph, V);  
    return 0;  
}