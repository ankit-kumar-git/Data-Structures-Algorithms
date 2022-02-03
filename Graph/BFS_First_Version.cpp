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

// ---->>>>   BFS FIRST VERSION (Where Source is given)  <<<<<---------
void printBFS(vector<int> adj[], int v, int s)
{
    bool visited[v + 1];
    for (int i = 0; i <= v; i++)
    {
        visited[i] = false;
    }

    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front(); //u represent vertex and v will be here all vertices in uth vector
        q.pop();
        cout << u << " ";

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

int main()
{
    int v = 6;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 5);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 5);

    int s;
    cin >> s;
    // displayGraph(adj, v);
    printBFS(adj, v, s);
    return 0;
}