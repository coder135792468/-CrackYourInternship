class Solution {
public:
    int res = 0;
    void merge(std::vector<int>& arr, int low, int mid, int high) {
        int j = mid + 1;
        for(int i = low;i<=mid;i++){
            while(j<=high and arr[i] > 2*(long long)arr[j])++j;
            res+= j - mid - 1;
        }

        int size = high - low + 1;
        vector<int> temp(size);
        int left = low, right = mid+1, k=0;
        while(left<=mid && right<=high){
            if(arr[left] < arr[right]){
                temp[k++] = arr[left++];
            }
            else{
                temp[k++] = arr[right++];
            }
        }
        while(left<=mid){
            temp[k++] = arr[left++]; 
        }
        while(right<=high){
            temp[k++] = arr[right++]; 
        }
        int m=0;
        for(int i=low; i<=high; i++){
            arr[i] = temp[m++];
        }
    }
    void mergeSort(std::vector<int>& arr, int low, int high) {
        if(low >= high) return;
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
   
    int reversePairs(vector<int>& arr) {
        mergeSort(arr,0,arr.size()-1);
        return res;
    }
};