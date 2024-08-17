class Solution {
public:
    string removeKdigits(string nums, int k) {
         string temp;
         for(auto ch:nums){
            while(!temp.empty() and temp.back() > ch and k){
                temp.pop_back();
                --k;
            };
            if(!temp.empty() or ch != '0')temp.push_back(ch);
         }
         while(!temp.empty() and k--)temp.pop_back();
         return temp.empty()?"0":temp;
    }
};