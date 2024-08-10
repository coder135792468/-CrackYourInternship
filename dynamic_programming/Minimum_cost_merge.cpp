class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
         int n = stones.size();
         if ((n - 1) % (k - 1)) return -1;
         vector<int> pre(n + 1);
        for (int i = 0; i <  n; i++)  pre[i + 1] = pre[i] + stones[i];
        
        vector<vector<long long>> dp(n+1,vector<long long>(n+1));
         for(int m = k;m<=n;m++){
            for(int i  = 0;i+m <=n;i++){
                int j = i  + m - 1;
                dp[i][j] = INT_MAX;
                for(int mid = i;mid<j;mid+=(k-1)){
                    dp[i][j] = min(
                        dp[i][j], 
                        dp[i][mid] + dp[mid+1][j]
                    );
                }

                if((j - i)%(k-1) == 0){
                    dp[i][j] += pre[j + 1] - pre[i];
                }
            }
         }
        return dp[0][n-1];
    }
};