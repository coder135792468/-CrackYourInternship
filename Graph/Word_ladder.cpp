class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet;
        bool isEndWordPresent = false;
        for(auto s:wordList){
            if (!isEndWordPresent && s.compare(endWord) == 0)isEndWordPresent = true;
            wordSet.insert(s);
        }
        if(!isEndWordPresent)return 0;
        queue<string> q;
        q.push(beginWord);
        int lvl = 0;
        while(!q.empty()){
            lvl++;
            int sz= q.size();
            while(sz--){
                string temp = q.front();
                q.pop();
                for(int i = 0;i<temp.size();i++){
                    string curr = temp;
                    for(char c='a'; c<='z'; c++){
                       curr[i] = c;
                       if(temp.compare(curr) ==0)continue;
                       if(temp.compare(endWord)==0)return lvl;
                        if (wordSet.find(curr) != wordSet.end()){
                            q.push(curr);
                            wordSet.erase(curr);
                        }
                    }
                }
            }
        }
        
        return 0;
    }
};