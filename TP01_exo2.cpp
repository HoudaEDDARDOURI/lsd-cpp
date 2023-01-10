#include <iostream>
#include <vector>

using namespace std;


void DFS(int i, bool visited[],vector<int> adj[])
{
	
	visited[i] = true;

	for (int j = 0; i < adj[i].size(); i++)
		if (!visited[adj[i][j]])
			DFS(adj[i][j], visited,adj);
}

int nbcomponents(int v, vector<int> adj[])
{
	
	bool visited [v];
	
	int count = 0;
	
	for (int i = 0; i < v; i++)
		visited[v] = false;
	
	for (int i = 0; i < v; i++) 
	{	
		//if we find a not visited node we do the apply the DFS
		if (visited[i] == false) 
		{
			DFS(i, visited,adj);
			//once the DFS is done, it means that all the nodes that can be reached form the node v are marked as visited, and we just complete one new component. 
			count += 1;
		}
	}

	return count;
}



int main()
{
	int v = 3;
	
	vector<int> adj[v];
	for(int i=0;i<v;i++)
	{
		for (int j=0;j<v;j++)
		{
			int a;
			cin>>a;
			if (a == 1)
				adj[i].push_back(a);
		}
	}

	cout<<"number of connected components is ;"<<nbcomponents(v,adj)<<endl;
	return 0;
}
