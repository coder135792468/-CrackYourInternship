class Solution {
  public:
    
    bool isPossible(long long mid,int arr[],int k,int n){
        int cnt = 0;
        long long sum = 0;
        for(int i= 0;i<n;i++){
            sum+=arr[i];
            if(sum > mid){
                sum = arr[i];
                ++cnt;
            }
        };
        
        return cnt >= k;
    }
  
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        if(m > n)return -1;
        long long sum =0;
        for(int i= 0;i<n;i++)sum+=arr[i];
        
        long long low = *max_element(arr,arr+n), high = sum;
        while(low <= high){
            long long mid = low + (high-low)/2;
            if(isPossible(mid,arr,m,n)){
                low = mid + 1;
            }else high = mid - 1;
        }
        
        return low;
    }
};