//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long getCount(int n) {
        vector<vector<int>> vec(10);
        vec[0] = {0, 8};
        vec[1] = {1, 2, 4};
        vec[2] = {1, 2, 3, 5};
        vec[3] = {2, 3, 6};
        vec[4] = {1, 4, 5, 7};
        vec[5] = {2, 4, 5, 6, 8};
        vec[6] = {3, 5, 6, 9};
        vec[7] = {4, 7, 8};
        vec[8] = {0, 5, 7, 8, 9};
        vec[9] = {6, 8, 9};
        
        vector<vector<long long>> dp(n+1,vector<long long>(10,0));
        for(int i = 0;i<10;i++){
            dp[1][i] = 1;            
        };
        
        for(int i = 2;i<=n;i++){
            for(int d = 0;d<=9;d++){
                for(auto ele:vec[d]){
                    dp[i][d] += dp[i-1][ele];   
                }
            }
        };
        
        long long sm =0;
        for(int i=  0;i<10;i++){
            sm+=dp[n][i];
        }
        return sm;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends