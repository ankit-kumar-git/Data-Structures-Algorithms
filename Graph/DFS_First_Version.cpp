// DFS FIRST VERSION (Where Source is given)

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

void DFSRec(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";
    for (auto u : adj[s])
    {
        if (visited[u] == false)
        {
            DFSRec(adj, u, visited);
        }
    }
}
void printDFS(vector<int> adj[], int v, int s)
{
    bool visited[v + 1];
    for (int i = 0; i <= v; i++)
    {
        visited[i] = false;
    }

    DFSRec(adj, s, visited);
}

int main()
{
    int v = 7;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);
    addEdge(adj, 5, 6);

    int s;
    cin >> s;
    // displayGraph(adj, v);
    printDFS(adj, v, s);
    return 0;
}