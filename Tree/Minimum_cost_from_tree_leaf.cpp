class Solution {
public: 
    map<pair<int,int>,int> mp;
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        for(int i=  0;i<n;i++){
            mp[{i,i}] = arr[i];
            for(int j = i + 1;j<n;j++){
                mp[{i,j}] = max({
                    mp[{i,j-1}],
                    arr[j]
                });
            }
        };

        vector<vector<long>> dp(n+2,vector<long>(n+2));
        for(int i = n-1;i>=0;i--){
            for(int j = 0;j<n;j++){
                if(i == j)continue;
                else{
                    long res = 1e9;
                    for(int k = i;k<j;k++){
                        res= min(
                           res,
                           mp[{i,k}]*mp[{k+1,j}] + dp[i][k] + dp[k+1][j]
                        );
                    }
                    dp[i][j] = res;
                }
            }
        }
        return dp[0][n-1];
    }
};