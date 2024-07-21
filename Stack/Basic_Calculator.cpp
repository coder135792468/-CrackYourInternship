class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        char sign = '+';
        int t = 0, temp = 0;
        for(int i = 0;i<s.size();i++){
             if(isdigit(s[i])){
                temp = temp*10 + (s[i] - '0');
             }
             if(!isdigit(s[i]) and !isspace(s[i]) or (i == s.size()-1)){
                if(sign == '+'){
                    st.push(temp);
                }else if(sign == '-'){
                    st.push(-1*temp);
                }else{
                    int num;
                    if(sign == '*'){
                        num = st.top()*temp;
                    }else{
                        num = st.top()/temp;
                    };
                    st.pop();
                    st.push(num);
                }
                sign = s[i];
                temp = 0;
             }
        }
        int res = 0;
        while(!st.empty()){
            res+=st.top();
            st.pop();
        };
        return res;
    }
};