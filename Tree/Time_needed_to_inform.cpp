class Solution {
public:
    int res = 0;
    int dfs(int node,vector<vector<int>>& adj,vector<int>& time){
        int ans = 0;
         for(auto ele:adj[node])
            ans = max(ans,dfs(ele,adj,time));
        return ans + time[node];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n+1);
        for(int i= 0;i<n;i++){
            if(manager[i] == -1)continue;
            adj[manager[i]].push_back(i);
        };
        return  dfs(headID,adj,informTime);
    }
};