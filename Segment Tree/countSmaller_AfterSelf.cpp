struct SegmentTree{
        vector<int> tree;
        int n;
        SegmentTree(int n){
            this->n = n,tree.resize(4*(n+4));
        }
       static inline int left(int node){return 2*node+1;}
       static inline int right(int node) {return 2*node+2;}
        void update(int node, int s, int e, int val){
            if(s>e) return;
            if(s==e){
                tree[node]++;
                return;
            }
            int mid = s + (e-s)/2;
            if(val<=mid) update(left(node), s, mid, val);
            else update(right(node), mid+1, e, val);
            tree[node] = tree[left(node)] + tree[right(node)];
        }
        
        int query(int node, int s, int e, int qs, int qe){
            if(s>e || qe < s || qs > e) return 0;
            if(s>=qs && e<=qe) return tree[node];
            
            int mid = s + (e-s)/2;
            int l = query(left(node),s,mid,qs,qe);
            int r = query(right(node),mid+1,e,qs,qe);
            return l+r;
        }
        
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        for(auto &ele:nums)ele+=10000;
        int mx = *max_element(nums.begin(),nums.end());
        SegmentTree *st = new SegmentTree(mx+1);
        for(int i= nums.size()-1;i>=0;i--){
            st->update(0,0,mx,nums[i]);
            res.push_back(st->query(0,0,mx,0,nums[i]-1));
        }
        reverse(res.begin(),res.end());
        return res;
    }
};