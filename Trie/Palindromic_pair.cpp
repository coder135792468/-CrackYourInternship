struct TrieNode {
    int index;
    vector<int> palindromeSuffix;
    TrieNode* children[26] = {nullptr};
    TrieNode(){
        index = -1;
    }
};

class Solution {
    bool isPalindrome(string& word, int start, int end){
        while(start<end){
            if (word[start++] != word[end--]){
                return false;
            }
        }
        return true;
    }
    void addWordInTrie(TrieNode* root, string& word, int idx){
        int n = word.size();
        for(int i=n-1; i>=0; i--){
            int next = word[i]-'a';
            if (root->children[next] == nullptr){
                root->children[next] = new TrieNode();
            }
            
            if (isPalindrome(word, 0, i)){
                root->palindromeSuffix.push_back(idx);
            }
            
            root = root->children[next];
        }
        
        root->index = idx;
        root->palindromeSuffix.push_back(idx);
    }
    
    void searchWord(TrieNode* root, string& word, int idx, vector<vector<int>>& op){
        int wordN = word.size();
        for(int i=0; i<wordN; i++){
            if (root->index >= 0 && root->index != idx && isPalindrome(word, i, wordN-1)){
                op.push_back({idx, root->index});
            }
            
            root = root->children[word[i]-'a'];
            if (root == NULL){
                return;
            }
        }
        for(auto i: root->palindromeSuffix){
            if (i == idx){
                continue;
            }
            op.push_back({idx, i});
        }
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        TrieNode* root = new TrieNode();
        vector<vector<int>> op;
        int n = words.size();
        for(int i=0; i<n; i++){
            addWordInTrie(root, words[i], i);
        }
        for(int i=0; i<n; i++){
            searchWord(root, words[i], i, op);
        }
        return op;
            
    }
};