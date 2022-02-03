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
bool checkCycle(int s, vector<int> adj[], int v, bool visited[])
{
    queue<pair<int, int>> q;
    visited[s] = true;
    q.push({s, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto x : adj[node])
        {
            if (visited[x] == false)
            {
                visited[x] = true;
                q.push({x, node});
            }
            else
            {
                if (parent != x)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
bool detectCycle(vector<int> adj[], int v)
{
    bool visited[v + 1];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            if (checkCycle(i, adj, v, visited))
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int v = 11;
    vector<int> adj[v];
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 11);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);
    addEdge(adj, 5, 7);
    addEdge(adj, 6, 8);
    addEdge(adj, 7, 9);
    addEdge(adj, 8, 9);
    addEdge(adj, 9, 10);
    displayGraph(adj, v);
    bool ans = detectCycle(adj, v);

    // MY CODE IS CORRECT BUT NOT RUNNING IN VS CODE BUT GOT SUBMITTED IN GFG
    cout << ans << endl;
    return 0;
}