//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> vis;
    bool dfs(int node,int parent,vector<int> adj[]){
        vis[node] = 1;
        for(auto ele:adj[node]){
            if(ele == parent)continue;
            if(vis[ele] or dfs(ele,node,adj))return 1;
        }
        return 0;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vis.resize(V+1,0);
        for(int i=  0;i<V;i++){
            if(!vis[i] and dfs(i,-1,adj))return 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends