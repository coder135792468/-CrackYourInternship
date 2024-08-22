class Solution {
public:
    bool isSafe(int row,int col,char val,vector<vector<char>>& board){
        for(int i = 0;i<9;i++){
            if(board[row][i] == val or board[i][col] == val)return false;
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val)return false;
        };
        return true;
    }
    bool helper(vector<vector<char>>& board){
        for(int i= 0;i<9;i++){
            for(int j = 0;j<9;j++){
                if(board[i][j] == '.'){
                    for(int cnt = 1;cnt<=9;cnt++){
                        if(isSafe(i,j,cnt + '0',board)){
                            board[i][j] = cnt + '0';
                            if(helper(board))return true;
                            board[i][j] = '.';
                        } 
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};