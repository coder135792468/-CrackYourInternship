//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
int rec(int ind,vector <vector <int>> &cost,int mask,vector <vector <int>> &dp){
    int n=cost.size();
    mask=mask^(1<<ind);
    if(mask==0)
    return cost[ind][0];
    if(dp[ind][mask]!=-1)
    return dp[ind][mask];
    int ans=INT_MAX;
    for(int j=0;j<n;j++){
        if(mask&(1<<j)){
            ans=min(ans,cost[ind][j]+rec(j,cost,mask,dp));
        }
    }
    return dp[ind][mask]=ans;
}
int total_cost(vector<vector<int>>cost){
    // Code here
    int n=cost.size();
    int mask=pow(2,n)-1;
    vector <vector<int>> dp(n,vector <int> (mask+1,-1));
    return rec(0,cost,mask,dp);
}


};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends