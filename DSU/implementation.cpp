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

// FINDING NO OF COMPONENTS OF A GRAPH USING DSU;
int main(){
    int n,k;  //n->nodes, k->edges;
    cin>>n>>k;
    for(int i=1;i<n;i++){
        make(i);
    }
    while(k--){
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }

    int components_cnt=0;
    //Concept-> No of nodes whose parent is the node itself is no of components in graph.
    for(int i=1;i<n;i++){
        if(find(i)==i){
            components_cnt++;
        }
    }

    cout<<components_cnt<<endl;

    return 0;

}