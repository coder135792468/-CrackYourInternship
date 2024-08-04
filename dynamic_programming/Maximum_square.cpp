class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                if(i == n-1 or j == m-1){
                    dp[i][j] = matrix[i][j] - '0';
                }else{
                    if(matrix[i][j] == '0')dp[i][j] = 0;
                    else dp[i][j] = 1 + min({
                            dp[i+1][j], dp[i][j+1], dp[i+1][j+1]
                        });  
                }
            }
        }
        int res = INT_MIN;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                res = max(res,dp[i][j]);
            }
        }

        return res*res;
    }
};