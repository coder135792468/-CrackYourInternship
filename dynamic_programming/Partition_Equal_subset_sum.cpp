//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
 
class Solution{
public:
    int equalPartition(int n, int arr[])
    {
         long long sum = 0;
         for(int i = 0;i<n;i++)sum+=arr[i];
         if(sum&1)return 0;
         
         vector<vector<int>> dp(sum/2 + 1,vector<int>(n));
         for(int i =0;i<n;i++){
             dp[0][i] = 1;
         };
         
         for(int i = 1;i<=sum/2;i++){
             for(int j = 0;j<n;j++){
                 if(i>=arr[j]){
                     dp[i][j] = dp[i][j-1] or dp[i-arr[j]][j-1];
                 }else{
                     dp[i][j] = dp[i][j-1];
                 }
             }
         }
         return dp[sum/2][n-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends