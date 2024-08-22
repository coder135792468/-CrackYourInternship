class Solution {
public:
    long long blocks = 1, res = 0;
    void dfs(vector<vector<int>>& grid,int n,int m,int i,int j){
        if(i>=n or j>=m or i< 0 or j<0 or grid[i][j] < 0)return;
        if(grid[i][j] == 2){
            res+= blocks == 0;
            return;
        }
        grid[i][j] = -2;
        --blocks;
        dfs(grid,n,m,i+1,j);
        dfs(grid,n,m,i-1,j);
        dfs(grid,n,m,i,j+1);
        dfs(grid,n,m,i,j-1);
        ++blocks;
        grid[i][j] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size(), m =grid[0].size();
        int x = -1,y = -1;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 0)++blocks;
                else if(grid[i][j] == 1){
                    x = i,y = j;
                }
            }
        };
        dfs(grid,n,m,x,y);
        return res;       
    }
};