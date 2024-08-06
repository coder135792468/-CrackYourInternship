class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        int n = arr.size();
        if(n <= 1) return 0;
        sort(arr.begin(), arr.end(), [] (auto &a, auto &b) {return a[1] < b[1];});
        int finishTime = arr[0][1];
        int len = 1;
        for(int i = 1; i < n; i++) {
            if(arr[i][0] >= finishTime){
                len++;
                finishTime = arr[i][1];
            }
        }
        
        return n - len;
    }
};