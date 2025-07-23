class AllOne {
public:
unordered_map<string,int>mp;

    AllOne() {
        
    }
    
    void inc(string key) {
        mp[key]++;
    }
    
    void dec(string key) {
        mp[key]--;
    }
    
    string getMaxKey() {
        int maxKey=INT_MIN;
        string ans="";
        for(auto ele:mp){
            if(maxKey<ele.second){
                maxKey=ele.second;
                ans=ele.first;
            }
        }
        return ans;
    }
    
    string getMinKey() {
         int minkey =INT_MAX;
        string ans="";
        for(auto ele:mp){
            if(minkey>ele.second){
                minkey=ele.second;
                ans=ele.first;
            }
        }
        return ans;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */