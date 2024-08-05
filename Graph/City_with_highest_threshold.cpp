class Solution {
public:
    unordered_map<int,vector<pair<int,int>>> adj;
    vector<int> shortestDist(int node,int n){
        queue<pair<int,int>> q;
        vector<int> dist(n,INT_MAX);

        q.push({node,0});
        dist[node] = 0;
        while(!q.empty()){
            auto ele = q.front();
            q.pop();
            int u = ele.first;
            for(auto num:adj[u]){
                int v = num.first, cost2 = num.second;
                if(dist[v] > dist[u] + cost2){
                    dist[v] = dist[u] + cost2;
                    q.push({v,dist[v]});
                }
            }
        }

        return dist;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist;
        
        for(auto e:edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        };

        for(int i = 0;i<n;i++){
            dist.push_back(shortestDist(i,n));
        }
        int res = -1,mxCity = n;
         for(int city = 0;city<n;city++){
             int cnt = 0;
             for(int newCity = 0;newCity<n;newCity++){
                 if(dist[city][newCity] <= distanceThreshold){
                        ++cnt;
                 }
             };
             if(cnt <= mxCity){
                 mxCity  = cnt;
                 res = city;
             }
         }
        return res;
    }
};