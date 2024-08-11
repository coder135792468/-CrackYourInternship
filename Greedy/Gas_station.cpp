class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res = 0;
        int n= gas.size();
        int total_dist = 0;
        int cur_dist = 0;
        for(int i= 0;i<n;i++){
            int diff = gas[i] - cost[i];
            total_dist += diff;
            cur_dist += diff;
            if(cur_dist < 0){
                res = i + 1;
                cur_dist = 0;
            }
        }
        return total_dist>=0?res:-1;
    }
};