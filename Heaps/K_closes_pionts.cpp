class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
         vector<vector<int>> res;
         priority_queue<pair<double,int>> pq;
         for(int i= 0;i<points.size();i++){
            auto ele = points[i];
            double dist = sqrt((ele[0]*ele[0]) + (ele[1]*ele[1]));
            pq.push({dist,i});
            while(pq.size() > k)pq.pop();
         }
         while(!pq.empty()){
            res.push_back(points[pq.top().second]);
            pq.pop();
         };
         return res;
    }
};