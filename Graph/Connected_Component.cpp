#include <bits/stdc++.h>
using namespace std;

// THIS QUESTION IS ALSO ASKED AS COUNT ISLANDS INSIDE THE GRAPH IN INTERVIEWS.

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

void BFS(vector<int> adj[], int i, bool visited[])
{
    queue<int> q;
    visited[i] = true;
    q.push(i);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        // cout << u << " ";

        for (auto v : adj[u])
        {
            if (visited[v] == false)
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
int BFSDis(vector<int> adj[], int v)
{
    bool visited[v + 1];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    int count = 0;
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            BFS(adj, i, visited);
            count++;
        }
    }
    return count;
}

int main()
{
    int v = 9;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 3, 4);
    addEdge(adj, 5, 6);
    addEdge(adj, 5, 7);
    addEdge(adj, 7, 8);

    // displayGraph(adj, v);
    int ans = BFSDis(adj, v);
    cout << ans << endl;
    return 0;
}