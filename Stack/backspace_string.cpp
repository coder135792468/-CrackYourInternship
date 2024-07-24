class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string str1,str2;
        for(int i = 0;i<s.size();i++){
            if(s[i] =='#'){
                if(str1.size()>0)str1.pop_back();
            }else str1.push_back(s[i]);
        }
        for(int i = 0;i<t.size();i++){
            if(t[i] =='#'){
                if(str2.size()>0)str2.pop_back();
            }else str2.push_back(t[i]);
        }
        cout<<str1<<endl;
        return str1 == str2;
    }
};