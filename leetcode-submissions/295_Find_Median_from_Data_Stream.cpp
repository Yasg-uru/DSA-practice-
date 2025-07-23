class MedianFinder {
public:
    unordered_set<int>st;
    MedianFinder() {
        st.clear();
    }
    
    void addNum(int num) {
        st.insert(num);
    }
    
    double findMedian() {
        int n = st.size();
        if(n%2==0){
            auto it1 = st.begin();
            auto it2 = st.begin();
            advance(it1 , n/2-1);
            advance(it2, n/2);
            return (double)(*it1+*it2)/2;
        }else{
            auto it = st.begin();
            advance(it, n/2);
            return *it;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */