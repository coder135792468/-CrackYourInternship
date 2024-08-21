class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>> adj;
        for(auto ele:pairs){
            adj[ele[0]].push_back(ele[1]);
            adj[ele[1]].push_back(ele[0]);
        };
        vector<int> res;
        for(auto ele:adj){
            if(ele.second.size() ==1 ){
                res.push_back(ele.first);
                res.push_back(ele.second.front());
                break;
            }
        }
        while(res.size() <= pairs.size()){
            int key = res.back();
            int prev = res[res.size()-2];
            if(adj[key][0] != prev){
                res.push_back(adj[key][0]);
            }else{
                res.push_back(adj[key][1]);
            }
        };
        return res;
    }
};