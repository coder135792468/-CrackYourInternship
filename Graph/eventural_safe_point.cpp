class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
         vector<int> res;
         int n = graph.size();
         vector<int> vis(n), out_degree(n);
         queue<int> q;
         vector<vector<int>> adj(n);

         for(int i = 0;i<n;i++){
            for(int ele:graph[i]){
                adj[ele].push_back(i);
            };
            out_degree[i] = graph[i].size();
            if(out_degree[i] == 0)q.push(i);
         };

         while(!q.empty()){
            auto node = q.front();
            q.pop();
            vis[node] = 1;
            for(auto ele:adj[node]){
                if(--out_degree[ele] == 0)q.push(ele);
            }
         };

         for(int i = 0;i<n;i++){
             if(vis[i])res.push_back(i);
         }

         return res;
    }
};