class Solution {
public:
    //Recursive Approach
    // int helper(int n){
    //     if(n == 1 or n == 2)return n;
    //     return helper(n-1) + helper(n-2);
    // }
    
    //Memoization Approach
    // int dp[46];
    // int helper(int n){
    //     if(n == 1 or n == 2)return n;
    //      if(dp[n] != -1)return dp[n];
    //     return dp[n] = helper(n-1) + helper(n-2);
    // }
    
    //Tabulation Approach
    // int helper(int n){
    //     vector<int> dp(46,0);
    //     dp[0] = 0;
    //     dp[1] = 1;
    //     dp[2] = 2;
    //     for(int i = 3;i<=45;i++){
    //         dp[i] = dp[i-1] + dp[i-2];
    //     };
    //     return dp[n];
    // }
    
    //Tablution + space Optimisation 
    int helper(int n){
        if(n <= 2)return n;
        int prev  = 1;
        int curr = 2;
        for(int i = 3;i<=n;i++){
            int res = curr+prev;
            prev = curr;
            curr = res;
        }
        return curr;
    }
    int climbStairs(int n) {
        
        //Recursive Approach
        // return helper(n);
        
        //Memoization Approach
        // memset(dp,-1,sizeof(dp));
        // return helper(n);
        
        //Tabulation Approach
        // return helper(n);
        
        //Tabulaiton + Space Optimisation 
        return helper(n);
    }
};