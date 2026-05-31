class LRUCache {
public:


    struct Node {
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;
    int capacity;

    LRUCache(int capacity) {
        this->capacity= capacity;
        head= new Node(-1, -1);
        tail= new Node(-1, -1);

        head->next= tail;
        tail->prev= head;
    }

    void insertNodeAtFront(Node* node){
        node->next= head->next;
        node->prev= head;

        node->next->prev= node;
        head->next= node;
    }

    void removeNode(Node* node){
        node->prev->next= node->next;
        node->next->prev= node->prev;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        
        else{
            removeNode(mp[key]);
            insertNodeAtFront(mp[key]);
            return mp[key]->val;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* node= mp[key];
            node->val= value;
            //Might be that I need to put/change the value of old key

            removeNode(mp[key]);
            insertNodeAtFront(mp[key]);
            return;
        }

        if(mp.size()==capacity){
            Node* lru= tail->prev;

            removeNode(lru);
            mp.erase(lru->key);
        }

        Node* temp= new Node(key, value);
        mp[key]= temp;
        insertNodeAtFront(mp[key]);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */