class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> vis(n*n+1,false);
		vis[1] = 1;
        queue<pair<int,int>> q;
		q.push({1,0});

        auto getCord = [&](int pos) -> vector<int>{
            int x = n - (pos -1)/n - 1,  y = (pos - 1)%n;
            if(n%2==x%2)y = n-1-y;
            return (vector<int>){x,y};
        };

        while(!q.empty()){
            pair<int,int> p = q.front();q.pop();
            int pos = p.first, dist = p.second;
            if(pos == n*n)return dist;
            
            for(int i=1;pos+i<=n*n && i<=6;i++){                
                vector<int> cords = getCord(pos+i);
                int row = cords[0], col = cords[1];
                int finalPos = board[row][col]==-1?pos+i:board[row][col];  
                if(!vis[finalPos]){
                    vis[finalPos] = 1;
                    q.push({finalPos,dist+1});
                }                
            }
        }
        return -1;
    }
};