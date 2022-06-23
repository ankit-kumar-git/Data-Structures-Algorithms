// Basically we will find shortest path to all the vertex of the graph 
//from the given source vertex;
#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<pair<int,int>>>& adj, int u, int v,int w)
{
    adj[u].push_back({v,w});
}
void displayGraph(vector<vector<pair<int,int>>>& adj, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (auto x : adj[i])
        {
            cout <<"{"<< x.first << "," << x.second<<"}"<<" ";
        }
        cout << endl;
    }
}
vector<int> getTopoSort(vector<vector<pair<int, int>>> &adj, int n)
{
    vector<int> ans;
    vector<int> outdegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto v : adj[i])
        {
            outdegree[v.first]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (outdegree[i] == 0)
        {
            q.push(i);
            ans.push_back(i);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            outdegree[v.first]--;
            if (outdegree[v.first] == 0)
            {
                q.push(v.first);
                ans.push_back(v.first);
            }
        }
    }
    return ans;
}

//--------------------TOPOLOGICAL SORT ALGO. <-----------------------------
vector<int> getShortestPath(int s,vector<vector<pair<int,int>>>& adj,int n){
    vector<int> dist(n,INT_MAX);
    dist[0]=0;
    vector<int> topoSorted=getTopoSort(adj,n);
    for(int i=0;i<n;i++){
        for(auto v:adj[i]){
            if(dist[v.first]> (dist[i]+v.second)){
                dist[v.first]=dist[i]+v.second;
            }
        }
    }
    return dist;
}
int main()
{
    int n=6; //No of vertices
    vector<vector<pair<int,int>>> adj(n);
    // adj, u , v , weight of edge connecting u and v
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 4, 1);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 2, 3, 6);
    addEdge(adj, 4, 2, 2);
    addEdge(adj, 4, 5, 4);
    addEdge(adj, 5, 3, 1);

    // displayGraph(adj, n);
    int source=0;
    vector<int> ans=getShortestPath(source,adj,n);
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
