// DFS SECOND VERSION (Where Source is not given and graph might be disconnected)

#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void displayGraph(vector<int> adj[], int v)
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

void DFSRec(vector<int> adj[], int i, bool visited[])
{
    visited[i] = true;
    cout << i << " ";
    for (auto u : adj[i])
    {
        if (visited[u] == false)
        {
            DFSRec(adj, u, visited);
        }
    }
}
void printDFS(vector<int> adj[], int v)
{
    bool visited[v + 1];
    for (int i = 0; i <= v; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            DFSRec(adj, i, visited);
        }
    }
}

int main()
{
    int v = 8;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 3, 4);
    addEdge(adj, 5, 6);
    addEdge(adj, 5, 7);
    addEdge(adj, 6, 7);

    // displayGraph(adj, v);
    printDFS(adj, v);
    return 0;
}