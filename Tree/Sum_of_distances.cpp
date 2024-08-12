class Solution {
public:
    vector<int> dis,cnt;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        dis.resize(n,0);
        cnt.resize(n,1);
        vector<vector<int>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        };
        auto dfs =  [&](int node,int parent,auto&& self) ->void{
            for(auto ele:adj[node]){
                if(ele == parent)continue;
                self(ele,node,self);
                cnt[node]+=cnt[ele];
                dis[node] += dis[ele] + cnt[ele];
            }
        };

        auto dfs2 = [&](int node,int parent, auto&& self) -> void{
            for(auto ele:adj[node]){
                if(ele == parent)continue;
                dis[ele] = dis[node] - cnt[ele] + (n - cnt[ele]);
                self(ele,node,self);
            }
        };
        dfs(0,-1,dfs);
        dfs2(0,-1,dfs2);
        return dis;
    }
};