class Solution {
public:
    int dp[20];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    int numTrees(int n) {
        if(n<=0)return 1;
        if(dp[n] != -1)return dp[n];
        int res = 0;
        for(int i = 0;i<n;i++){
            res+= numTrees(i)*numTrees(n-i-1);
        }
        return dp[n] = res;
    }
};