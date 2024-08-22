class Solution {
public:
    int getLiveNeighbours(vector<vector<int>>& curr, int i, int j, int m, int n) {
	int liveNeighbours = 0;
	if(i>0) if(curr[i-1][j] == 1) liveNeighbours++;
	if(i<m-1) if(curr[i+1][j] == 1) liveNeighbours++;
	if(j>0)  if(curr[i][j-1] == 1) liveNeighbours++;
	if(j<n-1)  if(curr[i][j+1] == 1) liveNeighbours++;
	if(i>0 && j>0)  if(curr[i-1][j-1] == 1) liveNeighbours++;
	if(i>0 && j<n-1)  if(curr[i-1][j+1] == 1) liveNeighbours++;
	if(i<m-1 && j>0) if(curr[i+1][j-1] == 1) liveNeighbours++;
	if(i<m-1 && j<n-1)  if(curr[i+1][j+1] == 1) liveNeighbours++;
	return liveNeighbours;
}
    void gameOfLife(vector<vector<int>>& board) {
        auto count = board;
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                int cnt = getLiveNeighbours(count,i,j,board.size(),board[0].size());
                if(board[i][j] == 0){
                    if(cnt == 3) board[i][j] = 1;
                }else if(board[i][j] == 1){
                    if(cnt >3 or cnt < 2)board[i][j] = 0;
                }
            }
        }
    }
};