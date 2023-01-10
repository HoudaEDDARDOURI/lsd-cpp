#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

//we create the function that will add edges between the different vertices
void addedge(vector<int> adj[], int src, int dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src) ;
}


//function that determines the shortestb path between the source 
//and destination using breadth search algorithm
// when it finds the shortest path, it returns true else it returns false 
// the function takes as arguments : the vector of adjacency, source, destination, number of vertices, 
//the array of predeccessors and array of distances 
/*bool check(vector<int> adj, int src, int dest, int v, int pred[],int dist[])
{
    // we define a queue that will store the connected vertices to each vertex i 
    list<int> queue;
    
    bool visited[v];
    
    for(int i =0;i<v;i++)
    {
        dist[i] = 5000; //dist for the moment is unkown so we define it for all vertices as 5000;
        pred[i] = -1; // no predecessor is known 
        visited[i] = false; // all vertices are still not visited
    }
    
    visited[src] = true;
    dist[src] = 0;
    pred[src] = 0;
    queue.push_back(src);
    
    while(queue.empty() == false)
    {
        int u;
        u = queue.front();
        queue.pop_front();
        for(int i =0;i<adj[u].size();i++)
        {
            if(visited[adj[u][i]] == false)
            {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                queue.push_back(adj[u][i]);
            }
            
            if(adj[u][i] == dest)
            {
                return true;
            }
        }
    }
    
    return false;
}*/






void printshortestpath(vector<int> adj, int src, int dest, int v)
{
    int pred[v];
    int dist[v];
    vector<int> path;
    
    if(BFS(&adj,src,dest,v,pred,dist)== false){
        cout << "dest and source given are not connected!";
        return;}
    else 
    {
        
        path.push_back(dest);
        int d = pred[dest];
        while(d != -1)
        {
            path.push_back(d);
            d = pred[d];
        }
    }
    
    for(int i = path.size()-1 ; i>=0;i--)
        cout << path[i] << " ";
}


int main()
{

    int v = 8;
 
 
    vector<int> adj[v];
 
    addedge(adj, 0, 1);
    addedge(adj, 0, 3);
    addedge(adj, 1, 2);
    addedge(adj, 3, 4);
    addedge(adj, 3, 7);
    addedge(adj, 4, 5);
    addedge(adj, 4, 6);
    addedge(adj, 4, 7);
    addedge(adj, 5, 6);
    addedge(adj, 6, 7);
    int source = 0, dest = 7;
    printshortestpath(adj, source, dest, v);
    return 0;
}
