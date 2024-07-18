class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& candidates, int target,vector<int>& temp,int idx){
        if(target == 0){
            ans.push_back(temp);
            return;
        };
        if(target < 0)return;
        for(int i = idx;i<candidates.size();i++){
            if(i>idx and candidates[i] == candidates[i-1])continue;
            temp.push_back(candidates[i]);
            helper(candidates,target-candidates[i],temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        helper(candidates,target,temp,0);
        return ans;
    }
};