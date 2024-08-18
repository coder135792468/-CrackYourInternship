class Solution {
public:
    string reorganizeString(string s) {
        vector<int> cnt(26);
        for(auto ch:s) cnt[ch - 'a']++;
        priority_queue<pair<int,char>> pq;
        for(int i = 0;i<26;i++){
            if(cnt[i] == 0)continue;
            pq.push({cnt[i], i + 'a'});
        };
        string temp;
        while(pq.size() > 1){
            auto ele1 = pq.top();
            pq.pop();
            auto ele2 = pq.top();
            pq.pop();
            temp.push_back(ele1.second), temp.push_back(ele2.second);
            --ele1.first, --ele2.first;
            if(ele1.first > 0)pq.push(ele1);
            if(ele2.first > 0)pq.push(ele2);
        };
        string t;
        while(!pq.empty()){
            t+=string(pq.top().first,pq.top().second);
            pq.pop();
        }
        for(int i  = 1;i<t.size();i++){
            if(t[i] == t[i-1])return "";
        }
        return temp + t;
    }
};