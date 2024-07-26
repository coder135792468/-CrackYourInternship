class NumArray {
public:
    vector<int> seg;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4*n + 2);
        build(nums,0,n-1,1);
    };

    void build(vector<int>& nums,int low, int high, int idx){
        if(low == high){
            seg[idx] = nums[low];
            return;
        };
        int mid = low + (high-low)/2;
        build(nums,low,mid,idx*2);
        build(nums,mid+1,high,idx*2 + 1);
        seg[idx] = seg[idx*2] + seg[idx*2 + 1];
    }
    int query(int left, int right, int segIdx ,int l,int r) {
        if(left > right) return 0;   
        if(l == left and r == right) return seg[segIdx];  
        int mid = (l + r) / 2;
        return  query(left, min(right, mid), 2*segIdx, l, mid) + 
                query(max(left, mid + 1), right, 2*segIdx + 1, mid + 1, r);
    }
    int sumRange(int left,int right){
        return query(left,right,1,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */