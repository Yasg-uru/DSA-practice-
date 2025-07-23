class StockSpanner {
public:
    stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans =1; //current have their own stock price is 1 '
        while(not st.empty() and st.top().first<=price){
            ans+=st.top().second;
            st.pop();
        }
        st.push({price, ans});
        return ans ;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */