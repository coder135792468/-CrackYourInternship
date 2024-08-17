//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n = nums.size();
        vector<int> dp(n,1e9);
        for(int i = 0;i<n;i++){
          int letter = 0, cnt = 0;
          for(int j = i;j>=0;j--){
              if(letter + cnt + nums[j] > k)break;
              letter+= nums[j];
              int space = k - letter - cnt;
              dp[i] = min(dp[i], (j>0?dp[j-1]:0) + ((i != n-1)*space*space));
              ++cnt;
          }
        }
        return dp[n-1];
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends