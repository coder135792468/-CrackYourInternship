class Solution {
public:
    string decodeString(string s) {
        string ans;
        stack<string> st;
        for(int i = 0;i<s.size();i++){
            if(s[i] == ']'){
                string temp;
                while(st.top()!="["){
                    temp= st.top() + temp;
                    st.pop();
                };
                st.pop();
                int len = 0;
                int i = 1;
                while(!st.empty() and isdigit(st.top()[0])){
                    len += i*(st.top()[0]-'0');
                    i*=10;
                    st.pop();
                };
                string res;
                while(len--){
                    res+=temp;
                };
                st.push(res);
            }else st.push(string(1,s[i]));     
        }
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};