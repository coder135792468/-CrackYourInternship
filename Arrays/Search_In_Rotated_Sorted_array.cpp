class Solution {
public:
    int search(vector<int>& arr, int target) {
        int low = 0, high = arr.size()-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid] == target)return mid;
            else if(low == mid){
                low = low + 1;
            } else if(arr[mid] > arr[low]){
                 if(arr[mid]>= target and arr[low] <= target){
                    high = mid - 1;
                 }else low = mid + 1;
            }else{
                if(arr[mid] <= target and arr[high] >= target){
                    low = mid + 1;
                }else high = mid -1;
            }
        };
        return -1;
    }
};