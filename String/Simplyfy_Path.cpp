class Solution {
public:
    string simplifyPath(string path,string ans = "",vector<string> st = {}) {
        for(int  i= 0;i<size(path);i++){
            if(path[i] == '/')continue;
            string temp;
            while(i<size(path) and path[i] != '/')temp.push_back(path[i++]);
            if(temp == ".")continue;
            else if(temp == ".."){
                if(!st.empty())st.pop_back();
            }else st.push_back("/" + temp);
        };
        for(auto ele:st) ans+=ele;
        return ans.empty() ? "/":ans;
    }
};