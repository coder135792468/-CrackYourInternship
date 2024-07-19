class Solution {
public:
    vector<string> res;
    void helper(int i,int len,int count,string& temp){
        if(i == 2*len){
            if(count == 0)res.push_back(temp);
            return;
        };

        if(count < len){
            temp.push_back('(');
            helper(i+1,len,count + 1,temp);
            temp.pop_back();
        }
        
        if(count > 0){
            temp.push_back(')');
            helper(i+1,len,count-1,temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string temp;
        helper(0,n,0,temp);
        return res;
    }
};