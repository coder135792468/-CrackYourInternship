//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int dp[101][101];
    int helper(int freq[],int low,int high){
        if(low > high)return 0;
        
        if(dp[low][high]!=-1)return dp[low][high];
        int res = INT_MAX;
        for(int i = low;i<=high;i++){
            res = min({
               res, 
               helper(freq,low,i-1) + helper(freq,i+1,high)
            });
        }
          for(int i= low;i<=high;i++){
            res+=freq[i];
        };
        return dp[low][high] = res;
    }
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        memset(dp,-1,sizeof(dp));
         return helper(freq,0,n-1);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int keys[n];
        for(int i=0;i<n;i++)cin>>keys[i];
        int freq[n];
        for(int i=0;i<n;i++)cin>>freq[i];
        Solution ob;
        cout<<ob.optimalSearchTree(keys, freq, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends