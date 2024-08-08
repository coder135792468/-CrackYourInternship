class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix,int res = INT_MIN) {
        
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> directions={{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>> dp(n,vector<int>(m));
        
        std::function<int(int, int)> dfs = [&](int x,int y){
            if(dp[x][y])return dp[x][y];
            
            for(auto &dir:directions){
                int dx = x+dir[0], dy = y+dir[1];
                if(dx < 0 or dy < 0 or dx>=n or dy >= m)continue;
                if(matrix[dx][dy] <= matrix[x][y]) continue;
                dp[x][y] = max(dp[x][y],dfs(dx,dy));
            };
            return ++dp[x][y];
        };
         
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)res =max(res,dfs(i,j));
        
        return res;
    }
};