class RandomizedSet {
public:
    vector<int>vals;
    unordered_map<int , int>valToIndex;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(valToIndex.find(val)!=valToIndex.end()){
            return false;
        }
        vals.push_back(val);
        
        valToIndex[val]= vals.size()-1;
        return true ;
    }
    
    bool remove(int val) {
        if(valToIndex.find(val)==valToIndex.end()){
            return false;
        }
        
        // now we have to get the index of the value
        int index = valToIndex[val];
        // after getting an index we need to swap this value 
        int lastElement = vals[vals.size()-1];
        valToIndex[lastElement] = index;
        vals.pop_back();
        valToIndex.erase(val);
        return true ;
        
    }
    
    int getRandom() {
        int randomIndex = rand()%vals.size();
        return vals[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */