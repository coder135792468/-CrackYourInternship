class Solution {
public:
    int characterReplacement(string s, int k) {
         vector<int> cnt(26);
         int j = 0, res = 0 , mx = 0;
         for(int i = 0 ;i<s.size();i++){
             mx = max(mx,++cnt[s[i] - 'A']);
             if((i - j - mx) >= k) --cnt[s[j++] - 'A'];
             res = max(res,i - j + 1);
         }
         return res;
    }
};