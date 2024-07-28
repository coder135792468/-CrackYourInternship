
class Solution {
  public:
    vector<vector<string>> res;
       bool isPossible(string s, int start, int end) {
        while(start<end) {
            if(s[start]!=s[end]) return false;
            start++,end--;
        }
        return true;
    }
    void helper(int i,string& s,vector<string>& arr){
        if(i>=s.size()){
            res.push_back(arr);
            return;
        };
        string t;
        for(int j = i;j<s.size();j++){
            t.push_back(s[j]);
            if(isPossible(t,0, t.size()-1)){
                arr.push_back(t);
                helper(j+1,s,arr);
                arr.pop_back();
            };
        }
           
    }
    vector<vector<string>> allPalindromicPerms(string s) {
        vector<string> arr;
        helper(0,s,arr);
        return res;
    }
};