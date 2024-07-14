class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 0, high  = nums.size()-1;
        while(low <=high){
            int mid = low+(high-low)/2;
            int cnt = 0;
            for(auto ele:nums){
                if(mid >= ele)++cnt;
            };
            if(cnt <= mid){
                low = mid+1;
            }else{
                high =mid-1;
            }
        }
        return low;
    }
};