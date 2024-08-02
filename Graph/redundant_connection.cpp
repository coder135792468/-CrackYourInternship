class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(1001),ans;

        for(int i= 0;i<=1000;i++) parent[i] = i;
        for(auto e:edges){
            int n1 = e[0], n2 = e[1];
            while(n1 != parent[n1])n1 = parent[n1];
            while(n2 != parent[n2])n2 = parent[n2];

            if(n1 == n2) ans = e;
            else parent[n1] = n2;
        }
        return ans;
    }
};