class Solution {
public:
    bool isPossible(vector<vector<int>> matrix,int mid,int k){
        int ptr1 = matrix.size()-1,ptr2 = 0;
        int cnt = 0;
        while(ptr1 >=0 and ptr2 < matrix.size()){
            if(matrix[ptr1][ptr2] > mid)--ptr1;
            else {
                cnt+=(ptr1+1);
                ++ptr2;
            }
        }
        return cnt < k;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int low = matrix[0][0],high = matrix[matrix.size()-1][matrix[0].size()-1];
        while(low <= high ){
            int mid = low+(high-low)/2;
            if(isPossible(matrix,mid,k)){
                low = mid+1;
            }else high =mid-1;
        }
        
        
        return low;
    }
};