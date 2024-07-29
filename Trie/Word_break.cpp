
class Trie{
public:
    int isEnd = 0;
    vector<Trie*> child;
    Trie(){
        child.resize(26,NULL);
    }
};

class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    
    
    void insert(Trie* root,string s){
        Trie* temp = root;
        for(auto ch:s){
            if(!temp->child[ch - 'a'])temp->child[ch - 'a'] = new Trie();
            temp = temp->child[ch - 'a'];
        };
        temp->isEnd = 1;
    };
    
    bool possible(Trie* root,string& str,int i = 0){
         if(i >= str.size())return true;    
         Trie* temp = root;
         for(int j = i;j<str.size();j++){
             if(!temp->child[str[j] - 'a'])return 0;
             temp = temp->child[str[j] - 'a'];
             if(temp->isEnd){
                 if(possible(root,str,j+1))return 1;
             }
         };
         return false;
    }
    int wordBreak(string A, vector<string> &B) {
        Trie* root = new Trie();
        for(auto str:B)insert(root,str);
        
        return possible(root,A);
    }
};