class FreqStack {
public:
     unordered_map<int, int>mp; // stores element and their frequency 
    priority_queue<tuple<int, int ,int>>pq; // it stores the frequency -> element 
   int timeStamp= 0 ;
    FreqStack() {
        mp.clear();
        
    }
    
    void push(int val) {
       
             mp[val]++;
    timeStamp++;
    pq.push({ mp[val],timeStamp, val});
    }
    
    int pop() {
        auto [ f , t , val]= pq.top();
        mp[val]--;
        if(mp[val]==0){
mp.erase(val);}
        pq.pop();
        return val;
    }
};


/**
 * Your FreqStack object will be instantiated and called as such:
 * var obj = new FreqStack()
 * obj.push(val)
 * var param_2 = obj.pop()
 */
/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */