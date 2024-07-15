class Solution {
public:
    bool startingBraces(char ch){
        return ch == '(' or ch == '{' or ch == '[';
    }
    char getClosingBraces(char ch){
        if(ch == ')')return '(';
        else if(ch == '}')return '{';
        else if(ch == ']') return '[';
        return '.';
    }
    bool isValid(string s) {
        stack<char> st;
        for(auto ch:s){
            if(startingBraces(ch)){
                st.push(ch);
            }else{
                if(st.empty() or st.top() != getClosingBraces(ch)){
                    return 0;
                }else st.pop();
            }
        }
        return st.empty();
    }
};