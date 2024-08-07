class Solution {
public:
    int numDecodings(string s) {
        int res = 1,temp = 1;
        for(int i = s.size()-1;i>=0;i--){
            if(s[i] == '0'){
               temp = res,res = 0;
               continue;
            }
            if(i+1>=s.size())continue;
            
            string str{s[i],s[i+1]};
            int num = temp;
            temp = res;
            if(str<="26")res += num;
        };
        return res;
    }
};