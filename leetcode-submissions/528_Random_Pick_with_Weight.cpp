class Solution {
public:
    vector<int>cumSum;
    Solution(vector<int>& w) {
        cumSum.push_back(w[0]);
        for(int i =1;i<w.size();i++){
            cumSum.push_back(w[i]+cumSum.back());
        }
    }
    
    int pickIndex() {
        int rand_weight = rand()%(cumSum.back());
        return upper_bound(cumSum.begin(), cumSum.end(), rand_weight)-cumSum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */