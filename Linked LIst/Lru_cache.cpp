class Node{
    public:
    int val,key;
    Node *next, *prev;
    Node(int _key,int _val){
        val = _val,key = _key;
        next = prev = NULL;
    }
};
class LRUCache {
public:
    Node *head, *tail;
    int n,size;
    vector<Node*> arr;
    LRUCache(int capacity) {
        n  = capacity;
        size = 0;
        head = new Node(-1,-1), tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        arr = vector<Node*> (10000,NULL);
    }
    
    int get(int key) {
        if(arr[key]){
            Node* temp =arr[key];
            int val = temp->val;
            arr[key] = NULL;
            deleteNode(temp);
            addNode(new Node(key,val));
            arr[key] = head->next;
            return val;
        };
        return -1;
    }
    
    void put(int key, int value) {
        if(arr[key]){
            Node* temp = arr[key];
            arr[key] = NULL;
            deleteNode(temp);
        };

        if(size == n){
            arr[tail->prev->key] = NULL;
            deleteNode(tail->prev);
        };
        addNode(new Node(key,value));
        arr[key] = head->next;

    }
private: 
    void addNode(Node* newNode){
        ++size;
        Node* temp = head->next;
        head->next = newNode;
        newNode->next = temp;
        newNode->prev = head;
        temp->prev = newNode;
    }
    void deleteNode(Node* del_node){
        --size;
        Node *del_prev = del_node->prev;
        Node *del_next = del_node->next;
        
        del_prev->next = del_next;
        del_next->prev = del_prev;

        del_node->next = NULL;
        del_node->prev = NULL;
        delete del_node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */