class MyHashSet {
public:
bool set[100000];
    MyHashSet() {
        for(int i=0;i<10000;i++){
            set[i]=false;
        }
    }
    
    void add(int key) {
       set[key]=true; 
    }
    
    void remove(int key) {
        set[key]=false;
    }
    
    bool contains(int key) {
        return set[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */