class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid){
        if(i>= grid.size() or j >= grid[0].size() or i<0 or j<0 or grid[i][j] == 0 or grid[i][j] ==2)return;
        grid[i][j] = 2;
        dfs(i+1,j,grid);
        dfs(i,j+1,grid);
        dfs(i-1,j,grid);
        dfs(i,j-1,grid);
    };
    
    int shortestBridge(vector<vector<int>>& grid) {
        bool canBreak = false;
        for(int i =0;i<grid.size();i++){
            for(int j =0;j<grid[i].size();j++){
                if(grid[i][j] == 1){
                    dfs(i,j,grid);
                    canBreak = true;
                    break;
                }
            }
            if(canBreak)break;
        };
        vector<pair<int,int>> v1,v2;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                if(grid[i][j] == 1)v1.push_back({i,j});
                else if(grid[i][j] == 2)v2.push_back({i,j});
            }
        }        
        int ans = INT_MAX;
      for(int i=0; i<v1.size(); i++){
            for(int j=0; j<v2.size(); j++){
                ans=min(ans, abs(v1[i].first-v2[j].first)+abs(v1[i].second-v2[j].second)-1);
            }
        }
        
        return ans;
    }
};