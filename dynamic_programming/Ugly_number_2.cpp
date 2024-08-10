class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<=1)return 1;
        vector<int> dp(n+1);
        dp[0] = 1;
        int l1 = 0, l2 = 0, l3 = 0;
        for(int i= 1;i<=n;i++){
            dp[i] = min({
                2*dp[l1], 3*dp[l2], 5*dp[l3]
            });
            if(dp[i] == 2*dp[l1])++l1;
            if(dp[i] == 3*dp[l2])++l2;
            if(dp[i] == 5*dp[l3])++l3;
        }
        return dp[n-1];
    }
};