#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int parent[N];
int size[N];
void make(int v){
    parent[v]=v;
    size[v]=1;
}

int find(int v){
    if(parent[v]==v) return v;
    //PATH COMPRESSION
    return parent[v]=find(parent[v]);
}
//UNION BY SIZE where if we always want to join small tree below bigger tree.
// I will always make a as bigger tree and put b below a;
void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(size[a]<size[b])
            swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
    }
}
void displayGraph(vector<vector<pair<int,int>>>& mst, int n)
{
    for (int i = 1; i < n; i++)
    {
        cout<<i<<": ";
        for (auto x : mst[i])
        {
            cout <<"{"<< x.first << "," << x.second<<"}"<<" ";
        }
        cout << endl;
    }
}


int main(){
    int n,m;//n->nodes, m->edges
    cin>>n>>m;
    vector<pair<int,pair<int,int>>> edges; // {weight,{node,node}}
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w; 
        edges.push_back({w,{a,b}});
    }

    sort(edges.begin(),edges.end());
    for(int i=1;i<=n;i++){
        make(i);
    }
    int total_cost=0;
    vector<vector<pair<int,int>>> mst(n+1); //{node,weight}

    for(auto x:edges){
        int wt=x.first;
        int u=x.second.first;
        int v=x.second.second;

        if(find(u)==find(v)){
            continue; //Forms cycle as it belongs to same component.
        }
        Union(u,v);
        total_cost+=wt;
        mst[u].push_back({v,wt});

    }

    cout<<total_cost<<endl;
    displayGraph(mst,n+1);
    return 0;

}