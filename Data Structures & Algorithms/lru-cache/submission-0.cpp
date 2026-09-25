class Node{
    public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int k, int v){
            key = k;
            val = v;
            prev = nullptr;
            next = nullptr;
        }
};


class LRUCache {
private:
    int capacity = 0;
    unordered_map<int, Node*> mp;
    Node* left;
    Node* right;

    void remove(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void insert(Node* node){
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* n = mp[key];
            remove(n);
            insert(n);
            return n->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            remove(mp[key]);
        }
        Node* newNode = new Node(key, value);
        mp[key] = newNode;
        insert(newNode);

        if(mp.size() > capacity){
            Node* lru = left->next;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }
    }
};
