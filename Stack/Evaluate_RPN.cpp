class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto num:tokens){
            if(num == "+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a + b);
            }else if(num == "-"){
               int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b-a);
            }else if(num == "*"){
               int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a * b);
            }else if(num == "/"){
               int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b/a);
            }else{
                st.push(stoi(num));
            }
        }
        return st.top();
    }
};