class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int low = 0, high = height.size()-1;
        while(low <= high){
            res = max(res,(high-low)*min(height[low],height[high]));
            height[low] < height[high] ? ++low:--high;
        };
        return res;
    }
};