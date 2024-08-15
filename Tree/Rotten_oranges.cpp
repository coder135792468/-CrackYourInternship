//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
      class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int dfs(vector<vector<int>>& grid, int i, int j, int depth) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0) {
            return INT_MAX; // Can't rot this way
        }
        if (grid[i][j] == 2) {
            return depth; // Found rotten orange
        }
    
        grid[i][j] = 0; // Mark as visited
        int minDepth = INT_MAX;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto dir : directions) {
            int ni = i + dir.first;
            int nj = j + dir.second;
            minDepth = min(minDepth, dfs(grid, ni, nj, depth + 1));
        } 
    
        grid[i][j] = 1; // Unmark the cell for other dfs calls
        return minDepth;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxTime = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    int timeToRot = dfs(grid, i, j, 0);
                    if (timeToRot == INT_MAX) {
                        return -1;
                    }
                    maxTime = max(maxTime, timeToRot);
                }
            }
        }
        return maxTime;
    }
};   

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends