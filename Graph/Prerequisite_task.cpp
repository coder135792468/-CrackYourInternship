//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<int> vis;
    bool dfs(int node ,vector<vector<int>> & adj,vector<int>& path){
        vis[node] = 1;
        path[node] = 1;
        for(auto ele:adj[node]){
            if(!vis[ele]){
                if(dfs(ele,adj,path))return 1;
            }
            else if(path[ele]) return 1;
        }
        path[node] = 0;
        return 0;
    }
    bool isCyclic(int V, vector<vector<int>>  adj) {
        vis.resize(V+1,0);
        vector<int> path(V+1,0);
        for(int i=  0;i<V;i++){
            if(!vis[i] and dfs(i,adj,path))return 1;
        }
        return 0;
    }
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    vector<vector<int>> adj(N);
	    for(auto ele:prerequisites){
	        adj[ele.first].push_back(ele.second);
	    };
	    return !isCyclic(N, adj);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends