class Solution {
public:
    unordered_map<string,double> mp;
    unordered_map<string,vector<string>> adj;
    map<string,int> vis;
    void dfs(string& start,string& end,double& val,int& flag){
        vis[start] = 1;
        if(flag)return;
        for(auto child:adj[start]){
            if(!vis[child]){
                val*=mp[start + "->" + child];
                if(child == end){
                    flag = 1;
                    return;
                }
                dfs(child,end,val,flag);
                if(flag)return;
                else val/=mp[start + "->" + child];
            }
        };
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i = 0;i<size(equations);i++){
            mp[equations[i][0] + "->" + equations[i][1]] = (values[i]);
            mp[equations[i][1] + "->" + equations[i][0]] = (1/values[i]);

            adj[equations[i][0]].push_back(equations[i][1]);
            adj[equations[i][1]].push_back(equations[i][0]);
        };

        vector<double> ans;
        for(auto q:queries){
            if(!adj.count(q[0]) or !adj.count(q[1])){
                ans.push_back(-1);
                continue;
            }
            vis.clear();
            double res = 1;
            int flag = 0;
            if(q[0] == q[1])flag = 1;
            else dfs(q[0],q[1],res,flag);
            
            ans.push_back(flag?res:-1);
        }

        return ans;
    }
};