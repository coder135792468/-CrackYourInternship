class Solution {
public:
    int minDeletions(string s) {
        vector<int> cnt(26);
        for(auto ele:s){
            cnt[ele - 'a']++;
        };
        sort(cnt.rbegin(),cnt.rend());
        int res = 0;
        for(int i = 1;i<26;i++){
            if(cnt[i] == 0)break;
            res += max(0, cnt[i] - max(0, cnt[i-1] -1));
            cnt[i] = min(cnt[i], max(0, cnt[i-1] -1));
        }
        return res;
    }
};