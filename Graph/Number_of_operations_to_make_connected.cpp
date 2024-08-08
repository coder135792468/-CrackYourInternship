class DisjointSet{
public:
    vector<int> parent;
    int countEdges = 0;
    DisjointSet(int n){
        for(int i = 0 ;i<n;i++)  parent.push_back(i);
    };
    int findParent(int x){
        return parent[x] == x?x:findParent(parent[x]);
    }
    void takeUnion(int u,int v){
        u = findParent(u), v = findParent(v);
        if(u == v)++countEdges;
        else parent[u] = v;
    }
    int getComponents(int cnt = 0){
        for(int i = 0;i<parent.size();i++)
                if(parent[i] == i)++cnt;
        return cnt;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet dsu(n);
        for(auto ele:connections){
            dsu.takeUnion(ele[0],ele[1]);
        };
        int components = dsu.getComponents() - 1;
        return dsu.countEdges >= components ? components:-1;
    }
};