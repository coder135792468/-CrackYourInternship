class Solution {
public:
    bool canCross(vector<int>& stones) {
        //dp[i] = (i) -> n 
        int n = stones.size();
        map<int,set<int>> mp;
        for(int i= 0;i<n;i++){
            set<int> st;
            mp[stones[i]] = st;
        };
        mp[0].insert(0);
        for(int i = 0;i<n;i++){
          int num = stones[i];
          for(auto ele:mp[stones[i]]){
            if(mp.find(num + ele - 1) != mp.end() and (ele - 1) > 0){
                mp[num + ele - 1].insert(ele - 1);
            }
            if(mp.find(num + ele) != mp.end() and ele > 0){
                mp[num + ele].insert(ele);
            }
            if(mp.find(num + ele + 1) != mp.end()){
                mp[num + ele + 1].insert(ele + 1);
            }
          }
        }
        return mp[stones[n-1]].size() > 0;
    }
};