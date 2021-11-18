// Problem Link -> https://leetcode.com/problems/lru-cache/submissions/
// Appraoch:-
// * To track the least Recently Used (LRU) node we will maintain a doubly linked and whenever we used any existing node or add a new node we will take that node 
//   to the very next of the head by which the very previous of tail node will have the LRU node
// * To remember the address of the exsting node we will use a hashmap.

class LRUCache {
public:
    class node{
        public:
        node* next;
        node* prev;
        int val;
        int key;
        
        node(int _val, int _key){
            val = _val;
            key = _key;
        }
    };
    unordered_map<int, node*> m;
    int cap;
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    
    void deleteNode(node* todelete){
        node* deleteNext = todelete->next;
        node* deletePrev = todelete->prev;
        deletePrev->next = deleteNext;
        deleteNext->prev = deletePrev;
    }
    
    void addNode(node* toAdd){
        node* headNext = head->next;
        toAdd->next = headNext;
        toAdd->prev = head;
        head->next = toAdd;
        headNext->prev = toAdd;
    }
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key_) {
        if(m.find(key_) != m.end()){
            node* resnode = m[key_];
            int res = resnode->val;
            m.erase(key_);
            deleteNode(resnode);
            addNode(resnode);
            m[key_] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key_, int value) {
        if(m.find(key_) != m.end()){
            node* exist = m[key_];
            m.erase(key_);
            deleteNode(exist);
        }
        
        if(m.size() == cap){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(value, key_));
        m[key_] = head->next;
    }
};
