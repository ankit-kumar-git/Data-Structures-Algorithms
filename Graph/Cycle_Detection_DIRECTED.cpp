#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>& adj, int u, int v)
{
    adj[u].push_back(v);
}
void displayGraph(vector<vector<int>>& adj, int v)
{
    for (int i = 0; i < v; i++)
    {
        cout<<i<<": ";
        for (auto x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

//--------------------------> DFS Code <-------------------------------
bool cycle(vector<vector<int>>& adj,int u,vector<bool>& visited,vector<bool>& dfs_visited)
{
    visited[u]=true;
    dfs_visited[u]=true;
    for(auto v:adj[u]){
       if(visited[v]==false){
           if(cycle(adj,v,visited,dfs_visited))
                return true;
       }
       else if(visited[v]==true && dfs_visited[v]==true){
           return true;
       }
    }
    dfs_visited[u]=false;
    return false;
}
bool detectCycle(vector<vector<int>>& adj, int v)
{
    vector<bool> visited(v+1,false);
    vector<bool> dfs_visited(v+1,false);
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            if (cycle(adj,i,visited,dfs_visited))
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int v = 8;
    vector<vector<int>> adj(v);
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 4, 3);
    addEdge(adj, 5, 0);
    addEdge(adj, 5, 6);
    addEdge(adj, 6, 7);
    addEdge(adj, 7, 5);
    // displayGraph(adj, v);
    bool ans = detectCycle(adj, v);
    cout<<ans<<endl;
    return 0;
}