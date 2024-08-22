class Solution {
public:
    vector<vector<string>> res;
    bool isSafe(vector<string>& board,int i,int j){
        int n = board.size();
        for(int k = 0;k<board.size();k++){
            if(board[k][j] == 'Q')return false;
            if((i-k)>=0 and (j - k)>=0 and board[i-k][j-k] == 'Q'){
                return false;
            }
            if((i-k)>=0 and (j + k)<n and board[i-k][j+k] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void helper(vector<string>& board,int i){
        if(i == board.size()){
            res.push_back(board);
            return;
        }
        for(int j = 0;j<board.size();j++){
            if(isSafe(board,i,j)){
                board[i][j] = 'Q';
                helper(board,i+1);
                board[i][j] = '.';
            }
        }
    };
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        helper(board,0);
        return res;
    }
};