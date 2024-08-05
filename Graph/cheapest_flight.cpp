class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        vector<int>dist(n,INT_MAX);
        queue<pair<int,int>> q;

        for(auto e:flights)adj[e[0]].push_back({e[1],e[2]});
        q.push({src,0});
        dist[src] = 0;

        while(k >= 0 and !q.empty()){
           int sz = q.size();
           while(sz--){
               auto [node,dis] = q.front();
               q.pop();
               for(auto [nbr,price] : adj[node]){
                   if(price + dis >= dist[nbr])continue;
                   dist[nbr] = price + dis;
                   q.push({nbr,dist[nbr]});
               }
           }
           k--;
        }

        return dist[dst] == INT_MAX?-1:dist[dst];
    }
};