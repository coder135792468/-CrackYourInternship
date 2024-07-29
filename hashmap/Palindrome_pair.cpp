class Solution {
public:
    bool isPalindrome(string str){
        int start  = 0,end = str.size()-1;
        while(start < end){
            if(str[start++] != str[end--])return 0;
        }
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> mp;
        vector<vector<int>> ans;
        int n = words.size();
        for(int i =0;i<n;i++){
            string temp = words[i];
            reverse(temp.begin(),temp.end());
            mp[temp] = i;
        };
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<words[i].size();j++){
                string left = words[i].substr(0,j);
                string right = words[i].substr(j);
                if(mp.count(left) and mp[left]!=i and isPalindrome(right)){
                    ans.push_back({i,mp[left]});
                    if(left.empty()){
                        ans.push_back({mp[left],i});
                    };
                };
                if(mp.count(right) and mp[right] != i and isPalindrome(left)){
                    ans.push_back({mp[right],i});
                }
            }
        }
        
        return ans;
    }
};