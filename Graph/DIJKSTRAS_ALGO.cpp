// Basically we will find shortest path to all the vertex of the graph 
//from the given source vertex;
#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<pair<int,int>>>& adj, int u, int v,int w)
{
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
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
// vector<int> dijkstra(vector<vector<pair<int,int>>>& adj,int s,int n){
//     vector<int> dist(n,INT_MAX);
//     dist[s]=0;
//     vector<bool> finalised(n,false);

//     for(int i=0;i<n;i++){
//         int minidx=-1;
//         for(int j=0;j<n;j++){
//             if(!finalised[j] && (minidx==-1 || dist[j]<dist[minidx])){
//                 minidx=j;
//             }
//         }

//         finalised[minidx]=true;
//         for(auto v:adj[minidx]){
//             if(!finalised[v.first]){
//                dist[v.first]=min(dist[v.first],dist[minidx]+v.second); 
//             }
//         }
//     }

//     return dist;
// }

//USING PRIORITY QUEUE/SET;
vector<int> dijkstra(vector<vector<pair<int,int>>> &adj,int src,int n){
    vector<int> dist(n+1,INT_MAX);
    vector<bool> visited(n+1,false);
    set<pair<int,int>> s; // {wt,node}
    s.insert({0,src});
    dist[src]=0;

    while(s.size()>0){
        auto u=*s.begin();
        int v_dist=u.first;
        int v=u.second;

        s.erase(u);
        if(visited[v]) continue;
        visited[v]=true;

        for(auto x:adj[v]){
            int child_v=x.first;
            int child_wt=x.second;

            if(dist[v]+child_wt<dist[child_v]){
                dist[child_v]=dist[v]+child_wt;
                s.insert({dist[child_v],child_v});
            }
        }
    }

    return dist;
}
int main()
{
    // int n=9; //No of vertices
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    // adj, u , v , weight of edge connecting u and v
    //Here we have taken undirected weighted graph.
    // addEdge(adj, 0, 1, 4);
    // addEdge(adj, 0, 7, 8);
    // addEdge(adj, 1, 2, 8);
    // addEdge(adj, 2, 3, 7);
    // addEdge(adj, 3, 4, 9);
    // addEdge(adj, 4, 5, 10);
    // addEdge(adj, 5, 6, 2);
    // addEdge(adj, 6, 7, 1);
    // addEdge(adj, 7, 8, 7);
    // addEdge(adj, 1, 7, 11);
    // addEdge(adj, 8, 2, 2);
    // addEdge(adj, 8, 6, 6);
    // addEdge(adj, 2, 5, 4);
    // addEdge(adj, 3, 5, 14);

    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w}); //Weighted directed graph.
    }


    // displayGraph(adj, n);
    int source=1;
    vector<int> dist=dijkstra(adj,source,n);
    for(int i=1;i<=n;i++){
         cout<<i<<": "<<dist[i]<<endl;
    }
    return 0;
}
