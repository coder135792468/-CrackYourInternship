class Solution {
public:
    int solve(vector<vector<int>>& stones,vector<int>& flag,int idx){

    flag[idx]=1;

    int cnt=1;

    for(int i=0;i<stones.size();i++){

        if(flag[i]==0 && (stones[idx][0]==stones[i][0] || stones[idx][1]==stones[i][1])){

            cnt+=solve(stones,flag,i);

        }

    }

    return cnt;

}

int removeStones(vector<vector<int>>& stones) {

    int n = stones.size();

    vector<int> flag(n,0);

    int ans=0;

    for(int i=0;i<n;i++){

        if(flag[i]==0){

            ans+=(solve(stones,flag,i)-1);

        }

    }

    

    return ans;

}
        
   
};