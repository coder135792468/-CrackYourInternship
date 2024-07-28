class Trie {
public:
    class Node{
        public:
         char data;
         Node* children[26];
         bool isTerminal;
         Node(char ch){
             data= ch;
             for(int i = 0;i<26;i++){
                 children[i] = NULL;
             };
             isTerminal = 0;
         }
     };
    
    Node* root = new Node('\0');
    Trie() {
        
    }
    void insertUtil(Node* root,string word){
        if(word.size()==0){
            root->isTerminal = 1;
            return;
        };
        int idx = word[0]-'a';
        Node* child;
        if(root->children[idx] != NULL){
            child = root->children[idx];
        }else{
            child = new Node(word[0]);
            root->children[idx] = child;
        };
        insertUtil(child,word.substr(1));
    }
    void insert(string word) {
        insertUtil(root,word);
    }
      bool searchUtil(Node* root,string word){
        if(word.size()==0)  return root->isTerminal;
        int idx = word[0]-'a';
        Node* child;
        if(root->children[idx] != NULL){
            child = root->children[idx];
        }else{
            return false;
        };
        return searchUtil(child,word.substr(1));
    }
    bool search(string word) {
       return searchUtil(root,word);
    }
    
    bool startsWithUtil(Node* root,string word){
          if(word.size()==0)return 1;
        int idx = word[0]-'a';
        Node* child;
        if(root->children[idx] != NULL){
            child = root->children[idx];
        }else{
            return false;
        };
        return startsWithUtil(child,word.substr(1));
    }
    bool startsWith(string prefix) {
        return startsWithUtil(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */