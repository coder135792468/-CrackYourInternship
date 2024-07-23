class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        unordered_map<int,int> mp;
        for(auto ele:arr)mp[ele]++;
        for(auto ele:arr){
            mp[ele]--;
            if(mp[ele - x] or mp[ele + x])return 1;
            mp[ele]++;
        };
        
        return -1;
    }
};