class Trie{
        public:
        bool word;
        Trie* child[26];
        Trie(){
            word = false,memset(child,NULL,sizeof(child));
        }
};

class WordDictionary {
public:
    Trie* root = new Trie();
    void addWord(string word) {
        Trie* node = root;
        for (char c:word) {
            if (!node->child[c - 'a'])node->child[c-'a']=new Trie();
            node = node -> child[c - 'a'];
        }
        node->word = true;
    }
    bool search(const char* word,Trie* temp){
         for(int i = 0 ; word[i] and temp;i++){
           if(word[i] != '.')temp = temp->child[word[i]-'a'];
           else{
               Trie* node= temp;
               for(int j = 0;j<26;j++){
                   temp = node->child[j];
                   if(search(word + i + 1,temp))return true;
               }
           }
       }
      return temp and temp->word;
    }
    bool search(string word) {
        return search(word.c_str(), root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */