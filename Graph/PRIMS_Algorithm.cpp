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
int getMinCostSpanningTree(vector<vector<pair<int, int>>> &adj, int n,vector<int>& parent)
{
    vector<int> key(n, INT_MAX);
    vector<bool> mset(n, false);
    parent[0]=-1;
    key[0] = 0;
    int res = 0;
    for (int cnt = 0; cnt < n; cnt++)
    {
        int u = -1; //(Index with min value in key vector initially);
        //Finding min value in key (basically minimum weight) among those not in mset yet.
        for (int i = 0; i < n; i++)
        {
            if (mset[i] == false && (u == -1 || key[i] < key[u]))
            {
                u = i;
            }
        }

        mset[u] = true; //Moving to mset
        res += key[u]; // here u is vertex that is added and key[u] is min.
        // distance from already existing vertices in mset;

        // Now updating key vector again with min distances for adjacents of u

        for (auto i:adj[u])
        {
            if (!mset[i.first] && i.second<key[i.first])
            {
                key[i.first] = i.second;
                parent[i.first]=u;
            }
        }
    }

    return res;
}

int main()
{
    int n=4; //No of vertices
    vector<vector<pair<int,int>>> adj(n);
    // adj, u , v , weight of edge connecting u and v
    addEdge(adj, 0, 1, 5);
    addEdge(adj, 0, 2, 8);
    addEdge(adj, 1, 2, 10);
    addEdge(adj, 1, 3, 15);
    addEdge(adj, 2, 3, 20);

    // displayGraph(adj, n);
    vector<int> parent(n);//To store constructes minimum spanning tree;
    int ans=getMinCostSpanningTree(adj,n,parent);
    cout<<ans<<endl;

    cout<<"MST\n";
    for (int i = 1; i < n; i++)
        cout<<parent[i]<<" - "<<i<<"\n";

    return 0;
}
