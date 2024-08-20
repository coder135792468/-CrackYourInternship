class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1,vector<int>(n+1,0));
        for(int i = 1;i<=k;i++){
            for(int j = 1;j<=n;j++){
                if(i == 1)dp[i][j] = j;
                else if(j == 1)dp[i][j] = 1;
                else{
                  int low = 0, high = j;
                  int res =INT_MAX;
                  while(low<=high){
                    int mid = low + (high-low)/2;
                    int drop = dp[i-1][mid-1];
                    int not_drop = dp[i][j - mid];
                    if(drop > not_drop){
                        high = mid - 1;
                    }else low = mid + 1;
                    res = min(res, 1 + max(drop,not_drop));
                  }
                  dp[i][j] = res;
                }
            }
        }
        return dp[k][n];
    }
};