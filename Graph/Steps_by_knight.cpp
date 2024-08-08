//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&src,vector<int>&target,int n)
	{
	    src = {src[0]-1,src[1]-1};
	    target ={target[0]-1, target[1] - 1};
	    queue<pair<int,vector<int>>> q;
	    q.push({ 0, src });
	    
	    vector<vector<int>> dir = {
            {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
            {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
        };
	    
	    vector<vector<int>> vis(n+1,vector<int>(n+1));
	    vis[src[0]][src[1]] = 1;
	    
	    int res = INT_MAX;
	    while(!q.empty()){
	        auto ele = q.front();
	        q.pop();
	        int moves = ele.first;
	        vector<int> pos = ele.second;
	        if(pos[0] == target[0] and pos[1] == target[1]){
	           return moves;
	        };
	        for(int i= 0;i<8;i++){
	            int ni = pos[0] + dir[i][0] , nj = pos[1] + dir[i][1];
	            if(ni<n and nj<n and ni>=0 and nj>=0 and !vis[ni][nj]){
    	            vector<int> temp = {ni,nj};
    	            q.push({moves + 1,temp });
    	            vis[ni][nj] = 1;
	            }
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends