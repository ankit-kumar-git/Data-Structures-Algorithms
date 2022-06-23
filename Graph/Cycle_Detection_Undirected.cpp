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
// ------------------------------> BFS Approach <-------------------------

// bool checkCycle(int s, vector<vector<int>>& adj, int v, bool visited[])
// {
//     queue<pair<int, int>> q;
//     visited[s] = true;
//     q.push({s, -1});
//     while (!q.empty())
//     {
//         int node = q.front().first;
//         int parent = q.front().second;
//         q.pop();
//         for (auto x : adj[node])
//         {
//             if (visited[x] == false)
//             {
//                 visited[x] = true;
//                 q.push({x, node});
//             }
//             else
//             {
//                 if (parent != x)
//                 {
//                     return true;
//                 }
//             }
//         }
//     }
//     return false;
// }
// bool detectCycle(vector<vector<int>>& adj, int v)
// {
//     bool visited[v + 1];
//     for (int i = 0; i < v; i++)
//     {
//         visited[i] = false;
//     }
//     for (int i = 0; i < v; i++)
//     {
//         if (visited[i] == false)
//         {
//             if (checkCycle(i, adj, v, visited))
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }


// ---------------------> DFS Approach <-------------------------------
bool checkCycle(int parent,int s,vector<vector<int>>& adj, int v,vector<bool>& visited)
{
    visited[s]=true;
    for(auto x:adj[s]){
        if(visited[x]==true && x!=parent){
            return true;
        }
        else if(visited[x]==false){
            checkCycle(s,x,adj,v,visited);
        }
    }
    return false;
}
bool detectCycle(vector<vector<int>>& adj, int v)
{
    vector<bool> visited(v+1,false);
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            //-1 is parent for starting vertex;
            if (checkCycle(-1,i, adj, v, visited))
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
      int v = 6;
    vector<vector<int>> adj(v);
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 4, 5);
    // displayGraph(adj, v);
    bool ans = detectCycle(adj, v);
    cout<<ans<<endl;
    return 0;
}