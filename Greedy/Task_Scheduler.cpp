class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char,int> mp;
        priority_queue<int> pq;
        for(auto ch:tasks)mp[ch]++;
        for(auto ele:mp){
            pq.push(ele.second);
        };
        queue<pair<int,int>> q;
        int time = 0;
        
        while(!pq.empty() or !q.empty()){
            if(!q.empty() and q.front().second <= time){
                pq.push(q.front().first);
                q.pop();
            };
            time+=1;
            if(!pq.empty()){
                int ele = pq.top()-1;
                pq.pop();
                if(ele > 0)q.push({ele,time+n});
            }
        }
        return time;
       
         
    }
};