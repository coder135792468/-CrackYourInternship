class Solution {
public:
    int mxSum(vector<int>& arr,int k){
        int sm = 0, mx_sum = INT_MAX;
        for(int i = 0;i<k;i++) sm+=arr[i];
        mx_sum = min(mx_sum,sm);
        for(int i = k;i<arr.size();i++){
            sm+=arr[i];
            sm-=arr[i-k];
            mx_sum = min(mx_sum,sm);
        }
        return mx_sum;
    }
    int maxScore(vector<int>& arr, int k) {
        return accumulate(arr.begin(),arr.end(),0) - mxSum(arr,arr.size()-k);
    }
};