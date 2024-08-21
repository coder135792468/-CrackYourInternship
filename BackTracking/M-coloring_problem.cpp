//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    bool isSafe(bool graph[101][101],int i,vector<int>& col,int color,int n){
        for(int j = 0;j<n;j++){
            if(graph[i][j] and col[j] == color)return false;
        }
        return true;
    }
    bool traverse(bool graph[101][101],vector<int>& col,int m,int n, int node = 0){
        if(node == n)return true;
        for(int color = 1;color<=m;color++){
            if(isSafe(graph,node,col,color,n)){
                col[node] = color;
                if(traverse(graph,col,m,n,node+1)){
                    return true;
                };
                col[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> color(n);
        return traverse(graph,color,m,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends