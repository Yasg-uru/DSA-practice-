class MyHashMap {
public:
 int hash[1000001];
    MyHashMap() {
        for(int i=0;i<1000001;i++){
            hash[i]=-1;
        }
    }
    
    void put(int key, int value) {
        hash[key]=1;
    }
    
    int get(int key) {
        if(hash[i]==-1) return -1;
    }
    
    void remove(int key) {
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */