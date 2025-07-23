class LRUCache {
public:
    list<int>dll;
    unordered_map<int , pair<list<int>::iterator , int >>mp;
    int n ;
    LRUCache(int capacity) {
        n = capacity ;


    }
    void MarkAsRecent(int key){
        // first we need to find that node from the map and delete them from the list 
        dll.erase(mp[key].first);
        
        //and insert in the front of the list 
        dll.push_front(key);
        mp[key].first = dll.begin();
        // and update the pointer in the map 

    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        int value  = mp[key].second;
        MarkAsRecent(key);
        return value ;

    }
    
    void put(int key, int value) {
        // now we have two conditions if not in the map then insert but make sure size does not increased 
        if(n==0){
            //when capacity is fulled then we need to remove the last least recent used and delete it from the map 
            mp.erase(dll.back());
            dll.pop_back();
            n++;
        }
        if(mp.find(key)==mp.end()){
            dll.push_front(key);
            mp[key]= {dll.begin() ,value };
            MarkAsRecent(key);
        }else{
            mp[key].second = value ;
            MarkAsRecent(key);
        }
        n--;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */