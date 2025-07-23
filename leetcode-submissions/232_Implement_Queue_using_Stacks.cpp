class MyQueue {
public:
stack<int>st;
stack<int>output;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
       while(st.size()>1){
           output.push(st.top());
           st.pop();
       } 
       int ele=st.top();
       st.pop();
       while(not output.empty()){
           st.push(output.top());
           output.pop();
       }
       return ele;
    }
    
    int peek() {
         while(st.size()>1){
           output.push(st.top());
           st.pop();
       } 
       int ele=st.top();
       while(not output.empty()){
           st.push(output.top());
           output.pop();
       }
       return ele;
        
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */