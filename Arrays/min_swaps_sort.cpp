	int minSwaps(vector<int>&nums)
	{
	   int n = nums.size();
	   vector<pair<int,int>> arr;
	   for(int i= 0;i<n;i++){
	       arr.push_back({nums[i],i});
	   };
	   sort(arr.begin(),arr.end());
	   int res = 0;
	   for(int i= 0;i<n;i++){
	       if(arr[i].first == nums[i])continue;
	       ++res;
	       swap(arr[arr[i].second], arr[i]);
	       --i;
	   }
	   return res;
	}