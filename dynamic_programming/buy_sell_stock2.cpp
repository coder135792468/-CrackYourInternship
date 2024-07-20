class Solution {
public:
    // int helper(vector<int>& arr,int i = 0,int prev = 0){
    //     if(i>=arr.size())return 0;

    //     int take = 0;
    //     if(prev == -1){
    //         take = helper(arr,i+1,i);
    //     }else if(arr[prev] <= arr[i]){
    //         take = (arr[i] - arr[prev]) + helper(arr,i+1,i);
    //     }else{
    //         take = helper(arr,i+1,i);
    //     }

    //     return take;
    // }
    int maxProfit(vector<int>& prices) {
        // return helper(prices,0,-1);
        int res = 0;
        for(int i = 1;i<prices.size();i++){
                res += max(0,(int)prices[i] - prices[i-1]);
        };
        return res;
    }
};