class Solution {
public:
    vector<string> arr;
    string reverseWords(string s) {
        string ans,temp;
        stringstream take(s);
       
        while(take >> temp)arr.push_back(temp + " ");
        while(arr.size())ans+=arr.back(), arr.pop_back();
        ans.pop_back();
        return ans;
    }
};