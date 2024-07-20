class Solution {
public:
    bool helper(vector<vector<char>>& grid,int i,int j,string& word,int cnt = 0){
        if(cnt == word.size())return 1;
        if(i>=grid.size() or j >= grid[0].size() or i< 0 or j < 0)return false;
        if(word[cnt] != grid[i][j])return false;
        char ch = grid[i][j];
        grid[i][j] = '.';
            if(helper(grid,i+1,j,word,cnt + 1))return 1;
            if(helper(grid,i-1,j,word,cnt + 1))return 1;
            if(helper(grid,i,j+1,word,cnt + 1))return 1;
            if(helper(grid,i,j-1,word,cnt + 1))return 1;
        grid[i][j] = ch;
        return 0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j] == word[0]){
                    if(helper(board,i,j,word))return 1;
                }
            }
        }
        return 0;
    }
};