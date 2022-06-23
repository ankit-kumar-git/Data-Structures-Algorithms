#include <bits/stdc++.h>
using namespace std;

// Directed Ayclic Graph
void addEdge(vector<vector<int>>& adj, int u, int v)
{
    adj[u].push_back(v);
}
void displayGraph(vector<vector<int>>& adj, int v)
{
    for (int i = 0; i < v; i++)
    {
        cout<<i<<": ";
        for (auto x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

// -------------------> BFS Method <------------------------------------
// vector<int> topoSort(vector<vector<int>>& adj, int v)
// {
//     vector<int> ans;
//     vector<int> indegree(v,0);
//     for(int i=0;i<v;i++){
//         for(auto x:adj[i]){
//             indegree[x]++;
//         }
//     }

//     queue<int> q;

//     for(int i=0;i<v;i++){
//         if(indegree[i]==0){
//             q.push(i);
//         }
//     }

//     while(!q.empty()){
//         int x=q.front();
//         q.pop();
//         ans.push_back(x);
//         for(auto y:adj[x]){
//                 indegree[y]--;
//                 if(indegree[y]==0){
//                     q.push(y);
//                 }
//         }
//     }

//     return ans;
// }


//----------------------------> DFS Method <-------------------------
void DFS_Rec(vector<vector<int>>& adj,int u,stack<int>& st,vector<bool>& visited){
    visited[u]=true;
    for(auto v:adj[u]){
        if(visited[v]==false){
            DFS_Rec(adj,v,st,visited);
        }
    }

    st.push(u);
}
vector<int> topoSort(vector<vector<int>>& adj,int v){
    vector<int> ans;
    stack<int> st;

    vector<bool> visited(v+1,false);
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            DFS_Rec(adj,i,st,visited);
        }
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
    
}
int main()
{
    int v = 5;
    vector<vector<int>> adj(v);
    // addEdge(adj, 0, 2);
    // addEdge(adj, 0, 3);
    // addEdge(adj, 2, 3);
    // addEdge(adj, 1, 4);
    // addEdge(adj, 1, 3);

    addEdge(adj, 0, 1);
    addEdge(adj, 3, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 1, 3);
    // displayGraph(adj, v);
    vector<int> ans = topoSort(adj, v);
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}