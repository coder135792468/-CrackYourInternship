//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void dfs(vector<vector<int>>& adj,stack<char>& st,vector<int>& vis,int node){
        vis[node] = 1;
        for(auto ele:adj[node]){
            if(!vis[ele]){
                dfs(adj,st,vis,ele);
            }
        }      
        st.push(node);
    }
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> adj(K+1);
        for(int idx = 0;idx<N-1;idx++){
            string s1 = dict[idx];
            string s2 = dict[idx+1];
            int n = s1.size(), m = s2.size();
            int len = min(n,m);
            for(int i = 0;i<len;i++){
                if(s1[i] != s2[i]){
                    adj[s1[i] - 'a'].push_back(s2[i] - 'a');
                    break;
                }
            }
        };
        string order = "";
        stack<char> st;
        vector<int> vis(K);
        for(int i= 0;i<K;i++){
            if(!vis[i]){
                dfs(adj,st,vis,i);
            }
        }
         while(!st.empty()){
            order += st.top() + 'a';
            st.pop();
        }
        
        return order;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends