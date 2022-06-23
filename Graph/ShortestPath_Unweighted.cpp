// Basically we will find shortest path to all the vertex of the graph 
//from the given source vertex;
//Here path is number of edge we need to travel to reach a vertex from
//source.
#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>>& adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void displayGraph(vector<vector<int>>& adj, int v)
{
    for (int i = 0; i < v; i++)
    {
        for (auto x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

vector<int> getShortestPath(int s,vector<vector<int>>& adj,int v){
    vector<bool> visited(v,false);
    visited[s]=true;
    vector<int> dist(v,INT_MAX);
    dist[0]=0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto u : adj[x])
        {
            if (visited[u] == false)
            {
                dist[u] = dist[x] + 1;
                visited[u] = true;
                q.push(u);
            }
        }
    }

    return dist;
}
int main()
{
    int v; //No of vertices
    v = 4;
    vector<vector<int>> adj(v);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);

    // displayGraph(adj, v);
    int source=0;
    vector<int> ans=getShortestPath(source,adj,v);
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
