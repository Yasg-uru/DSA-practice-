class TimeMap {
public:
    unordered_map<string , vector<pair<string , int>>>mp;
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value  ,timestamp});
    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key)){
            return "";
        }
        vector<pair<string , int >>&vec = mp[key];
        int target= timestamp;
        int low = 0, high = vec.size()-1 ;
        string result = "";
        while(low<=high){
            int mid = (low+high)/2;
            if(vec[mid].second<=target){
                result = vec[mid].first;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return result ;
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */