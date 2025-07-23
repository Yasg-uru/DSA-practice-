class CustomStack {
public:
stack<int>st;
int size;
    CustomStack(int maxSize) {
        this->size=maxSize;
    }
    
    void push(int x) {
        if(this->st.size()<this->size){
            this->st.push(x);
        }
    }
    
    int pop() {
        if(this->st.size()>0){
            int top=this->st.top();
            this->st.pop();
            return top;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        if(k>this->st.size()){
            stack<int>temp;
            while(not this->st.empty()){
                temp.push(st.top());
                st.pop();
            }
            while(not temp.empty()){
                st.push(temp.top()+val);
                temp.pop();
            }
        }else{
            
            stack<int>temp;
            while(not this->st.empty()){
                temp.push(st.top());
                st.pop();
            }
            int cnt=0;
           while(cnt<k){
            this->st.push(temp.top()+val);
            temp.pop();
            cnt++;
           }
           while(not temp.empty()){
            this->st.push(temp.top());
            temp.pop();

           }

        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */