class LRUCache {
public:
    map<int , pair<list<int>::iterator , int >>mp;
    list<int>dll;
    int n ;
    
    LRUCache(int capacity) {
        n= capacity ;
        
        
    }
    void markRecentlyUsed(int key)
    {
        // delete the key from the list and then push it to the front and update the address in the map 
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first = dll.begin();
        

    }
    int get(int key) {
       if(mp.find(key)==mp.end()){
return -1;
       }
        // if they exist then we need to mark them as recently used and then return the value from the map 
        markRecentlyUsed(key);
        return mp[key].second;
        
    }
    
    void put(int key, int value) {
    // if the key value already exist in the map 
        if(mp.find(key)==mp.end()){
            dll.push_front(key);
            mp[key]= {dll.begin(), value};
            n--;
        }else{
            mp[key].second = value ;
            markRecentlyUsed(key);
        }
        if(n<0){
            //more then capacity is pushed 
            int key_to_be_deleted = dll.back();
            mp.erase(key_to_be_deleted);
            dll.pop_back();
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */