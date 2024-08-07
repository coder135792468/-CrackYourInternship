class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<pair<int,int>> cnt;
        for(auto s:strs){
            int cnt_one = 0, cnt_zero = 0;
            for(auto ch:s){
                cnt_one+= ch == '1';
                cnt_zero+= ch == '0';
            };
            cnt.push_back({cnt_one,cnt_zero});
        };
        
        vector<vector<vector<int>>> dp(len+1,vector<vector<int>>(n+1,vector<int>(m+1,0)));
        for(int i = 1;i<=len;i++){
            for(int j = 0;j<=n;j++){
                for(int k = 0;k<=m;k++){
                    int one = cnt[i-1].first;
                    int zero = cnt[i-1].second;
                    dp[i][j][k] = dp[i-1][j][k];
                    if(j>=one and k>=zero){
                        dp[i][j][k] = max(
                               dp[i][j][k], 
                               1 + dp[i-1][j-one][k-zero]
                            );
                    }
                }
            }
        }

       return dp[len][n][m];
    }
};