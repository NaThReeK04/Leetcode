class MyHashMap {
public:
    vector<int>hash_map;
    MyHashMap() {
        hash_map=vector<int>(10000001,-1);
    }
    
    void put(int key, int value) {
        hash_map[key]=value;
    }
    
    int get(int key) {
        return hash_map[key];
    }
    
    void remove(int key) {
        hash_map[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */