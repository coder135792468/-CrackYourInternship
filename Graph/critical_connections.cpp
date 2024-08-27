class Solution {
public:
    vector<vector<int>> ans;
    vector<int> rank;
    unordered_map<int,vector<int>> adj;

    int dfs(int node,int curRank){
        if(rank[node] != -2)return rank[node];

        int temp = curRank;
        rank[node] = curRank;
        for(auto nbr:adj[node]){
            if(rank[nbr] == curRank-1 or rank[nbr] == size(rank))continue;
            int newRank = dfs(nbr,curRank+1);
            temp = min(temp,newRank);
            if(newRank > curRank){
                ans.push_back({nbr,node});
            }
        }
        rank[node] = size(rank);
        return temp;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        rank.resize(n,-2);
        for(auto e:connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        };

        dfs(0,0);

        return ans;
    }
};