class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int minOperations = 0 ;
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int& num:nums){
            pq.push(num);
        }
        while(not pq.empty() and pq.top()<k){
            pq.pop();
            minOperations++;
        }
        return minOperations;
    }
};