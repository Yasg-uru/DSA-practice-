class NumberContainers {
public:
    unordered_map<int,int>indexToNum;
    unordered_map<int,set<int>>numsToindex;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        //before setting index to values we need to check whether is this index have a value already then we need to delete the index from the set of that value
        if(indexToNum.find(index)!=indexToNum.end()){
           int prevNumber = indexToNum[index];
           numsToindex[prevNumber].erase(index);// prev ka index set se remove kardo 
           if(numsToindex[prevNumber].empty()){
            numsToindex.erase(prevNumber);
           }

        }
        indexToNum[index]=number;
        numsToindex[number].insert(index);

    }
    
    int find(int number) {
        if(numsToindex.find(number)!=numsToindex.end() and not numsToindex[number].empty()){
            
        return *numsToindex[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */